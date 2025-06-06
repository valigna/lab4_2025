#include "../include/ColeccionUsuario.h"
#include "../include/Usuario.h"
#include "../include/Propietario.h"

ColeccionUsuario* ColeccionUsuario::instancia=NULL;

ColeccionUsuario::ColeccionUsuario() {
    itUsuarios = usuarios.end();
}

Usuario* ColeccionUsuario::next(){
    if (usuarios.empty()) return nullptr;
    if (itUsuarios= usuarios.end() || itUsuarios==std::set<Usuario*>::iterator()) {
        itUsuarios=usuarios.begin();
    }
    Usuario* usuarioActual=*itUsuarios;
    itUsuarios++;
    return usuarioActual;
    }

ColeccionUsuario& ColeccionUsuario::getInstancia(){
    if (instancia==NULL){
        instancia = new ColeccionUsuario();
    }
    return instancia;
}

bool ColeccionUsuario::existsUsuario(std::string nickname){
    for (Usuario* usuario:usuarios){
        if (usuario->getNickname()==nickname){
            return true;
        }
    }
    return false;
}

void ColeccionUsuario::addUsuario(Usuario::Usuario u){
    usuarios.insert(u);
}

Usuario* ColeccionUsuario::findUsuario(std::string nickname){
    for (Usuario* usuario:usuarios){
        if (usuario->getNickname()==nickname){
            Usuario* f=usuario;
            break;
        }
    }
    return f;
}
