#ifndef ALTAUSUARIO_H
#define ALTAUSUARIO_H

#include <string>
#include <set>
#include "Usuario.h"
#include "TipoTecho.h"

class AltaUsuario{
    private:
        Usuario* Utemp;
        static AltaUsuario* instancia;
        AltaUsuario();
        AltaUsuario(const AltaUsuario&) = delete;
        AltaUsuario& operator=(const AltaUsuario&) = delete
    public:
        void guardarReferencia(Usuario::Usuario u);
        static AltaUsuario& getInstancia();
        Usuario* getUtemp();
        bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento); //PRE: contrasena tiene 6 >= caracteres
        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono); //PRE: contrasena tiene 6 >= caracteres
        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono); //PRE: contrasena tiene 6 >= caracteres
        std::set<DTUsuario::DTUsuario> listarPropietarios();
        void representarPropietario(std::string nicknamePropietario); //PRE Utemp!=NULL y Utemp es una instancia de Inmobiliaria
        void finalizarAltaUsuario();
        std::set<DTUsuario::DTUsuario> listarInmobiliarias();
        std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria); //PRE Existe una instancia de Inmobiliaria i con nickname=nicknameInmobiliaria
		std::set<DTInmueble> listarNoSuscripciones(std::string nick);
		void agregarSuscripciones(std::set<std::string> nicksInmobiliarias);
};

#endif
