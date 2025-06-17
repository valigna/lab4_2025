#include "../include/AdministraPropiedad.h"
#include "../include/Factory.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha)
    : fecha(new DTFecha(fecha)),
      inmobiliaria(NULL),
      inmueble(NULL),
      PVentaActiva(NULL),
      PAlquilerActiva(NULL) {
}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
}

Inmobiliaria* AdministraPropiedad::getInmobiliaria() {
    return this->inmobiliaria;
}

void AdministraPropiedad::setInmobiliaria(Inmobiliaria* i) {
    this->inmobiliaria = i;
}

Inmueble* AdministraPropiedad::getInmueble() {
    return this->inmueble;
}

void AdministraPropiedad::setInmueble(Inmueble* in) {
    this->inmueble = in;
}

DTFecha* AdministraPropiedad::getFechaIni() {
    return this->fecha;
}

DTInmuebleAdministrado* AdministraPropiedad::getDTInmuebleAdministrado() {
    Inmueble* i = this->getInmueble();
    DTInmuebleAdministrado* dtia = new DTInmuebleAdministrado(i->getCodigo(), 
                                                            i->getDireccion(), 
                                                            this->getFechaIni());
    return dtia;
}

std::set<Publicacion*> AdministraPropiedad::getPublicaciones() {
    return this->publicaciones;
}

bool AdministraPropiedad::existeTipoPublicacionActual(TipoPublicacion tipoPublicacion) {
    DTFecha* f = Factory::getInstance()->getControladorFechaActual()->getFechaActual();
    if (tipoPublicacion == Venta) {
        return this->PVentaActiva != NULL && *(this->PVentaActiva->getDTFecha()) == f;
    } else {
        return this->PAlquilerActiva != NULL && *(this->PAlquilerActiva->getDTFecha()) == f;
    }
}

Publicacion* AdministraPropiedad::getPVentaActiva() {
    return this->PVentaActiva;
}

void AdministraPropiedad::setPVentaActiva(Publicacion* p) {
    this->PVentaActiva = p;
}

Publicacion* AdministraPropiedad::getPAlquilerActiva() {
    return this->PAlquilerActiva;
}

void AdministraPropiedad::setPAlquilerActiva(Publicacion* p) {
    this->PAlquilerActiva = p;
}
