#ifndef ALTAUSUARIO_H
#define ALTAUSUARIO_H

#include <string>
#include "Usuario.h"
#include "TipoTecho.h"

class AltaUsuario{
    private:
        Usuario* Utemp;
    public:
        AltaUsuario();
        ~AltaUsuario();
        void guardarReferencia(Usuario::Usuario u);
        Usuario* getUtemp();
        bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento); //PRE: contrasena tiene 6 >= caracteres
        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono); //PRE: contrasena tiene 6 >= caracteres
        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono); //PRE: contrasena tiene 6 >= caracteres
        std::set<DTUsuario::DTUsuario> listarPropietarios();
        void representarPropietario(std::string nicknamePropietario); //PRE Utemp!=NULL y Utemp es una instancia de Inmobiliaria
        void finalizarAltaUsuario();
    };

#endif