#include "../include/Casa.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion),
    esPH(esPH),
    techo(techo)
{}