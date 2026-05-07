#pragma once
#include "Nodo.h"

template<class T>
class stack
{
private:
	Nodo<T>* tope;
	int sz;
public:
	stack() {
		tope = nullptr;
		sz = 0;
	}
	
	void push(T dato);
	void pop();
	T top();
	bool empty();
	int size();

};

template<class T>
void stack<T>::push(T dato) {
	if (empty()) {
		tope = new Nodo<T>(dato);
	}
	else
	{
		tope = new Nodo<T>(dato, tope);
	}
	sz++;
}

template<class T>
void stack<T>::pop()
{
	if (empty())
	{
		return;
	}
	else
	{
		T elemento = (T)(tope->dato);
		tope = (Nodo<T>*) tope->siguiente;
	}
	sz--;
}

template<class T>
T stack<T>::top()
{
	if (empty())
	{
		return nullptr;
	}
	else
	{
		T elemento = (T)(tope->dato);
		return elemento;
	}
}

template<class T>
bool stack<T>::empty()
{
	return (tope == nullptr);
}

template<class T>
int stack<T>::size() {
	if (empty()) {
		return 0;
	}
	return sz;
}
