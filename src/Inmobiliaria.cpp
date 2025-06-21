#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, 
                          std::string email, std::string direccion, std::string url, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email),
      direccion(direccion),
      url(url),
      telefono(telefono) {
}

Inmobiliaria::~Inmobiliaria() {
}

std::set<Propietario*>& Inmobiliaria::getPropietarios() {
    return this->propietarios;
}

std::set<AdministraPropiedad*> Inmobiliaria::getAPs() {
    return this->APs;
}

void Inmobiliaria::addAP(AdministraPropiedad* ap) {
    this->APs.insert(ap);
}

void Inmobiliaria::removeAP(AdministraPropiedad* ap) {
    this->APs.erase(ap);
}

AdministraPropiedad* Inmobiliaria::getAP(int codigoInmueble) {
    std::set<AdministraPropiedad*>::iterator it;
    for (it = APs.begin(); it != APs.end(); ++it) {
        if ((*it)->getInmueble()->getCodigo() == codigoInmueble) {
            return *it;
        }
    }
    return NULL;
}

bool Inmobiliaria::estaSuscrito(IObservers* observer) {
	return this->observers.find(observer) != this->observers.end();
}

void Inmobiliaria::suscribir(IObservers* o) {
    observers.insert(o);
}

void Inmobiliaria::desuscribir(IObservers* o) {
    observers.erase(o);
}

void Inmobiliaria::notificarObservers(int codigo) {
    std::set<IObservers*>::iterator it;
    for (it = observers.begin(); it != observers.end(); ++it) {
        (*it)->notificar(codigo);
    }
}
