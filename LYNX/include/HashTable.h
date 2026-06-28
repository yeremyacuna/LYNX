#pragma once
#include <iostream>
#include <string>
#include <functional>

using std::string; using std::cout;

// clave = DNI (string), valor = T (Passenger o Driver)
// Colisiones por encadenamiento: cada casilla guarda una minilista de nodos

template <typename T>
class HashTable
{
private:
    //nodo de la cadena
    struct HashNode {
        string clave;
        T valor;
        HashNode* siguiente;
        HashNode(const string& k, const T& v) : clave(k), valor(v), siguiente(nullptr) {}
    };

    HashNode** tabla;   // arreglo de casillas
    int capacidad;      // cuantas casillas tiene el arreglo
    int cantidad;       // elementos que hay guardados

    static const int CAPACIDAD_INICIAL = 13;
    static constexpr float FACTOR_CARGA_MAX = 0.75f;

    // Convierte el DNI en un num de casilla
    int funcionHash(const string& clave) const
    {
        const int PRIMO = 31;
        long long suma = 0;
        /* Multiplica cada caracter por su posicion y por 31, asi DNIs
        parecidos no caen siempre en la misma casilla.*/
        for (int i = 0; i < (int)clave.size(); i++)
            suma += (long long)(unsigned char)clave[i] * (i + 1) * PRIMO;
        return (int)(suma % capacidad);
    }

    // siguiente numero primo >= n (mejor distribucion al redimensionar)
    int siguientePrimo(int n) const
    {
        if (n <= 2) return 2;
        if (n % 2 == 0) n++;
        while (true) {
            bool esPrimo = true;
            for (int i = 3; (long long)i * i <= n; i += 2)
                if (n % i == 0) { esPrimo = false; break; }
            if (esPrimo) return n;
            n += 2;
        }
    }

    // borra todos los nodos de todas las casillas (no borra el arreglo)
    void liberarTabla(HashNode** t, int cap)
    {
        for (int i = 0; i < cap; i++) {
            HashNode* actual = t[i];
            while (actual != nullptr) {
                HashNode* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            }
            t[i] = nullptr;
        }
    }

public:

    HashTable() : capacidad(CAPACIDAD_INICIAL), cantidad(0)  {
        tabla = new HashNode * [capacidad];
        for (int i = 0; i < capacidad; i++) tabla[i] = nullptr;
    }

    ~HashTable()
    {
        liberarTabla(tabla, capacidad);
        delete[] tabla;
    }

    // guarda (clave, valor). Si la clave ya existe, solo actualiza
    void insertar(const string& clave, const T& valor)
    {
        if ((float)(cantidad + 1) / capacidad > FACTOR_CARGA_MAX)
            redimensionar();

        int posicion = funcionHash(clave);
        HashNode* actual = tabla[posicion];

        while (actual != nullptr) {
            if (actual->clave == clave) { actual->valor = valor; return; }
            actual = actual->siguiente;
        }

        HashNode* nuevo = new HashNode(clave, valor);
        nuevo->siguiente = tabla[posicion];
        tabla[posicion] = nuevo;
        cantidad++;
    }

    // busca por clave; si existe, copia el valor en valorEncontrado y devuelve true
    bool buscar(const string& clave, T& valorEncontrado) const
    {
        int posicion = funcionHash(clave);
        HashNode* actual = tabla[posicion];
        while (actual != nullptr) {
            if (actual->clave == clave) { valorEncontrado = actual->valor; return true; }
            actual = actual->siguiente;
        }
        return false;
    }

    // true si la clave existe en la tabla
    bool contiene(const string& clave) const
    {
        int posicion = funcionHash(clave);
        HashNode* actual = tabla[posicion];
        while (actual != nullptr) {
            if (actual->clave == clave) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    /* duplica la capacidad(al siguiente primo) y reubica todo.
    se llama sola desde insertar() al superar 75% de uso.*/
    void redimensionar()
    {
        int capacidadVieja = capacidad;
        HashNode** tablaVieja = tabla;

        capacidad = siguientePrimo(capacidadVieja * 2 + 1); // ya actualizada antes de hashear

        tabla = new HashNode * [capacidad];
        for (int i = 0; i < capacidad; i++) tabla[i] = nullptr;

        for (int i = 0; i < capacidadVieja; i++) {
            HashNode* actual = tablaVieja[i];
            while (actual != nullptr) {
                HashNode* siguiente = actual->siguiente;

                int nuevaPosicion = funcionHash(actual->clave); // misma formula de siempre
                actual->siguiente = tabla[nuevaPosicion];
                tabla[nuevaPosicion] = actual;
                actual = siguiente;
            }
        }

        delete[] tablaVieja;
        cout << "[HashTable] Redimensionamiento: nueva capacidad = " << capacidad << "\n";
    }

    // vacia todas las casillas, pero el arreglo SIGUE existiendo y se puede reusar
    void limpiar()
    {
        liberarTabla(tabla, capacidad);
        cantidad = 0;
    }
};