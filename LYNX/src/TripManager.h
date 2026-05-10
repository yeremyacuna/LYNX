#pragma once
#include "../include/Queue.h"
#include "../include/LinkedDoubleList.h"
#include "../include/Stack.h"
#include "Trip.h"
#include "AuthManager.h"
#include <iostream>
#include <string>
using namespace std;

//  TripManager
//  Maneja el ciclo de vida de un viaje usando las 4 estructuras:
//  waitingQueue -> Queue<Trip>             viajes esperando conductor (FIFO)
//  activeTrips  -> LinkedDoubleList<Trip>  viajes en curso ahora mismo
//  history      -> Stack<Trip>             historial (el ultimo viaje queda top)

class TripManager {
private:
    Queue<Trip>            waitingQueue;
    LinkedDoubleList<Trip> activeTrips;
    Stack<Trip>            history;
    int                    tripCounter;

    // Genera ID unico: TRP-10001, TRP-10002, ...
    string generateId() {
        return "TRP-" + to_string(10000 + (++tripCounter));
    }

    // Copia el Stack a un arreglo sin destruirlo (para poder recorrerlo)
    Trip* historyToArray(int& n) {
        n = history.getSize();
        if (n == 0) return nullptr;
        Trip* arr = new Trip[n];
        Stack<Trip> temp;
        for (int i = 0; i < n; i++) {
            arr[i] = history.peek();
            temp.push(history.peek());
            history.pop();
        }
        while (!temp.isEmpty()) { history.push(temp.peek()); temp.pop(); }
        return arr;
    }

public:
    TripManager() : tripCounter(0) {}

    // Acceso a las estructuras (las usa AdministratorMenu)
    Queue<Trip>& getWaitingQueue() { return waitingQueue; }
    LinkedDoubleList<Trip>& getActiveTrips() { return activeTrips; }
    Stack<Trip>& getHistory() { return history; }
    int getTotalWaiting() { return waitingQueue.getSize(); }
    int getTotalActiveTrips() { return activeTrips.getSize(); }
    int getTotalHistoryTrips() { return history.getSize(); }

    // Crea un viaje, calcula su precio y lo mete a la cola de espera
    Trip createTrip(string origin, string destination, int tipo, float km,
        string driverName, string passengerDni, string date) {
        Trip t(generateId(), origin, destination, 0.0f, driverName, passengerDni, date);
        t.setTipe(tipo);
        t.calcPrice(tipo, km);
        waitingQueue.enqueue(t);
        cout << "  [OK] Viaje " << t.getTripId() << " creado | S/ " << t.getPrice() << "\n";
        return t;
    }

    // Saca el primer viaje de la cola y lo asigna al conductor
    // Marca al conductor como ocupado en AuthManager
    bool assignDriver(string driverDni, AuthManager& auth) {
        if (waitingQueue.isEmpty()) { cout << "  [!] No hay viajes en espera.\n"; return false; }
        Trip t = waitingQueue.getFront();
        waitingQueue.dequeue();
        t.setStatus("en_curso");
        activeTrips.pushBack(t);
        auth.driverAcceptRide(driverDni, t.getPrice());
        cout << "  [OK] Viaje " << t.getTripId() << " asignado.\n";
        return true;
    }

    // Cancela el primer viaje en la cola y lo manda al historial
    void cancelTrip() {
        if (waitingQueue.isEmpty()) { cout << "  [!] Cola vacia.\n"; return; }
        Trip t = waitingQueue.getFront();
        t.setStatus("cancelado");
        history.push(t);
        waitingQueue.dequeue();
        cout << "  [XX] Viaje " << t.getTripId() << " cancelado.\n";
    }

    // Busca el viaje por ID en los activos, lo completa y lo manda al historial
    bool finishTrip(string tripId, AuthManager& auth, string passengerDni) {
        for (int i = 0; i < activeTrips.getSize(); i++) {
            if (activeTrips.get(i).getTripId() == tripId) {
                Trip t = activeTrips.get(i);
                t.setStatus("completado");
                auth.addTripToUser(passengerDni, t.getPrice());
                history.push(t);
                activeTrips.remove(i);
                cout << "  [OK] Viaje " << tripId << " completado.\n";
                return true;
            }
        }
        cout << "  [!] Viaje no encontrado en activos.\n";
        return false;
    }

