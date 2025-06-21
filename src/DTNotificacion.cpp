#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(std::string inmobiliaraNick, int codigo, std::string texto, TipoPublicacion tipo)
    : inmobiliaraNick(inmobiliaraNick), codigo(codigo), texto(texto), tipo(tipo) {
}

DTNotificacion::~DTNotificacion() {
}

std::string DTNotificacion::getInmobiliaraNick() const {
    return this->inmobiliaraNick;
}

int DTNotificacion::getCodigo() const {
    return this->codigo;
}

std::string DTNotificacion::getTexto() const {
    return this->texto;
}

TipoPublicacion DTNotificacion::getTipo() const {
    return this->tipo;
} 