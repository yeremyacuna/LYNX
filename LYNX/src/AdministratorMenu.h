#pragma once
#include "AuthManager.h"
#include "TripManager.h"
#include "Trip.h"
#include <iostream>
#include <string>
using std::cout; using std::cin;

void lynxs() {
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(45+18, 5);std::cout << (char)219 << (char)219 << "     " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 6);std::cout << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 7);std::cout << (char)219 << (char)219 << "       " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 8);std::cout << (char)219 << (char)219 << "        " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 9);std::cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";

    Console::ForegroundColor = ConsoleColor::White;
}

void navBarAs() {
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0);std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 1);std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 2);std::cout << "                                                                                                                                                                ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(3, 1);std::cout << "LYNX";
    Console::SetCursorPosition(20, 1);std::cout << "Pasajero";

    Console::SetCursorPosition(31, 1);std::cout << "Conductor";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(43, 1);std::cout << "Admin";
    Console::BackgroundColor = ConsoleColor::Black;
    Console::ForegroundColor = ConsoleColor::White;
}

void Seleccions(int keycode, int& inicio, int min, int max) {
    switch (keycode) {
    case 72:
        if (inicio > min) {
            inicio--;
        }
        break;
    case 80:
        if (inicio < max) {
            inicio++;
        }
        break;
    }
};

class AdministratorMenu {
private:
    AuthManager* authMgr;
    TripManager* tripMgr;

public:
    AdministratorMenu(AuthManager* a, TripManager* t) : authMgr(a), tripMgr(t) {}

