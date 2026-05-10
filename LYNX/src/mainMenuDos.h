#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <ctime>
#include <direct.h>
#include <conio.h>
#include "Driver.h"
#include "Passenger.h"
#include "Trip.h"
#include "AdministratorMenu.h"
#include "../include/FileManager.h"

using namespace System;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::to_string;

class MenuDos
{
public:
    MenuDos();
    ~MenuDos();

    void lynx();
    void principal(int& opcion);
    void passengerMenu(int& opcion);
    void passengerLogin(string& DNI, string& name, string& password);
    void passengerSignIn(string& DNI, string& name, string& password);
    void passengerOptions(int& opcion);
    void passengerSendTrip(string& origen, string& destino, int& tipo, float& km);
    void passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip);
    void passengerProfile(int& option, Passenger passenger);

    void driverMenu(int& opcion);
    void driverLogin(string& DNI, string& name, string& password);
    void driverOptions(int& opcion, string name, string placa, bool estado, float rating);
    void driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo);
    void driverSingIn(string& DNI, string& name, string& password);
    void driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano);
    void driverGains(int& option, Driver driver);
    void driverProfile(int& option, Driver driver);

    void tripHistory(int& option, Trip trips[], int s, string title);
    void LYNX();

private:
    void moverSeleccion(int keycode, int& inicio, int min, int max);
    void prepararDirectorioTrabajo();
    void limpiarPantalla();
    void pausaCorta();
    void mostrarMensaje(string titulo, string detalle = "");
    string fechaActual();
    string generarTripId(TripManager& tripMgr);
    string buscarDniConductorPorNombre(AuthManager& authMgr, const string& nombre);

    void cargarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr);
    void guardarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr);

    vector<Driver> exportarDrivers(AuthManager& authMgr);
    vector<Passenger> exportarPassengers(AuthManager& authMgr);
    vector<Trip> exportarWaitingTrips(TripManager& tripMgr);
    vector<Trip> exportarActiveTrips(TripManager& tripMgr);
    vector<Trip> exportarHistoryTrips(TripManager& tripMgr);
    vector<Trip> exportarTodosLosTrips(TripManager& tripMgr);

    Trip buscarViajeActivoDePasajero(TripManager& tripMgr, const string& dni);
    Trip buscarViajePendienteDePasajero(TripManager& tripMgr, const string& dni);
    vector<Trip> historialDePasajero(TripManager& tripMgr, const string& dni);
    vector<Trip> historialDeConductor(TripManager& tripMgr, const string& driverName);
};

MenuDos::MenuDos()
{
}

MenuDos::~MenuDos()
{
}

void MenuDos::moverSeleccion(int keycode, int& inicio, int min, int max)
{
    switch (keycode) {
    case 72:
        if (inicio > min) inicio--;
        break;
    case 80:
        if (inicio < max) inicio++;
        break;
    }
}

void MenuDos::prepararDirectorioTrabajo()
{
    std::ifstream testLocal("assets/drivers.txt");
    if (testLocal.is_open()) {
        testLocal.close();
        return;
    }

    std::ifstream testProyecto("LYNX/assets/drivers.txt");
    if (testProyecto.is_open()) {
        testProyecto.close();
        _chdir("LYNX");
    }
}

void MenuDos::limpiarPantalla()
{
    std::system("cls");
}

void MenuDos::pausaCorta()
{
    _getch();
}

void MenuDos::mostrarMensaje(string titulo, string detalle)
{
    limpiarPantalla();
    lynx();
    Console::SetCursorPosition(48, 11); cout << titulo;
    if (!detalle.empty()) {
        Console::SetCursorPosition(48, 13); cout << detalle;
    }
    Console::SetCursorPosition(48, 15); cout << "Presione una tecla para continuar...";
    pausaCorta();
}

string MenuDos::fechaActual()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime{};
    localtime_s(&localTime, &now);

    char buffer[16];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", &localTime);
    return buffer;
}

string MenuDos::generarTripId(TripManager& tripMgr)
{
    int total = tripMgr.getTotalWaiting() + tripMgr.getTotalActiveTrips() + tripMgr.getTotalHistoryTrips() + 1;
    return "TRP-" + to_string(10000 + total);
}

