#include "../include/core/AdministraPropiedad.h"
#include "../include/core/Inmobiliaria.h"
#include "../include/core/Inmueble.h"
#include "../include/core/Publicacion.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fechaInicio, Inmobiliaria* inmobiliaria, Inmueble* inmueble)
    : fechaInicio(fechaInicio), inmobiliaria(inmobiliaria), inmueble(inmueble), PVentaActiva(nullptr), PAlquilerActiva(nullptr) {
    if (inmobiliaria) {
        inmobiliaria->agregarAdministracion(this);
    }
}

const DTFecha& AdministraPropiedad::getFechaInicio() const {
    return *fechaInicio;
}

Inmobiliaria* AdministraPropiedad::getInmobiliaria() const {
    return inmobiliaria;
}

Inmueble* AdministraPropiedad::getInmueble() const {
    return inmueble;
}

DTInmuebleAdministrado AdministraPropiedad::getDTInmuebleAdministrado() const {
    return DTInmuebleAdministrado(inmueble->getCodigo(), inmueble->getDireccion(), fechaInicio.get());
}

const std::set<Publicacion*>& AdministraPropiedad::getPublicaciones() const {
    return publicaciones;
}

bool AdministraPropiedad::tienePublicacionActiva(TipoPublicacion tipo) const {
    Publicacion* activa = (tipo == TipoPublicacion::VENTA) ? PVentaActiva : PAlquilerActiva;
    return activa != nullptr && activa->estaActiva();
}

Publicacion* AdministraPropiedad::getPublicacionActiva(TipoPublicacion tipo) const {
    return (tipo == TipoPublicacion::VENTA) ? PVentaActiva : PAlquilerActiva;
}

bool AdministraPropiedad::puedeAgregarPublicacion(TipoPublicacion tipo, const DTFecha& fechaActual) const {
    Publicacion* actual = getPublicacionActiva(tipo);
    return actual == nullptr || !actual->esPosteriorA(fechaActual);
}

void AdministraPropiedad::setPublicacionActiva(Publicacion* publicacion, TipoPublicacion tipo) {
    if (publicacion == nullptr) return;
    
    if (tipo == TipoPublicacion::VENTA) {
        PVentaActiva = publicacion;
    } else {
        PAlquilerActiva = publicacion;
    }
}

void AdministraPropiedad::agregarPublicacion(Publicacion* publicacion) {
    if (publicacion == nullptr) return;
    
    publicaciones.insert(publicacion);
    setPublicacionActiva(publicacion, publicacion->getTipo());
}

void AdministraPropiedad::eliminarPublicacion(Publicacion* publicacion) {
    if (publicacion == nullptr) return;
    
    publicaciones.erase(publicacion);
    if (PVentaActiva == publicacion) PVentaActiva = nullptr;
    if (PAlquilerActiva == publicacion) PAlquilerActiva = nullptr;
}