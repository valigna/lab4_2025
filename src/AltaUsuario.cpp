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
#include <iostream>
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
    if (contrasena.length()>=6){
        bool exists = ColeccionUsuario::getInstancia().existsUsuario(nickname);
        if (!exists) {
            Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
            ColeccionUsuario::getInstancia().addUsuario(c);
        }
        return !exists;
    }
    else {
        std::cout << "La contraseña tiene que tener al menos 6 caracteres" << std::endl; 
        return false;
    }
}

bool AltaUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, 
                                 std::string email, std::string cuentaBancaria, std::string telefono) {
    if (contrasena.length()>=6){
        bool exists = ColeccionUsuario::getInstancia().existsUsuario(nickname);
        if (!exists) {
        Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        ColeccionUsuario::getInstancia().addUsuario(p);
        this->guardarReferencia(p);
        }
        return !exists;
    else {
        std::cout << "La contraseña tiene que tener al menos 6 caracteres" << std::endl; 
        return false;
        }
    }
}

bool AltaUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, 
                                  std::string email, std::string direccion, std::string url, std::string telefono) {
    if (contrasena.length()>=6){
    bool exists = ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!exists) {
        Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        ColeccionUsuario::getInstancia().addUsuario(i);
        this->guardarReferencia(i);
        }
    return !exists;
    else {
        std::cout << "La contraseña tiene que tener al menos 6 caracteres" << std::endl; 
        return false;
        }
    } 
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
            i->addAP(ap);
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
	Usuario* posibleSuscriptor = ColeccionUsuario::getInstancia().findUsuario(nick);
	this->guardarReferencia(posibleSuscriptor);
	IObservers* posibleSuscriptorObserver = dynamic_cast<IObservers*>(posibleSuscriptor);
	
	Usuario* primero = ColeccionUsuario::getInstancia().next();
    if (primero == NULL) return inmobiliarias;
    
    Usuario* usuario = primero;
	do {
		Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
        if (inmobiliaria != NULL) {
            if (!inmobiliaria->estaSuscrito(posibleSuscriptorObserver)) {
	            inmobiliarias.insert(usuario->getDTUsuario());
			}
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
            IObservers* suscriptor = dynamic_cast<IObservers*>(this->getUtemp());
			inmobiliaria->suscribir(suscriptor);
			
			/*
            if (cliente != NULL) {
                inmobiliaria->suscribir(cliente);
            }*/
        }
    }
}

std::set<DTNotificacion*> AltaUsuario::getNotifs(std::string nick) {
	Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(nick);
	IObservers* usuarioObserver = dynamic_cast<IObservers*>(usuario);
	std::set<DTNotificacion*> notifs;
	notifs = usuarioObserver->getNotifs();
	usuarioObserver->borrarNotifs();
	return notifs;
}

std::set<DTUsuario*> AltaUsuario::listarSuscripciones(std::string nick) {
    std::set<DTUsuario*> inmobiliarias;
	Usuario* posibleSuscriptor = ColeccionUsuario::getInstancia().findUsuario(nick);
	this->guardarReferencia(posibleSuscriptor);
	IObservers* posibleSuscriptorObserver = dynamic_cast<IObservers*>(posibleSuscriptor); 
	
	Usuario* primero = ColeccionUsuario::getInstancia().next();
    if (primero == NULL) return inmobiliarias;
    
    Usuario* usuario = primero;
	do {
		Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
        if (inmobiliaria != NULL) {
            if (inmobiliaria->estaSuscrito(posibleSuscriptorObserver)) {
	            inmobiliarias.insert(usuario->getDTUsuario());
			}
        }
        usuario = ColeccionUsuario::getInstancia().next();
    } while (usuario != primero);
    
    return inmobiliarias;
}

