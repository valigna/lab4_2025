#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H

#include "DTFecha.h"
#include <string>
#include <set>
#include "Usuario.h"
#include "TipoTecho.h"

class IAltaUsuario {
    public:
        virtual void guardarReferencia(Usuario* u) = 0;
        virtual Usuario* getUtemp() = 0;
        virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) = 0;
        virtual bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) = 0;
        virtual bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) = 0; 
        virtual std::set<DTUsuario::DTUsuario> listarPropietarios() = 0;
        virtual void representarPropietario(std::string nicknamePropietario) = 0; 
        virtual void finalizarAltaUsuario() = 0;
        virtual std::set<DTUsuario::DTUsuario> listarInmobiliarias() = 0;
        virtual std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria) = 0; 
};

#endif