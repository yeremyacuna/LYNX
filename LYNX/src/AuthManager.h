#pragma once
#include "../include/LinkedList.h"
#include "../include/Queue.h"
#include "Passenger.h"
#include "Driver.h"
#include "Trip.h"
#include <iostream>
#include <string>
using std::cout; using std::cin;

//  Guarda y gestiona las listas de pasajeros y conductores.
class AuthManager {
private:
    LinkedList<Passenger> userList;
    LinkedList<Driver>    driverList;

    // Busca la posicion de un pasajero por DNI
    int indexOfUser(string dni) {
        for (int i = 0; i < userList.getSize(); i++)
            if (userList.get(i).getDni() == dni) return i;
        return -1;
    }

    // Busca la posicion de un conductor por DNI
    int indexOfDriver(string dni) {
        for (int i = 0; i < driverList.getSize(); i++)
            if (driverList.get(i).getDni() == dni) return i;
        return -1;
    }

public:
    AuthManager() {}

    LinkedList<Passenger>& getUserList() { return userList; }
    LinkedList<Driver>& getDriverList() { return driverList; }
    int getTotalUsers() { return userList.getSize(); }
    int getTotalDrivers() { return driverList.getSize(); }

    // PASAJEROS

    bool userExists(string dni) { return indexOfUser(dni) != -1; }

    // Registra pasajero nuevo si el DNI no existe
    bool registerUser(string name, string dni, string password) {
        if (userExists(dni)) { cout << "  [!] DNI ya registrado.\n"; return false; }
        userList.pushBack(Passenger(name, dni, password));
        cout << "  [OK] Pasajero registrado.\n";
        return true;
    }

    // Valida credenciales
    bool loginUserValid(string dni, string password) {
        int i = indexOfUser(dni);
        if (i == -1) return false;
        return userList.get(i).login(dni, password);
    }

    // Devuelve copia del pasajero por DNI
    Passenger getUserByDni(string dni) {
        int i = indexOfUser(dni);
        if (i == -1) return Passenger();
        return userList.get(i);
    }

    // Registra un viaje al pasajero y lo actualiza en la lista
    void addTripToUser(string dni, float precio) {
        int i = indexOfUser(dni);
        if (i == -1) return;
        Passenger p = userList.get(i);
        p.addTrip(precio);
        userList.remove(i);
        userList.insert(i, p);
    }

    // Actualiza el rating
    void updateUserRating(string dni, float nuevaCalif) {
        int i = indexOfUser(dni);
        if (i == -1) return;
        Passenger p = userList.get(i);
        p.updateRating(nuevaCalif);
        userList.remove(i);
        userList.insert(i, p);
    }

    // CONDUCTORES

    bool driverExists(string dni) { return indexOfDriver(dni) != -1; }

    // Registra conductor nuevo con su vehiculo
    bool registerDriver(string name, string dni, string password, Vehicle vehicle) {
        if (driverExists(dni)) { cout << "  [!] DNI ya registrado.\n"; return false; }
        driverList.pushBack(Driver(name, dni, password, vehicle));
        cout << "  [OK] Conductor registrado.\n";
        return true;
    }

    // Valida credenciales
    bool loginDriverValid(string dni, string password) {
        int i = indexOfDriver(dni);
        if (i == -1) return false;
        return driverList.get(i).login(dni, password);
    }

    // Devuelve copia del conductor por DNI
    Driver getDriverByDni(string dni) {
        int i = indexOfDriver(dni);
        if (i == -1) return Driver();
        return driverList.get(i);
    }

    // Cambia disponibilidad
    void setDriverAvailability(string dni, bool disponible) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList.get(i);
        d.setAvailable(disponible);
        driverList.remove(i);
        driverList.insert(i, d);
    }

    // Actualiza el rating
    void updateDriverRating(string dni, float nuevaCalif) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList.get(i);
        d.updateRating(nuevaCalif);
        driverList.remove(i);
        driverList.insert(i, d);
    }

    // Marca al conductor como ocupado y acumula ganancia
    void driverAcceptRide(string dni, float precio) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList.get(i);
        d.acceptRide(precio);
        driverList.remove(i);
        driverList.insert(i, d);
    }

    // Marca al conductor como disponible ota ve
    void driverFinishRide(string dni) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList.get(i);
        d.finishRide();
        driverList.remove(i);
        driverList.insert(i, d);
    }

    // Devuelve DNI del primer conductor disponible, "" si no hay
    string findAvailableDriver() {
        for (int i = 0; i < driverList.getSize(); i++)
            if (driverList.get(i).getIsAvailable())
                return driverList.get(i).getDni();
        return "";
    }

    //  LAMBDAS

    // LAMBDA 1: valida que el DNI tenga 8 digitos numericos
    bool validateDni(string dni) {
        auto esDniValido = [](string d) -> bool {
            if (d.size() != 8) return false;
            for (char c : d) if (c < '0' || c > '9') return false;
            return true;
            };
        return esDniValido(dni);
    }

    // LAMBDA 2: muestra totales de usuarios y conductores en consola
    void mostrarResumen() {
        auto resumen = [](int users, int drivers) {
            Console::SetCursorPosition(50, 12);cout << "  Usuarios registrados   : " << users;
            Console::SetCursorPosition(50, 12);cout << "  Conductores registrados: " << drivers;
            };
        resumen(userList.getSize(), driverList.getSize());
    }

    // LAMBDA 3: usa filter() de LinkedList para obtener solo conductores disponibles
    LinkedList<Driver> getConductoresDisponibles() {
        return driverList.filter([](Driver d) { return d.getIsAvailable(); });
    }

    /* LAMBDA 4: encola un viaje solo si el pasajero existe, con Queue::enqueueIf
    Evita encolar viajes de pasajeros no registrados sin verificar afuera
    Llamamos TripManager::createTrip para validar antes de encolar*/
    bool encolarSiPasajeroExiste(Queue<Trip>& cola, Trip t) {
        return cola.enqueueIf(t, [&](Trip viaje) {
            return userExists(viaje.getPassengerDni());
            });
    }

    /* RECURSIVIDAD
    Cuenta conductores disponibles en la lista
    Caso base: indice >= total de conductores -> return 0
    si el conductor en 'indice' esta disponible -> suma 1
    si no                                       -> no suma*/
    int contarConductoresDisponibles(int indice) {
        if (indice >= driverList.getSize()) return 0;
        int resto = contarConductoresDisponibles(indice + 1);
        if (driverList.get(indice).getIsAvailable()) return 1 + resto;
        return resto;
    }

    //  ESPACIO PARA ORDENAMIENTO
    //  void sortDriversByRating() { /* ordenamiento wiwiwi) */ }
};