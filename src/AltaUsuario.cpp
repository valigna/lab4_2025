#include "../include/AltaUsuario.h"
#include "../include/ColeccionUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Factory.h"
#include "../include/AdministraPropiedad.h"

AltaUsuario* AltaUsuario::instancia = NULL;

AltaUsuario::AltaUsuario() : Utemp(NULL) {
}

AltaUsuario::~AltaUsuario() {
}

AltaUsuario& AltaUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new AltaUsuario();
        instancia->Utemp = NULL;
    }
    return *instancia;
}

void AltaUsuario::guardarReferencia(Usuario* u) {
    this->Utemp = u;
}

Usuario* AltaUsuario::getUtemp() {
    return this->Utemp;
}

bool AltaUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, 
                             std::string email, std::string apellido, std::string documento) {
    bool exists = ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!exists) {
        Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        ColeccionUsuario::getInstancia().addUsuario(c);
    }
    return !exists;
}

bool AltaUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, 
                                 std::string email, std::string cuentaBancaria, std::string telefono) {
    bool exists = ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!exists) {
        Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        ColeccionUsuario::getInstancia().addUsuario(p);
        this->guardarReferencia(p);
    }
    return !exists;
}

bool AltaUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, 
                                  std::string email, std::string direccion, std::string url, std::string telefono) {
    bool exists = ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!exists) {
        Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        ColeccionUsuario::getInstancia().addUsuario(i);
        this->guardarReferencia(i);
    }
    return !exists;
}

std::set<DTUsuario*> AltaUsuario::listarPropietarios() {
    std::set<DTUsuario*> propietarios;
    Usuario* primero = ColeccionUsuario::getInstancia().next();
    if (primero == NULL) return propietarios;
    
    Usuario* usuario = primero;
    do {
        if (dynamic_cast<Propietario*>(usuario) != NULL) {
            propietarios.insert(usuario->getDTUsuario());
        }
        usuario = ColeccionUsuario::getInstancia().next();
    } while (usuario != primero);
    
    return propietarios;
}

std::set<DTUsuario*> AltaUsuario::listarInmobiliarias() {
    std::set<DTUsuario*> inmobiliarias;
    Usuario* primero = ColeccionUsuario::getInstancia().next();
    if (primero == NULL) return inmobiliarias;
    
    Usuario* usuario = primero;
    do {
        if (dynamic_cast<Inmobiliaria*>(usuario) != NULL) {
            inmobiliarias.insert(usuario->getDTUsuario());
        }
        usuario = ColeccionUsuario::getInstancia().next();
    } while (usuario != primero);
    
    return inmobiliarias;
}

void AltaUsuario::representarPropietario(std::string nicknamePropietario) {
    Usuario* u = ColeccionUsuario::getInstancia().findUsuario(nicknamePropietario);
    Propietario* p = dynamic_cast<Propietario*>(u);
    Inmobiliaria* i = dynamic_cast<Inmobiliaria*>(this->getUtemp());
    
    if (p != NULL && i != NULL) {
        std::set<Inmueble*>& inmuebles = p->getInmuebles();
        std::set<Inmueble*>::iterator it;
        for (it = inmuebles.begin(); it != inmuebles.end(); ++it) {
            AdministraPropiedad* ap = new AdministraPropiedad(Factory::getInstance()->getControladorFechaActual()->getFechaActual());
            ap->setInmobiliaria(i);
            ap->setInmueble(*it);
            i->getAPs().insert(ap);
        }
        i->getPropietarios().insert(p);
    }
}

void AltaUsuario::finalizarAltaUsuario() {
    this->Utemp = NULL;
}

std::set<DTInmuebleAdministrado*> AltaUsuario::listarInmueblesAdministrados(std::string nicknameInmobiliaria) {
    std::set<DTInmuebleAdministrado*> dtia;
    Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria);
    Inmobiliaria* i = dynamic_cast<Inmobiliaria*>(usuario);
    
    if (i != NULL) {
        std::set<AdministraPropiedad*> aps = i->getAPs();
        std::set<AdministraPropiedad*>::iterator it;
        for (it = aps.begin(); it != aps.end(); ++it) {
            dtia.insert((*it)->getDTInmuebleAdministrado());
        }
    }
    
    return dtia;
}

std::set<DTUsuario*> AltaUsuario::listarNoSuscripciones(std::string nick) {
    std::set<DTUsuario*> inmobiliarias;
    Usuario* primero = ColeccionUsuario::getInstancia().next();
    if (primero == NULL) return inmobiliarias;
    
    Usuario* usuario = primero;
    do {
        if (dynamic_cast<Inmobiliaria*>(usuario) != NULL) {
            // TODO: Verificar si nick no existe en usuario.observers
            // agregar a inmobiliarias
            inmobiliarias.insert(usuario->getDTUsuario());
        }
        usuario = ColeccionUsuario::getInstancia().next();
    } while (usuario != primero);
    
    return inmobiliarias;
}

void AltaUsuario::agregarSuscripciones(std::set<std::string> nicksInmobiliarias) {
    std::set<std::string>::iterator it;
    for (it = nicksInmobiliarias.begin(); it != nicksInmobiliarias.end(); ++it) {
        Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(*it);
        Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
        if (inmobiliaria != NULL) {
            Cliente* cliente = dynamic_cast<Cliente*>(this->getUtemp());
            if (cliente != NULL) {
                inmobiliaria->suscribir(cliente);
            }
        }
    }
}	
