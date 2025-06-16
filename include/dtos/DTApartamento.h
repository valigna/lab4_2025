#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H

#include "DTInmueble.h"

class DTApartamento : public DTInmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        int getPiso();
        bool getTieneAscensor();
        float getGastosComunes();
        std::string getTipoInmueble() const override;
        friend std::ostream& operator<<(std::ostream& os, const DTApartamento& dt);
};

#endif