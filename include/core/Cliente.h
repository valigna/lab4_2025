#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "IObservers.h"
#include <string>

class Cliente : public Usuario, public IObservers {
    private:
        std::string apellido;
        std::string documento;
        
    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        ~Cliente();

        std::string getApellido();
        std::string getDocumento();
        
        DTUsuario* getDTUsuario() override;
        
};

#endif