string MenuDos::buscarDniConductorPorNombre(AuthManager& authMgr, const string& nombre)
{
    for (int i = 0; i < authMgr.getDriverList()->getSize(); i++) {
        Driver d = authMgr.getDriverList()->get(i);
        if (d.getName() == nombre) return d.getDni();
    }
    return "";
}

vector<Driver> MenuDos::exportarDrivers(AuthManager& authMgr)
{
    vector<Driver> lista;
    authMgr.getDriverList()->forEach([&](Driver d) {
        lista.push_back(d);
    });
    return lista;
}

vector<Passenger> MenuDos::exportarPassengers(AuthManager& authMgr)
{
    vector<Passenger> lista;
    authMgr.getPassengerList()->forEach([&](Passenger p) {
        lista.push_back(p);
        });
    return lista;
}

vector<Trip> MenuDos::exportarWaitingTrips(TripManager& tripMgr)
{
    vector<Trip> lista;
    tripMgr.getWaitingQueue().forEach([&](Trip t) {
        lista.push_back(t);
        });
    return lista;
}

vector<Trip> MenuDos::exportarActiveTrips(TripManager& tripMgr)
{
    vector<Trip> lista;
    for (int i = 0; i < tripMgr.getActiveTrips().getSize(); i++) {
        lista.push_back(tripMgr.getActiveTrips().get(i));
    }
    return lista;
}

vector<Trip> MenuDos::exportarHistoryTrips(TripManager& tripMgr)
{
    vector<Trip> lista;
    Stack<Trip>& history = tripMgr.getHistory();
    Stack<Trip> temp;

    while (!history.isEmpty()) {
        Trip t = history.peek();
        lista.push_back(t);
        temp.push(t);
        history.pop();
    }

    while (!temp.isEmpty()) {
        history.push(temp.peek());
        temp.pop();
    }

    return lista;
}

vector<Trip> MenuDos::exportarTodosLosTrips(TripManager& tripMgr)
{
    vector<Trip> total = exportarWaitingTrips(tripMgr);
    vector<Trip> activos = exportarActiveTrips(tripMgr);
    vector<Trip> historial = exportarHistoryTrips(tripMgr);

    total.insert(total.end(), activos.begin(), activos.end());
    total.insert(total.end(), historial.begin(), historial.end());
    return total;
}

void MenuDos::cargarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr)
{
    vector<Driver> driversCargados = fileManager.leerDriversTXT();
    for (int i = 0; i < (int)driversCargados.size(); i++) {
        authMgr.getDriverList()->pushBack(driversCargados[i]);
    }

    vector<Passenger> passengersCargados = fileManager.leerPassengersTXT();
    for (int i = 0; i < (int)passengersCargados.size(); i++) {
        authMgr.getPassengerList()->pushBack(passengersCargados[i]);
    }

    vector<Trip> tripsCargados = fileManager.leerTripsTXT();
    vector<Trip> historial;

    for (int i = 0; i < (int)tripsCargados.size(); i++) {
        Trip t = tripsCargados[i];
        if (t.getStatus() == "pendiente") {
            tripMgr.getWaitingQueue().enqueue(t);
        }
        else if (t.getStatus() == "en_curso") {
            tripMgr.getActiveTrips().pushBack(t);
        }
        else {
            historial.push_back(t);
        }
    }

    for (int i = (int)historial.size() - 1; i >= 0; i--) {
        tripMgr.getHistory().push(historial[i]);
    }
}

void MenuDos::guardarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr)
{
    fileManager.guardarDriversTXT(exportarDrivers(authMgr));
    fileManager.guardarPassengersTXT(exportarPassengers(authMgr));
    fileManager.guardarTripsTXT(exportarTodosLosTrips(tripMgr));
}

Trip MenuDos::buscarViajeActivoDePasajero(TripManager& tripMgr, const string& dni)
{
    for (int i = 0; i < tripMgr.getActiveTrips().getSize(); i++) {
        Trip t = tripMgr.getActiveTrips().get(i);
        if (t.getPassengerDni() == dni) return t;
    }
    return Trip();
}

