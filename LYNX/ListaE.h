#pragma once
#include "Nodo.h"
using namespace std;

template <typename T>
class ListaE
{
private:
    Nodo<T>* cabeza;

public:
    ListaE() {
        cabeza = nullptr;
    }

    ~ListaE() {}

    void Insertar(T dato)
    {
     
        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }

        Nodo<T>* actual = cabeza;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
    }
};

