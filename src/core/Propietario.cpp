#include "../include/Propietario.h"

Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono){
    this->nickname=nickname;
    this->contrasena=contrasena;
    this->nombre=nombre;
    this->email=email;
    this->cuentaBancaria=cuentaBancaria;
    this->telefono=telefono;
}

std::set<Inmueble*>& Propietario::getInmuebles(){
    return this->inmuebles;
}