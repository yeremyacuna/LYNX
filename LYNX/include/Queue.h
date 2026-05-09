#pragma once
#include <iostream>
#include <functional>  
#include "Node.h"

using std::cout; using std::cin; using std::function;

template <class T>
class Queue // FIRST IN FIRST OUT: FIFO 
{
private:
    Node<T>* front;     // first
    Node<T>* back;      // last el ultimo
    int      size;

public:
    Queue() : front(nullptr), back(nullptr), size(0) {}

    ~Queue() {
        Node<T>* current = front;   // un nodo actual que es igual al front
        while (current != nullptr)  // va a borrar siempre y cuando sea diferente que nullptr
        {
            Node<T>* next = current->next;  // va haber un nodo siguiente que tome el valor dell valor siguiente de la cabeza current
            delete current; // borra valor current, pero el siguiente se quedo guardado en next.
            current = next; // borra y setea current con next
        }
    }

    void enqueue(T value);
    void dequeue();

    T getFront() const;
    T getBack() const;

    void clear();
    void print();

    bool isEmpty() const;
    int  getSize() const;

    // LAMBDA

    /* LAMBDA 1: encola solo si el elemento cumple una condicion
    Ej: cola.enqueueIf(trip, [](Trip t){ return t.getPrice() > 0; });
    Evita encolar viajes invalidos sin hacer la verificacion afuera*/
    bool enqueueIf(T value, function<bool(T)> condicion) {
        auto validar = [](T val, function<bool(T)> cond) -> bool { return cond(val); };
        if (validar(value, condicion)) { enqueue(value); return true; }
        return false;
    }

    // LAMBDA 2: recorre toda la cola aplicando una accion sobre cada elemento sin modificarla
    // Ej: cola.forEach([](Trip t){ t.mostrar(); });
    void forEach(function<void(T)> accion) {
        auto recorrer = [](Node<T>* nodo, function<void(T)> fn) {
            while (nodo != nullptr) { fn(nodo->data); nodo = nodo->next; }
            };
        recorrer(front, accion);
    }

    // LAMBDA 3: suma un valor numerico extraido de cada elemento de la cola
    // Ej: float total = cola.sumBy([](Trip t){ return t.getPrice(); });
    float sumBy(function<float(T)> extractor) {
        auto sumar = [](Node<T>* nodo, function<float(T)> fn) -> float {
            float acum = 0.0f;
            while (nodo != nullptr) { acum += fn(nodo->data); nodo = nodo->next; }
            return acum;
            };
        return sumar(front, extractor);
    }
};

template <class T>
bool Queue<T>::isEmpty()  const { return size == 0; }
template <class T>
int  Queue<T>::getSize()  const { return size; }

// enqueue: encolar o agregar un elemento al final de la cola
template <class T>
void Queue<T>::enqueue(T value) 
{
    Node<T>* newNode = new Node<T>(value);  //crea nuevo nodo
    if (back == nullptr)    // si el back es nullptr, porque queue es vacia 
    {
        front = newNode;    // entonces el front sera el nuevo valor y back tambien
        back = newNode;
    }
    else 
    {
        back->next = newNode;  // si no es el caso , el back next apuntara al nuevo nodo
        back = newNode; // back es mi nuevo nodo
    }
    size++;
}

// dequeue; desencolar o quitar el primer elemento de la cola
template <class T>
void Queue<T>::dequeue() 
{
    if (isEmpty()) {
        cout << "La Queue esta vacia\n"; return;	// si es empty
    }

    Node<T>* toDelete = front;  // va a borrarse el primero
    front = front->next;    // ahora nuestro primer elementito es el siguiente next
    delete toDelete;

    if (front == nullptr)   // si front es nullptr es decir solo tiene 1 elemento tambien back es null
        back = nullptr;

    size--;
}

// getFront(): obtener el valor primero de la queue 
template <class T>
T Queue<T>::getFront() const 
{
    if (isEmpty()) { cout << "La Queue esta vacia\n"; return T{}; } // si es empty // T{}: define que retornar segun el tipo de dato del template ("", (0,1), '')
    
    return front->data;
}

// getBack(): obtener el valor ultimo de la queue 
template <class T>
T Queue<T>::getBack() const {
    if (isEmpty()) { cout << "La Queue esta vacia\n"; return T{}; }// si es empty // T{}: define que retornar segun el tipo de dato del template ("", (0,1), '')
    return back->data;
}

// clear: limpia todo el queue
template <class T>
void Queue<T>::clear() {
    Node<T>* current = front;   // un nodo nuevo q apunta al primer elemento

    while (current != nullptr) // mientras que este lleno;
    {
        Node<T>* next = current->next;  // logica de destructor
        delete current;
        current = next;
    }

    front = nullptr;   // seteamos todo
    back = nullptr;
    size = 0;
}

// print: imprime (cambiar segun datos de clase)
template <class T>
void Queue<T>::print() {
    if (isEmpty()) { cout << "[ empty ]\n"; return; }

    Node<T>* current = front; // un nuevo nodo que sea a front el primer elemento
    
    cout << "front -> [ ";
    while (current != nullptr) // mientras que current este lleno
    {
        cout << current->data.toString();  // imprime

        if (current->next != nullptr) // separa entre cada puntero a next
            cout << " | ";

        current = current->next; // actual se actualiza con el siguiente;
    }
    cout << " ] <- back\n";
}