#pragma once
#include "User.h"
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <functional>
using namespace std;
using namespace System;

class Driver : public User {
private:
    string  driverId;
    float   rating;
    bool    isAvailable;    // true= libre, false= en viaje
    int     totalTrips;
    float   totalEarnings;
    Vehicle vehicle;

public:

    Driver() : User() {
        driverId = "";
        rating = 5.0f;
        isAvailable = true;
        totalTrips = 0;
        totalEarnings = 0.0f;
    }

    Driver(string _name, string _dni, string _password, Vehicle _vehicle)
        : User(_name, _dni, _password)
    {
        driverId = "DRV-" + _dni.substr(0, 4);
        rating = 5.0f;
        isAvailable = true;
        totalTrips = 0;
        totalEarnings = 0.0f;
        vehicle = _vehicle;
    }

    ~Driver() {}

    string  getDriverId() { return driverId; }
    float   getRating() { return rating; }
    bool    getIsAvailable() { return isAvailable; }
    int     getTotalTrips() { return totalTrips; }
    float   getTotalEarnings() { return totalEarnings; }
    Vehicle getVehicle() { return vehicle; }

    void setAvailable(bool estado) { isAvailable = estado; }
    void setVehicle(Vehicle v) { vehicle = v; }


    bool login(string _dni, string _pass) {
        return (dni == _dni && checkPassword(_pass));
    }

    /* Si acepta un viaje : se marca ocupadeishon (busy)
    y se acumulan sus ganancias y viajes.*/
    void acceptRide(float precio) {
        isAvailable = false;
        totalEarnings += precio;
        totalTrips++;
    }

    // Termina el viaje y vuelve a estar disponibliseishon 
    void finishRide() {
        isAvailable = true;
    }

    /* El conductor califica al pasajero
    Devuelve la calificacion para que Passenger la procese
    con updateRating().*/
    float ratePassenger(int estrellas) {
        if (estrellas < 1) estrellas = 1;
        if (estrellas > 5) estrellas = 5;
        return (float)estrellas;
    }

    string toString() override {
        string estado = isAvailable ? "Disponible" : "En viaje";
        return "ID: " + driverId +
            " | Nombre: " + name +
            " | DNI: " + dni +
            " | Rating: " + to_string(rating) +
            " | Viajes: " + to_string(totalTrips) +
            " | Estado: " + estado +
            " | Vehiculo: " + vehicle.toString();
    }

    // LAMBDA 1
    // Calcula la ganancia NETA del conductor
    // La plataforma cobra 20%, el conductor se queda con el 80%
    float getNetEarnings() {
        auto calcularNeto = [](float bruto) -> float {
            return bruto * 0.80f;
            };
        return calcularNeto(totalEarnings);
    }

    // LAMBDA 2(promedio)
    // Actualiza el rating del conductor cuando un pasajero lo califica
    void updateRating(float nuevaCalif) {
        auto calcPromedio = [](float actual, float nueva, int viajes) -> float {
            if (viajes <= 1) return nueva;
            return ((actual * (viajes - 1)) + nueva) / viajes;
            };
        rating = calcPromedio(rating, nuevaCalif, totalTrips);
    }

    // LAMBDA 3
    /* Muestra si el conductor esta disponible o no
    Se usa en el panel del conductor y en el backoffice.*/
    void mostrarEstado(int x, int& y) {
        auto etiqueta = [](bool disponible) -> string {
            if (disponible) return "[LIBRE]   Listo para recibir viajes";
            else            return "[OCUPADO] Actualmente en viaje";
            };
        Console::SetCursorPosition(x, y++);
        cout << "Estado : " << etiqueta(isAvailable) << endl;
    }


    void mostrar(int x, int& y) override {
        string estadoStr = isAvailable ? "Disponible" : "En viaje";
        Console::SetCursorPosition(x, y++); cout << "ID         : " << driverId << endl;
        Console::SetCursorPosition(x, y++); cout << "Nombre     : " << name << endl;
        Console::SetCursorPosition(x, y++); cout << "DNI        : " << dni << endl;
        Console::SetCursorPosition(x, y++); cout << "Rating     : " << rating << endl;
        Console::SetCursorPosition(x, y++); cout << "Viajes     : " << totalTrips << endl;
        Console::SetCursorPosition(x, y++); cout << "Ganancias  : S/ " << totalEarnings << endl;
        Console::SetCursorPosition(x, y++); cout << "Neto (80%) : S/ " << getNetEarnings() << endl;
        Console::SetCursorPosition(x, y++); cout << "Estado     : " << estadoStr << endl;
        Console::SetCursorPosition(x, y++); cout << "-- Vehiculo --" << endl;
        vehicle.mostrar(x, y);
        Console::SetCursorPosition(x, y++); cout << "-----------------------" << endl;
    }

    string getCodigo() { return driverId; }
};