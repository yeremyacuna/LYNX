#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    string dni;
    string password;

public:

    User() {
        name = "";
        dni = "";
        password = "";
    }

    User(string _name, string _dni, string _password) {
        name = _name;
        dni = _dni;
        password = _password;
    }

    virtual ~User() {}

    string getName() { return name; }
    string getDni() { return dni; }
    string getPassword() { return password; }

    void setName(string _name) { name = _name; }
    void setPassword(string _password) { password = _password; }
    void setDni(string _dni) { dni = _dni; }

    // Verifica si la contra coincide con la guardada
    bool checkPassword(string intento) {
        return intento == password;
    }
    // datos del usuario como texto
    
    virtual string toString() {
        return "Nombre: " + name + " | DNI: " + dni;
    }

    virtual void mostrar() {
        cout << toString() << endl;
    }

    // lo usa LinkedList para ordenar la lista
    string getCodigo() { return dni; }
};