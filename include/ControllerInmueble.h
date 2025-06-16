#ifndef CONTROLLERINMUEBLE_H
#define CONTROLLERINMUEBLE_H

#include <string>
#include "TipoTecho.h"
#include "IControllerInmueble.h"

class ControllerInmueble : public IControllerInmueble{
    private:
        int ultimoCodigoInmueble;
        static ControllerInmueble* instancia;
    public:
        ControllerInmueble& getInstancia(){
        ControllerInmueble();
        ~ControllerInmueble();
        int actualizarCodigoInmueble();
        void eliminarInmueble(int codigoInmueble);
        void AltaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo); //PRE AltaUsuario::getUtemp()!=NULL
        void AltaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes); //PRE AltaUsuario::getUtemp()!=NULL
};

#endif