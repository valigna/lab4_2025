#include "../include/Apartamento.h"

Apartamento::Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion),
    piso(piso),
    tieneAscensor(tieneAscensor),
    gastosComunes(gastosComunes)
{}