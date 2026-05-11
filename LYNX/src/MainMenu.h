#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <ctime>
#include "Driver.h"
#include "Passenger.h"
#include "Trip.h"
#include "AdministratorMenu.h"
#include "../include/FileManager.h"

using namespace System;
using std::vector; using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

class Menu
{
public:
    Menu();
    ~Menu();

    void lynx();
    void navBar();
    void navBarP();
    void navBarC();
    void navBarA();
    void navName(string name);

    void principal(int& opcion);
    void passengerMenu(int& opcion);
    void passengerLogin(string& DNI, string& name, string& password);
    void passengerSignIn(string& DNI, string& name, string& password);
    void passengerOptions(int& opcion, Passenger passenger);
    void passengerSendTrip(string& origen, string& destino, int& tipo, float& km, Passenger passenger);
    void passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip, Passenger passenger);
    void passengerProfile(int& option, Passenger passenger);

    void driverMenu(int& opcion);
    void driverLogin(string& DNI, string& name, string& password);
    void driverOptions(int& opcion, string name, string placa, bool estado, float rating, Driver driver);
    void driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo, Driver driver);
    void driverSingIn(string& DNI, string& name, string& password);
    void driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano, Driver driver);
    void driverGains(int& option, Driver driver);
    void driverProfile(int& option, Driver driver);

    void tripHistory(int& option, Trip trips[], int s, string title);

    void LYNX();

private:
    void Seleccion(int keycode, int& inicio, int min, int max);
    void prepararDirectorioTrabajo();
    void limpiarPantalla();
    void mostrarMensaje(string titulo, string detalle = "");
    string fechaActual();
    string generarTripId(TripManager& tripMgr);
    string buscarDniConductorPorNombre(AuthManager& authMgr, const string& nombre);

    void cargarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr);
    void guardarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr);

    vector<Trip> exportarWaitingTrips(TripManager& tripMgr);
    vector<Trip> exportarActiveTrips(TripManager& tripMgr);
    vector<Trip> exportarHistoryTrips(TripManager& tripMgr);
    vector<Trip> exportarTodosLosTrips(TripManager& tripMgr);

    Trip buscarViajeActivoDePasajero(TripManager& tripMgr, const string& dni);
    Trip buscarViajeActivoDeConductor(TripManager& tripMgr, const string& driverName);
    Trip buscarViajePendienteDePasajero(TripManager& tripMgr, const string& dni);
    vector<Trip> historialDePasajero(TripManager& tripMgr, const string& dni);
    vector<Trip> historialDeConductor(TripManager& tripMgr, const string& driverName);

    void showPassengerSidebar(Passenger passenger);
    void showDriverSidebar(Driver driver);
};

Menu::Menu() {}
Menu::~Menu() {}

void Menu::Seleccion(int keycode, int& inicio, int min, int max)
{
    switch (keycode) {
    case 72: if (inicio > min) inicio--; break;
    case 80: if (inicio < max) inicio++; break;
    }
}

void Menu::prepararDirectorioTrabajo() {}
void Menu::limpiarPantalla() { std::system("cls"); }

void Menu::mostrarMensaje(string titulo, string detalle)
{
    limpiarPantalla();
    lynx();
    Console::SetCursorPosition(48 + 18, 11); cout << titulo;
    if (!detalle.empty()) {
        Console::SetCursorPosition(48 + 18, 13); cout << detalle;
    }
    Console::SetCursorPosition(48 + 18, 15); cout << "Presione una tecla para continuar...";
    _getch();
}

string Menu::fechaActual()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime{};
    localtime_s(&localTime, &now);
    char buffer[16];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", &localTime);
    return buffer;
}

string Menu::generarTripId(TripManager& tripMgr)
{
    int total = tripMgr.getTotalWaiting() + tripMgr.getTotalActiveTrips() + tripMgr.getTotalHistoryTrips() + 1;
    return "TRP-" + to_string(10000 + total);
}

string Menu::buscarDniConductorPorNombre(AuthManager& authMgr, const string& nombre)
{
    for (int i = 0; i < authMgr.getDriverList()->getSize(); i++) {
        Driver d = authMgr.getDriverList()->get(i);
        if (d.getName() == nombre) return d.getDni();
    }
    return "";
}

vector<Trip> Menu::exportarWaitingTrips(TripManager& tripMgr)
{
    vector<Trip> lista;
    tripMgr.getWaitingQueue().forEach([&](Trip t) {
        lista.push_back(t);
        });
    return lista;
}

vector<Trip> Menu::exportarActiveTrips(TripManager& tripMgr)
{
    vector<Trip> lista;
    for (int i = 0; i < tripMgr.getActiveTrips().getSize(); i++) {
        lista.push_back(tripMgr.getActiveTrips().get(i));
    }
    return lista;
}

vector<Trip> Menu::exportarHistoryTrips(TripManager& tripMgr)
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

