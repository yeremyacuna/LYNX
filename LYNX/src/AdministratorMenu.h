#pragma once
#include "AuthManager.h"
#include "TripManager.h"
#include "Trip.h"
#include <iostream>
#include <string>
#include <conio.h>
using std::cout; using std::cin;

// lynxs: dibuja el titulo LYNX en la vista de administrador
void lynxs() {
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(45+18, 5);std::cout << (char)219 << (char)219 << "     " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 6);std::cout << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 7);std::cout << (char)219 << (char)219 << "       " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 8);std::cout << (char)219 << (char)219 << "        " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45 + 18, 9);std::cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";

    Console::ForegroundColor = ConsoleColor::White;
}

// navBarAs: pinta la barra superior y resalta la seccion admin
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

// Seleccions: mueve la opcion seleccionada con flechas arriba y abajo
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

    // run: bucle principal del menu de administrador
    // aqui solo se navega entre opciones y se decide que modulo ejecutar
    void run(int& opcion) {
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

            Console::SetCursorPosition(48 + 18, 20);
            if (opcion == 8) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ordenar pasajeros por gasto"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ordenar pasajeros por gasto"; }

            Console::SetCursorPosition(48 + 18, 21);
            if (opcion == 9) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ordenar pasajeros por ID"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ordenar pasajeros por ID"; }

            Console::SetCursorPosition(48 + 18, 22);
            if (opcion == 10) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ordenar conductores por ID"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ordenar conductores por ID"; }

            Console::SetCursorPosition(48 + 18, 23);
            if (opcion == 11) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ordenar viajes activos por precio"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ordenar viajes activos por precio"; }

            Console::SetCursorPosition(48 + 18, 24);
            if (opcion == 12) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver passwords en binario"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver passwords en binario"; }

            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(46 + 18, 25); cout << "    ----------------------------";
            Console::SetCursorPosition(48 + 18, 26);
            if (opcion == 13) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal"; }
            else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal"; }

            Console::ForegroundColor = ConsoleColor::White;

            int key = _getch();
            if (key == 13) {
                if (opcion == 13) opcion = 0;
                return;
            }
            if (key == 0 || key == 224) key = _getch();
            Seleccions(key, opcion, 1, 13);
        }
    }

    // [1] LinkedList::forEach
    void listarUsuarios() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(50 + 18, 11);cout << "LISTA DE PASAJEROS";
        if (authMgr->getUserList()->isEmpty()) {
            Console::SetCursorPosition(48 + 18, 12); cout << "  Sin pasajeros registrados.\n"; pausar(); return;
        }
        int i = 1, y=12;
        authMgr->getUserList()->forEach([&i,&y](Passenger p) {
            Console::SetCursorPosition(18 + 18, y++);cout << "  [" << i++ << "] " << p.toString() << "\n";
            });
        pausar();
    }

    // [2] LinkedList::forEach
    void listarConductores() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(50 + 18, 11);cout << "LISTA DE CONDUCTORES";
        if (authMgr->getDriverList()->isEmpty()) {
            Console::SetCursorPosition(48 + 18, 12);cout << "  Sin conductores registrados.\n"; pausar(); return;
        }
        int i = 1, y=12;
        authMgr->getDriverList()->forEach([&i,&y](Driver d) {
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

        Passenger p = authMgr->getPassengerList()->findFirst([&](Passenger x) { return x.getDni() == dni; });

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

    // [5] ORDENAMIENTO
    void ordenarConductores() {
        system("cls");
        cout << "  === ORDENAR CONDUCTORES POR RATING ===\n\n";
        cout << "  Antes del ordenamiento:\n";
        int i = 1;
        authMgr->getDriverList()->forEach([&i](Driver d) {
            cout << "  [" << i++ << "] " << d.getName() << " - Rating: " << d.getRating() << "\n";
            });

        authMgr->sortDriversByRating(); // Shell Sort

        cout << "\n  Despues del ordenamiento (mayor a menor rating):\n";
        i = 1;
        authMgr->getDriverList()->forEach([&i](Driver d) {
            cout << "  [" << i++ << "] " << d.getName() << " - Rating: " << d.getRating() << "\n";
            });
        pausar();
    }

    // [6] TOP DRIVERS CON ORDENAMIENTO
    void topConductores() {
        system("cls");
        lynxs();navBarAs();
        Console::SetCursorPosition(48 + 18, 11);cout << "TOP CONDUCTORES (rating >= 4.0)";

        auto tieneBuenRating = [](Driver d) -> bool {
            return d.getRating() >= 4.0f;
            };

        int i = 1, y = 12;
        bool alguno = false;
        for (int j = 0; j < authMgr->getDriverList()->getSize(); j++) {
            Driver d = authMgr->getDriverList()->get(j);
            if (tieneBuenRating(d)) {
                Console::SetCursorPosition(20 + 18, y++);cout << "  [" << i++ << "] " << d.toString() << "\n";
                alguno = true;
            }
        }
        if (!alguno) {
            Console::SetCursorPosition(47 + 18, 12);
            cout << "  Ningun conductor con rating >= 4.0\n";
        }
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
        Console::SetCursorPosition(50, 15); fila("Conductores disponibles", to_string(disponibles));
        Console::SetCursorPosition(50, 16); fila("Viajes en espera", to_string(tripMgr->getTotalWaiting()));
        Console::SetCursorPosition(50, 17); fila("Viajes activos", to_string(tripMgr->getTotalActiveTrips()));
        Console::SetCursorPosition(50, 18); fila("Viajes en historial", to_string(tripMgr->getTotalHistoryTrips()));
        Console::SetCursorPosition(50, 19); fila("Ganancia plataforma", "S/ " + to_string(ganancia));
        Console::SetCursorPosition(50, 20); fila("Monto total en cola", "S/ " + to_string(tripMgr->calcTotalEnCola()));
        Console::SetCursorPosition(50, 21); fila("Viajes en curso", to_string(tripMgr->contarViajesEnCurso()));
        Console::SetCursorPosition(50, 22); tripMgr->mostrarEstadoCola();
        pausar();
    }

    //[8] ORDENAR PASAJEROS POR GASTO
    void ordenarPasajeros() {
        system("cls");
        cout << "  === ORDENAR PASAJEROS POR GASTO TOTAL ===\n\n";
        cout << "  Antes del ordenamiento:\n";
        int i = 1;
        authMgr->getPassengerList()->forEach([&i](Passenger p) {
            cout << "  [" << i++ << "] " << p.getName() << " - Gastado: S/ " << p.getTotalSpent() << "\n";
            });

        authMgr->sortUsersBySpent();

        cout << "\n  Despues del ordenamiento (mayor a menor gasto):\n";
        i = 1;
        authMgr->getPassengerList()->forEach([&i](Passenger p) {
            cout << "  [" << i++ << "] " << p.getName() << " - Gastado: S/ " << p.getTotalSpent() << "\n";
            });
        pausar();
    }

    //[9] ORDENAR PASAJEROS POR ID
    void ordenarPasajerosPorId() {
        system("cls");
        cout << "  === ORDENAR PASAJEROS POR ID ===\n\n";
        authMgr->sortPassengersById();
        int i = 1;
        authMgr->getPassengerList()->forEach([&i](Passenger p) {
            cout << "  [" << i++ << "] " << p.getPassengerId() << " | " << p.getName() << " | DNI: " << p.getDni() << "\n";
            });
        pausar();
    }

    //[10] ORDENAR DRIVERS POR ID
    void ordenarConductoresPorId() {
        system("cls");
        cout << "  === ORDENAR CONDUCTORES POR ID ===\n\n";
        authMgr->sortDriversById();
        int i = 1;
        authMgr->getDriverList()->forEach([&i](Driver d) {
            cout << "  [" << i++ << "] " << d.getDriverId() << " | " << d.getName() << " | DNI: " << d.getDni() << "\n";
            });
        pausar();
    }

    // [11] ORDENAR VIAJES ACTIVOS
    void ordenarViajesActivos() {
        system("cls");
        cout << "  === ORDENAR VIAJES ACTIVOS POR PRECIO ===\n\n";
        cout << "  Antes del ordenamiento:\n";
        for (int i = 0; i < tripMgr->getActiveTrips().getSize(); i++) {
            Trip t = tripMgr->getActiveTrips().get(i);
            cout << "  [" << i + 1 << "] " << t.getTripId() << " - S/ " << t.getPrice() << "\n";
        }

        tripMgr->sortActiveTripsByPrice();

        cout << "\n  Despues del ordenamiento (mayor a menor precio):\n";
        for (int i = 0; i < tripMgr->getActiveTrips().getSize(); i++) {
            Trip t = tripMgr->getActiveTrips().get(i);
            cout << "  [" << i + 1 << "] " << t.getTripId() << " - S/ " << t.getPrice() << "\n";
        }
        pausar();
    }

    // [12] IMPRIMIR LOS BINARIOS DE CONSTRASEÑAS Y DATOS
    void verPasswordsBinarias() {
        system("cls");
        lynxs();
        Console::SetCursorPosition(48, 11); cout << "PASSWORDS GUARDADAS EN BINARIO";

        authMgr->savePasswordsBinary();
        vector<FileManager::PasswordPreview> lista = authMgr->readPasswordsBinary();

        if (lista.empty()) {
            Console::SetCursorPosition(48, 13); cout << "No hay registros binarios.";
            pausar();
            return;
        }

        int y = 13;
        for (int i = 0; i < (int)lista.size(); i++) {
            Console::SetCursorPosition(10, y++);
            cout << "[" << i + 1 << "] "
                << lista[i].tipo
                << " | " << lista[i].id
                << " | DNI: " << lista[i].dni
                << " | Password(bin): " << lista[i].password;

            if (y >= 26 && i + 1 < (int)lista.size()) {
                Console::SetCursorPosition(10, 27); cout << "Presione enter para continuar";
                _getch();
                system("cls");
                lynxs();
                Console::SetCursorPosition(48, 11); cout << "PASSWORDS GUARDADAS EN BINARIO";
                y = 13;
            }
        }
        pausar();
    }

    // pausar: espera enter para que el usuario pueda leer la pantalla antes de volver
    void pausar() {
        lynxs();navBarAs();
        Console::SetCursorPosition(46 + 18, 27); cout << "Presione enter para continuar";
        int op = 0;
        int get = _getch();
        if (get == 13)op = 0;
    }
};
