#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include <set>
#include "Casa.h"
#include "Apartamento.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmobiliaria* inmobiliaria;
        Inmueble* inmueble;
        std::set<Publicacion*> publicaciones;
        Publicacion* PVentaActiva;
        Publicacion* PAlquilerActiva;
    public:
        AdministraPropiedad(DTFecha* fecha);
        ~AdministraPropiedad();
        Inmobiliaria* getInmobiliaria();
        Inmueble* getInmueble();
        DTInmuebleAdministrado* getDTInmuebleAdministrado();
        DTFecha* getFechaIni();
        void setInmobiliaria(Inmobiliaria* i);
        void setInmueble(Inmueble* in);
        bool existeTipoPublicacionActual(TipoPublicacion tipoPublicacion);
        std::set<Publicacion*> getPublicaciones();
        Publicacion* getPVentaActiva();
        Publicacion* getPAlquilerActiva();
        void setPVentaActiva(Publicacion* p);
        void setPAlquilerActiva(Publicacion* p);
};

#endif