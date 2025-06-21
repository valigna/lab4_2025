#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/TipoInmueble.h"
#include "../include/Inmobiliaria.h"
#include <sstream>

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, 
                        std::string texto, float precio, bool activa)
    : codigo(codigo),
      fecha(new DTFecha(fecha)),
      tipo(tipo),
      texto(texto),
      precio(precio),
      activa(activa),
      AP(NULL) {
}

Publicacion::~Publicacion() {
    delete fecha;
}

int Publicacion::getCodigo() {
    return this->codigo;
}

TipoPublicacion Publicacion::getTipoPublicacion() {
    return this->tipo;
}

DTFecha* Publicacion::getDTFecha() {
    return this->fecha;
}

std::string Publicacion::getTexto() {
    return this->texto;
}

float Publicacion::getPrecio() {
    return this->precio;
}

bool Publicacion::getActiva() {
    return this->activa;
}

AdministraPropiedad* Publicacion::getAP() {
    return this->AP;
}

void Publicacion::setAP(AdministraPropiedad* ap) {
    this->AP = ap;
}

void Publicacion::desactivar() {
    this->activa = false;
}

void Publicacion::activar() {
    this->activa = true;
}

bool Publicacion::cumpleFiltros(TipoPublicacion tipopublicacion, float preciominimo, float preciomaximo) {
    return ((tipopublicacion == tipo) && (preciominimo <= precio) && (precio <= preciomaximo));
}

bool Publicacion::mismotipo(TipoInmueble tipoInmueble) {
    if (tipoInmueble == Todos) {
        return true;
    }
    
    if (AP == NULL) {
        return false;
    }
    
    Inmueble* inmueble = AP->getInmueble();
    if (inmueble == NULL) {
        return false;
    }
    
    if (tipoInmueble == TipoCasa) {
        class Casa* casaPtr = dynamic_cast<class Casa*>(inmueble);
        return casaPtr != NULL;
    } else if (tipoInmueble == TipoApartamento) {
        class Apartamento* apartamentoPtr = dynamic_cast<class Apartamento*>(inmueble);
        return apartamentoPtr != NULL;
    }
    
    return false;
}

DTPublicacion* Publicacion::getDatos() {
    if (AP == NULL || AP->getInmobiliaria() == NULL) {
        return NULL;
    }
    
    std::ostringstream precioStr;
    precioStr << this->precio;
    
    return new DTPublicacion(this->codigo, this->fecha, this->texto, 
                           precioStr.str(), AP->getInmobiliaria()->getNombre());
}

DTNotificacion* Publicacion::getNotif() {
    if (AP == NULL || AP->getInmobiliaria() == NULL) {
        return NULL;
    }
    
    return new DTNotificacion(AP->getInmobiliaria()->getNickname(), this->codigo, this->texto, this->tipo);
}
