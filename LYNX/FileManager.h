#pragma once
#include <fstream>  // ofstream ifstream
#include <sstream>  // stringstream
#include <string>
#include <vector>
#include <iostream>
#include "src/Driver.h"
#include "src/Passenger.h"
    
using std::string; using std::vector; using std::cout; using std::cin; using std::stringstream; using std::getline;


//  Uso basico:
//      FileManager fm;
//      fm.guardarDriversTXT(lista);
//      vector<Driver> drivers = fm.leerDriversTXT();
// ============================================================

class FileManager 
{
private:
    char separador; // separador de atributos de cada clase en el TXT = |
    string rutaDrivers;
    string rutaPassengers;
    string rutaTrips;

    // ----------------------------------------------------------
    //  Divide una linea en partes usando el separador
    //  "DRV001|Cristiano|4.8"  ->  ["DRV001", "Cristiano", "4.8"]
    // ----------------------------------------------------------

    vector<string> dividirLinea(string linea) 
    {
        vector<string> partes;  // arreglo o vector de todas las partes que hay en una linea txt
        stringstream cinString(linea);  // cinString es como el lector de cin pero ya no de teclado si no de strings
        string parte; // temp
        while (std::getline(cinString, parte, separador))
        {
            partes.push_back(parte);
        }
        return partes;
    }

    string boolAString(bool valor) // convierte bool a 1 o 0 para guardar en txt
    {
        if (valor) return "1";
        return "0";
    }

    bool stringABool(string texto) // convierte "1" o "0" leido del txt de vuelta a bool
    {
        if (texto == "1") return true;
        return false;
    }

    void copiarAChar(char destino[], string origen, int tamano) // para binarios
    {
        int i = 0;

        for (; i < origen.length() && i < tamano - 1; i++)
        {
            destino[i] = origen[i];
        }

        destino[i] = '\0';
    }

public:
    FileManager() {
        separador = '|';
        rutaDrivers = "assets/drivers.txt";
        rutaPassengers = "assets/passengers.txt";
        rutaTrips = "assets/trips.txt";
    }

   
    FileManager(char _separador)  // constructor si quiero usar otro separador
    {
        separador = _separador;
        rutaDrivers = "assets/drivers.txt";
        rutaPassengers = "assets/passengers.txt";
        rutaTrips = "assets/trips.txt";
    }

    ~FileManager()
    {

    }

    //  Formato de cada linea en drivers.txt:
    //  driverId|name|dni|password|rating|isAvailable|totalTrips|totalEarnings|plate|brand|model|color|year

    bool guardarDriversTXT(const vector<Driver>& listaDeDrivers) // Guardar a nuevo conductor registrado
    {
        // Abriendo el archivo o creando si no existe:
        std::ofstream MyFile(rutaDrivers);      // MyFile: como esta con ofstream, sirve para escribir

        if (!MyFile.is_open()) {
            std::cout << "[ERROR] No se pudo abrir el archivo: " << rutaDrivers << "\n";
            return false;
        }

        for (int i = 0; i < (int)listaDeDrivers.size(); i++) {
            const Driver& d = listaDeDrivers[i];

            MyFile << d.getDriverId() << separador
                << d.getName() << separador
                << d.getDni() << separador
                << d.getPassword() << separador
                << d.getRating() << separador
                << boolAString(d.getIsAvailable()) << separador
                << d.getTotalTrips() << separador
                << d.getTotalEarnings() << separador
                << d.getVehicle().getPlate() << separador
                << d.getVehicle().getBrand() << separador
                << d.getVehicle().getModel() << separador
                << d.getVehicle().getColor() << separador
                << d.getVehicle().getYear()
                << "\n";
        }

        MyFile.close();
        std::cout << "Drivers guardados correctamente: " << rutaDrivers << "\n";
        return true;
    }

