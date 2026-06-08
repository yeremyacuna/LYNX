#pragma once
#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

//  Guarda el origen, destino, precio, estado y quien lo hizo.
//  Estados posibles: "pendiente", "en_curso", "completado", "cancelado"

class Trip {
private:
    string tripId;
    string origin;
    string destination;
    float  price;
    string status;
    string date;
    string driverName;
    string driverDni;
    string passengerDni;
    int tipe;

public:

    // Trip: constructor vacio
    // deja el viaje en estado pendiente y con todos sus campos inicializados
    Trip() {
        tripId = "";
        origin = "";
        destination = "";
        price = 0.0f;
        status = "pendiente";
        date = "";
        driverName = "";
        driverDni = "";
        passengerDni = "";
        tipe = 0;
    }

    // Trip: constructor principal
    // crea un viaje base con los datos mas importantes y lo deja pendiente por defecto
    Trip(string _id, string _origin, string _destination,
        float _price, string _driverName, string _driverDni, string _passengerDni, string _date)
    {
        tripId = _id;
        origin = _origin;
        destination = _destination;
        price = _price;
        status = "pendiente";
        driverName = _driverName;
        driverDni = _driverDni;
        passengerDni = _passengerDni;
        date = _date;
        tipe = 0;
    }

    // getters: devuelven cada dato guardado del viaje
    string getTripId() const { return tripId; }
    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    float  getPrice() const { return price; }
    string getStatus() const { return status; }
    string getDate() const { return date; }
    string getDriverName()  const { return driverName; }
    string getDriverDni() const { return driverDni; }
    string getPassengerDni() const { return passengerDni; }
    int getTipe() const { return tipe; }

    // setters: actualizan los atributos del viaje segun su avance o carga desde archivo
    void setStatus(string s) { status = s; }
    void setPrice(float p) { price = p; }
    void setOrigin(string s) { origin = s; }
    void setDestination(string s) { destination = s; }
    void setTipe(int t) { tipe = t; }
    void setPassengerDni(string d) { passengerDni = d; }
    void setTripId(string s) { tripId = s; }
    void setDriverName(string s) { driverName = s; }
    void setDriverDni(string s) { driverDni = s; }
    void setDate(string s) { date = s; }

    /*segun el tipo de servicio y los km estimados.
    Tipo 1 = Economico  -> S/ 1.20 por km
    Tipo 2 = Estandar   -> S/ 1.80 por km
    Tipo 3 = Premium    -> S/ 2.50 por km
    Se suma S/ 3.00 de costo base en todos los casos*/
    float calcPrice(int tipo, float km) {
        setTipe(tipo);
        float tarifa = 0.0f;
        if (tipo == 1) tarifa = 1.20f;
        else if (tipo == 2) tarifa = 1.80f;
        else                tarifa = 2.50f;
        price = tarifa * km + 3.0f;
        return price;
    }

    // toString: convierte el viaje en una linea facil de mostrar en listas
    string toString() {
        return tripId + " | " + origin + " -> " + destination +
            " | S/ " + to_string(price) +
            " | " + status +
            " | Conductor: " + driverName +
            " | Fecha: " + date;
    }

    // LAMBDA 1
    /* Devuelve una etiqueta del estado del viaje
    Se usa en el historial para que el pasajero vea si su viaje fue completado, cancelado, etc*/
    string getStatusLabel() {
        auto etiqueta = [](string est) -> string {
            if (est == "completado") return "[OK] " + est;
            if (est == "cancelado")  return "[XX] " + est;
            if (est == "en_curso")   return "[>>] " + est;
            return                          "[--] " + est;
            };
        return etiqueta(status);
    }

    // LAMBDA 2
    /* Verifica si el viaje esta completado
    Se usa en el historial para filtrar y sumar solo
    los viajes que realmente se realizaron.*/
    bool estaCompletado() {
        auto verificar = [](string est) -> bool {
            return est == "completado";
            };
        return verificar(status);
    }

    //  RECURSIVIDAD

    /* Suma el precio total de los viajes COMPLETADOS en un arreglo

    Si ya no hay mas viajes (indice == total) -> devuelve 0
    Si el viaje actual esta completado        -> suma su precio y sigue
    Si esta cancelado o pendiente             -> solo sigue

    Ej:
    Trip historial[4] = { t1, t2, t3, t4 };
    float total = t1.sumarGastado(historial, 0, 4);*/
    float sumarGastado(Trip arreglo[], int indice, int total) {
        if (indice == total) return 0.0f;                           // caso base: ya no hay mas
        float resto = sumarGastado(arreglo, indice + 1, total);     // suma el resto primero
        if (arreglo[indice].estaCompletado())
            return arreglo[indice].getPrice() + resto;              // este cuenta
        return resto;                                               // este no
    }

    // mostrar: imprime el detalle del viaje en la consola usando coordenadas
    void mostrar(int x, int& y) {
        Console::SetCursorPosition(x, y++); cout << "ID         : " << tripId << endl;
        Console::SetCursorPosition(x, y++); cout << "Origen     : " << origin << endl;
        Console::SetCursorPosition(x, y++); cout << "Destino    : " << destination << endl;
        Console::SetCursorPosition(x, y++); cout << "Precio     : S/ " << price << endl;
        Console::SetCursorPosition(x, y++); cout << "Estado     : " << getStatusLabel() << endl;
        Console::SetCursorPosition(x, y++); cout << "Conductor  : " << driverName << endl;
        Console::SetCursorPosition(x, y++); cout << "Fecha      : " << date << endl;
        Console::SetCursorPosition(x, y++); cout << "-----------------------" << endl;
    }

    // getCodigo: devuelve el id del viaje como codigo de referencia
    string getCodigo() { return tripId; }
};
