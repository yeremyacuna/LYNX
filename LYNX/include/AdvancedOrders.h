#pragma once
#include <iostream>
#include <functional>
#include "LinkedList.h"
#include "../src/Driver.h"
#include "../src/Passenger.h"
#include "../src/Trip.h"

using std::cout; using std::cin; using std::function; using std::string;

template <typename T>
class AdvancedOrders {
public:

    // SHELL SORT — conductores por GANANCIAS TOTALES de mayor a menor
    static void shellSortDriversByEarnings(LinkedList<Driver>* list)
    {
        int n = list->getSize();
        if (n <= 1) return;

        Driver* arr = new Driver[n];
        for (int i = 0; i < n; i++) arr[i] = list->get(i);

        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                Driver temp = arr[i];
                int j = i;
                // mueve hacia atras saltando de 'gap' en 'gap'
                while (j >= gap && arr[j - gap].getTotalEarnings() < temp.getTotalEarnings())
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }

        list->clear();
        for (int i = 0; i < n; i++) list->pushBack(arr[i]);
        delete[] arr;
    }

    // QUICK SORT — pasajeros por gasto total de mayor a menor
    static void quickSortPassengersBySpent(LinkedList<Passenger>* list)
    {
        int n = list->getSize();
        if (n <= 1) return;

        Passenger* arr = new Passenger[n];
        for (int i = 0; i < n; i++) arr[i] = list->get(i);

        quickSortHelper(arr, 0, n - 1);

        list->clear();
        for (int i = 0; i < n; i++) list->pushBack(arr[i]);
        delete[] arr;
    }

    // MERGE SORT — viajes por precio de mayor a menor
    static void mergeSortTripsByPrice(Trip* arr, int n)
    {
        if (n <= 1) return;
        mergeSortHelper(arr, 0, n - 1);
    }

    /* TIM SORT — pasajeros por num de viajes de mayor a menor
    combina Insertion Sort y Merge Sort.*/
    static void timSortPassengersByTrips(LinkedList<Passenger>* list)
    {
        int n = list->getSize();
        if (n <= 1) return;

        Passenger* arr = new Passenger[n];
        for (int i = 0; i < n; i++) arr[i] = list->get(i);

        const int RUN = 32; // tamano del bloque para Insertion Sort

        // ordenar cada bloque de RUN elementos con Insertion Sort
        for (int i = 0; i < n; i += RUN)
        {
            int fin = (i + RUN - 1 < n - 1) ? i + RUN - 1 : n - 1;
            insertionSortBloque(arr, i, fin);
        }

        // fusionar los bloques con Merge Sort
        for (int size = RUN; size < n; size *= 2)
        {
            for (int left = 0; left < n; left += 2 * size)
            {
                int mid = (left + size - 1 < n - 1) ? left + size - 1 : n - 1;
                int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;
                if (mid < right)
                    fusionarPasajeros(arr, left, mid, right);
            }
        }

        list->clear();
        for (int i = 0; i < n; i++) list->pushBack(arr[i]);
        delete[] arr;
    }

    // COUNTING SORT — conductores por total de viajes
    static void countingSortDriversByTrips(LinkedList<Driver>* list)
    {
        int n = list->getSize();
        if (n <= 1) return;

        Driver* arr = new Driver[n];
        for (int i = 0; i < n; i++) arr[i] = list->get(i);

        // encontrar el maximo de viajes entre todos los conductores
        int maxViajes = 0;
        for (int i = 0; i < n; i++)
            if (arr[i].getTotalTrips() > maxViajes)
                maxViajes = arr[i].getTotalTrips();

        if (maxViajes == 0) { delete[] arr; return; }

        // contar cuantos conductores tienen cada cantidad de viajes
        int* conteo = new int[maxViajes + 1]();
        for (int i = 0; i < n; i++)
            conteo[arr[i].getTotalTrips()]++;

        // reconstruir de mayor a menor usando el conteo
        Driver* resultado = new Driver[n];
        int pos = 0;
        for (int v = maxViajes; v >= 0; v--) {
            for (int i = 0; i < n; i++) {
                if (arr[i].getTotalTrips() == v && conteo[v] > 0) {
                    resultado[pos++] = arr[i];
                    conteo[v]--;
                }
            }
        }

        list->clear();
        for (int i = 0; i < n; i++) list->pushBack(resultado[i]);

        delete[] arr;
        delete[] conteo;
        delete[] resultado;
    }

private:

    // para Quick Sort
    
    // elige el ultimo como pivote y reordena
    static int particionar(Passenger* arr, int inicio, int fin)
    {
        float pivote = arr[fin].getTotalSpent();
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[j].getTotalSpent() >= pivote) {   // mayor a la izquierda
                i++;
                Passenger temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        Passenger temp = arr[i + 1]; arr[i + 1] = arr[fin]; arr[fin] = temp;
        return i + 1;
    }

    static void quickSortHelper(Passenger* arr, int inicio, int fin)
    {
        if (inicio < fin) {
            int p = particionar(arr, inicio, fin);
            quickSortHelper(arr, inicio, p - 1);
            quickSortHelper(arr, p + 1, fin);
        }
    }

    // para Merge Sort (Trips)

    static void fusionarTrips(Trip* arr, int inicio, int medio, int fin)
    {
        int n1 = medio - inicio + 1, n2 = fin - medio;
        Trip* izq = new Trip[n1]; Trip* der = new Trip[n2];

        for (int i = 0; i < n1; i++) izq[i] = arr[inicio + i];
        for (int j = 0; j < n2; j++) der[j] = arr[medio + 1 + j];

        int i = 0, j = 0, k = inicio;
        while (i < n1 && j < n2)
            arr[k++] = (izq[i].getPrice() >= der[j].getPrice()) ? izq[i++] : der[j++];
        while (i < n1) arr[k++] = izq[i++];
        while (j < n2) arr[k++] = der[j++];

        delete[] izq; delete[] der;
    }

    static void mergeSortHelper(Trip* arr, int inicio, int fin)
    {
        if (inicio < fin) {
            int medio = (inicio + fin) / 2;
            mergeSortHelper(arr, inicio, medio);
            mergeSortHelper(arr, medio + 1, fin);
            fusionarTrips(arr, inicio, medio, fin);
        }
    }

    // para Tim Sort (Passengers)

    // insertion sort para un bloque [inicio, fin]
    static void insertionSortBloque(Passenger* arr, int inicio, int fin)
    {
        for (int i = inicio + 1; i <= fin; i++) {
            Passenger key = arr[i];
            int j = i - 1;
            while (j >= inicio && arr[j].getTotalTrips() < key.getTotalTrips()) {
                arr[j + 1] = arr[j]; j--;
            }
            arr[j + 1] = key;
        }
    }

    // fusion para Tim Sort
    static void fusionarPasajeros(Passenger* arr, int inicio, int medio, int fin)
    {
        int n1 = medio - inicio + 1, n2 = fin - medio;
        Passenger* izq = new Passenger[n1]; Passenger* der = new Passenger[n2];

        for (int i = 0; i < n1; i++) izq[i] = arr[inicio + i];
        for (int j = 0; j < n2; j++) der[j] = arr[medio + 1 + j];

        int i = 0, j = 0, k = inicio;
        while (i < n1 && j < n2)
            arr[k++] = (izq[i].getTotalTrips() >= der[j].getTotalTrips()) ? izq[i++] : der[j++];
        while (i < n1) arr[k++] = izq[i++];
        while (j < n2) arr[k++] = der[j++];

        delete[] izq; delete[] der;
    }
};