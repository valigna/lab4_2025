#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "IObservers.h"
#include "Propietario.h"
#include <string>
#include <set>

class AdministraPropiedad;

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<Propietario*> propietarios;
        std::set<AdministraPropiedad*> administraciones;
		std::set<IObservers*> observers;
        
		void notificarObservers(int codigo);

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        ~Inmobiliaria();

        std::string getDireccion();
        std::string getUrl();
        std::string getTelefono();

        void agregarPropietario(Propietario* propietario);
        void eliminarPropietario(Propietario* propietario);
        std::set<Propietario*>& getPropietarios();

        void agregarAdministracion(AdministraPropiedad* administracion);
        void eliminarAdministracion(AdministraPropiedad* administracion);
        std::set<AdministraPropiedad*>& getAdministraciones();

        AdministraPropiedad* getAdministracion(int codigoInmueble);

		void suscribir(IObservers* observer);
		void desuscribir(IObservers* observer);
};

#endif
