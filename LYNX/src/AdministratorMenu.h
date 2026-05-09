#pragma once
#include "AuthManager.h"
#include "TripManager.h"
#include "Trip.h"
#include <iostream>
#include <string>
using std::cout; using std::cin;

class AdministratorMenu {
private:
    AuthManager* authMgr;
    TripManager* tripMgr;

public:
    AdministratorMenu(AuthManager* a, TripManager* t) : authMgr(a), tripMgr(t) {}

    void run() {
        int op;
        do {
            system("cls");
            cout << "\n  Lynx > ADMIN PANEL\n";
            cout << "  --------------------------------\n";
            cout << "  [1] Listar todos los usuarios\n";
            cout << "  [2] Listar todos los conductores\n";
            cout << "  [3] Listar todos los viajes\n";
            cout << "  [4] Buscar usuario por DNI\n";
            cout << "  [5] Ordenar conductores por rating\n";
            cout << "  [6] Top conductores del mes\n";
            cout << "  [7] Estadisticas generales\n";
            cout << "  --------------------------------\n";
            cout << "  [0] Volver al menu principal\n";
            cout << "  Opcion: "; cin >> op;

            if (op == 1) listarUsuarios();
            else if (op == 2) listarConductores();
            else if (op == 3) listarViajes();
            else if (op == 4) buscarUsuario();
            else if (op == 5) ordenarConductores();
            else if (op == 6) topConductores();
            else if (op == 7) estadisticas();
        } while (op != 0);
    }

private:

    // [1] LinkedList::forEach
    void listarUsuarios() {
        system("cls");
        cout << "  === LISTA DE PASAJEROS ===\n\n";
        if (authMgr->getUserList().isEmpty()) {
            cout << "  Sin pasajeros registrados.\n"; pausar(); return;
        }
        int i = 1;
        authMgr->getUserList().forEach([&i](Passenger p) {
            cout << "  [" << i++ << "] " << p.toString() << "\n";
            });
        pausar();
    }

    // [2] LinkedList::forEach
    void listarConductores() {
        system("cls");
        cout << "  === LISTA DE CONDUCTORES ===\n\n";
        if (authMgr->getDriverList().isEmpty()) {
            cout << "  Sin conductores registrados.\n"; pausar(); return;
        }
        int i = 1;
        authMgr->getDriverList().forEach([&i](Driver d) {
            cout << "  [" << i++ << "] " << d.toString() << "\n";
            });
        pausar();
    }

    // [3] viewWaitingDetailed usa Queue::forEach (TripManager)
    void listarViajes() {
        system("cls");
        cout << "  === TODOS LOS VIAJES ===\n";
        tripMgr->viewWaitingDetailed();
        tripMgr->viewActive();
        tripMgr->viewHistory();
        cout << "  Ganancia plataforma (20%): S/ "
            << tripMgr->getTotalPlatformEarnings() << "\n";
        pausar();
    }

    /*[4] LinkedList::findFirst
         + Stack::findInStack via getLastTripByPassenger (TripManager)*/
    void buscarUsuario() {
        system("cls");
        cout << "  === BUSCAR PASAJERO ===\n";
        string dni;
        cout << "  DNI: "; cin >> dni;

        Passenger p = authMgr->getUserList()
            .findFirst([&](Passenger x) { return x.getDni() == dni; });

        if (p.getDni() == "") {
            cout << "  No se encontro pasajero con DNI: " << dni << "\n";
        }
        else {
            cout << "\n  " << p.toString() << "\n";
            Trip ultimo = tripMgr->getLastTripByPassenger(dni);
            if (ultimo.getTripId() != "")
                cout << "  Ultimo viaje: " << ultimo.toString() << "\n";
            else
                cout << "  Sin viajes registrados.\n";
        }
        pausar();
    }

    // [5] ESPACIO PARA ORDENAMIENTO
    void ordenarConductores() {/*
        algoritmo de ordenamiento
        sobre la lista de conductores
    */
    }

    // [6] lambda para filtrar por rating
    void topConductores() {
        system("cls");
        cout << "  === TOP CONDUCTORES (rating >= 4.0) ===\n\n";

        auto tieneBuenRating = [](Driver d) -> bool {
            return d.getRating() >= 4.0f;
            };

        int i = 1;
        bool alguno = false;
        for (int j = 0; j < authMgr->getDriverList().getSize(); j++) {
            Driver d = authMgr->getDriverList().get(j);
            if (tieneBuenRating(d)) {
                cout << "  [" << i++ << "] " << d.toString() << "\n";
                alguno = true;
            }
        }
        if (!alguno) cout << "  Ningun conductor con rating >= 4.0\n";
        pausar();
    }

    /*[7] mostrarResumen(AuthManager), mostrarEstadoCola(TripManager)
         + recursividad: contarConductoresDisponibles, getTotalPlatformEarnings*/
    void estadisticas() {
        system("cls");
        cout << "  === ESTADISTICAS GENERALES ===\n\n";

        auto fila = [](string etiqueta, string valor) {
            cout << "  " << etiqueta << ": " << valor << "\n";
            };

        int disponibles = authMgr->contarConductoresDisponibles(0);
        float ganancia = tripMgr->getTotalPlatformEarnings();

        authMgr->mostrarResumen();
        fila("Conductores disponibles", to_string(disponibles));
        fila("Viajes en espera", to_string(tripMgr->getTotalWaiting()));
        fila("Viajes activos", to_string(tripMgr->getTotalActiveTrips()));
        fila("Viajes en historial", to_string(tripMgr->getTotalHistoryTrips()));
        fila("Ganancia plataforma", "S/ " + to_string(ganancia));
        tripMgr->mostrarEstadoCola();
        pausar();
    }

    void pausar() {
        cout << "\n  [0] Volver\n  Opcion: "; int op; cin >> op;
    }
};