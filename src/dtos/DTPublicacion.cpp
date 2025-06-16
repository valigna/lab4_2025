#include "../include/dtos/DTPublicacion.h"

DTPublicacion::DTPublicacion(int codigo, DTFecha* fecha, std::string texto, std::string precio, std::string inmobiliaria) {
    this->codigo = codigo;
    this->fecha = new DTFecha(fecha);
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
}

int DTPublicacion::getCodigo() {
    return codigo;
}

DTFecha* DTPublicacion::getFecha() {
    return fecha;
}

std::string DTPublicacion::getTexto() {
    return texto;
}

std::string DTPublicacion::getPrecio() {
    return precio;
}

std::string DTPublicacion::getInmobiliaria() {
    return inmobiliaria;
}

std::ostream& operator<<(std::ostream& os, const DTPublicacion& dt) {
    os << "Codigo: " << dt.codigo << ", Fecha: " << *dt.fecha << ", Texto: " << dt.texto
       << ", Precio: " << dt.precio << ", Inmobiliaria: " << dt.inmobiliaria;
    return os;
}

DTPublicacion::~DTPublicacion(){
    delete fecha;
}