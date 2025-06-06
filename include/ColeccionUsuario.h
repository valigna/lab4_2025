#ifndef COLECCIONUSUARIO_H
#define COLECCIONUSUARIO_H

#include "Usuario.h"
#include "DTUsuario.h"
#include <string>
#include <set>

class ColeccionUsuario {
    private:
        std::set<Usuario*> usuarios;
        std::set<Usuario*>::iterador itUsuarios;
        ColeccionUsuario();
        ColeccionUsuario(const ColeccionUsuario&) = delete;
        ColeccionUsuario& operator=(const ColeccionUsuario&) = delete

    public:
        Usuario* next();
        static ColeccionUsuario& getInstancia();
        bool existsUsuario(std::string nickname);
        void addUsuario(Usuario::Usuario u);
        Usuario::Usuario findUsuario(std::string nickname); //PRE: existsUsuario(nickname)
};
#endif