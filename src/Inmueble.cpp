#include "../include/Inmueble.h"
Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta,
                   int superficie, int anoConstruccion, Propietario* propietario)
    : codigo(codigo),
      direccion(direccion),
      numeroPuerta(numeroPuerta),
      superficie(superficie),
      anoConstruccion(anoConstruccion),
      propietario(propietario),
     {}

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
