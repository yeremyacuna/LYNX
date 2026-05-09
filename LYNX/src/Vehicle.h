#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string plate;   // placa
    string brand;   // marca
    string model;
    string color;
    int    year;

public:
    Vehicle() {
        plate = "";
        brand = "";
        model = "";
        color = "";
        year = 0;
    }

    Vehicle(string _plate, string _brand, string _model, string _color, int _year) {
        plate = _plate;
        brand = _brand;
        model = _model;
        color = _color;
        year = _year;
    }

    string getPlate() { return plate; }
    string getBrand() { return brand; }
    string getModel() { return model; }
    string getColor() { return color; }
    int    getYear() { return year; }

    void setColor(string _color) { color = _color; }
    void setPlate(string _plate) { plate = _plate; }
    void setBrand(string _brand) { brand = _brand; }
    void setModel(string _model) { model = _model; }
    void setYear(int _year) { year = _year; }
    

    string toString() {
        return plate + " | " + brand + " " + model + " | " + color + " | " + to_string(year);
    }

    void mostrar() {
        cout << "  Placa  : " << plate << endl;
        cout << "  Marca  : " << brand << endl;
        cout << "  Modelo : " << model << endl;
        cout << "  Color  : " << color << endl;
        cout << "  Anio   : " << year << endl;
    }

    string getCodigo() { return plate; }
};