#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/AltaUsuario.h"
#include "../include/ControllerPublicacion.h"
#include "../include/ControllerInmueble.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorAltaUsuario* Factory::getAltaUsuario(){
    return AltaUsuario::getInstancia();
}

IControllerPublicacion* Factory::getControllerPublicacion(){
    return ControllerPublicacion::getInstancia();
}

IControllerInmueble* Factory::getControllerInmueble(){
    return ControllerInmueble::getInstancia();
}