    vector<Driver> leerDriversTXT() {

        vector<Driver> listaDeDrivers;
        std::ifstream MyFile(rutaDrivers);   // MyFile: como esta con ifstream, sirve para leer

        if (!MyFile.is_open()) {

            std::ofstream crearArchivo(rutaDrivers); // crea si no existe o no lo abre o no lee
            crearArchivo.close();   // crea y cierra

            MyFile.open(rutaDrivers);

            std::cout << "[ALERTA] El archivo se acaba de crear: " << rutaDrivers << "\n";
            return listaDeDrivers;
        }

        std::string linea;
        while (std::getline(MyFile, linea))
        {
            if (linea.empty())
                continue;

            vector<string> p = dividirLinea(linea);

            if ((int)p.size() < 13) // 13 por la cantidad de atributos
            {
                std::cout << "[PELIGRO] Linea incompleta, se omite.\n";
                continue;
            }

            Vehicle v; // Armar Vehicle con los campos 9 al 13 (arr[8-12])
            v.setPlate(p[8]);
            v.setBrand(p[9]);
            v.setModel(p[10]);
            v.setColor(p[11]);
            v.setYear(std::stoi(p[12]));

            Driver d;  // Armar Driver con los campos 1 al 8 (arr[0-7])
            d.setDriverId(p[0]);
            d.setName(p[1]);
            d.setDni(p[2]);
            d.setPassword(p[3]);
            d.setRating(std::stof(p[4]));
            d.setAvailable(stringABool(p[5]));
            d.setTotalTrips(std::stoi(p[6]));
            d.setTotalEarnings(std::stof(p[7]));
            d.setVehicle(v);

            listaDeDrivers.push_back(d);
        }

        MyFile.close();
        std::cout << "[OK] " << listaDeDrivers.size() << " drivers leidos de: " << rutaDrivers << "\n";
        return listaDeDrivers;
    }


    //  Formato de cada linea en passengers.txt:
    //  passengerId|name|dni|password|rating|totalTrips|totalSpent

    bool guardarPassengersTXT(const vector<Passenger>& listaDePassengers) 
    {
        // Abriendo el archivo o creando si no existe :
        std::ofstream MyFile(rutaPassengers);      // MyFile: como esta con ofstream, sirve para escribir

        if (!MyFile.is_open()) {
            std::cout << "[ERROR] No se pudo abrir el archivo: " << rutaPassengers << "\n";
            return false;
        }

        for (int i = 0; i < (int)listaDePassengers.size(); i++) {
            const Passenger& p = listaDePassengers[i];

            MyFile << p.getPassengerId() << separador
                << p.getName() << separador
                << p.getDni() << separador
                << p.getPassword() << separador
                << p.getRating() << separador
                << p.getTotalTrips() << separador
                << p.getTotalSpent()
                << "\n";
        }

        MyFile.close();
        std::cout << "[OK] Passengers guardados en: " << rutaPassengers << "\n";
        return true;
    }


    vector<Passenger> leerPassengersTXT() {
        vector<Passenger> listaDePassengers;
        std::ifstream MyFile(rutaPassengers);

        if (!MyFile.is_open()) {
            std::ofstream crearArchivo(rutaPassengers); // crea si no existe o no lo abre o no lee
            crearArchivo.close();   // crea y cierra

            MyFile.open(rutaPassengers);

            std::cout << "[ALERTA] El archivo se acaba de crear: " << rutaPassengers << "\n";
            return listaDePassengers;
        }

        std::string linea;
        while (std::getline(MyFile, linea)) {

            if (linea.empty()) continue;

            vector<string> p = dividirLinea(linea);

            if ((int)p.size() < 7) {
                std::cout << "[PELIGRO] Linea incompleta, se omite.\n";
                continue;
            }

            Passenger pas;  // ARMAR PASASENGER
            pas.setPassengerId(p[0]);
            pas.setName(p[1]);
            pas.setDni(p[2]);
            pas.setPassword(p[3]);
            pas.setRating(std::stof(p[4]));
            pas.setTotalTrips(std::stoi(p[5]));
            pas.setTotalSpent(std::stof(p[6]));

            listaDePassengers.push_back(pas);
        }

        MyFile.close();
        std::cout << "[OK] " << listaDePassengers.size() << " passengers leidos de: " << rutaPassengers << "\n";
        return listaDePassengers;
    }


    //  Formato de cada linea en trips.txt:
    //  tripId|origin|destination|price|tipe|status|driverName|passengerDni|date

    bool guardarTripsTXT(const vector<Trip>& listaDeTrips) 
    {
        // Abriendo el archivo o creando si no existe :
        std::ofstream MyFile(rutaTrips);      // MyFile: como esta con ofstream, sirve para escribir

        if (!MyFile.is_open()) {
            std::cout << "[ERROR] No se pudo abrir el archivo: " << rutaTrips << "\n";
            return false;
        }

        for (int i = 0; i < (int)listaDeTrips.size(); i++) {
            const Trip& t = listaDeTrips[i];

            MyFile << t.getTripId() << separador
                << t.getOrigin() << separador
                << t.getDestination() << separador
                << t.getPrice() << separador
                << t.getTipe() << separador
                << t.getStatus() << separador
                << t.getDriverName() << separador
                << t.getPassengerDni() << separador
                << t.getDate()
                << "\n";
        }

        MyFile.close();
        std::cout << "[OK] Trips guardados en: " << rutaTrips << "\n";
        return true;
    }


