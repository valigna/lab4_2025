#include "../include/AdministraPropiedad.h"

Inmobiliaria* AdministraPropiedad::getInmobiliaria(){
    return this->inmobiliaria;
}

Inmueble* AdministraPropiedad::getInmueble(){
    return this->inmueble;
}

DTFecha* AdministraPropiedad::getFechaIni(){
    return this->fecha;
}

DTInmuebleAdministrado* AdministraPropiedad::getDTInmuebleAdministrado(){
    dtia= new DTInmuebleAdministrado;
    dtia.codigo=AdministraPropiedad::getInmueble().getCodigo();
    dtia.direccion=AdministraPropiedad::getInmueble().getDireccion();
    dtia.direccion=AdministraPropiedad::getFechaIni();
    return dtia;
}

bool AdministraPropiedad::existeTipoPublicacionActual(TipoPublicacion tipoPublicacion){
    DTFecha* f= Factory::getControladorFechaActual().getFechaActual();
    if (tipoPublicacion==Venta){
        return this->PVentaActiva.getDTFecha()==f;
    }
    else {
        return this->PAlquilerActiva.getDTFecha()==f;
    }
}

std::set<Publicacion*> AdministraPropiedad::getPublicaciones(){
    return this->publicaciones;
}

Publicacion* AdministraPropiedad::getPVentaActiva(){
    return this->PVentaActiva;
}

Publicacion* AdministraPropiedad::getPAlquilerActiva(){
    return this->PAlquilerActiva;
}

void AdministraPropiedad::setPVentaActiva(Publicacion* p){
    this->PVentaActiva=p;
}
void AdministraPropiedad::setPAlquilerActiva(Publicacion* p){
    this->PAlquilerActiva=p;
}