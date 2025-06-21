#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/DTNotificacion.h"
#include "../include/IAltaUsuario.h"
#include "../include/IControllerPublicacion.h"
#include "../include/IControllerInmueble.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTInmuebleListado.h"
#include <string>
#include <set>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Elimiinar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion = -1;
    if (!(std::cin >> opcion)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return 0;
    }
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();
    IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();
    IControllerInmueble* iControllerInmueble = factory->getControllerInmueble();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = iAltaUsuario->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = iAltaUsuario->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = iAltaUsuario->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario*> propietarios = iAltaUsuario->listarPropietarios();
                    for (std::set<DTUsuario*>::iterator it = propietarios.begin(); it != propietarios.end(); ++it) {
                        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
                    }
                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    iAltaUsuario->representarPropietario(nicknamePropietario);
                    // Inmobiliaria solo puede representar propietarios, no agrega inmuebles
                    salir = 0;
                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        iControllerInmueble->AltaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                        std::cout << "Casa creada exitosamente." << std::endl;
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        iControllerInmueble->AltaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                        std::cout << "Apartamento creado exitosamente." << std::endl;
                    }
                    
                    std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                    std::cin >> salir;
                    std::cin.ignore();
                }
            }
        }
        iAltaUsuario->finalizarAltaUsuario();
        std::cout << "Usuario creado exitosamente." << std::endl;
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){

    Factory* factory = Factory::getInstance();
    IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();
    IControllerPublicacion* iControllerPublicacion = factory->getControllerPublicacion();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> inmobiliarias = iAltaUsuario->listarInmobiliarias();
    if (inmobiliarias.empty()) {
        std::cout << "No hay inmobiliarias registradas." << std::endl;
        return;
    }
    for (std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    
    std::cout << "Lista de Inmuebles Administrados:\n";
    std::set<DTInmuebleAdministrado*> inmueblesAdministrados = iAltaUsuario->listarInmueblesAdministrados(nicknameInmobiliaria);
    if (inmueblesAdministrados.empty()) {
        std::cout << "Esta inmobiliaria no tiene inmuebles administrados." << std::endl;
        return;
    }
    for (std::set<DTInmuebleAdministrado*>::iterator it = inmueblesAdministrados.begin(); it != inmueblesAdministrados.end(); ++it) {
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", Direccion: " << (*it)->getDireccion() << std::endl;
    }
    int codigoInmueble;
    std::cout << "Inmueble: ";
    std::cin >> codigoInmueble;
    std::cin.ignore();
    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    
    try {
        iControllerPublicacion->AltaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
        std::cout << "Publicacion creada exitosamente." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error al crear la publicacion: " << e.what() << std::endl;
    }
}

void consultaPublicaciones(){

    Factory* factory = Factory::getInstance();
    IControllerPublicacion* iControllerPublicacion = factory->getControllerPublicacion();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoInmueble == 1){
        tipoInmueble = TipoCasa;
    }else if(inTipoInmueble == 2){
        tipoInmueble = TipoApartamento;
    }
    
    std::cout << "Publicaciones encontradas:\n";
    std::set<DTPublicacion*> publicaciones = iControllerPublicacion->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    
    if (publicaciones.empty()) {
        std::cout << "No se encontraron publicaciones con los criterios especificados." << std::endl;
        return;
    }
    
    for (std::set<DTPublicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        DTPublicacion* pub = *it;
        std::cout << "- Codigo: " << pub->getCodigo() 
                  << ", Fecha: " << pub->getFecha()->toString()
                  << ", Texto: " << pub->getTexto() 
                  << ", Precio: " << pub->getPrecio() 
                  << ", Inmobiliaria: " << pub->getInmobiliaria() << std::endl;
    }
    
    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        
        DTInmueble* dtInmueble = iControllerPublicacion->detalleInmueblePublicacion(codigoPublicacion);
        if (dtInmueble == NULL) {
            std::cout << "No se encontro la publicacion con el codigo especificado." << std::endl;
            return;
        }
        
        std::cout << "Detalle del inmueble:\n";
        
        DTApartamento* apartamento = dynamic_cast<DTApartamento*>(dtInmueble);
        if (apartamento != NULL) {
            std::cout << "Codigo: " << apartamento->getCodigo() 
                      << ", Direccion: " << apartamento->getDireccion() 
                      << ", Nro. puerta: " << apartamento->getNumeroPuerta() 
                      << ", Superficie: " << apartamento->getSuperficie() << " m2"
                      << ", Construccion: " << apartamento->getAnioConstruccion() 
                      << ", Piso: " << apartamento->getPiso() 
                      << ", Ascensor: " << (apartamento->getTieneAscensor() ? "Si" : "No")
                      << ", Gastos comunes: " << apartamento->getGastosComunes() << std::endl;
        } else {
            DTCasa* casa = dynamic_cast<DTCasa*>(dtInmueble);
            if (casa != NULL) {
                std::cout << "Codigo: " << casa->getCodigo() 
                          << ", Direccion: " << casa->getDireccion() 
                          << ", Nro. puerta: " << casa->getNumeroPuerta() 
                          << ", Superficie: " << casa->getSuperficie() << " m2"
                          << ", Construccion: " << casa->getAnioConstruccion() 
                          << ", PH: " << (casa->getEsPH() ? "Si" : "No")
                          << ", Tipo de techo: ";
                          
                switch(casa->getTecho()) {
                    case Liviano: std::cout << "Liviano"; break;
                    case A_dos_aguas: std::cout << "A dos aguas"; break;
                    case Plano: std::cout << "Plano"; break;
                }
                std::cout << std::endl;
            }
        }
        delete dtInmueble;
    }
}

