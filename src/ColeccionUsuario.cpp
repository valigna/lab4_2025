#include "../include/ColeccionUsuario.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"

ColeccionUsuario* ColeccionUsuario::instancia=NULL;

ColeccionUsuario::ColeccionUsuario() {
    itUsuarios = this->usuarios.end();
}

Usuario* ColeccionUsuario::next(){
    if (this->usuarios.empty()) return nullptr;
    if (itUsuarios= this->usuarios.end()) {
        itUsuarios=this->usuarios.begin();
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

void ColeccionUsuario::addUsuario(Usuario* u){
    this->usuarios.insert(u);
}

Usuario* ColeccionUsuario::findUsuario(std::string nickname){
    for (Usuario* usuario:usuarios){
        if (usuario->getNickname()==nickname){
            return usuario
        }
    }
    return NULL;
}