vector<Trip> Menu::exportarTodosLosTrips(TripManager& tripMgr)
{
    vector<Trip> total = exportarWaitingTrips(tripMgr);
    vector<Trip> activos = exportarActiveTrips(tripMgr);
    vector<Trip> historial = exportarHistoryTrips(tripMgr);
    total.insert(total.end(), activos.begin(), activos.end());
    total.insert(total.end(), historial.begin(), historial.end());
    return total;
}

void Menu::cargarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr)
{
    vector<Trip> tripsCargados = fileManager.leerTripsTXT();
    vector<Trip> historial;
    for (int i = 0; i < (int)tripsCargados.size(); i++) {
        Trip t = tripsCargados[i];
        if (t.getStatus() == "pendiente") tripMgr.getWaitingQueue().enqueue(t);
        else if (t.getStatus() == "en_curso") tripMgr.getActiveTrips().pushBack(t);
        else historial.push_back(t);
    }
    for (int i = (int)historial.size() - 1; i >= 0; i--) {
        tripMgr.getHistory().push(historial[i]);
    }
    tripMgr.rebuildTripCounter();
}

void Menu::guardarDatos(FileManager& fileManager, AuthManager& authMgr, TripManager& tripMgr)
{
    authMgr.saveAll();
    fileManager.guardarTripsTXT(exportarTodosLosTrips(tripMgr));
}

Trip Menu::buscarViajeActivoDePasajero(TripManager& tripMgr, const string& dni)
{
    for (int i = 0; i < tripMgr.getActiveTrips().getSize(); i++) {
        Trip t = tripMgr.getActiveTrips().get(i);
        if (t.getPassengerDni() == dni) return t;
    }
    return Trip();
}

Trip Menu::buscarViajeActivoDeConductor(TripManager& tripMgr, const string& driverName)
{
    for (int i = 0; i < tripMgr.getActiveTrips().getSize(); i++) {
        Trip t = tripMgr.getActiveTrips().get(i);
        if (t.getDriverName() == driverName) return t;
    }
    return Trip();
}

Trip Menu::buscarViajePendienteDePasajero(TripManager& tripMgr, const string& dni)
{
    Trip encontrado;
    tripMgr.getWaitingQueue().forEach([&](Trip t) {
        if (encontrado.getTripId() == "" && t.getPassengerDni() == dni) encontrado = t;
        });
    return encontrado;
}

vector<Trip> Menu::historialDePasajero(TripManager& tripMgr, const string& dni)
{
    vector<Trip> lista;
    vector<Trip> historial = exportarTodosLosTrips(tripMgr);
    for (int i = 0; i < (int)historial.size(); i++) {
        if (historial[i].getPassengerDni() == dni) lista.push_back(historial[i]);
    }
    return lista;
}

vector<Trip> Menu::historialDeConductor(TripManager& tripMgr, const string& driverName)
{
    vector<Trip> lista;
    vector<Trip> historial = exportarHistoryTrips(tripMgr);
    for (int i = 0; i < (int)historial.size(); i++) {
        if (historial[i].getDriverName() == driverName) lista.push_back(historial[i]);
    }
    return lista;
}