void eliminarInmueble(){
    Factory* factory = Factory::getInstance();
    IControllerInmueble* iControllerInmueble = factory->getControllerInmueble();
    
    std::cout << "Listado de inmuebles:\n";
    std::set<DTInmuebleListado*> inmuebles = iControllerInmueble->listarInmuebles();
    
    if (inmuebles.empty()) {
        std::cout << "No hay inmuebles registrados en el sistema." << std::endl;
        return;
    }
    
    for (std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        DTInmuebleListado* inmueble = *it;
        std::cout << "- Codigo: " << inmueble->getCodigo() 
                  << ", direccion: " << inmueble->getDireccion() 
                  << ", propietario: " << inmueble->getPropietario() << std::endl;
    }
    
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    
    DTInmueble* dtInmueble = iControllerInmueble->detalleInmueble(codigoInmueble);
    if (dtInmueble == NULL) {
        std::cout << "No se encontro el inmueble con el codigo especificado." << std::endl;
        for (std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
            delete *it;
        }
        return;
    }
    
    std::cout << "Detalle del inmueble:\n";
    
    DTApartamento* apartamento = dynamic_cast<DTApartamento*>(dtInmueble);
    if (apartamento != NULL) {
        std::cout << "Codigo: " << apartamento->getCodigo() 
                  << ", direccion: " << apartamento->getDireccion() 
                  << ", nro. puerta: " << apartamento->getNumeroPuerta() 
                  << ", superficie: " << apartamento->getSuperficie() << " m2"
                  << ", construccion: " << apartamento->getAnioConstruccion() 
                  << ", piso: " << apartamento->getPiso() 
                  << ", ascensor: " << (apartamento->getTieneAscensor() ? "Si" : "No")
                  << ", gastos comunes: " << apartamento->getGastosComunes() << std::endl;
    } else {
        DTCasa* casa = dynamic_cast<DTCasa*>(dtInmueble);
        if (casa != NULL) {
            std::cout << "Codigo: " << casa->getCodigo() 
                      << ", direccion: " << casa->getDireccion() 
                      << ", nro. puerta: " << casa->getNumeroPuerta() 
                      << ", superficie: " << casa->getSuperficie() << " m2"
                      << ", construccion: " << casa->getAnioConstruccion() 
                      << ", PH: " << (casa->getEsPH() ? "Si" : "No")
                      << ", Tipo de techo: ";
                      
            switch(casa->getTecho()) {
                case Liviano: std::cout << "Liviano"; break;
                case A_dos_aguas: std::cout << "A dos aguas"; break;
                case Plano: std::cout << "Plano"; break;
            }
            std::cout << std::endl;
        }
    }
    
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    
    if (deseaEliminar == 1) {
        iControllerInmueble->eliminarInmueble(codigoInmueble);
        std::cout << "Inmueble eliminado exitosamente." << std::endl;
    } else {
        std::cout << "Operacion cancelada." << std::endl;
    }
    
    delete dtInmueble;
    for (std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        delete *it;
    }
}

