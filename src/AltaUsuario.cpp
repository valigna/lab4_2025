#include <string>
#include "../include/AltaUsuario.h"
#include "../include/ColeccionUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"

void guardarReferencia(Usuario::Usuario u){
    this->Utemp=u;
}

Usuario* getUtemp(){
    return this->Utemp;
}

bool AltaUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento){
    bool t= ColeccionUsuario::exists(nickname);
    if (!t){
        Cliente cliente(nickname, contrasena, nombre, email, apellido, documento);
        ColeccionUsuario::getInstancia().add(cliente);
    }
    return t;
}

bool AltaUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono){
    bool t= ColeccionUsuario::exists(nickname);
    if (!t){
        Propietario propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        ColeccionUsuario::getInstancia().add(propietario);
        AltaUsuario::guardarReferencia(propietario);
        guardarReferencia(propietario);
    }
    return t;
}

bool AltaUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono){
    bool t= ColeccionUsuario::exists(nickname);
    if (!t){
        Inmobiliaria inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        ColeccionUsuario::getInstancia().add(inmobiliaria);
        AltaUsuario::guardarReferencia(inmobiliaria);
        guardarReferencia(inmobiliaria);
    }
    return t;
}

std::set<DTUsuario::DTUsuario> listarPropietarios(){
    std::set<DTUsuario::DTUsuario> p;
    Usuario* primero=ColeccionUsuario::getInstancia().next();
    if (primero==NULL) return p;
    Usuario* usuario=primero
    do {
        if (dynamic_cast<Propietario*>(usuario)!=NULL){
            p.insert(usuario->getDTUsuario());
        }
        usuario=ColeccionUsuario::getInstancia().next();
    } while (usuario!=primero);
    return p;
}

void representarPropietario(std::string nicknamePropietario){
    Propietario* p=ColeccionUsuario::getInstancia().find(nicknamePropietario);
    AltaUsuario::getUtemp().getPropietarios().insert(p);
    return;
}

void finalizarAltaUsuario(){
    this->Utemp=NULL;
}
