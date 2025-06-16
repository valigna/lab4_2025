#include "../include/dtos/DTInmueble.h"

DTInmueble::DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anioConstruccion = anioConstruccion;
}

int DTInmueble::getCodigo() {
    return codigo;
}

std::string DTInmueble::getDireccion() {
    return direccion;
}

int DTInmueble::getNumeroPuerta() {
    return numeroPuerta;
}

int DTInmueble::getSuperficie() {
    return superficie;
}

int DTInmueble::getAnioConstruccion() {
    return anioConstruccion;
}

std::ostream& operator<<(std::ostream& os, const DTInmueble& dt) {
    os << "Codigo: " << dt.codigo << ", Direccion: " << dt.direccion
       << ", Numero de Puerta: " << dt.numeroPuerta << ", Superficie: " 
       << dt.superficie << ", Anio de Construccion: " << dt.anioConstruccion;
    return os;
}

DTInmueble::~DTInmueble(){
    
}