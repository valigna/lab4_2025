#include "../include/ControllerPublicacion.h"
#include "../include/Publicacion.h"
#include "../include/Factory.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"
#include "../include/ColeccionUsuario.h"

ControllerPublicacion& ControllerPublicacion::getInstancia(){
    if (instancia==NULL){
        instancia= new ControllerPublicacion;
        instancia->codigoUP=0;
    }
    return *instancia;
}

int ControllerPublicacion::actualizarCodigoUP(){
    this->codigoUP++;
    return this->codigoUP;
}

bool ControllerPublicacion::AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
    Inmobiliaria* i= static_cast<Inmobiliaria*>(ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria));
    AdministraPropiedad* ap=i->getAP(codigoInmueble);
    DTFecha* f= Factory::getInstance()->getControladorFechaActual()->getFechaActual();
    if (ap->existeTipoPublicacionActual(tipoPublicacion)){
        return false;
    }
    else {
        int c=ControllerPublicacion::actualizarCodigoUP();
        Publicacion* p= new Publicacion(c, f, tipoPublicacion, texto, precio, false);
        ap->getPublicaciones().insert(p);
        ControllerPublicacion::getInstancia().publicaciones.insert({c, p}); 
        p->setAP(ap);
        if (tipoPublicacion==Venta){
            if (ap->getPVentaActiva()==NULL){
                p->activar();
                ap->setPVentaActiva(p);
            }
            else if (ap->getPVentaActiva()->getDTFecha()->operator<(f)){
                ap->getPVentaActiva()->desactivar();
                p->activar();
                ap->setPVentaActiva(p);
            }
        }
        else {
            if (ap->getPAlquilerActiva()==NULL){
                p->activar();
                ap->setPAlquilerActiva(p);
            }
            else if (ap->getPAlquilerActiva()->getDTFecha()->operator<(f)){
                ap->getPAlquilerActiva()->desactivar();
                p->activar();
                ap->setPAlquilerActiva(p);
            }
        }
    }
    return true;
}

std::set<DTPublicacion*> ControllerPublicacion::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){  
    std::set<DTPublicacion*> resultado;
    for (const auto& par : publicaciones) {
        Publicacion* pub = par.second;
        if (pub->cumpleFiltros(tipoPublicacion, precioMinimo, precioMaximo) &&
            pub->mismotipo(tipoInmueble)) {

            DTPublicacion* dt = pub->getDatos();
            resultado.insert(dt);
        }
    }

    return resultado;
}

DTInmueble* ControllerPublicacion::detalleInmueblePublicacion(int codigoPublicacion){
    Publicacion* pub = this->publicaciones.find(codigoPublicacion)->second;
    Inmueble* i = pub->getAP()->getInmueble();
    Casa* casa = dynamic_cast<Casa*>(i);
    if (casa!=NULL){
        return DTCasa(casa->getCodigo(),casa->getDireccion(), casa->getNumeroPuerta(),casa->getSuperficie(),casa->getAnoConstruccion(),casa->getEsPH(),casa->getTecho());
    else{
        Apartamento* apto = dynamic_cast<Apartamento*>(i)
        return DTApartamento(apto->getCodigo(),apto->getDireccion(),apto->getNumeroPuerta(), apto->getSuperficie(),apto->getAnoConstruccion(),apto->getPiso(),apto->getTieneAscensor(), apto->getGastosComunes() );
        }
    }
}



    

