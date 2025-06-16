#include "../include/ControllerInmueble.h"
#include "../include/Inmueble.h"
#include "../include/AltaUsuario.h"
#include "../include/Factory.h"

ControllerInmueble* ControllerInmueble::instancia=NULL;

ControllerInmueble& ControllerInmueble::getInstancia(){
    if (instancia==NULL){
        instancia= new ControllerInmueble;
        instancia->ultimoCodigoInmueble=0;
    }
    return ControllerInmueble;
}

int ControllerInmueble::actualizarCodigoInmueble(){
    return this->ultimoCodigoInmueble+1;
}

void ControllerInmueble::AltaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho::TipoTecho techo){
    Casa casa(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    setPropietario(Factory::getAltaUsuario().getUtemp());
    Factory::getAltaUsuario().getUtemp().getInmuebles().insert(casa);
}

void ControllerInmueble::AltaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes){
    Apartamento apartamento(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    setPropietario(Factory::getAltaUsuario().getUtemp());
    Factory::getAltaUsuario().getUtemp().getInmuebles().insert(apartamento);
}
