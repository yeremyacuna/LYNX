#pragma once
#include <iostream>
#include <string>

using namespace System;
using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

class User {
protected:
    string name;
    string dni;
    string password;

public:
    // User: constructor base vacio
    // deja nombre, dni y contra listos con strings vacios
    User() {
        name = "";
        dni = "";
        password = "";
    }

    // User: constructor base con datos iniciales del usuario
    User(string _name, string _dni, string _password) {
        name = _name;
        dni = _dni;
        password = _password;
    }

    virtual ~User() {}

    // getters: devuelven los datos basicos del usuario
    string getName() const  { return name; }
    string getDni() const  { return dni; }
    string getPassword() const { return password; }

    // setters: actualizan cada dato base del usuario
    void setName(string _name) { name = _name; }
    void setPassword(string _password) { password = _password; }
    void setDni(string _dni) { dni = _dni; }

    // Verifica si la contra coincide con la guardada
    bool checkPassword(string intento) {
        return intento == password;
    }
    // datos del usuario como texto
    
    virtual string toString() const {
        return "Nombre: " + name + " | DNI: " + dni;
    }

    // mostrar: imprime el usuario en una posicion concreta de la consola
    virtual void mostrar(int x, int& y) {
        Console::SetCursorPosition(x, y++);
        cout << toString() << endl;
    }

    // getCodigo: codigo simple usado como referencia al ordenar o identificar
    string getCodigo() { return dni; }
};