    // Devuelve el primer viaje en cola sin sacarlo
    Trip getNextInQueue() {
        if (waitingQueue.isEmpty()) return Trip();
        return waitingQueue.getFront();
    }

    // Busca el conductor disponible con mejor rating
    // Devuelve su DNI, o "" si no hay ning
    string matchBestDriver(AuthManager& auth) {
        string bestDni = "";
        float  bestRating = -1.0f;
        LinkedList<Driver>& dl = auth.getDriverList();
        for (int i = 0; i < dl.getSize(); i++) {
            Driver d = dl.get(i);
            if (d.getIsAvailable() && d.getRating() > bestRating) {
                bestRating = d.getRating();
                bestDni = d.getDni();
            }
        }
        return bestDni;
    }

    // VER

    void viewWaiting() {
        cout << "\n  COLA DE ESPERA (" << waitingQueue.getSize() << " viajes)\n";
        waitingQueue.print();
    }

    void viewActive() {
        cout << "VIAJES ACTIVOS (" << activeTrips.getSize() << ")\n";
        
    }

    void viewHistory() {
        cout << "HISTORIAL DE VIAJES (" << history.getSize() << ")\n";
        int n; Trip* arr = historyToArray(n);
        
        delete[] arr;
    }

    //  LAMBDAS

    // LAMBDA 1: muestra el estado de la cola en una linea
    void mostrarEstadoCola() {
        auto etiqueta = [](int pendientes) -> string {
            if (pendientes == 0) return "[--] Sin viajes en espera";
            return "[>>] " + to_string(pendientes) + " viaje(s) esperando conductor";
            };
        cout << "  Cola: " << etiqueta(waitingQueue.getSize()) << "\n";
    }

    // LAMBDA 2: suma precios de viajes en cola con sumBy() de Queue
    float calcTotalEnCola() {
        return waitingQueue.sumBy([](Trip t) { return t.getPrice(); });
    }

    // LAMBDA 3: cuenta viajes activos con countIf() de LinkedDoubleList
    int contarViajesEnCurso() {
        return activeTrips.countIf([](Trip t) { return t.getStatus() == "en_curso"; });
    }

    // LAMBDA 4: muestra la cola de espera con posicion con Queue::forEach
    // Se usa en listarViajes() del AdministratorMenu para mostrar la cola sin sacar elementos
    void viewWaitingDetailed() {
        cout << "COLA DE ESPERA (" << waitingQueue.getSize() << " viajes)\n";
        
    }

    // LAMBDA 5: busca el ultimo viaje de un pasajero en el historial con Stack::findInStack
    // No destruye la pila. Se usa en buscarUsuario() del AdministratorMenu
    Trip getLastTripByPassenger(string dni) {
        return history.findInStack([&](Trip t) { return t.getPassengerDni() == dni; });
    }

    // LAMBDA 6: cancela un viaje activo por ID usando LinkedDoubleList::updateIf
    // Cambia su estado a "cancelado" sin necesitar el indice
    bool cancelActiveTrip(string tripId) {
        bool encontrado = false;
        activeTrips.updateIf(
            [&](Trip t) { if (t.getTripId() == tripId) { encontrado = true; return true; } return false; },
            [](Trip& t) { t.setStatus("cancelado"); }
        );
        return encontrado;
    }

    /*  RECURSIVIDAD
    Suma la ganancia de la plataforma (20% de cada viaje completado).
    si el viaje esta completado -> suma 20% de su precio
    si no                       -> solo sigue*/
private:
    float sumarGananciaRec(Trip* arr, int indice, int total) {
        if (indice == total) return 0.0f;                   // caso base
        float resto = sumarGananciaRec(arr, indice + 1, total);
        if (arr[indice].estaCompletado())
            return arr[indice].getPrice() * 0.20f + resto;  // plataforma cobra 20%
        return resto;
    }

public:
    float getTotalPlatformEarnings() {
        int n; Trip* arr = historyToArray(n);
        if (!arr) return 0.0f;
        float total = sumarGananciaRec(arr, 0, n);
        delete[] arr;
        return total;
    }

    //  ESPACIO PARA ORDENAMIENTO
    //  void sortTripsByPrice() { /* ordenamiento wiwiwi sobre activeTrips }
};