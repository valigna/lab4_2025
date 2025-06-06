#include "../include/Inmobiliria.h"
#include <set>

std::set<Propietario*>& getPropietarios(){
    return this->propietarios;
}