Trip MenuDos::buscarViajePendienteDePasajero(TripManager& tripMgr, const string& dni)
{
    Trip encontrado;
    tripMgr.getWaitingQueue().forEach([&](Trip t) {
        if (encontrado.getTripId() == "" && t.getPassengerDni() == dni) {
            encontrado = t;
        }
    });
    return encontrado;
}

vector<Trip> MenuDos::historialDePasajero(TripManager& tripMgr, const string& dni)
{
    vector<Trip> lista;
    vector<Trip> historial = exportarHistoryTrips(tripMgr);
    for (int i = 0; i < (int)historial.size(); i++) {
        if (historial[i].getPassengerDni() == dni) {
            lista.push_back(historial[i]);
        }
    }
    return lista;
}

vector<Trip> MenuDos::historialDeConductor(TripManager& tripMgr, const string& driverName)
{
    vector<Trip> lista;
    vector<Trip> historial = exportarHistoryTrips(tripMgr);
    for (int i = 0; i < (int)historial.size(); i++) {
        if (historial[i].getDriverName() == driverName) {
            lista.push_back(historial[i]);
        }
    }
    return lista;
}

void MenuDos::lynx()
{
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(45, 5); std::cout << (char)219 << (char)219 << "     " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45, 6); std::cout << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45, 7); std::cout << (char)219 << (char)219 << "       " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45, 8); std::cout << (char)219 << (char)219 << "        " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(45, 9); std::cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
    Console::ForegroundColor = ConsoleColor::White;
}

void MenuDos::principal(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();

        Console::SetCursorPosition(52, 11);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Soy pasajero <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Soy pasajero"; }

        Console::SetCursorPosition(52, 12);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << ">> Soy conductor <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Soy conductor"; }

        Console::SetCursorPosition(52, 13);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Administracion <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Administracion"; }

        Console::SetCursorPosition(52, 14);
        if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << ">> Salir <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Salir"; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) return;
        if (key == 0 || key == 224) key = _getch();
        moverSeleccion(key, opcion, 1, 4);
    }
}

void MenuDos::passengerMenu(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        Console::SetCursorPosition(56, 10); cout << "Pasajero";
        Console::SetCursorPosition(46, 11); cout << "----------------------------";

        Console::SetCursorPosition(50, 12);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion"; }

        Console::SetCursorPosition(50, 13);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme"; }

        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46, 14); cout << "----------------------------";
        Console::SetCursorPosition(50, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal "; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal "; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) {
            if (opcion == 3) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        moverSeleccion(key, opcion, 1, 3);
    }
}

void MenuDos::passengerLogin(string& DNI, string& name, string& password)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Pasajero > Iniciar Sesion";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
}

void MenuDos::passengerSignIn(string& DNI, string& name, string& password)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Pasajero > Registro";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
}

void MenuDos::passengerOptions(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        Console::SetCursorPosition(56, 11); cout << "Pasajero";
        Console::SetCursorPosition(46, 12); cout << "----------------------------";

        Console::SetCursorPosition(48, 13);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Solicitar un viaje"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Solicitar un viaje"; }

        Console::SetCursorPosition(48, 14);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver viaje activo"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver viaje activo"; }

        Console::SetCursorPosition(48, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Historial de viajes"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Historial de viajes"; }

        Console::SetCursorPosition(48, 16);
        if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Calificar ultimo conductor"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Calificar ultimo conductor"; }

        Console::SetCursorPosition(48, 17);
        if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }

        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46, 18); cout << "----------------------------";
        Console::SetCursorPosition(48, 19);
        if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cerrar sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cerrar sesion"; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) {
            if (opcion == 6) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        moverSeleccion(key, opcion, 1, 6);
    }
}

