#pragma once

#include "Node.h"
#include <iostream>

template<class T>
class queue {
private:
	Node<T>* inicio;
	Node<T>* fin;
	int sz;
public:
	queue() {
		this->inicio = nullptr;
		this->fin = nullptr;
		sz = 0;
	}

	void push(T v);
	void pop();
	T front();
	bool empty();
	int size();

};

template<class T>
bool queue<T>::empty() {
	return (inicio == nullptr);
}

template<class T>
void queue<T>::push(T v) {
	Node<T>* nodo = new Node<T>(v);
	if (empty()) {
		inicio = nodo;
		fin = inicio;
	}
	else {

		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = nullptr;
	sz++;
}

template<class T>
void queue<T>::pop() {
	if (empty()) {
		return;
	}

	T dato = inicio->dato;

	if (inicio == fin) {
		inicio = nullptr;
		fin = nullptr;
	}
	else {
		inicio = inicio->siguiente;
	}
	sz--;
}

template<class T>
T queue<T>::front() {
	if (empty()) {
		return nullptr;
	}
	T dato = inicio->dato;

	return dato;
}

template<class T>
int queue<T>::size() {
	if (empty()) {
		return 0;
	}
	return sz;
}
