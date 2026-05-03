#pragma once
#include "Nodo.h"


template <typename T>
class EList
{
private:
    Nodo<T>* cabeza;

public:
    EList() {
        cabeza = nullptr;
    }

    ~EList() {}

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