void MenuDos::passengerSendTrip(string& origen, string& destino, int& tipo, float& km)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Pasajero > Solicitar Viaje";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    cin >> std::ws;
    Console::SetCursorPosition(48, y++); cout << "Origen   : "; std::getline(cin, origen);
    Console::SetCursorPosition(48, y++); cout << "Destino  : "; std::getline(cin, destino);

    int yPrompt = y;
    Console::SetCursorPosition(48, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
    while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
        Console::SetCursorPosition(48, y); cout << "Error: Elija 1-3.         ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Console::SetCursorPosition(80, yPrompt); cout << "   ";
        Console::SetCursorPosition(80, yPrompt);
    }
    y++;

    int yKm = y;
    Console::SetCursorPosition(48, y++); cout << "Distancia (km): ";
    while (!(cin >> km) || km <= 0) {
        Console::SetCursorPosition(48, y); cout << "Error: Ingrese un dato valido (km > 0)";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Console::SetCursorPosition(64, yKm); cout << "                             ";
        Console::SetCursorPosition(64, yKm);
    }
}

void MenuDos::passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        int y = 11;
        Console::SetCursorPosition(50, y++); cout << "Pasajero > Confirmar Viaje";
        Console::SetCursorPosition(46, y++); cout << "----------------------------";
        trip.mostrar(52, y);

        y++;
        Console::SetCursorPosition(48, y);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Confirmar viaje"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Confirmar viaje"; }

        Console::SetCursorPosition(48, y + 1);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cancelar"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cancelar"; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) return;
        if (key == 0 || key == 224) key = _getch();
        moverSeleccion(key, opcion, 1, 2);
    }
}

void MenuDos::passengerProfile(int& option, Passenger passenger)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Pasajero > Perfil";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    passenger.mostrar(48, y);
    y++;
    Console::SetCursorPosition(56, y++); cout << "Volver";
    int get = _getch();
    if (get == 13) option = 0;
}

void MenuDos::driverMenu(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        Console::SetCursorPosition(50, 10); cout << "Conductor";
        Console::SetCursorPosition(46, 11); cout << "----------------------------";

        Console::SetCursorPosition(48, 12);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion"; }

        Console::SetCursorPosition(48, 13);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme"; }

        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46, 14); cout << "----------------------------";
        Console::SetCursorPosition(48, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal "; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal "; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) {
            if (opcion == 3) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        moverSeleccion(key, opcion, 1, 3);
    }
}

void MenuDos::driverLogin(string& DNI, string& name, string& password)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Conductor > Iniciar Sesion";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
}

void MenuDos::driverOptions(int& opcion, string name, string placa, bool estado, float rating)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        Console::SetCursorPosition(50, 11); cout << "Conductor";
        Console::SetCursorPosition(46, 12); cout << "----------------------------";

        Console::SetCursorPosition(48, 13);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrar Viaje"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrar Viaje"; }

        Console::SetCursorPosition(48, 14);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver Carreras Hechas"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver Carreras Hechas"; }

        Console::SetCursorPosition(48, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cambiar a Disponible"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cambiar a Disponible"; }

        Console::SetCursorPosition(48, 16);
        if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver mis Ganancias"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver mis Ganancias"; }

        Console::SetCursorPosition(48, 17);
        if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }

        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46, 18); cout << "----------------------------";
        Console::SetCursorPosition(48, 19);
        if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cerrar sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cerrar sesion"; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) {
            if (opcion == 6) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        moverSeleccion(key, opcion, 1, 6);
    }
}

void MenuDos::driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Conductor > Registrar Viaje";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    cin >> std::ws;
    Console::SetCursorPosition(48, y++); cout << "Origen   : "; std::getline(cin, partida);
    Console::SetCursorPosition(48, y++); cout << "Destino  : "; std::getline(cin, llegada);

    int yT = y;
    Console::SetCursorPosition(48, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
    while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
        Console::SetCursorPosition(48, y); cout << "Error: Elija 1-3.         ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Console::SetCursorPosition(80, yT); cout << "   ";
        Console::SetCursorPosition(80, yT);
    }
    y++;

    int yKm = y;
    Console::SetCursorPosition(48, y++); cout << "Distancia (km): ";
    while (!(cin >> km) || km <= 0) {
        Console::SetCursorPosition(48, y); cout << "Error: Km > 0.            ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Console::SetCursorPosition(68, yKm); cout << "   ";
        Console::SetCursorPosition(68, yKm);
    }
}

