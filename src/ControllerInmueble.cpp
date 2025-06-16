#include "../include/ControllerInmueble.h"
#include "../include/Inmueble.h"
#include "../include/AltaUsuario.h"
#include "../include/Factory.h"
#include "../include/Casa.h"
#include "../include/Propietario.h"
#include "../include/Apartamento.h"

ControllerInmueble* ControllerInmueble::instancia=NULL;

ControllerInmueble& ControllerInmueble::getInstancia(){
    if (instancia==NULL){
        instancia= new ControllerInmueble;
        instancia->ultimoCodigoInmueble=0;
    }
    return *instancia;
}

int ControllerInmueble::actualizarCodigoInmueble(){
    return this->ultimoCodigoInmueble+1;
}

void ControllerInmueble::AltaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo){
    Casa casa(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    Propietario* p = static_cast<Propietario*> (Factory::getInstance()->getAltaUsuario()->getUtemp());
    casa.setPropietario(p);
    p->getInmuebles().insert(casa);
}

void ControllerInmueble::AltaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes){
    Apartamento apartamento(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    Propietario* p = static_cast<Propietario*> (Factory::getInstance()->getAltaUsuario()->getUtemp());
    apartamento.setPropietario(p);
    p->getInmuebles().insert(apartamento);
}
