#include "../include/Publicacion.h"

TipoPublicacion Publicacion::getTipoPublicacion(){
    return this->tipo;
}

DTFecha* Publicacion::getDTFecha(){
    return this->fecha;
}

AdministraPropiedad* Publicacion::getAP(){
    return this->AP;
}

void Publicacion::setAP(AdministraPropiedad* ap);{
    this->AP=ap;
}

void Publicacion::desactivar(){
    this->activa=false;
}

void Publicacion::activar(){
    this->activa=true;
}