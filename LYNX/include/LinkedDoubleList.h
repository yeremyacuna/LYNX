#pragma once
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::function;

template <typename T>
class DNode {
public:
    T     data;
    DNode<T>* prev;   // nuevo de que Node.h no tenia
    DNode<T>* next;

    DNode(T _data) {
        data = _data;
        prev = nullptr;   
        next = nullptr;
    }
};

template <typename T>
class LinkedDoubleList
{
private:
    DNode<T>* head;  // cabeza -> apunta al primer nodo
    DNode<T>* tail;  // cola -> apunta al ultimo nodo
    int size;   // tamaño -> para controlar el tamaño

    bool validIndex(int index) const     // para validar indice que no sobrepase ni que haga fuga
    {
        return (index >= 0 && index < size);
    }

public:
    LinkedDoubleList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedDoubleList()
    {
        DNode<T>* current = head;
        while (current != nullptr) {       // mientras que la cabeza actual sea diferente que nullptr
            DNode<T>* next = current->next;      // el nodo siguiente va a mover la cabeza al next entonces ya que hay un valor en actual
            delete current;                     // va a borrar la cabeza que estaba apuntando actualment
            current = next;                     // luego actual va hacer el siguiente o next como su nueva cabeza
        }
    }

    bool isEmpty() const { return size == 0; }    // si es vacio
    int  getSize() { return size; }         // get tamaño

    // pushFront: inserta valor al inicio
    void pushFront(T value)  // complejidad O(1)
    {
        DNode<T>* newNode = new DNode<T>(value);
        if (head == nullptr) {  // si es vacio
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;   /// el nuevo nodo apunta a la cabeza y se conecta,
            head->prev = newNode;   // ---->>>> old head mira atras al nuevo Y SE CONECTA DE ATRAS TAMBIEN
            head = newNode;
        }
        size++;
    }

    // pushBack: inserta valor al ultimo
    void pushBack(T value)      // esto seria O(1), en ves de insertar normalmente reccorriendo toda la lista y al final insertar
    {
        DNode<T>* newNode = new DNode<T>(value);

        if (tail == nullptr) {    // es decir si; la cola es vacia entonces no hay ningun valor
            head = newNode;    
            tail = newNode;
        }
        else {
            newNode->prev = tail;       // --->>> nuevo nodo mira atrAs al old tail
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

        DNode<T>* newNode = new DNode<T>(value);
        DNode<T>* prev = head; // prev = previous -> anterior, nodo anterior apunta a cabezita

        for (int i = 0; i < index - 1; i++) // -1 el nodo anterior solo trabaja previous
        {
            prev = prev->next;  // es decir: cabeza del anterior nodo que va antes del index que quiero, va a apuntar asu next
        }

        DNode<T>* afterNew = prev->next;
        newNode->prev = prev;
        newNode->next = afterNew;
        prev->next = newNode;       // y el valor antiguo apuntara al nuevo nodo
        afterNew->prev = newNode;
        size++;
    }

    // popFront: remueve el primer nodo
    void popFront() // complejidad O(1)
    {
        if (isEmpty())
        {
            cout << "La LinkedDoubleList esta vacia\n";
            return;
        }

        DNode<T>* toDelete = head; // para borrar
        head = head->next;  // la cabeza va hacer ahora el siguiente
        delete toDelete; // se borro el primer elemento o nodo

        if (head == nullptr) { 
            tail = nullptr; 
        }
        else 
            head->prev = nullptr;

        size--;
    }

    // popBack: remueve el ultimo nodo
    void popBack() // complejidad O(1)
    {
        if (isEmpty())
        {
            cout << "La LinkedDoubleList esta vacia\n";
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

        DNode<T>* toDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete toDelete;
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

        DNode<T>* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }




    // ===================== others function falta
    T get(int index) const {
        if (!validIndex(index)) {
            cout << "[LinkedDoubleList] get(" << index << ") out of range. size=" << size << "\n";
            return T{};
        }
        DNode<T>* current = head;
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
        DNode<T>* current = head;
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
        DNode<T>* current = head;
        int n = 0;
        while (current != nullptr) {
            if (current->data == value) n++;
            current = current->next;
        }
        return n;
    }

    void reverse() {
        if (size <= 1) return;
        DNode<T>* current = head;
        while (current != nullptr) {
            DNode<T>* tmp = current->prev;
            current->prev = current->next;
            current->next = tmp;
            current = current->prev;  // avanza (prev porque ya se intercambio)
        }
        DNode<T>* tmp = head;
        head = tail;
        tail = tmp;
    }

    void clear() {
        DNode<T>* current = head;
        while (current != nullptr) {
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print() {
        if (isEmpty()) { cout << "[ empty ]\n"; return; }
        DNode<T>* current = head;
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

    void printReverse() {
        DNode<T>* current = tail;
        while (current != nullptr) {
            cout << current->data;
            current = current->prev;
        }
    }

   // LAMBDAS
   
   /* LAMBDA 1: actualiza todos los elementos que cumplan el criterio aplicando una transformacion
   Ej: activos.updateIf([](Trip t){ return t.getTripId()=="TRP-10001"; },
                          [](Trip& t){ t.setStatus("completado"); });
   Puede servir para cambiar estado de un viaje activo sin tener que buscarlo manualmente*/
    void updateIf(function<bool(T)> criterio, function<void(T&)> transformar) {
        auto aplicar = [](DNode<T>* nodo, function<bool(T)> crit, function<void(T&)> transf) {
            while (nodo != nullptr) {
                if (crit(nodo->data)) transf(nodo->data);
                nodo = nodo->next;
            }
            };
        aplicar(head, criterio, transformar);
    }

    // LAMBDA 2: cuenta cuantos elementos cumplen un criterio
    // Ej: int activos = lista.countIf([](Trip t){ return t.getStatus()=="en_curso"; });
    int countIf(function<bool(T)> criterio) {
        auto contar = [](DNode<T>* nodo, function<bool(T)> fn) -> int {
            int n = 0;
            while (nodo != nullptr) { if (fn(nodo->data)) n++; nodo = nodo->next; }
            return n;
            };
        return contar(head, criterio);
    }
};
