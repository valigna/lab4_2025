#include <string>
#include "../include/ControllerPublicacion.h"
#include "../include/Publicacion.h"

ControllerPublicacion* ControllerPublicacion::instancia=NULL;

ControllerPublicacion& ControllerPublicacion::getInstancia(){
    if (instancia==NULL){
        instancia= new ControllerPublicacion;
        instancia->codigoUP=0;
    }
    return *ControllerPublicacion;
}

int ControllerPublicacion::actualizarCodigoUP(){
    this->codigoUP++;
    return this->codigoUP;
}

bool ControllerPublicacion::AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
    Inmobiliaria* i=AltaUsuario::getInstancia().find(nicknameInmobiliaria);
    AdministraPropiedad ap =i.getAP(codigoInmueble);
    DTFecha* f= ControladorFechaActual::getInstance().getFechaActual();
    if (ap.existeTipoPublicacionActual(tipoPublicacion)){
        return false;
    }
    else {
        int c=ControllerPublicacion::actualizarCodigoUP();
        Publicacion p(c, f, tipoPublicacion, texto, precio, false);
        ap.getPublicaciones().insert(p);
        p.setAP(ap);
        if (tipoPublicacion==Venta){
            if (ap.getPVentaActiva()==NULL){
                p.activar();
                ap.setPVentaActiva(p);
            }
            else if (ap.getPVentaActiva().getDTFecha()->operator<(f)){
                ap.getPVentaActiva().desactivar();
                p.activar();
                ap.setPVentaActiva(p);
            }
        }
        else {
            if (ap.getPAlquilerActiva()==NULL){
                p.activar();
                ap.setAlquileraActiva(p);
            }
            else if (ap.getAlquilerActiva().getDTFecha()->operator<(f)){
                ap.getAlquilerActiva().desactivar();
                p.activar();
                ap.setAlquileraActiva(p);
            }
        }
        return true;
    }
}