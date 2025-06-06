#include "../include/Propietario.h"
#include <set>

std::set<Inmueble*>& getInmuebles(){
    return this->inmuebles;
}