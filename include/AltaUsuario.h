#ifndef ALTAUSUARIO_H
#define ALTAUSUARIO_H

#include <string>
#include <set>
#include "Usuario.h"
#include "TipoTecho.h"
#include "IAltaUsuario.h"
#include "IObservers.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"

class AltaUsuario : public IAltaUsuario {
private:
    Usuario* Utemp;
    static AltaUsuario* instancia;
    AltaUsuario();

public:
    static AltaUsuario& getInstancia();
    ~AltaUsuario();
    
    void guardarReferencia(Usuario* u);
    Usuario* getUtemp();
    
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, 
                     std::string email, std::string apellido, std::string documento);
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, 
                        std::string email, std::string cuentaBancaria, std::string telefono);
    bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, 
                         std::string email, std::string direccion, std::string url, std::string telefono);
    
    std::set<DTUsuario*> listarPropietarios();
    std::set<DTUsuario*> listarInmobiliarias();
    void representarPropietario(std::string nicknamePropietario);
    void finalizarAltaUsuario();
    
    std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nicknameInmobiliaria);
    std::set<DTUsuario*> listarNoSuscripciones(std::string nick);
    void agregarSuscripciones(std::set<std::string> nicksInmobiliarias);
	std::set<DTNotificacion*> getNotifs(std::string nick);
    std::set<DTUsuario*> listarSuscripciones(std::string nick);
    void eliminarSuscripciones(std::set<std::string> nicksInmobiliarias);
    std::set<DTInmuebleListado*> listarInmueblesNoAdministrados(std::string nicknameInmobiliaria);
    void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble);
};

#endif
