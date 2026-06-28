#pragma once
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::function;

template <typename T>
class AdvancedSorts {
private:
    // Funcion general para intercambiar mi swap
    static void swapTo(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

private:
    // ============ HELPERS / HEAP SORT ============
    // --- Heapify --- (Ascendente)
    static void heapify(T* arr, int size, int index) {
        // mas grande o padre
        int largest = index;
        // izquierda
        int left = 2 * index + 1;
        // derecha 
        int right = 2 * index + 2;

        // if  el hijo izquierdo exista dentro del arreglo > size, y si el arraglo de la izquierda es mayor que el mas grande
        if (left < size && arr[left] > arr[largest]) 
            largest = left; // el mas grande va hacer el izquierdo

        // if el valor de la derecha es menor que el tamaño, y si el arraglo de la derecha es mayor que el mas grande
        if (right < size && arr[right] > arr[largest]) 
            largest = right; // el mas grande va hacer el valor derecho

        // if el largest o padre cambia entonces swap para que mayor sea el nuevo mayor
        if (largest != index) {
            // cambia con el mayor verdadero, el nuevo valor heredado de right o left
            swapTo(arr[index], arr[largest]);
            // valida correcion y arregla recursiva
            heapify(arr, size, largest);
        }
    }

    // --- Heapify --- (Ascendente con lambda de compare)
    template <typename Compare>
    static void heapify(T* arr, int size, int index, Compare compare) {
        int root = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && compare(arr[root], arr[left]))  root = left;
        if (right < size && compare(arr[root], arr[right]))  root = right;

        if (root != index) {
            swapTo(arr[index], arr[root]);
            heapify(arr, size, root, compare);
        }
    }

public:
    // ====================================  HEAP SORT ==================================== 
    // --- Funcion de Heap Sort --- (normal)
    static void heapSort(T* arr, int size) {
        // Paso 1: Construir el Max-Heap inicial (buildHeap)
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i);

        // Paso 2: Extraer elementos uno a uno para ordenar
        for (int i = size - 1; i > 0; i--) {
            swapTo(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }


    // --- Funcion de Heap Sort --- (con comparador lambda)
    template <typename Compare>
    static void heapSort(T* arr, int size, Compare compare) {
        // Paso 1: Construir el Max-Heap inicial (buildHeap)
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i, compare);

        // Paso 2: Extraer elementos uno a uno para ordenar
        for (int i = size - 1; i > 0; i--) {
            swapTo(arr[0], arr[i]);
            heapify(arr, i, 0, compare);
        }
    }

    // ==================================== SHELL SORT ====================================
    // --- Funcion ShellSort --- (normal)
    static void shellSort(T* arr, int size)
    {
        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < size; i++)
            {
                T temp = arr[i];
                int j = i;

                while (j >= gap && arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }

                arr[j] = temp;
            }
        }
    }

    // --- Funcion ShellSort --- (con comparador)
    template<typename Compare>
    static void shellSort(T* arr, int size, Compare compare)
    {
        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < size; i++)
            {
                T temp = arr[i];
                int j = i;

                while (j >= gap && compare(arr[j - gap], temp))
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }

                arr[j] = temp;
            }
        }
    }
};