    void run(int & opcion) {
        opcion = 1;
        while (true) {
            system("cls");
            lynxs();navBarAs();
            Console::SetCursorPosition(54 + 18, 11);cout << "ADMIN PANEL";
            Console::SetCursorPosition(46 + 18, 12);cout << "    ----------------------------";
            Console::SetCursorPosition(48 + 18, 13);
            if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Listar todos los usuarios"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Listar todos los usuarios"; }
            Console::SetCursorPosition(48 + 18, 14);
            if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Listar todos los conductores"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Listar todos los conductores"; }
            Console::SetCursorPosition(48 + 18, 15);
            if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Listar todos los viajes"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Listar todos los viajes"; }
            Console::SetCursorPosition(48 + 18, 16);
            if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Buscar usuario por DNI"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Buscar usuario por DNI"; }

            Console::SetCursorPosition(48 + 18, 17);
            if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ordenar conductores por rating"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ordenar conductores por rating"; }

            Console::SetCursorPosition(48 + 18, 18);
            if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Top conductores del mes"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Top conductores del mes"; }

            Console::SetCursorPosition(48 + 18, 19);
            if (opcion == 7) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Estadisticas generales"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Estadisticas generales"; }
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(46 + 18, 20);cout << "    ----------------------------";
            Console::SetCursorPosition(48 + 18, 21);
            if (opcion == 8) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal"; }

            Console::ForegroundColor = ConsoleColor::White;

            int key = _getch();
            if (key == 13) {
                if (opcion == 8) opcion = 0;
                return;
            }
            if (key == 0 || key == 224) key = _getch();
            Seleccions(key, opcion, 1, 8);
        }

            /*
            if (op == 1) listarUsuarios();
            else if (op == 2) listarConductores();
            else if (op == 3) listarViajes();
            else if (op == 4) buscarUsuario();
            else if (op == 5) ordenarConductores();
            else if (op == 6) topConductores();
            else if (op == 7) estadisticas();
            */
      
    }



   
    // [1] LinkedList::forEach
    void listarUsuarios() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(50 + 18, 11);cout << "LISTA DE PASAJEROS";
        if (authMgr->getUserList().isEmpty()) {
            Console::SetCursorPosition(48 + 18, 12); cout << "  Sin pasajeros registrados.\n"; pausar(); return;
        }
        int i = 1, y=12;
        authMgr->getUserList().forEach([&i,&y](Passenger p) {
            Console::SetCursorPosition(18 + 18, y++);cout << "  [" << i++ << "] " << p.toString() << "\n";
            });
        pausar();
    }

    // [2] LinkedList::forEach
    void listarConductores() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(50 + 18, 11);cout << "LISTA DE CONDUCTORES";
        if (authMgr->getDriverList().isEmpty()) {
            Console::SetCursorPosition(48 + 18, 12);cout << "  Sin conductores registrados.\n"; pausar(); return;
        }
        int i = 1, y=12;
        authMgr->getDriverList().forEach([&i,&y](Driver d) {
            Console::SetCursorPosition(18 + 18, y++);cout << "  [" << i++ << "] " << d.toString() << "\n";
            });
        pausar();
    }

    // [3] viewWaitingDetailed usa Queue::forEach (TripManager)
    void listarViajes() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(52 + 18, 11);cout << "TODOS LOS VIAJES";
        Console::SetCursorPosition(47 + 18, 12);tripMgr->viewWaitingDetailed();
        Console::SetCursorPosition(47 + 18, 14);tripMgr->viewActive();
        Console::SetCursorPosition(47 + 18, 16);tripMgr->viewHistory();
        Console::SetCursorPosition(47 + 18, 18);cout << "Ganancia plataforma (20%): S/ "
            << tripMgr->getTotalPlatformEarnings();
        pausar();
    }

    /*[4] LinkedList::findFirst
         + Stack::findInStack via getLastTripByPassenger (TripManager)*/
    void buscarUsuario() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(53 + 18, 11);cout << "BUSCAR PASAJERO";
        string dni;
        Console::SetCursorPosition(55 + 18, 12);cout << "DNI: "; cin >> dni;

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
        lynxs();navBarAs();
        Console::SetCursorPosition(48 + 18, 11);cout << "TOP CONDUCTORES (rating >= 4.0)";

        auto tieneBuenRating = [](Driver d) -> bool {
            return d.getRating() >= 4.0f;
            };

        int i = 1,y=12;
        bool alguno = false;
        for (int j = 0; j < authMgr->getDriverList().getSize(); j++) {
            Driver d = authMgr->getDriverList().get(j);
            if (tieneBuenRating(d)) {
                Console::SetCursorPosition(20 + 18, y++);cout << "  [" << i++ << "] " << d.toString() << "\n";
                alguno = true;
            }
        }
        if (!alguno) Console::SetCursorPosition(47 + 18, 12);cout << "  Ningun conductor con rating >= 4.0\n";
        pausar();
    }

    /*[7] mostrarResumen(AuthManager), mostrarEstadoCola(TripManager)
         + recursividad: contarConductoresDisponibles, getTotalPlatformEarnings*/
    void estadisticas() {

        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(54 + 18, 11);cout << "ESTADISTICAS GENERALES";

        auto fila = [](string etiqueta, string valor) {
            cout << "  " << etiqueta << ": " << valor << "\n";
            };

        int disponibles = authMgr->contarConductoresDisponibles(0);
        float ganancia = tripMgr->getTotalPlatformEarnings();

        authMgr->mostrarResumen();
        Console::SetCursorPosition(50 + 18, 13);fila("Conductores disponibles", to_string(disponibles));
        Console::SetCursorPosition(50 + 18, 14);fila("Viajes en espera", to_string(tripMgr->getTotalWaiting()));
        Console::SetCursorPosition(50 + 18, 15);fila("Viajes activos", to_string(tripMgr->getTotalActiveTrips()));
        Console::SetCursorPosition(50 + 18, 16);fila("Viajes en historial", to_string(tripMgr->getTotalHistoryTrips()));
        Console::SetCursorPosition(50 + 18, 17);fila("Ganancia plataforma", "S/ " + to_string(ganancia));
        Console::SetCursorPosition(50 + 18, 18);tripMgr->mostrarEstadoCola();
        pausar();
    }

    void pausar() {
        lynxs();navBarAs();
        Console::SetCursorPosition(46 + 18, 27); cout << "Presione enter para continuar";
        int op = 0;
        int get = _getch();
        if (get == 13)op = 0;
    }
};
