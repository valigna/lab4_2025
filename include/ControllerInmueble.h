#ifndef COLECCIONUSUARIO_H
#define COLECCIONUSUARIO_H

#include <string>
#include "TipoTecho.h"

class ControllerInmueble{
    private:
        int ultimoCodigoInmueble;
    public:
        ControllerInmueble();
        ~ControllerInmueble();
        int actualizarCodigoInmueble();
        void eliminarInmueble(int:codigoInmueble);
        void AltaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho::TipoTecho techo); //PRE AltaUsuario::getUtemp()!=NULL
        void AltaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes); //PRE AltaUsuario::getUtemp()!=NULL
};

#endif