void Menu::lynx()
{
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(63, 5); std::cout << (char)219 << (char)219 << "     " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(63, 6); std::cout << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(63, 7); std::cout << (char)219 << (char)219 << "       " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(63, 8); std::cout << (char)219 << (char)219 << "        " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
    Console::SetCursorPosition(63, 9); std::cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::navBar() {
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 1); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 2); std::cout << "                                                                                                                                                                ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(3, 1); std::cout << "LYNX";
    Console::SetCursorPosition(20, 1); std::cout << "Pasajero";
    Console::SetCursorPosition(31, 1); std::cout << "Conductor";
    Console::SetCursorPosition(43, 1); std::cout << "Admin";
    Console::BackgroundColor = ConsoleColor::Black;
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::navBarP() {
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 1); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 2); std::cout << "                                                                                                                                                                ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(3, 1); std::cout << "LYNX";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(20, 1); std::cout << "Pasajero";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(31, 1); std::cout << "Conductor";
    Console::SetCursorPosition(43, 1); std::cout << "Admin";
    Console::BackgroundColor = ConsoleColor::Black;
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::navBarC() {
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 1); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 2); std::cout << "                                                                                                                                                                ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(3, 1); std::cout << "LYNX";
    Console::SetCursorPosition(20, 1); std::cout << "Pasajero";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(31, 1); std::cout << "Conductor";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(43, 1); std::cout << "Admin";
    Console::BackgroundColor = ConsoleColor::Black;
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::navBarA() {
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 1); std::cout << "                                                                                                                                                                ";
    Console::SetCursorPosition(0, 2); std::cout << "                                                                                                                                                                ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(3, 1); std::cout << "LYNX";
    Console::SetCursorPosition(20, 1); std::cout << "Pasajero";
    Console::SetCursorPosition(31, 1); std::cout << "Conductor";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(43, 1); std::cout << "Admin";
    Console::BackgroundColor = ConsoleColor::Black;
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::navName(string name) {
    Console::BackgroundColor = ConsoleColor::White;
    Console::ForegroundColor = ConsoleColor::Black;
    Console::SetCursorPosition(140, 1); std::cout << name;
    Console::BackgroundColor = ConsoleColor::Black;
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::showPassengerSidebar(Passenger passenger) {
    int y = 7, dy = 9;
    Console::ForegroundColor = ConsoleColor::Gray;
    Console::SetCursorPosition(130, y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "           Perfil           " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(130, y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    passenger.mostrar(131, dy);
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::showDriverSidebar(Driver driver) {
    int y = 7, dy = 9, x = 128;
    Console::ForegroundColor = ConsoleColor::Gray;
    Console::SetCursorPosition(x, y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "           Perfil           " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << "                            " << (char)219;
    Console::SetCursorPosition(x, y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    driver.mostrar(x + 2, dy);
    Console::ForegroundColor = ConsoleColor::White;
}

void Menu::principal(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        navBar();
        Console::SetCursorPosition(52 + 18, 11);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Soy pasajero <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Soy pasajero"; }

        Console::SetCursorPosition(52 + 18, 12);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << ">> Soy conductor <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Soy conductor"; }

        Console::SetCursorPosition(52 + 18, 13);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Administracion <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Administracion"; }

        Console::SetCursorPosition(52 + 18, 14);
        if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << ">> Salir <<"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "Salir"; }

        Console::ForegroundColor = ConsoleColor::White;

        int key = _getch();
        if (key == 13) return;
        if (key == 0 || key == 224) key = _getch();
        Seleccion(key, opcion, 1, 4);
    }
}

void Menu::passengerMenu(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla();
        lynx();
        navBarP();
        Console::SetCursorPosition(46 + 18, 12); cout << "----------------------------";
        Console::SetCursorPosition(50 + 18, 13);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion"; }
        Console::SetCursorPosition(50 + 18, 14);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme"; }

        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46 + 18, 15); cout << "----------------------------";
        Console::SetCursorPosition(50 + 18, 16);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal "; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal "; }

        Console::ForegroundColor = ConsoleColor::White;
        int key = _getch();
        if (key == 13) {
            if (opcion == 3) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        Seleccion(key, opcion, 1, 3);
    }
}

void Menu::passengerLogin(string& DNI, string& name, string& password)
{
    limpiarPantalla(); lynx(); navBarP(); int y = 11;
    Console::SetCursorPosition(54 + 18, y++); cout << "Iniciar Sesion";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    Console::SetCursorPosition(48 + 18, y++); cout << "DNI             : "; cin >> DNI; cin.ignore();
    Console::SetCursorPosition(48 + 18, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48 + 18, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::passengerSignIn(string& DNI, string& name, string& password)
{
    limpiarPantalla(); lynx(); navBarP(); int y = 11;
    Console::SetCursorPosition(54 + 18, y++); cout << "Registro";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    Console::SetCursorPosition(48 + 18, y++); cout << "DNI             : "; cin >> DNI; cin.ignore();
    Console::SetCursorPosition(48 + 18, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48 + 18, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::passengerOptions(int& opcion, Passenger passenger)
{
    opcion = 1;
    while (true) {
        limpiarPantalla(); lynx(); navBarP(); navName(passenger.getName());
        showPassengerSidebar(passenger);
        Console::SetCursorPosition(46 + 18, 12); cout << "----------------------------";
        Console::SetCursorPosition(48 + 18, 13);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Solicitar un viaje"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Solicitar un viaje"; }
        Console::SetCursorPosition(48 + 18, 14);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver viaje activo"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver viaje activo"; }
        Console::SetCursorPosition(48 + 18, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Historial de viajes"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Historial de viajes"; }
        Console::SetCursorPosition(48 + 18, 16);
        if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Calificar ultimo conductor"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Calificar ultimo conductor"; }
        Console::SetCursorPosition(48 + 18, 17);
        if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46 + 18, 18); cout << "----------------------------";
        Console::SetCursorPosition(48 + 18, 19);
        if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cerrar sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cerrar sesion"; }
        Console::ForegroundColor = ConsoleColor::White;
        int key = _getch();
        if (key == 13) {
            if (opcion == 6) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        Seleccion(key, opcion, 1, 6);
    }
}

void Menu::passengerSendTrip(string& origen, string& destino, int& tipo, float& km, Passenger passenger)
{
    limpiarPantalla(); lynx(); navBarP(); navName(passenger.getName());
    showPassengerSidebar(passenger);
    int y = 11;
    Console::SetCursorPosition(53 + 18, y++); cout << "Solicitar Viaje";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    cin.ignore();
    Console::SetCursorPosition(48 + 18, y++); cout << "Origen   : "; std::getline(cin, origen);
    Console::SetCursorPosition(48 + 18, y++); cout << "Destino  : "; std::getline(cin, destino);
    int yPrompt = y;
    Console::SetCursorPosition(48 + 18, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
    while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
        Console::SetCursorPosition(48 + 18, y); cout << "Error: Elija 1-3.         ";
        cin.clear(); cin.ignore(10000, '\n');
        Console::SetCursorPosition(80 + 18, yPrompt); cout << "   "; Console::SetCursorPosition(80 + 18, yPrompt);
    }
    y++; int yKm = y;
    Console::SetCursorPosition(48 + 18, y++); cout << "Distancia (km): ";
    while (!(cin >> km) || km <= 0) {
        Console::SetCursorPosition(48 + 18, y); cout << "Error: Ingrese un dato valido (km > 0)";
        cin.clear(); cin.ignore(10000, '\n');
        Console::SetCursorPosition(64 + 18, yKm); cout << "                             "; Console::SetCursorPosition(64 + 18, yKm);
    }
}

void Menu::passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip, Passenger passenger)
{
    opcion = 1;
    while (true) {
        limpiarPantalla(); lynx(); navBarP(); navName(passenger.getName());
        showPassengerSidebar(passenger);
        int y = 11;
        Console::SetCursorPosition(55 + 18, y++); cout << "Confirmar Viaje";
        Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
        trip.mostrar(52 + 18, y); y += 6;
        Console::SetCursorPosition(48 + 18, y);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Confirmar viaje"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Confirmar viaje"; }
        Console::SetCursorPosition(48 + 18, y + 1);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cancelar"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cancelar"; }
        Console::ForegroundColor = ConsoleColor::White;
        int key = _getch();
        if (key == 13) return;
        if (key == 0 || key == 224) key = _getch();
        Seleccion(key, opcion, 1, 2);
    }
}

