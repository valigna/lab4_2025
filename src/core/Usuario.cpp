#include "../include/core/Usuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}

std::string Usuario::getNickname(){
    return this->nickname;
}
std::string Usuario::getContrasena(){
    return this->contrasena;
}
std::string Usuario::getNombre(){
    return this->nombre;
}
std::string Usuario::getEmail(){
    return this->email;
}