#include "../include/ControllerInmueble.h"
#include "../include/Inmueble.h"
#include "../include/AltaUsuario.h"
#include "../include/Factory.h"
#include "../include/Casa.h"
#include "../include/Propietario.h"
#include "../include/Apartamento.h"

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
    Inmueble* inmueble = it->second;
    Propietario* propietario = inmueble->getPropietario();
 propietario->inmuebles.erase(inmueble);
 inmueble->setPropietario(NULL); 
    for (AdministraPropiedad* ap : inmueble->getAPs()) {
        for (Publicacion* pub : ap->getPublicaciones()) {
            // se borraron las agendas entonces ¿tambien se borro el link entre cliente y publicacion?
         pub->setAP(NULL);
         delete pub->getDTFecha();
            delete pub;
            
        }
     ap->getPublicaciones().clear();
 ap->setPAlquilerActiva(NULL);
        ap->setPVentaActiva(NULL);
ap->setInmueble(NULL);
    inmueble->getAPs().erase(ap);
 Inmobiliaria* i = ap->getInmobiliaria();
 if (i != NULL)
            i->getAPs().erase(ap);
            ap->setInmobiliaria(NULL);
        delete ap;
    }
  inmueble->getAPs().clear();
   this->inmuebles.erase(it);
    delete inmueble;
}


void ControllerInmueble::AltaCasa(std::string direccion, int numeroPuerta, int superficie, 
                                 int anioConstruccion, bool esPH, TipoTecho techo) {
    Casa* c = new Casa(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    Propietario* p = dynamic_cast<Propietario*>(Factory::getInstance()->getAltaUsuario()->getUtemp());
    if (p != NULL) {
        c->setPropietario(p);
        p->agregarInmueble(c);
    }
}

void ControllerInmueble::AltaApartamento(std::string direccion, int numeroPuerta, int superficie, 
                                        int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes) {
    Apartamento* a = new Apartamento(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anioConstruccion, piso, tieneAscensor, gastosComunes);
    Propietario* p = dynamic_cast<Propietario*>(Factory::getInstance()->getAltaUsuario()->getUtemp());
    if (p != NULL) {
        a->setPropietario(p);
        p->agregarInmueble(a);
    }
}
std::set(DTInmuebleListado*) ControllerInmueble::listarInmuebles() {
    
    std::set<DTInmuebleListado*> resultado;
    std::map<int,Inmueble*>::iterator it;
    for (it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* in = it->second;
DTInmuebleListado* dtil = new DTInmuebleListado(in->getCodigo(),in->getDireccion(),in->getPropietario()->getNickname());
    resultado.insert(dtil);
    } 
return resultado;}

    


    DTInmueble* ControllerInmueble::detalleInmueble(codigoInmueble int) {
         std::map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
if (it == this->inmuebles.end()) {
        return NULL;
    }
    Inmueble* i = it->second;
      class Casa* casa = dynamic_cast<class Casa*>(i);
    if (casa != NULL) {
        return new DTCasa(casa->getCodigo(), casa->getDireccion(), casa->getNumeroPuerta(), 
                         casa->getSuperficie(), casa->getAnioConstruccion(), casa->getEsPH(), casa->getTecho());
    } else {
        class Apartamento* apto = dynamic_cast<class Apartamento*>(i);
        return new DTApartamento(apto->getCodigo(), apto->getDireccion(), apto->getNumeroPuerta(), 
                                apto->getSuperficie(), apto->getAnioConstruccion(), apto->getPiso(), 
                                apto->getTieneAscensor(), apto->getGastosComunes());
    }
}