void Menu::passengerProfile(int& option, Passenger passenger)
{
    limpiarPantalla(); lynx(); navBarP(); navName(passenger.getName());
    showPassengerSidebar(passenger);
    int y = 11;
    Console::SetCursorPosition(50 + 18, y++); cout << "Perfil";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    passenger.mostrar(48 + 18, y); y += 6;
    Console::SetCursorPosition(48 + 18, y++); cout << "[1] - Actualizar Datos";
    Console::SetCursorPosition(48 + 18, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(48 + 18, y++); cout << "Opcion: ";
    Console::SetCursorPosition(56 + 18, y - 1); cin >> option;
}

void Menu::driverMenu(int& opcion)
{
    opcion = 1;
    while (true) {
        limpiarPantalla(); lynx(); navBarC();
        Console::SetCursorPosition(46 + 18, 11); cout << "----------------------------";
        Console::SetCursorPosition(48 + 18, 12);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion"; }
        Console::SetCursorPosition(48 + 18, 13);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme"; }
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46 + 18, 14); cout << "----------------------------";
        Console::SetCursorPosition(48 + 18, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal "; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal "; }
        Console::ForegroundColor = ConsoleColor::White;
        int key = _getch();
        if (key == 13) {
            if (opcion == 3) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        Seleccion(key, opcion, 1, 3);
    }
}

void Menu::driverLogin(string& DNI, string& name, string& password)
{
    limpiarPantalla(); lynx(); navBarC(); int y = 11;
    Console::SetCursorPosition(54 + 18, y++); cout << "Iniciar Sesion";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    Console::SetCursorPosition(48 + 18, y++); cout << "DNI             : "; cin >> DNI; cin.ignore();
    Console::SetCursorPosition(48 + 18, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48 + 18, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::driverOptions(int& opcion, string name, string placa, bool estado, float rating, Driver driver)
{
    opcion = 1;
    while (true) {
        limpiarPantalla(); lynx(); navBarC(); navName(driver.getName());
        showDriverSidebar(driver);
        Console::SetCursorPosition(46 + 18, 12); cout << "----------------------------";
        Console::SetCursorPosition(48 + 18, 13);
        if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrar Viaje Manual"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrar Viaje Manual"; }
        Console::SetCursorPosition(48 + 18, 14);
        if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver Carreras Hechas"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver Carreras Hechas"; }
        Console::SetCursorPosition(48 + 18, 15);
        if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cambiar a Disponible / Finalizar Viaje"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cambiar a Disponible / Finalizar Viaje"; }
        Console::SetCursorPosition(48 + 18, 16);
        if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver mis Ganancias"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver mis Ganancias"; }
        Console::SetCursorPosition(48 + 18, 17);
        if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(46 + 18, 18); cout << "----------------------------";
        Console::SetCursorPosition(48 + 18, 19);
        if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cerrar sesion"; }
        else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cerrar sesion"; }
        Console::ForegroundColor = ConsoleColor::White;
        int key = _getch();
        if (key == 13) {
            if (opcion == 6) opcion = 0;
            return;
        }
        if (key == 0 || key == 224) key = _getch();
        Seleccion(key, opcion, 1, 6);
    }
}

