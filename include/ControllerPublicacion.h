#ifndef CONTROLLERPUBLICACION_H
#define CONTROLLERPUBLICACION_H

#include <string>
#include "TipoPublicacion.h"

class ControllerPublicacion {
    private:
        int codigoUP;
        static ControllerPublicacion* instancia;
        ControllerPublicacion();
        ControllerPublicacion(const ControllerPublicacion&) = delete;
        ControllerPublicacion& operator=(const ControllerPublicacion&) = delete
    public:
        static ControllerPublicacion& getInstancia();
        bool AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
        int actualizarCodigoUP();

};

#endif