#include "../include/ColeccionUsuario.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"

ColeccionUsuario* ColeccionUsuario::instancia = NULL;

ColeccionUsuario::ColeccionUsuario() {
    itUsuarios = this->usuarios.end();
}

ColeccionUsuario::~ColeccionUsuario() {
}

Usuario* ColeccionUsuario::next() {
    if (this->usuarios.empty()) {
        return NULL;
    }
    
    if (itUsuarios == this->usuarios.end()) {
        itUsuarios = this->usuarios.begin();
    }
    
    Usuario* usuarioActual = *itUsuarios;
    ++itUsuarios;
    return usuarioActual;
}

ColeccionUsuario& ColeccionUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new ColeccionUsuario();
    }
    return *instancia;
}

void ColeccionUsuario::addUsuario(Usuario* u) {
    this->usuarios.insert(u);
}

bool ColeccionUsuario::existsUsuario(std::string nickname) {
    std::set<Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it)->getNickname() == nickname) {
            return true;
        }
    }
    return false;
}

Usuario* ColeccionUsuario::findUsuario(std::string nickname) {
    std::set<Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it)->getNickname() == nickname) {
            return *it;
        }
    }
    return NULL;
}
