#ifndef IOBSERVERS_H
#define IOBSERVERS_H
#include <set>
#include "DTNotificacion.h"

class IObservers {
	protected:
		std::set<DTNotificacion *> notificaciones;

	public:
		virtual void notificar(int codigo) = 0;
		virtual std::set<DTNotificacion*> getNotifs() = 0;
		virtual void borrarNotifs() = 0;
		virtual ~IObservers() {}
};

#endif
