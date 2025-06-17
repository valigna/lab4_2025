#include "../include/Cliente.h"

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
    // Implementación del observer - por ahora vacía
    // TODO: Implementar lógica de notificación al cliente
}

