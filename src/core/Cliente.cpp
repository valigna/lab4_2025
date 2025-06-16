#include "../include/core/Cliente.h"

Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento){
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
    this->apellido = apellido;
    this->documento = documento;
}

std::string Cliente::getApellido(){
    return this->apellido;
}
std::string Cliente::getDocumento(){
    return this->documento;
}
`
DTUsuario* Cliente::getDTUsuario() {
    return new DTUsuario(nickname, nombre);
}