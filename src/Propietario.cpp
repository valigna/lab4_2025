#include "../include/Propietario.h"

std::set<Inmueble*>& Propietario::getInmuebles(){
    return this->inmuebles;
}