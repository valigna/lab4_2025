#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include "Casa.h"
#include "Apartamento.h"
#include <set>

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
    
    // Getters y Setters básicos
    Inmobiliaria* getInmobiliaria();
    void setInmobiliaria(Inmobiliaria* i);
    
    Inmueble* getInmueble();
    void setInmueble(Inmueble* in);
    
    DTFecha* getFechaIni();
    DTInmuebleAdministrado* getDTInmuebleAdministrado();
    
    // Manejo de publicaciones
    std::set<Publicacion*> getPublicaciones();
    bool existeTipoPublicacionActual(TipoPublicacion tipoPublicacion);
    
    Publicacion* getPVentaActiva();
    void setPVentaActiva(Publicacion* p);
    
    Publicacion* getPAlquilerActiva();
    void setPAlquilerActiva(Publicacion* p);
};

#endif