#include "../include/Cliente.h"
#include "../include/ControllerPublicacion.h"
#include "../include/Publicacion.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento)
    : Usuario(nickname, contrasena, nombre, email),
    apellido(apellido),
    documento(documento)
{}

Cliente::~Cliente() {
}

std::string Cliente::getApellido() {
    return this->apellido;
}

std::string Cliente::getDocumento() {
    return this->documento;
}

void Cliente::notificar(int codigo) {
    ControllerPublicacion& controller = ControllerPublicacion::getInstancia();
    Publicacion* publicacion = controller.getPublicacion(codigo);
    
    if (publicacion != NULL) {
        DTNotificacion* notificacion = publicacion->getNotif();
        if (notificacion != NULL) {
            this->notificaciones.insert(notificacion);
        }
    }
}

std::set<DTNotificacion*> Cliente::getNotifs() {
	return this->notificaciones;
}

void Cliente::borrarNotifs() {
	this->notificaciones.clear();
}
