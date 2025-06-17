#include "../include/Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta,
                   int superficie, int anioConstruccion)
    : codigo(codigo),
      direccion(direccion),
      numeroPuerta(numeroPuerta),
      superficie(superficie),
      anioConstruccion(anioConstruccion),
      propietario(NULL) {
}

Inmueble::~Inmueble() {
}

int Inmueble::getCodigo() {
    return this->codigo;
}

std::string Inmueble::getDireccion() {
    return this->direccion;
}

int Inmueble::getNumeroPuerta() {
    return this->numeroPuerta;
}

int Inmueble::getSuperficie() {
    return this->superficie;
}

int Inmueble::getAnioConstruccion() {
    return this->anioConstruccion;
}

Propietario* Inmueble::getPropietario() {
    return this->propietario;
}

void Inmueble::setPropietario(Propietario* propietario) {
    this->propietario = propietario;
}

std::set<AdministraPropiedad*>& Inmueble::getAPs() {
    return this->APs;
}

void Inmueble::agregarAP(AdministraPropiedad* ap) {
    this->APs.insert(ap);
}