void Menu::driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo, Driver driver)
{
    limpiarPantalla(); lynx(); navBarC(); navName(driver.getName());
    showDriverSidebar(driver);
    int y = 11;
    Console::SetCursorPosition(53 + 18, y++); cout << "Registrar Viaje";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    cin.ignore();
    Console::SetCursorPosition(48 + 18, y++); cout << "Origen   : "; std::getline(cin, partida);
    Console::SetCursorPosition(48 + 18, y++); cout << "Destino  : "; std::getline(cin, llegada);
    int yT = y; Console::SetCursorPosition(48 + 18, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
    while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
        Console::SetCursorPosition(48 + 18, y); cout << "Error: Elija 1-3.         ";
        cin.clear(); cin.ignore(10000, '\n');
        Console::SetCursorPosition(80 + 18, yT); cout << "   "; Console::SetCursorPosition(80 + 18, yT);
    }
    y++; int yKm = y; Console::SetCursorPosition(48 + 18, y++); cout << "Distancia (km): ";
    while (!(cin >> km) || km <= 0) {
        Console::SetCursorPosition(48 + 18, y); cout << "Error: Km > 0.            ";
        cin.clear(); cin.ignore(10000, '\n');
        Console::SetCursorPosition(68 + 18, yKm); cout << "   "; Console::SetCursorPosition(68 + 18, yKm);
    }
}

