#pragma once
#include "../include/Queue.h"
#include "../include/DoublyLinkedList.h"
#include "../include/Stack.h"
#include "Trip.h"
#include "AuthManager.h"
#include <iostream>
#include <string>
using namespace std;

//  TripManager
//  Maneja el ciclo de vida de un viaje usando las 4 estructuras:
//  waitingQueue -> Queue<Trip>             viajes esperando conductor (FIFO)
//  activeTrips  -> DoublyLinkedList<Trip>  viajes en curso ahora mismo
//  history      -> Stack<Trip>             historial (el ultimo viaje queda top)

class TripManager {
private:
    Queue<Trip> waitingQueue;
    DoublyLinkedList<Trip> activeTrips;
    Stack<Trip> history;
    int tripCounter;

    // extre los id de cada trip
    static int extractTripNumber(const string& tripId) {
        if (tripId.size() < 5) return 0;
        if (tripId.substr(0, 4) != "TRP-") return 0;
        try {
            return std::stoi(tripId.substr(4));
        }
        catch (...) {
            return 0;
        }
    }

    // Genera ID unico: TRP-10001, TRP-10002
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

        while (!temp.isEmpty()) {
            history.push(temp.peek());
            temp.pop();
        }

        return arr;
    }

public:
    TripManager() : tripCounter(0) {}

    // Acceso a las estructuras (las usa AdministratorMenu)
    Queue<Trip>& getWaitingQueue() { return waitingQueue; }
    DoublyLinkedList<Trip>& getActiveTrips() { return activeTrips; }
    Stack<Trip>& getHistory() { return history; }
    int getTotalWaiting() { return waitingQueue.getSize(); }
    int getTotalActiveTrips() { return activeTrips.getSize(); }
    int getTotalHistoryTrips() { return history.getSize(); }

    // previewNextTripId: muestra cual seria el proximo id sin consumirlo todavia
    string previewNextTripId() const { return "TRP-" + to_string(10000 + tripCounter + 1); }

    // reconstruir contador de viajes o ids para el file trip
    void rebuildTripCounter() {
        int maxId = 0;

        waitingQueue.forEach([&](Trip t) {
            int actual = extractTripNumber(t.getTripId());
            if (actual > maxId) maxId = actual;
            });

        for (int i = 0; i < activeTrips.getSize(); i++) {
            int actual = extractTripNumber(activeTrips.get(i).getTripId());
            if (actual > maxId) maxId = actual;
        }

        int n = 0;
        Trip* historial = historyToArray(n);
        for (int i = 0; i < n; i++) {
            int actual = extractTripNumber(historial[i].getTripId());
            if (actual > maxId) maxId = actual;
        }
        delete[] historial;

        if (maxId >= 10000) tripCounter = maxId - 10000;
        else tripCounter = 0;
    }

    // createTrip: crea el viaje, calcula precio y lo encola como pendiente
    // si no hay conductor, guarda "Por asignar" y deja driverDni vacio
    Trip createTrip(string origin, string destination, int tipo, float km,
        string driverName, string driverDni, string passengerDni, string date) {
        Trip t(generateId(), origin, destination, 0.0f, driverName, driverDni, passengerDni, date);
        t.setTipe(tipo);
        t.setPrice(t.calcPrice(tipo, km));
        t.setStatus("pendiente");
        if (driverName.empty()) {
            t.setDriverName("Por asignar");
            t.setDriverDni("");
        }
        waitingQueue.enqueue(t);
        cout << "  [OK] Viaje " << t.getTripId() << " creado | S/ " << t.getPrice() << "\n";
        return t;
    }

    // assignDriver: toma el primer viaje pendiente y lo pasa a activos
    // tambien marca al conductor como ocupado dentro del AuthManager
    bool assignDriver(string driverDni, AuthManager& auth) {
        if (waitingQueue.isEmpty()) { cout << "  [!] No hay viajes en espera.\n"; return false; }
        Driver d = auth.getDriverByDni(driverDni);
        if (d.getDni() == "" || !d.getIsAvailable()) {
            cout << "  [!] Conductor invalido o no disponible.\n";
            return false;
        }

        Trip t = waitingQueue.getFront();
        waitingQueue.dequeue();
        t.setDriverName(d.getName());
        t.setDriverDni(d.getDni());
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
        waitingQueue.dequeue();
        t.setStatus("cancelado");
        history.push(t);
        cout << "  [XX] Viaje " << t.getTripId() << " cancelado.\n";
    }

    // finishTrip: mueve un viaje activo al historial como completado
    // actualiza al pasajero y libera al conductor si el viaje ya tenia driverDni
    bool finishTrip(string tripId, AuthManager& auth) {
        for (int i = 0; i < activeTrips.getSize(); i++) {
            if (activeTrips.get(i).getTripId() == tripId) {
                Trip t = activeTrips.get(i);
                t.setStatus("completado");
                auth.addTripToUser(t.getPassengerDni(), t.getPrice());
                if (!t.getDriverDni().empty()) {
                    auth.driverFinishRide(t.getDriverDni());
                }
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
    // Devuelve su DNI, o "" si no hay ninguno
    string matchBestDriver(AuthManager& auth) {
        string bestDni = "";
        float bestRating = -1.0f;
        LinkedList<Driver>* dl = auth.getDriverList();

        for (int i = 0; i < dl->getSize(); i++) {
            Driver d = dl->get(i);
            if (d.getIsAvailable() && d.getRating() > bestRating) {
                bestRating = d.getRating();
                bestDni = d.getDni();
            }
        }
        return bestDni;
    }

    // FUNCIONES DE VER COMPLETADO
    void viewWaiting() {
        cout << "\nCOLA DE ESPERA (" << waitingQueue.getSize() << " viajes)\n";
        if (waitingQueue.isEmpty()) {
            cout << "  Sin viajes pendientes.\n";
            return;
        }
        waitingQueue.print();
    }

    void viewActive() {
        cout << "VIAJES ACTIVOS (" << activeTrips.getSize() << ")\n";
        if (activeTrips.isEmpty()) {
            cout << "  Sin viajes activos.\n";
            return;
        }

        for (int i = 0; i < activeTrips.getSize(); i++) {
            cout << "  [" << i + 1 << "] " << activeTrips.get(i).toString() << "\n";
        }
    }

    void viewHistory() {
        cout << "HISTORIAL DE VIAJES (" << history.getSize() << ")\n";
        int n = 0;
        Trip* arr = historyToArray(n);

        if (!arr) {
            cout << "  Sin historial registrado.\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "  [" << i + 1 << "] " << arr[i].toString() << "\n";
        }

        delete[] arr;
    }

    //  LAMBDAS

    // LAMBDA 1: muestra el estado de la cola en una linea
    void mostrarEstadoCola() {
        auto etiqueta = [](int pendientes) -> string {
            if (pendientes == 0) return "[--] Sin viajes en espera";
            return "[>>] " + to_string(pendientes) + " viaje(s) esperando conductor";
            };
        cout << "  Cola: " << etiqueta(waitingQueue.getSize());
    }

    // LAMBDA 2: suma precios de viajes en cola con sumBy() de Queue
    float calcTotalEnCola() {
        return waitingQueue.sumBy([](Trip t) { return t.getPrice(); });
    }

    // LAMBDA 3: cuenta viajes activos con countIf() de DoublyLinkedList
    int contarViajesEnCurso() {
        return activeTrips.countIf([](Trip t) { return t.getStatus() == "en_curso"; });
    }

    // LAMBDA 4: muestra la cola de espera con posicion con Queue::forEach
    // Se usa en listarViajes() del AdministratorMenu para mostrar la cola sin sacar elementos
    void viewWaitingDetailed() {
        cout << "COLA DE ESPERA (" << waitingQueue.getSize() << " viajes)\n";
        if (waitingQueue.isEmpty()) {
            cout << "  Sin viajes pendientes.\n";
            return;
        }

        int posicion = 1;
        waitingQueue.forEach([&](Trip t) {
            cout << "  [" << posicion++ << "] " << t.toString() << "\n";
            });
    }

    // LAMBDA 5: busca el ultimo viaje de un pasajero en el historial con Stack::findInStack
   // No destruye la pila. Se usa en buscarUsuario() del AdministratorMenu
    Trip getLastTripByPassenger(string dni) {
        return history.findInStack([&](Trip t) { return t.getPassengerDni() == dni; });
    }

    // cancelActiveTrip: cancela un viaje activo, lo manda al historial
    // y devuelve el conductor a disponible si estaba asignado
    bool cancelActiveTrip(string tripId, AuthManager& auth) {
        for (int i = 0; i < activeTrips.getSize(); i++) {
            if (activeTrips.get(i).getTripId() == tripId) {
                Trip t = activeTrips.get(i);
                t.setStatus("cancelado");
                if (!t.getDriverDni().empty()) {
                    auth.driverFinishRide(t.getDriverDni());
                }
                history.push(t);
                activeTrips.remove(i);
                return true;
            }
        }
        return false;
    }

    /*  RECURSIVIDAD
    Suma la ganancia de la plataforma (20% de cada viaje completado).
    si el viaje esta completado -> suma 20% de su precio
    si no                       -> solo sigue*/
private:
    float sumarGananciaRec(Trip* arr, int indice, int total) {
        if (indice == total) return 0.0f;
        float resto = sumarGananciaRec(arr, indice + 1, total);
        if (arr[indice].estaCompletado())
            return arr[indice].getPrice() * 0.20f + resto;
        return resto;
    }

public:
    float getTotalPlatformEarnings() {
        int n = 0;
        Trip* arr = historyToArray(n);
        if (!arr) return 0.0f;
        float total = sumarGananciaRec(arr, 0, n);
        delete[] arr;
        return total;
    }

    // ordena viajes activos por precio de mayor a menor
    void sortActiveTripsByPrice() {
        int n = activeTrips.getSize();
        if (n <= 1) return;

        // Copiamos a arreglo auxiliar
        Trip* arr = new Trip[n];
        for (int i = 0; i < n; i++) arr[i] = activeTrips.get(i);

        // Selection Sort: busca el máximo en el subarreglo restante y lo pone al frente
        for (int i = 0; i < n - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j].getPrice() > arr[maxIdx].getPrice()) {
                    maxIdx = j;
                }
            }
            // Intercambiamos
            if (maxIdx != i) {
                Trip temp = arr[i];
                arr[i] = arr[maxIdx];
                arr[maxIdx] = temp;
            }
        }

        // Reconstruimos la lista doble
        activeTrips.clear();
        for (int i = 0; i < n; i++) activeTrips.pushBack(arr[i]);
        delete[] arr;
    }
};
