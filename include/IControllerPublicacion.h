#ifndef ICONTROLLERPUBLICACION_H
#define ICONTROLLERPUBLICACION_H

#include <string>
#include "TipoPublicacion.h"

class IControllerPublicacion {
    public:
        bool AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio) = 0;
        int actualizarCodigoUP() = 0;
};

#endif