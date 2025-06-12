#include "../include/Inmueble.h"

int Inmueble::getCodigo(){
    return this->codigo;
}

std::set<AdministraPropiedad*> Inmueble::getAPs(){
    return this->APs;
}

std::string Inmueble::getDireccion(){
    return this->direccion;
}

void Inmueble::setPropietario(Propietario* propietario){
    this->propietario=propietario;
}