#include "../include/ControllerInmueble.h"
#include "../include/Inmueble.h"
#include "../include/AltaUsuario.h"
#include "../include/Factory.h"
#include "../include/Casa.h"
#include "../include/Propietario.h"
#include "../include/Apartamento.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Publicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTCasa.h"
#include "../include/DTApartamento.h"

ControllerInmueble* ControllerInmueble::instancia = NULL;

ControllerInmueble::ControllerInmueble() : ultimoCodigoInmueble(0) {
}

ControllerInmueble::~ControllerInmueble() {
}

ControllerInmueble& ControllerInmueble::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControllerInmueble();
        instancia->ultimoCodigoInmueble = 0;
    }
    return *instancia;
}

int ControllerInmueble::actualizarCodigoInmueble() {
    this->ultimoCodigoInmueble++;
    return this->ultimoCodigoInmueble;
}

void ControllerInmueble::eliminarInmueble(int codigoInmueble) {
    std::map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
    if (it == this->inmuebles.end()) {
        return;
    }
    
    Inmueble* inmueble = it->second;
    Propietario* propietario = inmueble->getPropietario();
    if (propietario != NULL) {
        propietario->getInmuebles().erase(inmueble);
    }
    inmueble->setPropietario(NULL);
    
    std::set<AdministraPropiedad*> aps = inmueble->getAPs();
    for (std::set<AdministraPropiedad*>::iterator apIt = aps.begin(); apIt != aps.end(); ++apIt) {
        AdministraPropiedad* ap = *apIt;
        
        std::set<Publicacion*> pubs = ap->getPublicaciones();
        for (std::set<Publicacion*>::iterator pubIt = pubs.begin(); pubIt != pubs.end(); ++pubIt) {
            Publicacion* pub = *pubIt;
            pub->setAP(NULL);
            Factory::getInstance()->getControllerPublicacion()->eliminarPublicacion(pub->getCodigo());
        }
        ap->getPublicaciones().clear();
        
        ap->setPAlquilerActiva(NULL);
        ap->setPVentaActiva(NULL);
        ap->setInmueble(NULL);
        
        Inmobiliaria* inmobiliaria = ap->getInmobiliaria();
        if (inmobiliaria != NULL) {
            inmobiliaria->removeAP(ap);
            ap->setInmobiliaria(NULL);
        }
        delete ap;
        ap=NULL;
    }
    
    inmueble->getAPs().clear();
    this->inmuebles.erase(it);
    delete inmueble;
}

void ControllerInmueble::AltaCasa(std::string direccion, int numeroPuerta, int superficie, 
                                 int anioConstruccion, bool esPH, TipoTecho techo) {
    int codigo = actualizarCodigoInmueble();
    class Casa* nuevaCasa = new class Casa(codigo, direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    this->inmuebles[codigo] = nuevaCasa;
    
    Propietario* propietario = dynamic_cast<Propietario*>(Factory::getInstance()->getAltaUsuario()->getUtemp());
    if (propietario != NULL) {
        nuevaCasa->setPropietario(propietario);
        propietario->agregarInmueble(nuevaCasa);
    }
}

void ControllerInmueble::AltaApartamento(std::string direccion, int numeroPuerta, int superficie, 
                                        int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes) {
    int codigo = actualizarCodigoInmueble();
    class Apartamento* nuevoApartamento = new class Apartamento(codigo, direccion, numeroPuerta, superficie, anioConstruccion, piso, tieneAscensor, gastosComunes);
    this->inmuebles[codigo] = nuevoApartamento;
    
    Propietario* propietario = dynamic_cast<Propietario*>(Factory::getInstance()->getAltaUsuario()->getUtemp());
    if (propietario != NULL) {
        nuevoApartamento->setPropietario(propietario);
        propietario->agregarInmueble(nuevoApartamento);
    }
}

std::set<DTInmuebleListado*> ControllerInmueble::listarInmuebles() {
    std::set<DTInmuebleListado*> resultado;
    
    for (std::map<int, Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* inmueble = it->second;
        std::string propietarioNick = (inmueble->getPropietario() != NULL) ? 
                                     inmueble->getPropietario()->getNickname() : "Sin propietario";
        DTInmuebleListado* dtil = new DTInmuebleListado(inmueble->getCodigo(), 
                                                       inmueble->getDireccion(), 
                                                       propietarioNick);
        resultado.insert(dtil);
    } 
    return resultado;
}

DTInmueble* ControllerInmueble::detalleInmueble(int codigoInmueble) {
    std::map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
    if (it == this->inmuebles.end()) {
        return NULL;
    }
    
    Inmueble* inmueble = it->second;
    class Casa* casaPtr = dynamic_cast<class Casa*>(inmueble);
    if (casaPtr != NULL) {
        return new DTCasa(casaPtr->getCodigo(), casaPtr->getDireccion(), casaPtr->getNumeroPuerta(), 
                         casaPtr->getSuperficie(), casaPtr->getAnioConstruccion(), 
                         casaPtr->getEsPH(), casaPtr->getTecho());
    } else {
        class Apartamento* apartamentoPtr = dynamic_cast<class Apartamento*>(inmueble);
        if (apartamentoPtr != NULL) {
            return new DTApartamento(apartamentoPtr->getCodigo(), apartamentoPtr->getDireccion(), 
                                   apartamentoPtr->getNumeroPuerta(), apartamentoPtr->getSuperficie(), 
                                   apartamentoPtr->getAnioConstruccion(), apartamentoPtr->getPiso(), 
                                   apartamentoPtr->getTieneAscensor(), apartamentoPtr->getGastosComunes());
        }
    }
    return NULL;
}
