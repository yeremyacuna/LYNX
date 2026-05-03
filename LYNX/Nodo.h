#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
public:
	Nodo(T dato, Nodo<T>* sig = nullptr) {
		siguiente = sig;
		this->dato = dato;
	}

	T dato;

	Nodo<T>* siguiente;

private:
};