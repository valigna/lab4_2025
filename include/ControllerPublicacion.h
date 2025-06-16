#ifndef CONTROLLERPUBLICACION_H
#define CONTROLLERPUBLICACION_H

#include <string>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "IControllerPublicacion.h"
#include "DTInmueble.h"
#include "DTPublicacion.h"
#include <map>

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
        std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoPublicacion, float precionMinimo, float precioMaximo, TipoInmueble tipoInmueble);
        DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);
 

};

#endif