void Menu::driverSingIn(string& DNI, string& name, string& password)
{
    limpiarPantalla(); lynx(); navBarC(); int y = 11;
    Console::SetCursorPosition(50 + 18, y++); cout << "Registro";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    Console::SetCursorPosition(48 + 18, y++); cout << "DNI             : "; cin >> DNI; cin.ignore();
    Console::SetCursorPosition(48 + 18, y++); cout << "Nombre Completo : "; std::getline(cin, name);
    Console::SetCursorPosition(48 + 18, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano, Driver driver)
{
    limpiarPantalla(); lynx(); navBarC(); navName(driver.getName());
    showDriverSidebar(driver);
    int y = 11;
    Console::SetCursorPosition(50 + 18, y++); cout << "Registrar Carro";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    Console::SetCursorPosition(48 + 18, y++); cout << "Placa           : "; cin >> placa;
    Console::SetCursorPosition(48 + 18, y++); cout << "Marca           : "; cin >> marca;
    Console::SetCursorPosition(48 + 18, y++); cout << "Modelo          : "; cin >> modelo;
    Console::SetCursorPosition(48 + 18, y++); cout << "Color           : "; cin >> color;
    Console::SetCursorPosition(48 + 18, y++); cout << "Anio            : "; cin >> ano;
}

void Menu::driverGains(int& option, Driver driver)
{
    limpiarPantalla(); lynx(); navBarC(); navName(driver.getName());
    showDriverSidebar(driver);
    int y = 11;
    Console::SetCursorPosition(50 + 18, y++); cout << "Ganancias";
    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
    Console::SetCursorPosition(48 + 18, y++); cout << "Viajes          : "; std::cout << driver.getTotalTrips();
    Console::SetCursorPosition(48 + 18, y++); cout << "Ganancia Bruta  : "; std::cout << driver.getTotalEarnings();
    Console::SetCursorPosition(48 + 18, y++); cout << "Comision (20%)  : "; std::cout << driver.getTotalEarnings() * 0.20f;
    Console::SetCursorPosition(48 + 18, y++); cout << "Ganancia Neta   : "; std::cout << driver.getNetEarnings();
    y++; Console::SetCursorPosition(48 + 18, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(61 + 18, y - 1); cin >> option;
}

void Menu::driverProfile(int& option, Driver driver)
{
    limpiarPantalla(); lynx(); navBarC(); navName(driver.getName());
    showDriverSidebar(driver);
    int y = 11;
    Console::SetCursorPosition(52 + 18, y++); cout << "Perfil";
    Console::SetCursorPosition(52 + 18, y++); cout << "-------------------------";
    driver.mostrar(52 + 18, y); y += 6;
    Console::SetCursorPosition(52 + 18, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(65 + 18, y - 1); cin >> option;
}

void Menu::tripHistory(int& option, Trip trips[], int s, string title)
{
    limpiarPantalla(); lynx(); int y = 11;
    Console::SetCursorPosition(52 + 18, y++); cout << "Lynx > " << title << " > Historial";
    Console::SetCursorPosition(52 + 18, y++); cout << "------------------------------------";
    if (s == 0 || trips == nullptr) {
        Console::SetCursorPosition(52 + 18, y++); cout << "No hay registros disponibles.";
    }
    else {
        for (int i = 0; i < s; i++) {
            trips[i].mostrar(52 + 18, y);
            if (y > 20) {
                Console::SetCursorPosition(52 + 18, y++); cout << "-- Presione una tecla para mas --";
                _getch(); limpiarPantalla(); lynx(); y = 11;
                Console::SetCursorPosition(52 + 18, y++); cout << "Lynx > " << title << " > Historial (cont.)";
                Console::SetCursorPosition(52 + 18, y++); cout << "------------------------------------";
            }
        }
    }
    y++; Console::SetCursorPosition(52 + 18, y++); cout << "[0] - Volver";
    Console::SetCursorPosition(65 + 18, y - 1); cin >> option;
}

void Menu::LYNX()
{
    Console::CursorVisible = false;
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
                        mostrarMensaje("Datos incorrectos"); option = 6; break;
                    }
                    Passenger currentPassenger = authMgr.getUserByDni(DNI);
                    if (currentPassenger.getDni() == "" || currentPassenger.getName() != name) {
                        mostrarMensaje("Datos incorrectos"); option = 6; break;
                    }
                    currentPassengerDni = DNI;

                    do {
                        Passenger menuPassenger = authMgr.getUserByDni(currentPassengerDni);
                        passengerOptions(option, menuPassenger);
                        switch (option) {
                        case 1:
                        {
                            passengerSendTrip(origen, destino, tipo, km, menuPassenger);
                            if (origen.empty() || destino.empty() || tipo < 1 || tipo > 3 || km <= 0.0f) {
                                mostrarMensaje("Datos invalidos"); option = 6; break;
                            }
                            string bestDriverDni = tripMgr.matchBestDriver(authMgr);
                            if (bestDriverDni.empty()) bestDriverDni = authMgr.findAvailableDriver();
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

                            do { passengerConfirmTrip(option, origen, destino, tipo, preview, menuPassenger); } while (option < 1 || option > 2);

                            if (option == 1) {
                                Trip activeT;
                                while ((activeT = buscarViajeActivoDePasajero(tripMgr, currentPassengerDni)).getTripId() != "") {
                                    tripMgr.finishTrip(activeT.getTripId(), authMgr, currentPassengerDni);
                                    if (activeT.getDriverName() != "" && activeT.getDriverName() != "Por asignar") {
                                        string driverDni = buscarDniConductorPorNombre(authMgr, activeT.getDriverName());
                                        if (!driverDni.empty()) authMgr.driverFinishRide(driverDni);
                                    }
                                }
                                tripMgr.createTrip(origen, destino, tipo, km, bestDriverName, currentPassengerDni, fechaActual());
                                if (!bestDriverDni.empty()) {
                                    tripMgr.assignDriver(bestDriverDni, authMgr);
                                    guardarDatos(fileManager, authMgr, tripMgr);
                                    mostrarMensaje("[OK] Viaje solicitado!", "Conductor asignado: " + bestDriverName);
                                }
                                else {
                                    guardarDatos(fileManager, authMgr, tripMgr);
                                    mostrarMensaje("[OK] Viaje solicitado!", "No hay conductor libre, quedo en espera.");
                                }
                            }
                            else { mostrarMensaje("[XX] Viaje cancelado"); }
                            option = 6; break;
                        }
                        case 2:
                        {
                            Trip activeTrip = buscarViajeActivoDePasajero(tripMgr, currentPassengerDni);
                            if (activeTrip.getTripId() != "") {
                                int subOpt = 1;
                                while (subOpt != 0) {
                                    limpiarPantalla(); lynx(); navBarP(); navName(menuPassenger.getName());
                                    showPassengerSidebar(menuPassenger);
                                    int y = 11;
                                    Console::SetCursorPosition(48 + 18, y++); cout << "Viaje en curso";
                                    Console::SetCursorPosition(48 + 18, y++); cout << "--------------";
                                    activeTrip.mostrar(48 + 18, y); y += 6;
                                    Console::SetCursorPosition(48 + 18, y++); cout << "[0] - Volver";
                                    Console::SetCursorPosition(48 + 18, y - 1); cin >> subOpt;
                                }
                            }
                            else {
                                Trip pendingTrip = buscarViajePendienteDePasajero(tripMgr, currentPassengerDni);
                                if (pendingTrip.getTripId() != "") {
                                    int subOpt = 1;
                                    while (subOpt != 0) {
                                        limpiarPantalla(); lynx(); navBarP(); navName(menuPassenger.getName());
                                        showPassengerSidebar(menuPassenger);
                                        int y = 11;
                                        Console::SetCursorPosition(48 + 18, y++); cout << "Viaje pendiente";
                                        Console::SetCursorPosition(48 + 18, y++); cout << "---------------";
                                        pendingTrip.mostrar(48 + 18, y); y += 6;
                                        Console::SetCursorPosition(48 + 18, y++); cout << "[0] - Volver";
                                        Console::SetCursorPosition(48 + 18, y - 1); cin >> subOpt;
                                    }
                                }
                                else { mostrarMensaje("No hay viaje activo."); }
                            }
                            option = 6; break;
                        }
                        case 3:
                        {
                            vector<Trip> historial = historialDePasajero(tripMgr, currentPassengerDni);
                            int historyOption = 1;
                            while (historyOption != 0) {
                                tripHistory(historyOption, historial.empty() ? nullptr : historial.data(), (int)historial.size(), "Pasajero");
                            }
                            option = 6; break;
                        }
                        case 4:
                        {
                            Trip ultimo = tripMgr.getLastTripByPassenger(currentPassengerDni);
                            if (ultimo.getTripId() == "" || ultimo.getDriverName() == "" || ultimo.getDriverName() == "Por asignar") {
                                mostrarMensaje("No hay conductor valido para calificar");
                                option = 6; break;
                            }

                            int ratingOption = -1;
                            do {
                                limpiarPantalla(); lynx(); navBarP(); navName(menuPassenger.getName());
                                showPassengerSidebar(menuPassenger);
                                int y = 11;
                                Console::SetCursorPosition(48 + 18, y++); cout << "Calificar Conductor";
                                Console::SetCursorPosition(48 + 18, y++); cout << "-------------------";
                                Console::SetCursorPosition(48 + 18, y++); cout << "[1] - * Muy malo";
                                Console::SetCursorPosition(48 + 18, y++); cout << "[2] - ** Malo";
                                Console::SetCursorPosition(48 + 18, y++); cout << "[3] - *** Regular";
                                Console::SetCursorPosition(48 + 18, y++); cout << "[4] - **** Bueno";
                                Console::SetCursorPosition(48 + 18, y++); cout << "[5] - ***** Excelente";
                                Console::SetCursorPosition(48 + 18, y++); cout << "[0] - Omitir";
                                Console::SetCursorPosition(48 + 18, y++); cout << "Opcion: "; cin >> ratingOption;
                            } while (ratingOption < 0 || ratingOption > 5);

                            if (ratingOption > 0) {
                                string driverDni = buscarDniConductorPorNombre(authMgr, ultimo.getDriverName());
                                if (!driverDni.empty()) {
                                    Passenger p = authMgr.getUserByDni(currentPassengerDni);
                                    authMgr.updateDriverRating(driverDni, p.rateDriver(ratingOption));
                                    guardarDatos(fileManager, authMgr, tripMgr);
                                    mostrarMensaje("[OK] Calificacion guardada");
                                }
                                else { mostrarMensaje("No se encontro al conductor"); }
                            }
                            option = 6; break;
                        }
                        case 5:
                        {
                            int profileOption = 1;
                            while (profileOption != 0) {
                                Passenger current = authMgr.getUserByDni(currentPassengerDni);
                                passengerProfile(profileOption, current);
                                if (profileOption == 1) {
                                    string newName, newPass;
                                    limpiarPantalla(); lynx(); navBarP(); navName(current.getName());
                                    showPassengerSidebar(current);
                                    int y = 11;
                                    Console::SetCursorPosition(50 + 18, y++); cout << "Pasajero > Actualizar Datos";
                                    Console::SetCursorPosition(46 + 18, y++); cout << "----------------------------";
                                    cin.ignore();
                                    Console::SetCursorPosition(48 + 18, y++); cout << "Nuevo Nombre : "; std::getline(cin, newName);
                                    Console::SetCursorPosition(48 + 18, y++); cout << "Nueva Contra : "; cin >> newPass;
                                    if (!newName.empty() && !newPass.empty()) {
                                        authMgr.updatePassengerData(currentPassengerDni, newName, newPass);
                                        guardarDatos(fileManager, authMgr, tripMgr);
                                        name = newName;
                                        password = newPass;
                                        mostrarMensaje("[OK] Datos actualizados correctamente.");
                                    }
                                    else {
                                        mostrarMensaje("[XX] Datos invalidos.");
                                    }
                                }
                            }
                            option = 6; break;
                        }
                        }
                    } while (option != 0);
                    option = 6; break;
                }
                case 2:
                {
                    do { passengerSignIn(DNI, name, password); } while (DNI.empty() || password.empty() || name.empty());
                    if (!authMgr.validateDni(DNI)) { mostrarMensaje("DNI invalido", "Debe tener 8 digitos."); option = 6; break; }
                    if (!authMgr.registerPassenger(name, DNI, password)) { mostrarMensaje("No se pudo crear la cuenta", "El DNI ya esta registrado."); option = 6; break; }
                    guardarDatos(fileManager, authMgr, tripMgr);
                    mostrarMensaje("Cuenta creada exitosamente.");
                    option = 6; break;
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
                    if (!authMgr.loginDriverValid(DNI, password)) { mostrarMensaje("Datos incorrectos"); option = 6; break; }
                    Driver currentDriver = authMgr.getDriverByDni(DNI);
                    if (currentDriver.getDni() == "" || currentDriver.getName() != name) { mostrarMensaje("Datos incorrectos"); option = 6; break; }
                    currentDriverDni = DNI;

                    do {
                        Driver menuDriver = authMgr.getDriverByDni(currentDriverDni);
                        driverOptions(option, menuDriver.getName(), menuDriver.getVehicle().getPlate(), menuDriver.getIsAvailable(), menuDriver.getRating(), menuDriver);
                        switch (option) {
                        case 1:
                        {
                            driverRegisterTrip(partida, llegada, km, tipo, menuDriver);
                            if (partida.empty() || llegada.empty() || km <= 0.0f || tipo < 1 || tipo > 3) { mostrarMensaje("Datos invalidos"); option = 7; break; }

                            Driver current = authMgr.getDriverByDni(currentDriverDni);
                            Trip nuevo;
                            nuevo.setTripId(generarTripId(tripMgr));
                            nuevo.setOrigin(partida); nuevo.setDestination(llegada);
                            nuevo.setTipe(tipo); nuevo.setPassengerDni("");
                            nuevo.setDriverName(current.getName()); nuevo.setDate(fechaActual());
                            nuevo.setPrice(nuevo.calcPrice(tipo, km)); nuevo.setStatus("completado");

                            authMgr.driverAcceptRide(currentDriverDni, nuevo.getPrice());
                            authMgr.driverFinishRide(currentDriverDni);
                            tripMgr.getHistory().push(nuevo);
                            guardarDatos(fileManager, authMgr, tripMgr);
                            mostrarMensaje("[OK] Viaje manual registrado", "NOTA: Este viaje manual no afectara metricas de pasajeros.");
                            option = 7; break;
                        }
                        case 2:
                        {
                            Driver current = authMgr.getDriverByDni(currentDriverDni);
                            vector<Trip> historial = historialDeConductor(tripMgr, current.getName());
                            int historyOption = 1;
                            while (historyOption != 0) { tripHistory(historyOption, historial.empty() ? nullptr : historial.data(), (int)historial.size(), "Conductor"); }
                            option = 7; break;
                        }
                        case 3:
                        {
                            Driver current = authMgr.getDriverByDni(currentDriverDni);
                            Trip activo = buscarViajeActivoDeConductor(tripMgr, current.getName());

                            if (activo.getTripId() != "") {
                                tripMgr.finishTrip(activo.getTripId(), authMgr, activo.getPassengerDni());
                                authMgr.driverFinishRide(currentDriverDni);
                                guardarDatos(fileManager, authMgr, tripMgr);
                                mostrarMensaje("[OK] Viaje finalizado", "Ahora estas disponible.");
                            }
                            else {
                                authMgr.setDriverAvailability(currentDriverDni, true);
                                guardarDatos(fileManager, authMgr, tripMgr);
                                mostrarMensaje("[OK] Estado actualizado", "Ahora estas disponible.");
                            }
                            option = 7; break;
                        }
                        case 4:
                        {
                            int gainsOption = 1;
                            while (gainsOption != 0) { driverGains(gainsOption, authMgr.getDriverByDni(currentDriverDni)); }
                            option = 7; break;
                        }
                        case 5:
                        {
                            int profileOption = 1;
                            while (profileOption != 0) { driverProfile(profileOption, authMgr.getDriverByDni(currentDriverDni)); }
                            option = 7; break;
                        }
                        }
                    } while (option != 0);
                    option = 6; break;
                }
                case 2:
                {
                    do { driverSingIn(DNI, name, password); } while (DNI.empty() || password.empty() || name.empty());
                    if (!authMgr.validateDni(DNI)) { mostrarMensaje("DNI invalido", "Debe tener 8 digitos."); option = 6; break; }
                    do {
                        Driver dummy; dummy.setName(name); dummy.setDni(DNI);
                        driverRegisterCar(placa, marca, modelo, color, anio, dummy);
                    } while (placa.empty() || marca.empty() || modelo.empty() || color.empty() || anio < 2005 || anio > 2026);
                    Vehicle vehicle(placa, marca, modelo, color, anio);
                    if (!authMgr.registerDriver(name, DNI, password, vehicle)) { mostrarMensaje("No se pudo crear la cuenta", "El DNI ya esta registrado."); option = 6; break; }
                    guardarDatos(fileManager, authMgr, tripMgr);
                    mostrarMensaje("Cuenta de conductor creada.");
                    option = 6; break;
                }
                }
            } while (option != 0);
            break;

        case 3:
            do {
                admin.run(option);
                switch (option) {
                case 1: admin.listarUsuarios(); option = 8; break;
                case 2: admin.listarConductores(); option = 8; break;
                case 3: admin.listarViajes(); option = 8; break;
                case 4: admin.buscarUsuario(); option = 8; break;
                case 5: admin.ordenarConductores(); option = 8; break;
                case 6: admin.topConductores(); option = 8; break;
                case 7: admin.estadisticas(); option = 8; break;
                case 8: admin.ordenarPasajeros(); option = 13; break;
                case 9: admin.ordenarPasajerosPorId(); option = 13; break;
                case 10: admin.ordenarConductoresPorId(); option = 13; break;
                case 11: admin.ordenarViajesActivos(); option = 13; break;
                case 12: admin.verPasswordsBinarias(); option = 13; break;
                }
            } while (option != 0);
            break;
        }
    } while (option != 4);

    guardarDatos(fileManager, authMgr, tripMgr);
    mostrarMensaje("Hasta la proxima");
}
