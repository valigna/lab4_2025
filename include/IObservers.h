#ifndef IOBSERVERS_H
#define IOBSERVERS_H

class IObservers {
	public:
		virtual void notificar(int codigo) = 0;
		virtual ~IObservers() {}
};

#endif
