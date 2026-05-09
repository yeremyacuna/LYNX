#pragma once
#include <iostream>
#include <functional>  
#include "Node.h"

using std::cout; using std::cin; using std::function;

template <typename T>
class LinkedList {
private:
    Node<T>* head;  // cabeza -> apunta al primer nodo
    Node<T>* tail;  // cola -> apunta al ultimo nodo
    int size;   // tamaño -> para controlar el tamaño

    bool validIndex(int index) const      // para validar indice que no sobrepase ni que haga fuga
    {
        return (index >= 0 && index < size);    
    }

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList()
    {
        Node<T>* current = head;
        while (current != nullptr) {       // mientras que la cabeza actual sea diferente que nullptr
            Node<T>* next = current->next;      // el nodo siguiente va a mover la cabeza al next entonces ya que hay un valor en actual
            delete current;                     // va a borrar la cabeza que estaba apuntando actualment
            current = next;                     // luego actual va hacer el siguiente o next como su nueva cabeza
        }
    }

    bool isEmpty() const { return size == 0; }    // si es vacio
    int  getSize() { return size; }         // get tamaño

    // pushFront: inserta valor al inicio
    void pushFront(T value)  // complejidad O(1)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;                   // nuevo nodo apunta al antiguo primer nodo que estaaba en head

        head = newNode;     // ahora la cabezita de newNode sera nuestro head actual que seria el primero

        if (tail == nullptr)
        {
            tail = newNode; // head y tail apuntan a ese nodo
        }

        size++;
    }

    // pushBack: inserta valor al ultimo
    void pushBack(T value)      // esto seria O(1), en ves de insertar normalmente reccorriendo toda la lista y al final insertar
    {
        Node<T>* newNode = new Node<T>(value);

        if (tail == nullptr) {    // es decir si; la cola es vacia entonces no hay ningun valor
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;       // si no es asi, entonces el vacio que apuntaba tail es ahora el nuevo valor
            tail = newNode;             // actualiza que el nuevo valor es ahora tail , la colita
        }

        size++;
    }

    // insert: aqui se puede insertar un valor y poner el indice exactamente donde tu quieres
    void insert(int index, T value)  // complejidad O(n)
    {
        if (index < 0 || index > size)
        {
            cout << "Error, index incorrecto o fuera de rango\n";
            return;
        }

        if (index == 0)
        {
            pushFront(value);
            return;
        }

        if (index == size) // cero == cero || 4 == 4, si agrega en la misma poscion final
        {
            pushBack(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* prev = head; // prev = previous -> anterior, nodo anterior apunta a cabezita

        for (int i = 0; i < index - 1; i++) // -1 el nodo anterior solo trabaja previous
        {
            prev = prev->next;  // es decir: cabeza del anterior nodo que va antes del index que quiero, va a apuntar asu next
        }

        newNode->next = prev->next;     // mi nuevo valor o nodo, apuntara al nodo que estaba despues de prev
        prev->next = newNode;   // y el valor antiguo apuntara al nuevo nodo
        size++;
    }

    // popFront: remueve el primer nodo
    void popFront() // complejidad O(1)
    {
        if (isEmpty())
        {
            cout << "La LinkedList esta vacia\n";
            return;
        }

        Node<T>* toDelete = head; // para borrar
        head = head->next;  // la cabeza va hacer ahora el siguiente
        delete toDelete; // se borro el primer elemento o nodo

        if (head == nullptr) { tail = nullptr; }
        size--;
    }

    // popBack: remueve el ultimo nodo
    void popBack() // complejidad O(n)
    {
        if (isEmpty())
        {
            cout << "La LinkedList esta vacia\n";
            return;
        }

        if (head == tail)   // en el caso hubiera solo un elemento
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }

        Node<T>* prev = head;

        while (prev->next != tail) { // mientras que previous siguiente no sea igual a la cola
            prev = prev->next; // guardamos el anterior de tail
        }
        delete tail;    // borramos tail

        tail = prev;    // tail igual al anterior de su tail original se actualiza
        tail->next = nullptr;   // su siguiente es nullptr
        size--;
    }
    
    // remove: para borrar nodo segun indice
    void remove(int index) {
        if (!validIndex(index)) {
            cout << "Error, index incorrecto o fuera de rango";
            return;
        }

        if (index == 0) { popFront(); return; } // if es en la primera posicion
        if (index == size - 1) { popBack();  return; }  // if es en la ultima

        Node<T>* prev = head;   // nodo anterior
        Node<T>* current = head->next;  // nodo a borrar

        for (int i = 1; i < index; i++) {
            prev = prev->next;  // previous apunta a siguiente
            current = current->next;    // actual apunta a su siguiente es decir 1 posicion mas que previos
        }

        prev->next = current->next; // ahora se conectan , 
        delete current; // elimina lo que queria de actual
        size--;
    }




    // ===================== others function falta
    T get(int index) const {
        if (!validIndex(index)) {
            cout << "[LinkedDoubleList] get(" << index << ") out of range. size=" << size << "\n";
            return T{};
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        return current->data;
    }

    T front() const {
        if (isEmpty()) { cout << "[LinkedDoubleList] front() — empty\n"; return T{}; }
        return head->data;
    }

    T back() {
        if (isEmpty()) { cout << "[LinkedDoubleList] back() — empty\n"; return T{}; }
        return tail->data;
    }

    int search(T value) {
        Node<T>* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    bool contains(T value) { return search(value) != -1; }

    int count(T value) {
        Node<T>* current = head;
        int n = 0;
        while (current != nullptr) {
            if (current->data == value) n++;
            current = current->next;
        }
        return n;
    }

    void reverse() {
        if (size <= 1) return;
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        tail = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print() {
        if (isEmpty()) { cout << "[ empty ]\n"; return; }
        Node<T>* current = head;
        cout << "[ ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << " -> nullptr ]\n";
    }

    void printInfo() {
        cout << "size=" << size;
        if (!isEmpty())
            cout << " | head=" << head->data << " | tail=" << tail->data;
        cout << "\n";
    }

    // LAMBDAS

    // LAMBDA 1: recorre la lista y ejecuta una accion sobre cada elemento
    // Ej: lista.forEach([](Driver d){ d.mostrar(); });
    void forEach(function<void(T)> accion) {
        auto recorrer = [&](Node<T>* nodo, function<void(T)> fn) {
            while (nodo != nullptr) { fn(nodo->data); nodo = nodo->next; }
            };
        recorrer(head, accion);
    }

    // LAMBDA 2: filtra elementos que cumplen un criterio y retorna una nueva lista
    // Ej: auto libres = lista.filter([](Driver d){ return d.getIsAvailable(); });
    LinkedList<T> filter(function<bool(T)> criterio) {
        auto cumple = [&](Node<T>* nodo, LinkedList<T>& resultado, function<bool(T)> fn) {
            while (nodo != nullptr) { if (fn(nodo->data)) resultado.pushBack(nodo->data); nodo = nodo->next; }
            };
        LinkedList<T> resultado;
        cumple(head, resultado, criterio);
        return resultado;
    }

    // LAMBDA 3: busca y retorna el primer elemento que cumple el criterio, o T{} si no hay
    // Ej: Passenger p = lista.findFirst([&](Passenger p){ return p.getDni() == dni; });
    T findFirst(function<bool(T)> criterio) {
        auto buscar = [](Node<T>* nodo, function<bool(T)> fn) -> T {
            while (nodo != nullptr) { if (fn(nodo->data)) return nodo->data; nodo = nodo->next; }
            return T{};
            };
        return buscar(head, criterio);
    }


    /*
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
    */

};
