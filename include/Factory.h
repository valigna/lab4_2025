#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IAltaUsuario.h"
#include "IControllerPublicacion.h"
#include "IControllerInmueble.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        IAltaUsuario* getAltaUsuario();
        IControllerPublicacion* getControllerPublicacion();
        IControllerInmueble* getControllerInmueble();
        //TODO: Get interfaces de controladores
        ~Factory();
};

#endif