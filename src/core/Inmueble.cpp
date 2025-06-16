#include "../include/core/Inmueble.h"


Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion) :{
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anioConstruccion = anioConstruccion;
    this->propietario = nullptr;
}

int Inmueble::getCodigo(){
    return this->codigo;
}
std::string Inmueble::getDireccion(){
    return this->direccion;
}
int Inmueble::getNumeroPuerta(){
    return this->numeroPuerta;
}
int Inmueble::getSuperficie(){
    return this->superficie;
}
int Inmueble::getAnioConstruccion(){
    return this->anioConstruccion;
}
std::set<AdministraPropiedad*> Inmueble::getAdministraciones(){
    return this->administraciones;
}
Propietario* Inmueble::getPropietario(){
    return this->propietario;
}

void Inmueble::setPropietario(Propietario* propietario){
    this->propietario=propietario;
}
