#include "../include/Usuario.h"

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
DTUsuario::DTUsuario Usuario::getDTUsuario(){
    DTUsuario::DTUsuario u;
    u->nickname=this->nickname;
    u->nombre=this->nombre;
}