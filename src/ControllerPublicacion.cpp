#include "../include/ControllerPublicacion.h"
#include "../include/Publicacion.h"
#include "../include/Factory.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"
#include "../include/ColeccionUsuario.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTApartamento.h"

ControllerPublicacion* ControllerPublicacion::instancia = NULL;

ControllerPublicacion::ControllerPublicacion() : codigoUP(0) {
}

ControllerPublicacion::~ControllerPublicacion() {
}

ControllerPublicacion& ControllerPublicacion::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControllerPublicacion();
        instancia->codigoUP = 0;
    }
    return *instancia;
}

int ControllerPublicacion::actualizarCodigoUP() {
    this->codigoUP++;
    return this->codigoUP;
}

bool ControllerPublicacion::AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, 
                                          TipoPublicacion tipoPublicacion, std::string texto, float precio) {
    Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria);
    Inmobiliaria* i = dynamic_cast<Inmobiliaria*>(usuario);
    
    if (i == NULL) return false;
    
    AdministraPropiedad* ap = i->getAP(codigoInmueble);
    if (ap == NULL) return false;
    
    DTFecha* f = Factory::getInstance()->getControladorFechaActual()->getFechaActual();
    
    if (ap->existeTipoPublicacionActual(tipoPublicacion)) {
        delete f;
        return false;
    }
    
    int c = this->actualizarCodigoUP();
    Publicacion* p = new Publicacion(c, f, tipoPublicacion, texto, precio, false);
    ap->getPublicaciones().insert(p);
    this->publicaciones.insert(std::make_pair(c, p)); 
    p->setAP(ap);
    
    if (tipoPublicacion == Venta) {
        if (ap->getPVentaActiva() == NULL) {
            p->activar();
            ap->setPVentaActiva(p);
        } else if (ap->getPVentaActiva()->getDTFecha()->operator<(f)) {
            ap->getPVentaActiva()->desactivar();
            p->activar();
            ap->setPVentaActiva(p);
        }
    } else {
        if (ap->getPAlquilerActiva() == NULL) {
            p->activar();
            ap->setPAlquilerActiva(p);
        } else if (ap->getPAlquilerActiva()->getDTFecha()->operator<(f)) {
            ap->getPAlquilerActiva()->desactivar();
            p->activar();
            ap->setPAlquilerActiva(p);
        }
    }
    
    i->notificarObservers(c);
    
    return true;
}

std::set<DTPublicacion*> ControllerPublicacion::listarPublicacion(TipoPublicacion tipoPublicacion, 
                                                                 float precioMinimo, float precioMaximo, 
                                                                 TipoInmueble tipoInmueble) {
    std::set<DTPublicacion*> resultado;
    std::map<int, Publicacion*>::iterator it;
    
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        Publicacion* pub = it->second;
        if (pub!=NULL && (pub->cumpleFiltros(tipoPublicacion, precioMinimo, precioMaximo) &&
            pub->mismotipo(tipoInmueble))) {
            DTPublicacion* dt = pub->getDatos();
            resultado.insert(dt);
        }
    }
    
    return resultado;
}

DTInmueble* ControllerPublicacion::detalleInmueblePublicacion(int codigoPublicacion) {
    std::map<int, Publicacion*>::iterator it = this->publicaciones.find(codigoPublicacion);
    if (it == this->publicaciones.end()) {
        return NULL;
    }
    
    Publicacion* pub = it->second;
    Inmueble* i = pub->getAP()->getInmueble();
    
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

Publicacion* ControllerPublicacion::getPublicacion(int codigo) {
    std::map<int, Publicacion*>::iterator it = this->publicaciones.find(codigo);
    if (it != this->publicaciones.end()) {
        return it->second;
    }
    return NULL;
}

void eliminarPublicacion(int codigoPublicacion) {
    std::map<int, Publicacion*>::iterator it = this->publicaciones.find(codigoPublicacion);
    if (it == this->publicaciones.end()) {
        return;
    }
    
    Publicacion* pub = it->second;
    AdministraPropiedad* ap = pub->getAP();
    
    if (ap != NULL) {
        ap->getPublicaciones().erase(pub);
        if (ap->getPVentaActiva() == pub) {
            ap->setPVentaActiva(NULL);
        } else if (ap->getPAlquilerActiva() == pub) {
            ap->setPAlquilerActiva(NULL);
        }
    }
    
    delete pub;
    this->publicaciones.erase(it);
}