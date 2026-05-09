#pragma once
#include <iostream>
#include <functional>  
#include "Node.h"

using std::cout; using std::cin; using std::function;

template<class T>
class Stack	// LAST IN FIRST OUT: LIFO
{
private:
	Node<T>* top;
	int size;

public:
	Stack() : top(nullptr), size(0) {}

	~Stack() 
	{
		Node<T>* current = top;	// actual a primero
		while (current != nullptr) {
			Node<T>* next = current->next; // guarda siguiente del ultimo porque si hay un valor en current
			delete current; // borra current porque no es nullptr
			current = next;	// actual es ahora el siguiente que guardo next
		}
	}
	
	void push(T dato);
	void pop();

	T peek();

	void clear();
	void print();

	bool isEmpty();
	int getSize();
};

template<class T>
bool Stack<T>::isEmpty() { return (size == 0); }

template<class T>
int Stack<T>::getSize() { return size; }


// push: pushea al inicio de la pila
template<class T>
void Stack<T>::push(T value) 
{
	Node<T>* newNode = new Node<T>(value);	//crea nuevo nodo
	newNode->next = top;	// el nodo nuevo siguiente apunta al top, caso si es vacio es nullptr por constructor, sino, 
	top = newNode;	// el top va hacer el nuevo nodo
	size++;
}

// pop: borra el primero en entrar de la pila
template<class T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "La Stack esta vacia\n"; return;	// si es empty
	}
	Node<T>* toDelete = top;	// un node de apoyo para borrar que apunta al ultimo agregado
	top = top->next;	// entonces top ahora va hacer su siguiente top->next
	delete toDelete;	//borra nodo actual y listo
	size--;
}

// peek: devuelve el top sin eliminar, de la pila
template<class T>
T Stack<T>::peek()
{
	if (isEmpty()) {
		cout << "La Stack esta vacia\n"; return T{};	// si es empty // T{}: define que retornar segun el tipo de dato del template ("", (0,1), '')
	}
	return top->data;
}

// clear: limpia todo el stack
template<class T>
void Stack<T>::clear() 
{
	Node<T>* current = top; // un nodito al actual ultimo elemento agregado 
	while (current != nullptr) // mientras que current sea diferente a nullptr
	{
		Node<T>* next = current->next;	// nodo next = current siguiente: esto si tiene un elemento el current actual
		delete current;	// aqui borra el current actual
		current = next;	// actualiza el current con el siguiente
	}
	top = nullptr;	// setea
	size = 0;	// setea
}

// print: imprime (cambiar segun datos de clase)
template<class T>
void Stack<T>::print() 
{
	if (isEmpty()) { cout << "[ empty ]\n"; return; }

	Node<T>* current = top; // un nodo actual de apoyo que es igual al ultimo valor agregado a la pila

	cout << "top -> [ ";
	
	while (current != nullptr) // mientras que current sea diferente que nullptr
	{
		cout << current->data;
		if (current->next != nullptr) // entre cada next si existe un valor imprime separador
			cout << " | ";
		current = current->next;	// actualiza
	}
	cout << " ] <- bottom\n"; //end
}