#include "../include/Inmobiliria.h"

Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono){
    this->nickname=nickname;
    this->contrasena=contrasena;
    this->nombre=nombre;
    this->email=email;
    this->direccion=direccion;
    this->url=url;
    this->telefono=telefono;
}

void notificarObservers(int codigo) {
	std::set<IObservers*>::iterator it;
	for (it = observers.begin(); it != observers.end(); ++it) {
		it->notificar(int codigo);
	}	
}

std::set<Propietario*>& Inmobiliaria::getPropietarios(){
    return this->propietarios;
}

std::set<AdministraPropiedad*> Inmobiliaria::getAPs(){
    return this->APs;
}

AdministraPropiedad* Inmobiliaria::getAP(int codigoInmueble){
    for (AdministraPropiedad* ap:APs){
        if (ap->inmueble.getCodigo()==codigoInmueble){
            return ap;
        }
    }
    return NULL;
}

void suscribir(IObservers* o) {
	observers->insert(o);
}
