#include "../include/Casa.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, 
           int superficie, int anioConstruccion, bool esPH, TipoTecho techo)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion),
      esPH(esPH),
      techo(techo) {
}

Casa::~Casa() {
}

bool Casa::getEsPH() {
    return this->esPH;
}

TipoTecho Casa::getTecho() {
    return this->techo;
}