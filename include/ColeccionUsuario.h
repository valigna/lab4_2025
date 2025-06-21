#ifndef COLECCIONUSUARIO_H
#define COLECCIONUSUARIO_H

#include "Usuario.h"
#include "DTUsuario.h"
#include <string>
#include <set>

class ColeccionUsuario {
private:
    static ColeccionUsuario* instancia;
    std::set<Usuario*> usuarios;
    std::set<Usuario*>::iterator itUsuarios;
    
    ColeccionUsuario();
    
    ColeccionUsuario(const ColeccionUsuario&);
    ColeccionUsuario& operator=(const ColeccionUsuario&);

public:
    ~ColeccionUsuario();
    
    static ColeccionUsuario& getInstancia();
    
    void addUsuario(Usuario* u);
    bool existsUsuario(std::string nickname);
    Usuario* findUsuario(std::string nickname);
    
    Usuario* next();
};

#endif