void AltaUsuario::eliminarSuscripciones(std::set<std::string> nicksInmobiliarias) {
    std::set<std::string>::iterator it;
    for (it = nicksInmobiliarias.begin(); it != nicksInmobiliarias.end(); ++it) {
        Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(*it);
        Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
        if (inmobiliaria != NULL) { 
            IObservers* suscriptor = dynamic_cast<IObservers*>(this->getUtemp());
			inmobiliaria->desuscribir(suscriptor);
        }
    }
}

std::set<DTInmuebleListado*> AltaUsuario::listarInmueblesNoAdministrados(std::string nicknameInmobiliaria) {
    std::set<DTInmuebleListado*> resultado;
    
    Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria);
    Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
    
    if (inmobiliaria == NULL) {
        return resultado;
    }
    
    IControllerInmueble* controllerInmueble = Factory::getInstance()->getControllerInmueble();
    std::set<DTInmuebleListado*> todosInmuebles = controllerInmueble->listarInmuebles();
    
    std::set<int> codigosAdministrados;
    std::set<AdministraPropiedad*> aps = inmobiliaria->getAPs();
    for (std::set<AdministraPropiedad*>::iterator it = aps.begin(); it != aps.end(); ++it) {
        codigosAdministrados.insert((*it)->getInmueble()->getCodigo());
    }
    
    for (std::set<DTInmuebleListado*>::iterator it = todosInmuebles.begin(); it != todosInmuebles.end(); ++it) {
        DTInmuebleListado* inmueble = *it;
        if (codigosAdministrados.find(inmueble->getCodigo()) == codigosAdministrados.end()) {
            resultado.insert(new DTInmuebleListado(inmueble->getCodigo(), inmueble->getDireccion(), inmueble->getPropietario()));
        }
    }
    
    for (std::set<DTInmuebleListado*>::iterator it = todosInmuebles.begin(); it != todosInmuebles.end(); ++it) {
        delete *it;
    }
    
    return resultado;
}

void AltaUsuario::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) {
    Usuario* usuario = ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria);
    Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
    
    if (inmobiliaria == NULL) {
        return;
    }
    
    IControllerInmueble* controllerInmueble = Factory::getInstance()->getControllerInmueble();
    std::set<DTInmuebleListado*> todosInmuebles = controllerInmueble->listarInmuebles();
    
    Inmueble* inmueble = NULL;
    DTInmueble* dtInmueble = controllerInmueble->detalleInmueble(codigoInmueble);
    if (dtInmueble == NULL) {
        for (std::set<DTInmuebleListado*>::iterator it = todosInmuebles.begin(); it != todosInmuebles.end(); ++it) {
            delete *it;
        }
        return;
    }
    
    for (std::set<DTInmuebleListado*>::iterator it = todosInmuebles.begin(); it != todosInmuebles.end(); ++it) {
        if ((*it)->getCodigo() == codigoInmueble) {
            Usuario* propietarioUsuario = ColeccionUsuario::getInstancia().findUsuario((*it)->getPropietario());
            Propietario* propietario = dynamic_cast<Propietario*>(propietarioUsuario);
            if (propietario != NULL) {
                std::set<Inmueble*>& inmuebles = propietario->getInmuebles();
                for (std::set<Inmueble*>::iterator inmIt = inmuebles.begin(); inmIt != inmuebles.end(); ++inmIt) {
                    if ((*inmIt)->getCodigo() == codigoInmueble) {
                        inmueble = *inmIt;
                        break;
                    }
                }
            }
            break;
        }
    }
    
    if (inmueble != NULL) {
        AdministraPropiedad* ap = new AdministraPropiedad(Factory::getInstance()->getControladorFechaActual()->getFechaActual());
        ap->setInmobiliaria(inmobiliaria);
        ap->setInmueble(inmueble);
        
        inmobiliaria->addAP(ap);
        
        inmueble->agregarAP(ap);
    }
    
    delete dtInmueble;
    for (std::set<DTInmuebleListado*>::iterator it = todosInmuebles.begin(); it != todosInmuebles.end(); ++it) {
        delete *it;
    }
}
