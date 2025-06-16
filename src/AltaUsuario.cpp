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

ColeccionUsuario* ColeccionUsuario::instancia=NULL;

AltaUsuario& AltaUsuario::getInstancia(){
    if (instancia==NULL){
        instancia= new AltaUsuario;
        instancia->Utemp=NULL;
    }
    return *instancia;
}

void AltaUsuario::guardarReferencia(Usuario* u){
    this->Utemp=u;
}

Usuario* AltaUsuario::getUtemp(){
    return this->Utemp;
}

bool AltaUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento){
    bool t= ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!t){
        Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        ColeccionUsuario::getInstancia().addUsuario(c);
    }
    return t;
}

bool AltaUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono){
    bool t= ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!t){
        Propietario* p= new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        ColeccionUsuario::getInstancia().addUsuario(p);
        AltaUsuario::guardarReferencia(p);
    }
    return t;
}

bool AltaUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono){
    bool t= ColeccionUsuario::getInstancia().existsUsuario(nickname);
    if (!t){
        Inmobiliaria* i= new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        ColeccionUsuario::getInstancia().addUsuario(i);
        AltaUsuario::guardarReferencia(i);
    }
    return t;
}

std::set<DTUsuario*> AltaUsuario::listarPropietarios(){
    std::set<DTUsuario*> p;
    Usuario* primero=ColeccionUsuario::getInstancia().next();
    if (primero==NULL) return p;
    Usuario* usuario=primero;
    do {
        if (dynamic_cast<Propietario*>(usuario)!=NULL){
            p.insert(usuario->getDTUsuario());
        }
        usuario=ColeccionUsuario::getInstancia().next();
    } while (usuario!=primero);
    return p;
}

void AltaUsuario::representarPropietario(std::string nicknamePropietario){
    Usuario* u= ColeccionUsuario::getInstancia().findUsuario(nicknamePropietario);
    Propietario* p = static_cast<Propietario*>(u);
    Inmobiliaria* i= static_cast<Inmobiliaria*>(AltaUsuario::getUtemp());
    for (Inmueble* inmueble:p->getInmuebles()){
        AdministraPropiedad* ap= new AdministraPropiedad(Factory::getInstance()->getControladorFechaActual()->getFechaActual());
        ap->setInmobiliaria(i);
        ap->setInmueble(inmueble);
    };
    i->getPropietarios().insert(p);
    return;
}

void AltaUsuario::finalizarAltaUsuario(){
    this->Utemp=NULL;
}

std::set<DTUsuario*> AltaUsuario::listarInmobiliarias(){
     std::set<DTUsuario*> i;
    Usuario* primero=ColeccionUsuario::getInstancia().next();
    if (primero==NULL) return i;
    Usuario* usuario=primero;
    do {
        if (dynamic_cast<Inmobiliaria*>(usuario)!=NULL){
            i.insert(usuario->getDTUsuario());
        }
        usuario=ColeccionUsuario::getInstancia().next();
    } while (usuario!=primero);
    return i;
}

std::set<DTInmuebleAdministrado*> AltaUsuario::listarInmueblesAdministrados(std::string nicknameInmobiliaria){
    std::set<DTInmuebleAdministrado*> dtia;
    Inmobiliaria* i= static_cast<Inmobiliaria*>(ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria));
    for (AdministraPropiedad* ap:i->getAPs()){
        dtia.insert(ap->getDTInmuebleAdministrado());
    }
    return dtia;
}
