#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "IObservers.h"
#include "Inmueble.h"
#include <string>
#include <set>

class Propietario : public Usuario, public IObservers {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::set<Inmueble*> inmuebles;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        std::set<Inmueble*> getInmuebles();
    };

#endif