void suscribirseNotificaciones(){
	Factory* factory = Factory::getInstance();
	IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();
	std::set<std::string> suscripciones;
	std::cout << "Ingrese su nickname: ";
	std::string nick;
	if (!std::getline(std::cin, nick)) {
		std::cout << "Operacion cancelada." << std::endl;
		return;
	}
	std::set<DTUsuario*> lista = iAltaUsuario->listarNoSuscripciones(nick);
	
	std::cout << "Inmobiliarias disponibles para suscripcion:\n";
	for (std::set<DTUsuario*>::iterator it = lista.begin(); it != lista.end(); ++it) {
		std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
	}
	
	std::cout << "Ingrese los nicknames de las inmobiliarias (termine con 'fin'): ";
	std::string nickInmobiliaria;
	while (std::getline(std::cin, nickInmobiliaria)) {
		if (nickInmobiliaria == "fin") break;
		if (nickInmobiliaria.empty()) continue; 
		suscripciones.insert(nickInmobiliaria);
	}
	
	iAltaUsuario->agregarSuscripciones(suscripciones);
	std::cout << "Suscripciones agregadas exitosamente." << std::endl;
}

void consultaNotificaciones(){
	std::cout << "Ingrese su nickname: ";
	std::string nick;
	if (!std::getline(std::cin, nick)) {
		std::cout << "Operacion cancelada." << std::endl;
		return;
	}
	Factory* factory = Factory::getInstance();
	IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();
	std::set<DTNotificacion*> notifs = iAltaUsuario->getNotifs(nick);
	
	std::cout << "Notificaciones:\n";
	if (notifs.empty()) {
		std::cout << "No tiene notificaciones pendientes." << std::endl;
	} else {
		for (std::set<DTNotificacion*>::iterator it = notifs.begin(); it != notifs.end(); ++it) {
			std::cout << "- " << (*it)->getTexto() << std::endl;
		}
	}
}

void eliminarSuscripciones(){
	Factory* factory = Factory::getInstance();
	IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();
	std::set<std::string> suscripciones;
	
	std::cout << "Ingrese su nickname: ";
	std::string nick;
	if (!std::getline(std::cin, nick)) {
		std::cout << "Operacion cancelada." << std::endl;
		return;
	}
	
	std::set<DTUsuario*> lista = iAltaUsuario->listarSuscripciones(nick);
	
	if (lista.empty()) {
		std::cout << "No tiene suscripciones activas." << std::endl;
		return;
	}
	
	std::cout << "Sus suscripciones actuales:\n";
	for (std::set<DTUsuario*>::iterator it = lista.begin(); it != lista.end(); ++it) {
		std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
	}
	
	std::cout << "Ingrese los nicknames de las inmobiliarias a desuscribir (termine con 'fin'): ";
	std::string nickInmobiliaria;
	while (std::getline(std::cin, nickInmobiliaria)) {
		if (nickInmobiliaria == "fin") break;
		if (nickInmobiliaria.empty()) continue; 
		suscripciones.insert(nickInmobiliaria);
	}
	
	if (!suscripciones.empty()) {
		iAltaUsuario->eliminarSuscripciones(suscripciones);
		std::cout << "Suscripciones eliminadas exitosamente." << std::endl;
	} else {
		std::cout << "No se seleccionaron suscripciones para eliminar." << std::endl;
	}
}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();
    IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> inmobiliarias = iAltaUsuario->listarInmobiliarias();
    if (inmobiliarias.empty()) {
        std::cout << "No hay inmobiliarias registradas." << std::endl;
        return;
    }
    for (std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
    }
    
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    
    std::cout << "Lista de Inmuebles No Administrados:\n";
    std::set<DTInmuebleListado*> inmueblesNoAdministrados = iAltaUsuario->listarInmueblesNoAdministrados(nicknameInmobiliaria);
    if (inmueblesNoAdministrados.empty()) {
        std::cout << "No hay inmuebles disponibles para administrar por esta inmobiliaria." << std::endl;
        return;
    }
    for (std::set<DTInmuebleListado*>::iterator it = inmueblesNoAdministrados.begin(); it != inmueblesNoAdministrados.end(); ++it) {
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", direccion: " << (*it)->getDireccion() << ", propietario: " << (*it)->getPropietario() << std::endl;
    }
    
    std::cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    
    iAltaUsuario->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
    std::cout << "Administracion de propiedad creada exitosamente." << std::endl;
    
    for (std::set<DTInmuebleListado*>::iterator it = inmueblesNoAdministrados.begin(); it != inmueblesNoAdministrados.end(); ++it) {
        delete *it;
    }
}

void cargarDatos(){
    CargaDatos::getInstance();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }
