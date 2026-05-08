#pragma once
#include "Node.h"


template <typename T>
class LinkedDoubleList
{
private:
    Node<T>* cabeza;

public:
    LinkedDoubleList() {
        cabeza = nullptr;
    }

    ~LinkedDoubleList() {}

    void Insertar(T dato)
    {
     
        Node<T>* nuevo = new Node<T>(dato);

        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }

        Node<T>* actual = cabeza;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
    }
};
