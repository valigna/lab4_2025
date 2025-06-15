#ifndef CONTROLLERPUBLICACION_H
#define CONTROLLERPUBLICACION_H

#include <string>
#include "TipoPublicacion.h"

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
     set<DTPublicacion> listarPublicacion(tipoPublicacion TipoPublicacion,precionMinimo float, precioMaximo float,tipoInmueble TipoInmueble);
    DTInmueble detalleInmueblePublicacion(codigoPublicacion int);
 

};

#endif
