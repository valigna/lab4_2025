#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "IObservers.h"
#include "Propietario.h"
#include <string>
#include <set>

class administraPropiedad; // Forward declaration

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<Propietario*> propietarios;
        std::set<AdministraPropiedad*> APs;
		std::set<IObservers*> observers;
		void notificarObservers(int codigo);

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        ~Inmobiliaria();
        std::set<Propietario*>& getPropietarios();
        std::set<AdministraPropiedad*> getAPs();
        AdministraPropiedad* getAP(int codigoInmueble);
		void suscribir(IObservers* o);
		void desuscribir(IObservers* o);
};

#endif
