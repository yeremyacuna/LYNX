#pragma once
#include "User.h"
#include <iostream>
#include <string>
#include "Trip.h"

using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

class Passenger : public User {
private:
    string passengerId;
    float  rating;
    int    totalTrips;
    float  totalSpent;    // total gastado en viajes completados 

public:

    Passenger() : User() {
        passengerId = "";
        rating = 5.0f;
        totalTrips = 0;
        totalSpent = 0.0f;
    }

    Passenger(string _name, string _dni, string _password)
        : User(_name, _dni, _password)
    {
        passengerId = "PAS-" + _dni.substr(0, 4);
        rating = 5.0f;
        totalTrips = 0;
        totalSpent = 0.0f;
    }

    ~Passenger() {}

    string getPassengerId() const { return passengerId; }
   
    float  getRating() const  { return rating; }
    int    getTotalTrips() const { return totalTrips; }
    float  getTotalSpent() const { return totalSpent; }

    void setRating(float r) { rating = r; }
    void setTotalTrips(int t) { totalTrips = t; }
    void setPassengerId(string pID) { passengerId = pID;  }
    void setTotalSpent(float tSpent) { totalSpent = tSpent; }

    // c/viaje completado suma el precio pagado
    void addTrip(float precio) {
        totalTrips++;
        totalSpent += precio;
    }

    // Verifica si el pasajero ya esta registrado
    bool tieneCuenta() {
        return passengerId != "";
    }

    // Verifica DNI y contra
    bool login(string _dni, string _pass) {
        return (dni == _dni && checkPassword(_pass));
    }

    /* El pasajero califica al conductor
    Devuelve la calificacion para que Driver la procese con updateRating().
    
    Ej:float nota = pasajero.rateDriver(5);
            conductor.updateRating(nota);*/
    float rateDriver(int estrellas) {
        if (estrellas < 1) estrellas = 1;
        if (estrellas > 5) estrellas = 5;
        return (float)estrellas;
    }

    string toString() const override {
        return "ID: " + passengerId +
            " | Nombre: " + name +
            " | DNI: " + dni +
            " | Viajes: " + to_string(totalTrips) +
            " | Gastado: S/ " + to_string(totalSpent) +
            " | Rating: " + to_string(rating);
    }

    // LAMBDA 1(promedio)
    // Actualiza el rating del pasajero cuando un conductor lo califica.
   
    void updateRating(float nuevaCalif) {
        auto calcularPromedio = [](float ratingActual, float nueva, int viajes) -> float {
            if (viajes == 0) return nueva;
            return ((ratingActual * viajes) + nueva) / (viajes + 1);
            };
        rating = calcularPromedio(rating, nuevaCalif, totalTrips);
    }

   
    // LAMBDA 2
    // Rating del pasajero con estrellas (*).

    void mostrarRating(int x, int& y) {
        auto estrellas = [](float r) -> string {
            string s = "";
            int cantidad = (int)r;
            for (int i = 0; i < cantidad; i++) s += "*";
            return s;
            };
        Console::SetCursorPosition(x, y++);
        cout << "Rating  : " << rating << "  [" << estrellas(rating) << "]" << endl;
    }

    // LAMBDA 3: etiqueta segun cuanto ha gastado el pasajero
    string getNivelCliente() {
        auto nivel = [](float gasto) -> string {
            if (gasto < 50.0f)  return "Cliente nuevo";
            if (gasto < 200.0f) return "Cliente frecuente";
            return                     "Cliente premium";
            };
        return nivel(totalSpent);
    }
    //  RECURSIVIDAD
 
    /* Cuenta cuantos viajes del historial estan completados.
    Si ya no hay mas (indice == total) -> devuelve 0
    Si el viaje actual esta completado -> suma 1 y sigue
    Si esta cancelado o pendiente      -> solo sigue
    Ej:
    Trip historial[4] = {t1, t2, t3, t4};
    int completados = pasajero.contarViajesCompletados(historial, 0, 4);*/
    int contarViajesCompletados(Trip historial[], int indice, int total) {
        if (indice == total) return 0;                                        // caso base
        int resto = contarViajesCompletados(historial, indice + 1, total);    // revisa el resto
        if (historial[indice].getStatus() == "completado") return 1 + resto;  // este cuenta
        return resto;                                                          // este no
    }

    void mostrar(int x, int& y) override {
        Console::SetCursorPosition(x, y++); cout << "ID      : " << passengerId << endl;
        Console::SetCursorPosition(x, y++); cout << "Nombre  : " << name << endl;
        Console::SetCursorPosition(x, y++); cout << "DNI     : " << dni << endl;
        Console::SetCursorPosition(x, y++); cout << "Viajes  : " << totalTrips << endl;
        Console::SetCursorPosition(x, y++); cout << "Gastado : S/ " << totalSpent << endl;
        mostrarRating(x, y);
        Console::SetCursorPosition(x, y++); cout << "-----------------------" << endl;
    }

    string getCodigo() { return passengerId; }

    bool operator==(const Passenger& other) const  // Recibe otro conductor (other) por referencia. No hace copia del objeto  más eficiente.
    {
        return passengerId == other.passengerId;  // Entonces operator sera comparar los id
    }

    friend ostream& operator<<(ostream& os, const Passenger& d) // friend para acceder a atributos privados
    {
        os << d.toString();
        return os;
    }

};