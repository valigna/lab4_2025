#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H

#include <string>
#include <iostream>

class DTInmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;

    public:
        DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        virtual std::string getTipoInmueble() = 0;
        friend std::ostream& operator<<(std::ostream& os, const DTInmueble& dt);
        virtual ~DTInmueble();
};

#endif