#include "../include/Inmobiliria.h"

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
