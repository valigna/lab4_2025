#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "Propietario.h"
#include "AdministraPropiedad.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        std::set<AdministraPropiedad*> APs;
        Propietario* propietario;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();
        int getCodigo();
        void setPropietario(Propietario* propietario);
        std::set<AdministraPropiedad*> getAPs();
        std::string getDireccion();
};

#endif