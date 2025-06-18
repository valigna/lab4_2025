#ifndef CONTROLLERINMUEBLE_H
#define CONTROLLERINMUEBLE_H

#include <string>
#include "TipoTecho.h"
#include "IControllerInmueble.h"

class ControllerInmueble : public IControllerInmueble {
private:
    int ultimoCodigoInmueble;
    static ControllerInmueble* instancia;
    ControllerInmueble();
  std::map <int,Inmueble*> inmuebles;
public:
    static ControllerInmueble& getInstancia();
    ~ControllerInmueble();
    
    int actualizarCodigoInmueble();
    void eliminarInmueble(int codigoInmueble);
    void AltaCasa(std::string direccion, int numeroPuerta, int superficie, 
                  int anioConstruccion, bool esPH, TipoTecho techo);
    void AltaApartamento(std::string direccion, int numeroPuerta, int superficie, 
                        int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
 std::set(DTInmuebleListado*) listarInmuebles();
    DTInmueble* detalleInmueble(codigoInmueble int);

};

#endif
