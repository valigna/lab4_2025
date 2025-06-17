#include "../include/DTPublicacion.h"

DTPublicacion::DTPublicacion(int codigo, DTFecha* fecha, std::string texto, 
                           std::string precio, std::string inmobiliaria)
    : codigo(codigo),
      fecha(new DTFecha(fecha)),
      texto(texto),
      precio(precio),
      inmobiliaria(inmobiliaria) {
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

DTPublicacion::~DTPublicacion() {
    delete fecha;
}