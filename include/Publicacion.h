#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "DTNotificacion.h"
#include "TipoInmueble.h"
#include <string>

class AdministraPropiedad; //Forward declaration

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
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, 
                std::string texto, float precio, bool activa);
    ~Publicacion();
    
    int getCodigo();
    TipoPublicacion getTipoPublicacion();
    DTFecha* getDTFecha();
    std::string getTexto();
    float getPrecio();
    bool getActiva();
    
    AdministraPropiedad* getAP();
    void setAP(AdministraPropiedad* ap);
    
    void desactivar();
    void activar();
    
    bool cumpleFiltros(TipoPublicacion tipopublicacion, float preciominimo, float preciomaximo);
    bool mismotipo(TipoInmueble tipo);
    DTPublicacion* getDatos();

	DTNotificacion* getNotif();
};

#endif
