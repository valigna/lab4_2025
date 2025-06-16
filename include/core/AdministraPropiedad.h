#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include <set>
#include <memory>

// Forward declarations
class Inmobiliaria;
class Inmueble;
class Publicacion;
enum class TipoPublicacion;

class AdministraPropiedad {
private:
    DTFecha* fechaInicio;
    Inmobiliaria* inmobiliaria;
    Inmueble* inmueble;
    std::set<Publicacion*> publicaciones;
    Publicacion* PVentaActiva;
    Publicacion* PAlquilerActiva;

    bool tienePublicacionActiva(TipoPublicacion tipo) const;

public:
    AdministraPropiedad(DTFecha* fechaInicio, Inmobiliaria* inmobiliaria, Inmueble* inmueble);
    ~AdministraPropiedad() = default;

    DTFecha& getFechaInicio();
    Inmobiliaria* getInmobiliaria();
    Inmueble* getInmueble();
    DTInmuebleAdministrado getDTInmuebleAdministrado();
    const std::set<Publicacion*>& getPublicaciones();

    Publicacion* getPublicacionActiva(TipoPublicacion tipo);
    bool puedeAgregarPublicacion(TipoPublicacion tipo, const DTFecha& fechaActual);

    void setPublicacionActiva(Publicacion* publicacion, TipoPublicacion tipo);

    void agregarPublicacion(Publicacion* publicacion);
    void eliminarPublicacion(Publicacion* publicacion);

    AdministraPropiedad(const AdministraPropiedad&) = delete;
    AdministraPropiedad& operator=(const AdministraPropiedad&) = delete;
};
#endif