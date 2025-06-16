#ifndef CONTROLLERPUBLICACION_H
#define CONTROLLERPUBLICACION_H

#include <string>
#include <map>
#include <set>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "IControllerPublicacion.h"
#include "Publicacion.h"
#include "DTInmueble.h"
#include "DTPublicacion.h"

class ControllerPublicacion : public IControllerPublicacion{
    private:
        int codigoUP;
        static ControllerPublicacion* instancia;
        ControllerPublicacion();
        std::map<int,Publicacion*> publicaciones;
    public:
        static ControllerPublicacion& getInstancia();
        bool AltaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
        int actualizarCodigoUP();
        std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
        DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);
 

};

#endif
