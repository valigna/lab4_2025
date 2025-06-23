#ifndef ICONTROLLERPUBLICACION_H
#define ICONTROLLERPUBLICACION_H

#include <string>
#include <set>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include "DTInmueble.h"
#include "Publicacion.h"

class IControllerPublicacion {
    public:
        virtual bool AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio) = 0;
        virtual int actualizarCodigoUP() = 0;
        virtual std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) = 0;
        virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;
        virtual void eliminarPublicacionesDeInmueble(int codigoInmueble) = 0;
        virtual Publicacion* getPublicacion(int codigo) = 0;
        virtual void eliminarPublicacion(int codigoPublicacion) = 0;
};

#endif