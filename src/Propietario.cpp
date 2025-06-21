#include "../include/Propietario.h"
#include "../include/ControllerPublicacion.h"
#include "../include/Publicacion.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, 
                        std::string email, std::string cuentaBancaria, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email),
      cuentaBancaria(cuentaBancaria),
      telefono(telefono) {
}

Propietario::~Propietario() {
}

std::string Propietario::getCuentaBancaria() {
    return this->cuentaBancaria;
}

std::string Propietario::getTelefono() {
    return this->telefono;
}

std::set<Inmueble*>& Propietario::getInmuebles() {
    return this->inmuebles;
}

void Propietario::agregarInmueble(Inmueble* inmueble) {
    this->inmuebles.insert(inmueble);
}

void Propietario::notificar(int codigo) {
    ControllerPublicacion& controller = ControllerPublicacion::getInstancia();
    Publicacion* publicacion = controller.getPublicacion(codigo);
    
    if (publicacion != NULL) {
        DTNotificacion* notificacion = publicacion->getNotif();
        if (notificacion != NULL) {
            this->notificaciones.insert(notificacion);
        }
    }
}

std::set<DTNotificacion*> Propietario::getNotifs() {
	return this->notificaciones;
}

void Propietario::borrarNotifs() {
	this->notificaciones.clear();
}