    vector<Trip> leerTripsTXT() {
        vector<Trip> listaDeTrips;
        std::ifstream MyFile(rutaTrips);

        if (!MyFile.is_open()) {
            std::ofstream crearArchivo(rutaTrips); // crea si no existe o no lo abre o no lee
            crearArchivo.close();   // crea y cierra

            MyFile.open(rutaTrips);

            std::cout << "[ALERTA] El archivo se acaba de crear: " << rutaTrips << "\n";
            return listaDeTrips;
        }

        std::string linea;
        while (std::getline(MyFile, linea)) {

            if (linea.empty()) continue;

            vector<std::string> p = dividirLinea(linea);

            if ((int)p.size() < 9) {
                std::cout << "[PELIGRO] Linea incompleta, se omite.\n";
                continue;
            }

            Trip t;
            t.setTripId(p[0]);
            t.setOrigin(p[1]);
            t.setDestination(p[2]) ;
            t.setPrice(std::stof(p[3])) ;
            t.setTipe(std::stoi(p[4])) ;
            t.setStatus(p[5]) ;
            t.setDriverName(p[6]) ;
            t.setPassengerDni(p[7]) ;
            t.setDate(p[8]);

            listaDeTrips.push_back(t);
        }

        MyFile.close();
        std::cout << "[OK] " << listaDeTrips.size() << " trips leidos de: " << rutaTrips << "\n";
        return listaDeTrips;
    }
    
