#include "../include/AltaUsuario.h"
#include "../include/ColeccionUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/ControladorFechaActual.h"

AltaUsuario* AltaUsuario::instancia=NULL;

AltaUsuario& AltaUsuario::getInstancia(){
    if (instancia==NULL){
        instancia= new AltaUsuario;
        instancia->Utemp=NULL;
    }
    return *AltaUsuario;
}

void AltaUsuario::guardarReferencia(Usuario::Usuario u){
    this->Utemp=u;
}

Usuario* AltaUsuario::getUtemp(){
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

std::set<DTUsuario::DTUsuario> AltaUsuario::listarPropietarios(){
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

void AltaUsuario::representarPropietario(std::string nicknamePropietario){
    Propietario* p=ColeccionUsuario::getInstancia().findUsuario(nicknamePropietario);
    for (Inmueble* inmueble:p.getInmuebles()){
        AdministraPropiedad* ap= AdministraPropiedad(ControladorFechaActual::getInstance().getFechaActual());
        ap.inmobiliaria=AltaUsuario::getUtemp();
        ap.inmueble=inmueble;
    };
    AltaUsuario::getUtemp().getPropietarios().insert(p);
    return;
}

void AltaUsuario::finalizarAltaUsuario(){
    this->Utemp=NULL;
}

std::set<DTUsuario::DTUsuario> AltaUsuario::listarInmobiliarias(){
     std::set<DTUsuario::DTUsuario> i;
    Usuario* primero=ColeccionUsuario::getInstancia().next();
    if (primero==NULL) return i;
    Usuario* usuario=primero
    do {
        if (dynamic_cast<Inmobiliaria*>(usuario)!=NULL){
            i.insert(usuario->getDTUsuario());
        }
        usuario=ColeccionUsuario::getInstancia().next();
    } while (usuario!=primero);
    return i;
}

std::set<DTInmuebleAdministrado> AltaUsuario::listarInmueblesAdministrados(std::string nicknameInmobiliaria){
    std::set<DTInmuebleAdministrado> dtia;
    Inmobiliaria* i=ColeccionUsuario::getInstancia().findUsuario(nicknameInmobiliaria);
    for (AdministraPropiedad* ap:i.getAPs()){
        dtia.insert(ap->getDTInmuebleAdministrado());
    }
    return dtia;
}
