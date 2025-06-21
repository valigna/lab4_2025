#ifndef ICONTROLLERINMUEBLE_H
#define ICONTROLLERINMUEBLE_H

#include <string>
#include <set>
#include "TipoTecho.h"
#include <DTInmuebleListado.h>

class IControllerInmueble{
    public:
        virtual int actualizarCodigoInmueble() = 0;
        virtual void eliminarInmueble(int codigoInmueble) = 0;
        virtual void AltaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) = 0;
        virtual void AltaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;
        virtual std::set<DTInmuebleListado*> listarInmuebles() = 0;
        virtual DTInmueble* detalleInmueble(codigoInmueble int) = 0;
};

#endif
