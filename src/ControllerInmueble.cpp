#include "../include/ControllerInmueble.h"
#include "../include/Inmueble.h"
#include "../include/AltaUsuario.h"
#include "../include/Factory.h"
#include "../include/Casa.h"
#include "../include/Propietario.h"
#include "../include/Apartamento.h"

ControllerInmueble* ControllerInmueble::instancia = NULL;

ControllerInmueble::ControllerInmueble() : ultimoCodigoInmueble(0) {
}

ControllerInmueble::~ControllerInmueble() {
}

ControllerInmueble& ControllerInmueble::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControllerInmueble();
        instancia->ultimoCodigoInmueble = 0;
    }
    return *instancia;
}

int ControllerInmueble::actualizarCodigoInmueble() {
    this->ultimoCodigoInmueble++;
    return this->ultimoCodigoInmueble;
}

void ControllerInmueble::eliminarInmueble(int codigoInmueble) {
    // TODO: Implementar eliminación de inmueble
    // Buscar inmueble por código y eliminar de propietario
}

void ControllerInmueble::AltaCasa(std::string direccion, int numeroPuerta, int superficie, 
                                 int anioConstruccion, bool esPH, TipoTecho techo) {
    Casa* c = new Casa(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    Propietario* p = dynamic_cast<Propietario*>(Factory::getInstance()->getAltaUsuario()->getUtemp());
    if (p != NULL) {
        c->setPropietario(p);
        p->agregarInmueble(c);
    }
}

void ControllerInmueble::AltaApartamento(std::string direccion, int numeroPuerta, int superficie, 
                                        int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes) {
    Apartamento* a = new Apartamento(actualizarCodigoInmueble(), direccion, numeroPuerta, superficie, anioConstruccion, piso, tieneAscensor, gastosComunes);
    Propietario* p = dynamic_cast<Propietario*>(Factory::getInstance()->getAltaUsuario()->getUtemp());
    if (p != NULL) {
        a->setPropietario(p);
        p->agregarInmueble(a);
    }
}
