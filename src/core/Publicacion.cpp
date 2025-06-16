#include "../include/Publicacion.h"
    Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa) {
}
Publicacion::~Publicacion(){}
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
bool  Publicacion::cumpleFiltros(tipopublicacion TipoPublicacion ,preciominimo float, preciomaximo float)
{return ((tipopublicacion == tipo) && (preciominimo < p.precio) && (p.precio < preciomaximo));}

bool Publicacion::mismotipo(tipo tipoInmueble) {
      if (tipoInmueble == todos) return true;

  
    Inmueble* in = AP->getInmueble();

    if (tipoInmueble == casa) {
        return dynamic_cast<Casa*>(in) != nullptr;
    } else if (tipoInmueble == apartamento) {
        return dynamic_cast<Apartamento*>(in) != nullptr;
    }
}

DTPublicacion Publicacion::getDatos() {
    return DTPublicacion(this->codigo,*this->fecha this->texto,this->precio,this->AP->inmobiliaria->getNombre())
}