    /*
    // ==========================================================
    //  STRUCTS PARA BINARIO
    //  El binario necesita tamanos fijos en memoria.
    //  std::string no tiene tamano fijo, asi que aqui usamos
    //  char[] de tamano definido. Son SOLO para el archivo,
    //  no reemplazan tus clases del dominio.
    // ==========================================================

    /*
    struct DriverBin {
        char  driverId[20];
        char  name[50];
        char  dni[10];
        char  password[30];
        float rating;
        bool  isAvailable;
        int   totalTrips;
        float totalEarnings;
        // campos de Vehicle aplanados aqui
        char  plate[10];
        char  brand[30];
        char  model[30];
        char  color[20];
        int   year;
    };

    struct PassengerBin {
        char  passengerId[20];
        char  name[50];
        char  dni[10];
        char  password[30];
        float rating;
        int   totalTrips;
        float totalSpent;
    };

    struct TripBin {
        char  tripId[20];
        char  passengerId[20];
        char  driverId[20];
        char  origin[60];
        char  destination[60];
        float price;
        char  status[15];
        char  date[15];
    };
   
    // ==========================================================
    //  BINARIO  -  DRIVER
    // ==========================================================

    bool guardarDriversBIN(std::vector<Driver> lista, std::string archivo) {
        std::ofstream file(archivo, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "[ERROR] No se pudo abrir: " << archivo << "\n";
            return false;
        }

        for (int i = 0; i < (int)lista.size(); i++) {
            Driver d = lista[i];

            DriverBin db;
            memset(&db, 0, sizeof(DriverBin));  // limpia basura de memoria

            copiarAChar(db.driverId, d.getDriverId(), 20);
            copiarAChar(db.name, d.getName(), 50);
            copiarAChar(db.dni, d.getDni(), 10);
            copiarAChar(db.password, d.getPassword(), 30);
            db.rating = d.getRating();
            db.isAvailable = d.getIsAvailable();
            db.totalTrips = d.getTotalTrips();
            db.totalEarnings = d.getTotalEarnings();
            copiarAChar(db.plate, d.getVehicle().getPlate(), 10);
            copiarAChar(db.brand, d.getVehicle().getBrand(), 30);
            copiarAChar(db.model, d.getVehicle().getModel(), 30);
            copiarAChar(db.color, d.getVehicle().getColor(), 20);
            db.year = d.getVehicle().getYear();

            // escribe exactamente sizeof(DriverBin) bytes en disco
            file.write((char*)&db, sizeof(DriverBin));
        }

        file.close();
        std::cout << "[OK] Drivers guardados en binario: " << archivo << "\n";
        return true;
    }


    std::vector<Driver> leerDriversBIN(std::string archivo) {
        std::vector<Driver> lista;
        std::ifstream file(archivo, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "[ERROR] No se pudo abrir: " << archivo << "\n";
            return lista;
        }

        DriverBin db;
        // lee de a un bloque del tamano exacto de DriverBin hasta EOF
        while (file.read((char*)&db, sizeof(DriverBin))) {

            Vehicle v;
            v.setPlate(std::string(db.plate));
            v.setBrand(std::string(db.brand));
            v.setModel(std::string(db.model));
            v.setColor(std::string(db.color));
            v.setYear(db.year);

            Driver d;
            d.setDriverId(std::string(db.driverId));
            d.setName(std::string(db.name));
            d.setDni(std::string(db.dni));
            d.setPassword(std::string(db.password));
            d.setRating(db.rating);
            d.setIsAvailable(db.isAvailable);
            d.setTotalTrips(db.totalTrips);
            d.setTotalEarnings(db.totalEarnings);
            d.setVehicle(v);

            lista.push_back(d);
        }

        file.close();
        std::cout << "[OK] " << lista.size() << " drivers leidos de binario: " << archivo << "\n";
        return lista;
    }


    // ==========================================================
    //  BINARIO  -  PASSENGER
    // ==========================================================

    bool guardarPassengersBIN(std::vector<Passenger> lista, std::string archivo) {
        std::ofstream file(archivo, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "[ERROR] No se pudo abrir: " << archivo << "\n";
            return false;
        }

        for (int i = 0; i < (int)lista.size(); i++) {
            Passenger p = lista[i];

            PassengerBin pb;
            memset(&pb, 0, sizeof(PassengerBin));

            copiarAChar(pb.passengerId, p.getPassengerId(), 20);
            copiarAChar(pb.name, p.getName(), 50);
            copiarAChar(pb.dni, p.getDni(), 10);
            copiarAChar(pb.password, p.getPassword(), 30);
            pb.rating = p.getRating();
            pb.totalTrips = p.getTotalTrips();
            pb.totalSpent = p.getTotalSpent();

            file.write((char*)&pb, sizeof(PassengerBin));
        }

        file.close();
        std::cout << "[OK] Passengers guardados en binario: " << archivo << "\n";
        return true;
    }


    std::vector<Passenger> leerPassengersBIN(std::string archivo) {
        std::vector<Passenger> lista;
        std::ifstream file(archivo, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "[ERROR] No se pudo abrir: " << archivo << "\n";
            return lista;
        }

        PassengerBin pb;
        while (file.read((char*)&pb, sizeof(PassengerBin))) {

            Passenger p;
            p.setPassengerId(std::string(pb.passengerId));
            p.setName(std::string(pb.name));
            p.setDni(std::string(pb.dni));
            p.setPassword(std::string(pb.password));
            p.setRating(pb.rating);
            p.setTotalTrips(pb.totalTrips);
            p.setTotalSpent(pb.totalSpent);

            lista.push_back(p);
        }

        file.close();
        std::cout << "[OK] " << lista.size() << " passengers leidos de binario: " << archivo << "\n";
        return lista;
    }


    // ==========================================================
    //  BINARIO  -  TRIP
    // ==========================================================

    bool guardarTripsBIN(std::vector<Trip> lista, std::string archivo) {
        std::ofstream file(archivo, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "[ERROR] No se pudo abrir: " << archivo << "\n";
            return false;
        }

        for (int i = 0; i < (int)lista.size(); i++) {
            Trip t = lista[i];

            TripBin tb;
            memset(&tb, 0, sizeof(TripBin));

            copiarAChar(tb.tripId, t.getTripId(), 20);
            copiarAChar(tb.passengerId, t.getPassengerId(), 20);
            copiarAChar(tb.driverId, t.getDriverId(), 20);
            copiarAChar(tb.origin, t.getOrigin(), 60);
            copiarAChar(tb.destination, t.getDestination(), 60);
            tb.price = t.getPrice();
            copiarAChar(tb.status, t.getStatus(), 15);
            copiarAChar(tb.date, t.getDate(), 15);

            file.write((char*)&tb, sizeof(TripBin));
        }

        file.close();
        std::cout << "[OK] Trips guardados en binario: " << archivo << "\n";
        return true;
    }


    std::vector<Trip> leerTripsBIN(std::string archivo) {
        std::vector<Trip> lista;
        std::ifstream file(archivo, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "[ERROR] No se pudo abrir: " << archivo << "\n";
            return lista;
        }

        TripBin tb;
        while (file.read((char*)&tb, sizeof(TripBin))) {

            Trip t;
            t.setTripId(std::string(tb.tripId));
            t.setPassengerId(std::string(tb.passengerId));
            t.setDriverId(std::string(tb.driverId));
            t.setOrigin(std::string(tb.origin));
            t.setDestination(std::string(tb.destination));
            t.setPrice(tb.price);
            t.setStatus(std::string(tb.status));
            t.setDate(std::string(tb.date));

            lista.push_back(t);
        }

        file.close();
        std::cout << "[OK] " << lista.size() << " trips leidos de binario: " << archivo << "\n";
        return lista;
    }
    */
};