void MenuDos::driverSingIn(string& DNI, string& name, string& password)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Conductor > Registro";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
}

void MenuDos::driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Conductor > Registrar Carro";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    Console::SetCursorPosition(48, y++); cout << "Placa           : "; cin >> placa;
    Console::SetCursorPosition(48, y++); cout << "Marca           : "; cin >> marca;
    Console::SetCursorPosition(48, y++); cout << "Modelo          : "; cin >> modelo;
    Console::SetCursorPosition(48, y++); cout << "Color           : "; cin >> color;
    Console::SetCursorPosition(48, y++); cout << "Anio            : "; cin >> ano;
}

void MenuDos::driverGains(int& option, Driver driver)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(50, y++); cout << "Conductor > Ganancias";
    Console::SetCursorPosition(46, y++); cout << "----------------------------";
    Console::SetCursorPosition(48, y++); cout << "Viajes          : "; std::cout << driver.getTotalTrips();
    Console::SetCursorPosition(48, y++); cout << "Ganancia Bruta  : "; std::cout << driver.getTotalEarnings();
    Console::SetCursorPosition(48, y++); cout << "Comision (20%)  : "; std::cout << driver.getTotalEarnings() * 0.20f;
    Console::SetCursorPosition(48, y++); cout << "Ganancia Neta   : "; std::cout << driver.getNetEarnings();
    y++;
    Console::SetCursorPosition(48, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(61, y - 1); cin >> option;
}

void MenuDos::driverProfile(int& option, Driver driver)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(52, y++); cout << "Conductor > Perfil";
    Console::SetCursorPosition(52, y++); cout << "-------------------------";
    driver.mostrar(52, y);
    y++;
    Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(65, y - 1); cin >> option;
}

void MenuDos::tripHistory(int& option, Trip trips[], int s, string title)
{
    limpiarPantalla();
    lynx();
    int y = 11;
    Console::SetCursorPosition(52, y++); cout << "Lynx > " << title << " > Historial";
    Console::SetCursorPosition(52, y++); cout << "------------------------------------";
    if (s == 0 || trips == nullptr) {
        Console::SetCursorPosition(52, y++); cout << "No hay registros disponibles.";
    }
    else {
        for (int i = 0; i < s; i++) {
            trips[i].mostrar(52, y);
            y++;
            if (y > 20 && i + 1 < s) {
                Console::SetCursorPosition(52, y++); cout << "-- Presione una tecla para mas --";
                _getch();
                limpiarPantalla();
                lynx();
                y = 11;
                Console::SetCursorPosition(52, y++); cout << "Lynx > " << title << " > Historial (cont.)";
                Console::SetCursorPosition(52, y++); cout << "------------------------------------";
            }
        }
    }
    y++;
    Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(65, y - 1); cin >> option;
}

