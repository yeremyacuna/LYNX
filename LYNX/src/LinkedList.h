#pragma once
#include <iostream>
#include <functional>  
#include "Node.h"

using std::cout; using std::cin; using std::function;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node<T>* actual = head;
        while (actual != nullptr) {
            Node<T>* siguiente = actual->next;
            delete actual;
            actual = siguiente;
        }
    }

    // Inserta e indica posicion del valor
    void insertar(T value) {
        Node<T>* nuevoNodo = new Node<T>(value);

        if (head == nullptr)
        {
            head = nuevoNodo;
        }
        else {
            Node<T>* actual = head;
            while (actual->next != nullptr)
            {
                actual = actual->next;
            }

            actual->next = nuevoNodo;
        }

        cout << "Insertado con exito en la posicion [" << size << "]" << endl;
        size++;
    }

    // Lista o muestra los datos segun T dato pasado, con la funcion mostrar
    void listar()
    {
        if (head == nullptr)
        {
            cout << "|La lista esta vacia|" << endl;
            return;
        }

        Node<T>* actual = head;
        int i = 0;

        while (actual != nullptr) {
            cout << "--- Registro " << i + 1 << " --- Posicion " << i << " ---" << endl;
            actual->data.mostrar();
            actual = actual->next;
            i++;

        }

    }

    // Obtener tamaño de la lista enlazada simple
    int getSize()
    {
        return size;
    }

    // Listar ordenadamente segun dos parametros
    void listarOrdenado(function<bool(T, T)> comparar) {
        if (head == nullptr) {
            cout << "|La lista esta vacia|" << endl;
            return;
        }

        int n = size;
        T* arreglo = new T[n];

        Node<T>* actual = head;
        for (int i = 0; i < n; i++) {
            arreglo[i] = actual->data;
            actual = actual->next;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (comparar(arreglo[i], arreglo[j]) == false) {
                    T temp = arreglo[i];
                    arreglo[i] = arreglo[j];
                    arreglo[j] = temp;
                }
            }
        }

        cout << "Mayor: " << arreglo[0].getCodigo() << endl;   //mayor valor (change(get))
        cout << "\n--- Ordenados de mayor a menor ---" << endl;
        for (int i = 0; i < n; i++) {
            cout << "  [" << i << "] " << arreglo[i].getCodigo() << endl;   // listar ordenadamente (change(get))
        }

        delete[] arreglo;
    }

    // Eliminar dentro de la lista
    void eliminar(int posicion) {
        if (head == nullptr) {
            cout << "|La lista esta vacia|" << endl;
            return;
        }

        if (posicion < 0 || posicion >= size) {
            cout << "Posicion invalida." << endl;
            return;
        }

        Node<T>* actual = head;
        Node<T>* anterior = nullptr;

        for (int i = 0; i < posicion; i++) {
            anterior = actual;
            actual = actual->next;
        }

        if (anterior == nullptr) {
            head = actual->next;
        }
        else {
            anterior->next = actual->next;
        }

        delete actual;
        size--;
        cout << "Eliminado con exito." << endl;
    }

    // Actualizar valores segun posicion
    void actualizar(int posicion, T nuevoValor) {
        if (head == nullptr) {
            cout << "|La lista esta vacia|" << endl;
            return;
        }

        if (posicion < 0 || posicion >= size) {
            cout << "Posicion invalida." << endl;
            return;
        }

        Node<T>* actual = head;

        for (int i = 0; i < posicion; i++) {
            actual = actual->next;
        }

        actual->data = nuevoValor;
        cout << "Actualizado con exito en posicion [" << posicion << "]" << endl;
    }

    // Busqueda de data
    void buscar(function<bool(T)> criterio) {
        if (head == nullptr) {
            cout << "|La lista esta vacia|" << endl;
            return;
        }

        Node<T>* actual = head;
        int i = 0;
        bool encontrado = false;

        while (actual != nullptr) {
            if (criterio(actual->data)) {
                cout << "Encontrado en posicion [" << i << "]:" << endl;
                actual->data.mostrar();
                encontrado = true;
            }
            actual = actual->next;
            i++;
        }

        if (!encontrado) {
            cout << "No se encontro ningun resultado." << endl;
        }
    }

};
