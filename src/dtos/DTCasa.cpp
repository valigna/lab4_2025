#include "../include/dtos/DTCasa.h"

DTCasa::DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}

bool DTCasa::getEsPH() {
    return esPH;
}

TipoTecho DTCasa::getTecho() {
    return techo;
}

std::string DTCasa::getTipoInmueble() const {
    return "Casa";
}

std::ostream& operator<<(std::ostream& os, const DTCasa& dt) {
    os << static_cast<const DTInmueble&>(dt) << ", Es PH: " << dt.esPH << ", Techo: " << dt.techo;
    return os;
}
