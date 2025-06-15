#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>
#include "AdministraPropiedad.h"

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* AP;
public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    ~Publicacion();
    TipoPublicacion getTipoPublicacion();
    DTFecha* getDTFecha();
    AdministraPropiedad* getAP();
    void setAP(AdministraPropiedad* ap);
    void desactivar();
    void activar();
bool cumpleFiltros(tipopublicacion TipoPublicacion ,preciominimo float, preciomaximo float;
    bool mismotipo(tipo tipoInmueble);
    DTPublicacion getDatos();
};

#endif
