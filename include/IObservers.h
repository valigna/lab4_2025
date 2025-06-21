#ifndef IOBSERVERS_H
#define IOBSERVERS_H
#include <set>
#include "DTNotificacion.h"

class IObservers {
	private:
		std::set<DTNotificacion *> notificaciones;

	public:
		virtual void notificar(int codigo) = 0;
		virtual ~IObservers() {}
};

#endif
