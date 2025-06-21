#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "IObservers.h"
#include "Propietario.h"
#include <string>
#include <set>

class AdministraPropiedad; // Forward declaration

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;
    std::set<Propietario*> propietarios;
    std::set<AdministraPropiedad*> APs;
    std::set<IObservers*> observers;

public:
    Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, 
                 std::string email, std::string direccion, std::string url, std::string telefono);
    ~Inmobiliaria();
    
    std::set<Propietario*>& getPropietarios();
    std::set<AdministraPropiedad*> getAPs();
    void addAP(AdministraPropiedad* ap);
    void removeAP(AdministraPropiedad* ap);
    AdministraPropiedad* getAP(int codigoInmueble);
	bool estaSuscrito(IObservers* observer);    
    void suscribir(IObservers* o);
    void desuscribir(IObservers* o);
    void notificarObservers(int codigo);
};

#endif
