#include "../include/Apartamento.h"

Apartamento::Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion),
    piso(piso),
    tieneAscensor(tieneAscensor),
    gastosComunes(gastosComunes) {
}

Apartamento::~Apartamento() {
}

int Apartamento::getPiso() {
    return this->piso;
}

bool Apartamento::getTieneAscensor() {
    return this->tieneAscensor;
}

float Apartamento::getGastosComunes() {
    return this->gastosComunes;
}