#include "../include/Inmobiliria.h"

std::set<Propietario*>& Inmobiliaria::getPropietarios(){
    return this->propietarios;
}

std::set<AdministraPropiedad*> Inmobiliaria::getAPs(){
    return this->APs;
}

AdministraPropiedad* Inmobiliaria::getAP(int codigoInmueble){
    for (AdministraPropiedad* ap:APs){
        if (ap->inmueble.getCodigo()==codigoInmueble){
            return ap;
        }
    }
    return NULL;
}