void MenuDos::LYNX()
{
    Console::SetWindowSize(160, 30);
    prepararDirectorioTrabajo();

    FileManager fileManager;
    AuthManager authMgr;
    TripManager tripMgr;
    AdministratorMenu admin(&authMgr, &tripMgr);

    cargarDatos(fileManager, authMgr, tripMgr);

    int option = 0;
    int tipo = 0;
    float km = 0.0f;
    string password = "", DNI = "", name = "", origen = "", destino = "";
    string partida = "", llegada = "";
    string placa = "", marca = "", color = "", modelo = "";
    int anio = 0;
    string currentPassengerDni = "";
    string currentDriverDni = "";

    do {
        principal(option);
        switch (option) {
        case 1:
            do {
                passengerMenu(option);
                switch (option) {
                case 1:
                {
                    passengerLogin(DNI, name, password);
                    if (!authMgr.loginUserValid(DNI, password)) {
                        mostrarMensaje("Datos incorrectos");
                        option = 6;
                        break;
                    }

                    Passenger currentPassenger = authMgr.getUserByDni(DNI);
                    if (currentPassenger.getDni() == "" || currentPassenger.getName() != name) {
                        mostrarMensaje("Datos incorrectos");
                        option = 6;
                        break;
                    }

                    currentPassengerDni = DNI;

                    do {
                        passengerOptions(option);
                        switch (option) {
                        case 1:
                        {
                            passengerSendTrip(origen, destino, tipo, km);
                            if (origen.empty() || destino.empty() || tipo < 1 || tipo > 3 || km <= 0.0f) {
                                mostrarMensaje("Datos invalidos");
                                option = 6;
                                break;
                            }

                            string bestDriverDni = authMgr.findAvailableDriver();
                            string bestDriverName = "Por asignar";
                            if (!bestDriverDni.empty()) {
                                Driver bestDriver = authMgr.getDriverByDni(bestDriverDni);
                                bestDriverName = bestDriver.getName();
                            }

                            Trip preview;
                            preview.setTripId(generarTripId(tripMgr));
                            preview.setOrigin(origen);
                            preview.setDestination(destino);
                            preview.setTipe(tipo);
                            preview.setPassengerDni(currentPassengerDni);
                            preview.setDriverName(bestDriverName);
                            preview.setDate(fechaActual());
                            preview.setPrice(preview.calcPrice(tipo, km));
                            if (bestDriverDni.empty()) preview.setStatus("pendiente");
                            else preview.setStatus("en_curso");

                            do {
                                passengerConfirmTrip(option, origen, destino, tipo, preview);
                            } while (option < 1 || option > 2);

                            if (option == 1) {
                                if (bestDriverDni.empty()) {
                                    tripMgr.getWaitingQueue().enqueue(preview);
                                    guardarDatos(fileManager, authMgr, tripMgr);
                                    mostrarMensaje("[OK] Viaje solicitado!", "No hay conductor libre, quedo en espera.");
                                }
                                else {
                                    tripMgr.getActiveTrips().pushBack(preview);
                                    authMgr.driverAcceptRide(bestDriverDni, preview.getPrice());
                                    guardarDatos(fileManager, authMgr, tripMgr);
                                    mostrarMensaje("[OK] Viaje solicitado!", "Conductor asignado: " + bestDriverName);
                                }
                            }
                            else {
                                mostrarMensaje("[XX] Viaje cancelado");
                            }

                            option = 6;
                            break;
                        }
                        case 2:
                        {
                            Trip activeTrip = buscarViajeActivoDePasajero(tripMgr, currentPassengerDni);
                            if (activeTrip.getTripId() != "") {
                                int subOpt = 1;
                                while (subOpt != 0) {
                                    limpiarPantalla();
                                    lynx();
                                    int y = 11;
                                    Console::SetCursorPosition(48, y++); cout << "Viaje en curso";
                                    Console::SetCursorPosition(48, y++); cout << "--------------";
                                    activeTrip.mostrar(48, y);
                                    y++;
                                    Console::SetCursorPosition(48, y++); cout << "[0] - Volver";
                                    Console::SetCursorPosition(48, y - 1); cin >> subOpt;
                                }
                            }
                            else {
                                Trip pendingTrip = buscarViajePendienteDePasajero(tripMgr, currentPassengerDni);
                                if (pendingTrip.getTripId() != "") {
                                    int subOpt = 1;
                                    while (subOpt != 0) {
                                        limpiarPantalla();
                                        lynx();
                                        int y = 11;
                                        Console::SetCursorPosition(48, y++); cout << "Viaje pendiente";
                                        Console::SetCursorPosition(48, y++); cout << "---------------";
                                        pendingTrip.mostrar(48, y);
                                        y++;
                                        Console::SetCursorPosition(48, y++); cout << "[0] - Volver";
                                        Console::SetCursorPosition(48, y - 1); cin >> subOpt;
                                    }
                                }
                                else {
                                    mostrarMensaje("No hay viaje activo.");
                                }
                            }
                            option = 6;
                            break;
                        }
                        case 3:
                        {
                            vector<Trip> historial = historialDePasajero(tripMgr, currentPassengerDni);
                            int historyOption = 1;
                            while (historyOption != 0) {
                                tripHistory(historyOption, historial.empty() ? nullptr : historial.data(), (int)historial.size(), "Pasajero");
                            }
                            option = 6;
                            break;
                        }
                        case 4:
                        {
                            Trip ultimo = tripMgr.getLastTripByPassenger(currentPassengerDni);
                            if (ultimo.getTripId() == "" || ultimo.getDriverName() == "") {
                                mostrarMensaje("No hay conductor para calificar");
                                option = 6;
                                break;
                            }

                            int ratingOption = -1;
                            do {
                                limpiarPantalla();
                                lynx();
                                int y = 11;
                                Console::SetCursorPosition(48, y++); cout << "Calificar Conductor";
                                Console::SetCursorPosition(48, y++); cout << "-------------------";
                                Console::SetCursorPosition(48, y++); cout << "[1] - * Muy malo";
                                Console::SetCursorPosition(48, y++); cout << "[2] - ** Malo";
                                Console::SetCursorPosition(48, y++); cout << "[3] - *** Regular";
                                Console::SetCursorPosition(48, y++); cout << "[4] - **** Bueno";
                                Console::SetCursorPosition(48, y++); cout << "[5] - ***** Excelente";
                                Console::SetCursorPosition(48, y++); cout << "[0] - Omitir";
                                Console::SetCursorPosition(48, y++); cout << "Opcion: "; cin >> ratingOption;
                            } while (ratingOption < 0 || ratingOption > 5);

                            if (ratingOption > 0) {
                                string driverDni = buscarDniConductorPorNombre(authMgr, ultimo.getDriverName());
                                if (!driverDni.empty()) {
                                    Passenger current = authMgr.getUserByDni(currentPassengerDni);
                                    authMgr.updateDriverRating(driverDni, current.rateDriver(ratingOption));
                                    guardarDatos(fileManager, authMgr, tripMgr);
                                    mostrarMensaje("[OK] Calificacion guardada");
                                }
                                else {
                                    mostrarMensaje("No se encontro al conductor");
                                }
                            }

                            option = 6;
                            break;
                        }
                        case 5:
                        {
                            Passenger current = authMgr.getUserByDni(currentPassengerDni);
                            int profileOption = 1;
                            while (profileOption != 0) {
                                passengerProfile(profileOption, current);
                            }
                            option = 6;
                            break;
                        }
                        }
                    } while (option != 0);

                    option = 6;
                    break;
                }
                case 2:
                {
                    do {
                        passengerSignIn(DNI, name, password);
                    } while (DNI.empty() || password.empty() || name.empty());

                    if (!authMgr.validateDni(DNI)) {
                        mostrarMensaje("DNI invalido", "Debe tener 8 digitos.");
                        option = 6;
                        break;
                    }

                    if (!authMgr.registerPassenger(name, DNI, password)) {
                        mostrarMensaje("No se pudo crear la cuenta", "El DNI ya esta registrado.");
                        option = 6;
                        break;
                    }

                    guardarDatos(fileManager, authMgr, tripMgr);
                    mostrarMensaje("Cuenta creada exitosamente.");
                    option = 6;
                    break;
                }
                }
            } while (option != 0);
            break;

        case 2:
            do {
                driverMenu(option);
                switch (option) {
                case 1:
                {
                    driverLogin(DNI, name, password);
                    if (!authMgr.loginDriverValid(DNI, password)) {
                        mostrarMensaje("Datos incorrectos");
                        option = 6;
                        break;
                    }

                    Driver currentDriver = authMgr.getDriverByDni(DNI);
                    if (currentDriver.getDni() == "" || currentDriver.getName() != name) {
                        mostrarMensaje("Datos incorrectos");
                        option = 6;
                        break;
                    }

                    currentDriverDni = DNI;

                    do {
                        Driver menuDriver = authMgr.getDriverByDni(currentDriverDni);
                        driverOptions(option, menuDriver.getName(), menuDriver.getVehicle().getPlate(), menuDriver.getIsAvailable(), menuDriver.getRating());
                        switch (option) {
                        case 1:
                        {
                            driverRegisterTrip(partida, llegada, km, tipo);
                            if (partida.empty() || llegada.empty() || km <= 0.0f || tipo < 1 || tipo > 3) {
                                mostrarMensaje("Datos invalidos");
                                option = 7;
                                break;
                            }

                            Driver current = authMgr.getDriverByDni(currentDriverDni);
                            Trip nuevo;
                            nuevo.setTripId(generarTripId(tripMgr));
                            nuevo.setOrigin(partida);
                            nuevo.setDestination(llegada);
                            nuevo.setTipe(tipo);
                            nuevo.setPassengerDni("");
                            nuevo.setDriverName(current.getName());
                            nuevo.setDate(fechaActual());
                            nuevo.setPrice(nuevo.calcPrice(tipo, km));
                            nuevo.setStatus("completado");

                            authMgr.driverAcceptRide(currentDriverDni, nuevo.getPrice());
                            authMgr.driverFinishRide(currentDriverDni);
                            tripMgr.getHistory().push(nuevo);
                            guardarDatos(fileManager, authMgr, tripMgr);

                            mostrarMensaje("[OK] Viaje registrado");
                            option = 7;
                            break;
                        }
                        case 2:
                        {
                            Driver current = authMgr.getDriverByDni(currentDriverDni);
                            vector<Trip> historial = historialDeConductor(tripMgr, current.getName());
                            int historyOption = 1;
                            while (historyOption != 0) {
                                tripHistory(historyOption, historial.empty() ? nullptr : historial.data(), (int)historial.size(), "Conductor");
                            }
                            option = 7;
                            break;
                        }
                        case 3:
                            authMgr.setDriverAvailability(currentDriverDni, true);
                            guardarDatos(fileManager, authMgr, tripMgr);
                            mostrarMensaje("[OK] Estado actualizado", "Ahora estas disponible.");
                            option = 7;
                            break;

                        case 4:
                        {
                            int gainsOption = 1;
                            while (gainsOption != 0) {
                                driverGains(gainsOption, authMgr.getDriverByDni(currentDriverDni));
                            }
                            option = 7;
                            break;
                        }
                        case 5:
                        {
                            int profileOption = 1;
                            while (profileOption != 0) {
                                driverProfile(profileOption, authMgr.getDriverByDni(currentDriverDni));
                            }
                            option = 7;
                            break;
                        }
                        }
                    } while (option != 0);

                    option = 6;
                    break;
                }
                case 2:
                {
                    do {
                        driverSingIn(DNI, name, password);
                    } while (DNI.empty() || password.empty() || name.empty());

                    if (!authMgr.validateDni(DNI)) {
                        mostrarMensaje("DNI invalido", "Debe tener 8 digitos.");
                        option = 6;
                        break;
                    }

                    do {
                        driverRegisterCar(placa, marca, modelo, color, anio);
                    } while (placa.empty() || marca.empty() || modelo.empty() || color.empty() || anio < 2005 || anio > 2026);

                    Vehicle vehicle(placa, marca, modelo, color, anio);

                    if (!authMgr.registerDriver(name, DNI, password, vehicle)) {
                        mostrarMensaje("No se pudo crear la cuenta", "El DNI ya esta registrado.");
                        option = 6;
                        break;
                    }

                    guardarDatos(fileManager, authMgr, tripMgr);
                    mostrarMensaje("Cuenta de conductor creada.");
                    option = 6;
                    break;
                }
                }
            } while (option != 0);
            break;

        case 3:
            do {
                admin.run(option);
                switch (option) {
                case 1:
                    admin.listarUsuarios();
                    option = 8;
                    break;

                case 2:
                    admin.listarConductores();
                    option = 8;
                    break;

                case 3:
                    admin.listarViajes();
                    option = 8;
                    break;

                case 4:
                    admin.buscarUsuario();
                    option = 8;
                    break;

                case 5:
                    admin.ordenarConductores();
                    option = 8;
                    break;

                case 6:
                    admin.topConductores();
                    option = 8;
                    break;

                case 7:
                    admin.estadisticas();
                    option = 8;
                    break;
                }
            } while (option != 0);
            break;
        }
    } while (option != 4);

    guardarDatos(fileManager, authMgr, tripMgr);
    mostrarMensaje("Hasta la proxima");
}
