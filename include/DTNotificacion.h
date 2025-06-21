#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include "TipoPublicacion.h"
#include <string>

class DTNotificacion {
	private:
		std::string inmobiliaraNick;
		int codigo;
		std::string texto;
		TipoPublicacion tipo;

	public:
		DTNotificacion(std::string inmobiliaraNick, int codigo, std::string texto, TipoPublicacion tipo);
		~DTNotificacion();
};

#endif
