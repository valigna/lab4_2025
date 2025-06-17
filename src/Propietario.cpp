#include "../include/Propietario.h"

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
    // Implementación del observer - por ahora vacía
    // TODO: Implementar lógica de notificación al propietario
}