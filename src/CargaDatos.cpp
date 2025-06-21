#include "../include/CargaDatos.h"
#include "../include/Factory.h"
#include "../include/IAltaUsuario.h"
#include "../include/IControllerInmueble.h"
#include "../include/IControllerPublicacion.h"
#include "../include/IControladorFechaActual.h"
#include "../include/TipoTecho.h"
#include "../include/TipoPublicacion.h"
#include <cstddef>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    cargarDatosPrueba();
}

void CargaDatos::cargarDatosPrueba() {
    Factory* factory = Factory::getInstance();
    IAltaUsuario* iAltaUsuario = factory->getAltaUsuario();
    IControllerInmueble* iControllerInmueble = factory->getControllerInmueble();
    IControllerPublicacion* iControllerPublicacion = factory->getControllerPublicacion();
    IControladorFechaActual* iControladorFecha = factory->getControladorFechaActual();
    
    // ===== CREAR CLIENTES =====
    iAltaUsuario->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    iAltaUsuario->finalizarAltaUsuario();
    
    // ===== CREAR PROPIETARIOS =====
    iAltaUsuario->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "099876543");
    iControladorFecha->setNewFechaActual(1, 1, 2024);
    
    iControllerInmueble->AltaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
    
    iControllerInmueble->AltaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
    
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "091234567");
    iControllerInmueble->AltaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "092345678");
    iControllerInmueble->AltaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432", "098765432");
    iControllerInmueble->AltaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "097654321");
    iControllerInmueble->AltaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    iControllerInmueble->AltaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    iControllerInmueble->AltaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
    iAltaUsuario->finalizarAltaUsuario();
    
    // ===== CREAR INMOBILIARIAS =====
    iAltaUsuario->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    iAltaUsuario->representarPropietario("marcelom");
    iAltaUsuario->representarPropietario("jorge88");
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "099123456");
    iAltaUsuario->representarPropietario("marcelom");
    iAltaUsuario->representarPropietario("martagal");
    iAltaUsuario->representarPropietario("jorge88");
    iAltaUsuario->finalizarAltaUsuario();
    
    iAltaUsuario->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    iAltaUsuario->representarPropietario("robertarce");
    iAltaUsuario->representarPropietario("soledadf");
    iAltaUsuario->representarPropietario("jorge88");
    iAltaUsuario->finalizarAltaUsuario();
    
    // ===== ADMINISTRACIONES DE PROPIEDAD =====
    iControladorFecha->setNewFechaActual(12, 12, 2015);
    iAltaUsuario->altaAdministraPropiedad("casasur123", 2);
    
    iControladorFecha->setNewFechaActual(25, 9, 2023);
    iAltaUsuario->altaAdministraPropiedad("idealhome", 1);
    
    iControladorFecha->setNewFechaActual(20, 7, 2022);
    iAltaUsuario->altaAdministraPropiedad("vivaurbana", 3);
    
    iControladorFecha->setNewFechaActual(1, 1, 2022);
    iAltaUsuario->altaAdministraPropiedad("vivaurbana", 4);
    
    iControladorFecha->setNewFechaActual(3, 7, 2010);
    iAltaUsuario->altaAdministraPropiedad("idealhome", 5);
    
    iControladorFecha->setNewFechaActual(4, 11, 2019);
    iAltaUsuario->altaAdministraPropiedad("casasur123", 6);
    
    iControladorFecha->setNewFechaActual(19, 5, 2020);
    iAltaUsuario->altaAdministraPropiedad("vivaurbana", 6);
    
    iControladorFecha->setNewFechaActual(19, 7, 2024);
    iAltaUsuario->altaAdministraPropiedad("idealhome", 6);
    
    iControladorFecha->setNewFechaActual(18, 9, 2023);
    iAltaUsuario->altaAdministraPropiedad("idealhome", 7);
    
    iControladorFecha->setNewFechaActual(19, 5, 2022);
    iAltaUsuario->altaAdministraPropiedad("vivaurbana", 8);
    
    // ===== PUBLICACIONES =====
    iControladorFecha->setNewFechaActual(9, 10, 2011);
    iControllerPublicacion->AltaPublicacion("idealhome", 5, Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000);
    
    iControladorFecha->setNewFechaActual(15, 1, 2016);
    iControllerPublicacion->AltaPublicacion("casasur123", 2, Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000);
    
    iControladorFecha->setNewFechaActual(5, 3, 2019);
    iControllerPublicacion->AltaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500);
    
    iControladorFecha->setNewFechaActual(3, 4, 2019);
    iControllerPublicacion->AltaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500);
    
    iControladorFecha->setNewFechaActual(12, 12, 2019);
    iControllerPublicacion->AltaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000);
    
    iControladorFecha->setNewFechaActual(12, 6, 2020);
    iControllerPublicacion->AltaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 390000);
    
    iControladorFecha->setNewFechaActual(20, 7, 2020);
    iControllerPublicacion->AltaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000);
    
    iControladorFecha->setNewFechaActual(4, 3, 2022);
    iControllerPublicacion->AltaPublicacion("vivaurbana", 4, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000);
    
    iControladorFecha->setNewFechaActual(12, 9, 2022);
    iControllerPublicacion->AltaPublicacion("vivaurbana", 3, Alquiler, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000);
    
    iControladorFecha->setNewFechaActual(1, 10, 2023);
    iControllerPublicacion->AltaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000);
    
    iControladorFecha->setNewFechaActual(18, 10, 2023);
    iControllerPublicacion->AltaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000);
    
    iControladorFecha->setNewFechaActual(19, 10, 2023);
    iControllerPublicacion->AltaPublicacion("idealhome", 7, Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000);
    
    iControladorFecha->setNewFechaActual(20, 11, 2023);
    iControllerPublicacion->AltaPublicacion("idealhome", 7, Alquiler, "Apartamento con gran vista a la rambla", 31000);
    
    iControladorFecha->setNewFechaActual(20, 11, 2023);
    iControllerPublicacion->AltaPublicacion("idealhome", 7, Venta, "Aprtamente en excelentes condiciones de 80 m", 450000);
    
    iControladorFecha->setNewFechaActual(8, 3, 2024);
    iControllerPublicacion->AltaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000);
    
    iControladorFecha->setNewFechaActual(5, 5, 2024);
    iControllerPublicacion->AltaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000);
    
    iControladorFecha->setNewFechaActual(1, 8, 2024);
    iControllerPublicacion->AltaPublicacion("idealhome", 6, Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000);
    
    // ===== SUSCRIPCIONES =====
    std::set<std::string> suscripcionesLuis;
    suscripcionesLuis.insert("casasur123");
    suscripcionesLuis.insert("idealhome");
    iAltaUsuario->listarNoSuscripciones("luisito23");
    iAltaUsuario->agregarSuscripciones(suscripcionesLuis);
    
    std::set<std::string> suscripcionesAna;
    suscripcionesAna.insert("casasur123");
    suscripcionesAna.insert("idealhome");
    suscripcionesAna.insert("vivaurbana");
    iAltaUsuario->listarNoSuscripciones("anarojo88");
    iAltaUsuario->agregarSuscripciones(suscripcionesAna);
    
    std::set<std::string> suscripcionesMarcelo;
    suscripcionesMarcelo.insert("idealhome");
    iAltaUsuario->listarNoSuscripciones("marcelom");
    iAltaUsuario->agregarSuscripciones(suscripcionesMarcelo);
    
    std::set<std::string> suscripcionesRoberto;
    suscripcionesRoberto.insert("idealhome");
    iAltaUsuario->listarNoSuscripciones("robertarce");
    iAltaUsuario->agregarSuscripciones(suscripcionesRoberto);
    
    std::set<std::string> suscripcionesSoledad;
    suscripcionesSoledad.insert("vivaurbana");
    iAltaUsuario->listarNoSuscripciones("soledadf");
    iAltaUsuario->agregarSuscripciones(suscripcionesSoledad);
    
    std::set<std::string> suscripcionesMarta;
    suscripcionesMarta.insert("vivaurbana");
    iAltaUsuario->listarNoSuscripciones("martagal");
    iAltaUsuario->agregarSuscripciones(suscripcionesMarta);
    
    std::set<std::string> suscripcionesJorge;
    suscripcionesJorge.insert("casasur123");
    suscripcionesJorge.insert("idealhome");
    suscripcionesJorge.insert("vivaurbana");
    iAltaUsuario->listarNoSuscripciones("jorge88");
    iAltaUsuario->agregarSuscripciones(suscripcionesJorge);
    
    // ===== FECHA ACTUAL =====
    iControladorFecha->setNewFechaActual(1, 12, 2024);
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}

CargaDatos::~CargaDatos() {
}