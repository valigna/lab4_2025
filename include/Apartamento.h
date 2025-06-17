#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Inmueble.h"

class Apartamento : public Inmueble {
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;

public:
    Apartamento(int codigo, std::string direccion, int numeroPuerta, 
                int superficie, int anioConstruccion, int piso, 
                bool tieneAscensor, float gastosComunes);
    ~Apartamento();
    
    int getPiso();
    bool getTieneAscensor();
    float getGastosComunes();
};

#endif