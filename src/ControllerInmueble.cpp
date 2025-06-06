#include "../include/ControllerInmueble.h"
#include "../include/Inmueble.h"
#include "../include/AltaUsuario.h"
#include "../include/AltaUsuario.h"
#include "../include/AltaUsuario.h"

ControllerInmueble::ControllerInmueble() : ultimoCodigoInmueble(0) {}

int ControllerInmueble::actualizarCodigoInmueble(){
    return this->ultimoCodigoInmueble+1;
}

void ControllerInmueble::AltaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho::TipoTecho techo){
    Casa casa(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    AltaUsuario::getUtemp().getInmuebles().insert(casa);
}

void ControllerInmueble::AltaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes){
    Apartamento apartamento(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    AltaUsuario::getUtemp().getInmuebles().insert(apartamento);
}

