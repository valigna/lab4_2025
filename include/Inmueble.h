#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <string>
#include <set>

class Propietario; // Forward declaration
class AdministraPropiedad; // Forward declaration

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;
        std::set<AdministraPropiedad*> APs;
        Propietario* propietario;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        virtual ~Inmueble();
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        Propietario* getPropietario();
        void setPropietario(Propietario* propietario);
        std::set<AdministraPropiedad*>& getAPs();
        void agregarAP(AdministraPropiedad* ap);
};

#endif