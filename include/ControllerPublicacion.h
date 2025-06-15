#ifndef CONTROLLERPUBLICACION_H
#define CONTROLLERPUBLICACION_H

#include <string>
#include "TipoPublicacion.h"

class ControllerPublicacion : public IControllerPublicacion{
    private:
        int codigoUP;
        static ControllerPublicacion* instancia;
        ControllerPublicacion();
    public:
        static ControllerPublicacion& getInstancia();
        bool AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
        int actualizarCodigoUP();

};

#endif