#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email)
    : nickname(nickname),
      contrasena(contrasena),
      nombre(nombre),
      email(email) {
}

Usuario::~Usuario() {
}

std::string Usuario::getNickname() {
    return this->nickname;
}

std::string Usuario::getContrasena() {
    return this->contrasena;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

std::string Usuario::getEmail() {
    return this->email;
}

DTUsuario* Usuario::getDTUsuario() {
    return new DTUsuario(this->nickname, this->nombre);
}