#pragma once
#include <fstream>  // ofstream ifstream
#include <sstream>  // stringstream
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../src/Driver.h"
#include "../src/Passenger.h"
#include "../src/Trip.h"

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
    string rutaAdmins;
    string rutaTrips;
    string rutaPasswordsBin;

    struct PasswordRecordBin {      // para hacer binarios necesito chars asi que arreglo de charcitos para guardar
        char tipo[16];
        char id[24];
        char dni[16];
        char password[32];
    };

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
        if (valor) 
            return "1";

        return "0";
    }

    bool stringABool(string texto) // convierte "1" o "0" leido del txt de vuelta a bool
    {
        if (texto == "1") 
            return true;

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

    bool contieneString(const vector<string>& lista, const string& valor)
    {
        for (int i = 0; i < (int)lista.size(); i++) {
            if (lista[i] == valor)
                return true;
        }

        return false;
    }

public:
    struct PasswordPreview {    // variables que van hacer ingresadas por users son strings
        string tipo;
        string id;
        string dni;
        string password;
    };

    struct AdminPreview {
        string id;
        string username;
        string password;
    };

    FileManager() {
        separador = '|';
        rutaDrivers = "assets/drivers.txt";
        rutaPassengers = "assets/passengers.txt";
        rutaAdmins = "assets/admins.txt";
        rutaTrips = "assets/trips.txt";
        rutaPasswordsBin = "assets/passwords.bin";
    }


    FileManager(char _separador)  // constructor si quiero usar otro separador
    {
        separador = _separador;
        rutaDrivers = "assets/drivers.txt";
        rutaPassengers = "assets/passengers.txt";
        rutaAdmins = "assets/admins.txt";
        rutaTrips = "assets/trips.txt";
        rutaPasswordsBin = "assets/passwords.bin";
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
        std::cout << "[OK] Drivers guardados correctamente: " << rutaDrivers << "\n";
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
    //  tripId|origin|destination|price|tipe|status|driverName|driverDni|passengerDni|date

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
                << t.getDriverDni() << separador
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

            vector<string> p = dividirLinea(linea);

            if ((int)p.size() < 9) {
                std::cout << "[PELIGRO] Linea incompleta, se omite.\n";
                continue;
            }

            Trip t;
            t.setTripId(p[0]);
            t.setOrigin(p[1]);
            t.setDestination(p[2]);
            t.setPrice(std::stof(p[3]));
            t.setTipe(std::stoi(p[4]));
            t.setStatus(p[5]);
            t.setDriverName(p[6]);
            if ((int)p.size() >= 10) {
                t.setDriverDni(p[7]);
                t.setPassengerDni(p[8]);
                t.setDate(p[9]);
            }
            else {
                t.setDriverDni("");
                t.setPassengerDni(p[7]);
                t.setDate(p[8]);
            }

            listaDeTrips.push_back(t);
        }

        MyFile.close();
        std::cout << "[OK] " << listaDeTrips.size() << " trips leidos de: " << rutaTrips << "\n";
        return listaDeTrips;
    }




    /// para Binarios de contraseñas
    ///  Formato de cada linea en passwords.bin:
    ///  tripId|origin|destination|price|tipe|status|driverName|passengerDni|date

    bool guardarPasswordsBIN(const vector<Passenger>& listaDePassengers, const vector<Driver>& listaDeDrivers) {
        std::ofstream MyFile(rutaPasswordsBin, std::ios::binary); // abrir o crear si no existe los binarios un MyFile de binary

        if (!MyFile.is_open()) {
            std::cout << "[ERROR] No se pudo abrir el archivo binario: " << rutaPasswordsBin << "\n";
            return false;
        }

        for (int i = 0; i < (int)listaDePassengers.size(); i++) {   // reccoro la lista de pasajeros y extraigo la info que quiero
            PasswordRecordBin miBinario{};
            copiarAChar(miBinario.tipo, "Passenger", 16);   // 16 de tamaño para el tipo
            copiarAChar(miBinario.id, listaDePassengers[i].getPassengerId(), 24); // 24 de tamaño  
            copiarAChar(miBinario.dni, listaDePassengers[i].getDni(), 16);
            copiarAChar(miBinario.password, listaDePassengers[i].getPassword(), 32);
            MyFile.write(reinterpret_cast<char*>(&miBinario), sizeof(PasswordRecordBin));   // casting para transformar mi binario a char
        }

        for (int i = 0; i < (int)listaDeDrivers.size(); i++) { // reccoro la lista de drivers y extraigo la info que quiero
            PasswordRecordBin miBinario{};
            copiarAChar(miBinario.tipo, "Driver", 16);
            copiarAChar(miBinario.id, listaDeDrivers[i].getDriverId(), 24);
            copiarAChar(miBinario.dni, listaDeDrivers[i].getDni(), 16);
            copiarAChar(miBinario.password, listaDeDrivers[i].getPassword(), 32);
            MyFile.write(reinterpret_cast<char*>(&miBinario), sizeof(PasswordRecordBin)); // casting para transformar mi binario a char
        }

        MyFile.close();
        std::cout << "[OK] Passwords guardadas en binario: " << rutaPasswordsBin << "\n";
        return true;
    }

    vector<PasswordPreview> leerPasswordsBIN() {
        vector<PasswordPreview> listaDelArchivoBin;
        std::ifstream MyFile(rutaPasswordsBin, std::ios::binary);

        if (!MyFile.is_open()) {
            std::ofstream crearArchivo(rutaPasswordsBin, std::ios::binary);
            crearArchivo.close();
            return listaDelArchivoBin;
        }

        PasswordRecordBin miBinario{};
        while (MyFile.read(reinterpret_cast<char*>(&miBinario), sizeof(PasswordRecordBin))) {
            PasswordPreview pas;
            pas.tipo = miBinario.tipo;
            pas.id = miBinario.id;
            pas.dni = miBinario.dni;
            pas.password = miBinario.password;
            listaDelArchivoBin.push_back(pas);
        }
        
        MyFile.close();
        std::cout << "[OK] " << listaDelArchivoBin.size() << " passwords leidos de: " << rutaPasswordsBin << "\n";
        return listaDelArchivoBin;
    }

    bool guardarPasswordsTXT() {

        vector<PasswordPreview> lista = leerPasswordsBIN();

        std::ofstream MyFile("assets/passwords.txt");

        if (!MyFile.is_open()) {
            std::cout << "[ERROR] No se pudo crear el TXT de: passwords.bin\n";
            return false;
        }

        bool saltoAgregado = false;

        for (const PasswordPreview& p : lista) 
        {
            if (!saltoAgregado && p.tipo == "Driver") {
                MyFile << "\n";
                saltoAgregado = true;
            }

            MyFile << p.tipo << "-"
                << p.id << "-"
                << p.dni << "-"
                << p.password
                << "\n";
        }

        MyFile.close();

        std::cout << "[OK] TXT generado desde el passwords.bin\n";

        return true;
    }


    //  Formato de cada linea en admin.txt:
    //  adminId|username|password

    bool guardarAdminsTXT(const vector<AdminPreview>& listaDeAdmins) // Guardar a nuevo  registrado
    {
        // Abriendo el archivo o creando si no existe:
        std::ofstream MyFile(rutaAdmins);      // MyFile: como esta con ofstream, sirve para escribir

        if (!MyFile.is_open()) {
            std::cout << "[ERROR] No se pudo abrir el archivo: " << rutaAdmins << "\n";
            return false;
        }

        for (int i = 0; i < (int)listaDeAdmins.size(); i++) {
            const AdminPreview& ap = listaDeAdmins[i];

            MyFile << ap.id << separador << ap.username << separador 
                << ap.password << "\n";
        }

        MyFile.close();
        std::cout << "[OK] Admins guardados correctamente: " << rutaAdmins << "\n";
        return true;
    }

    vector<AdminPreview> leerAdminsTXT() {

        vector<AdminPreview> listaDeAdmins;
        std::ifstream MyFile(rutaAdmins);   // MyFile: como esta con ifstream, sirve para leer

        if (!MyFile.is_open()) {

            std::ofstream crearArchivo(rutaAdmins); // crea si no existe o no lo abre o no lee
            crearArchivo.close();   // crea y cierra

            MyFile.open(rutaAdmins);

            std::cout << "[ALERTA] El archivo se acaba de crear: " << rutaAdmins << "\n";
            return listaDeAdmins;
        }

        std::string linea;
        while (std::getline(MyFile, linea))
        {
            if (linea.empty())
                continue;

            vector<string> p = dividirLinea(linea);

            if ((int)p.size() < 3) 
            {
                std::cout << "[PELIGRO] Linea incompleta, se omite.\n";
                continue;
            }

            AdminPreview admin;
            admin.id = p[0];
            admin.username = p[1];
            admin.password = p[2];

            listaDeAdmins.push_back(admin);
        }

        MyFile.close();
        std::cout << "[OK] " << listaDeAdmins.size() << " admins leidos de: " << rutaAdmins << "\n";
        return listaDeAdmins;
    }

    string generarIdAdmin(int contador) {
        std::ostringstream oss;
        // Rellena con '0' a la izquierda hasta tener un ancho de 2 caracteres numéricos
        oss << "ADM-" << std::setfill('0') << std::setw(3) << contador;
        return oss.str();
    }

    bool generarAdminsTXT()
    {
        srand((unsigned int)time(nullptr));

		string userNames[] = {
			"Pedro", "Lynx", "Control", "Root", "Sistema", "Panel", "Master",
	        "Carlos", "Diego", "Mateo", "Lucas", "Mario", "Andres", "Felipe",
	        "Ricardo", "Fernando", "Eduardo", "Gabriel", "Daniel", "Miguel",
	        "Alejandro", "Rodrigo", "Javier", "Sergio", "Ivan", "Cristian",
	        "Marcos", "Adrian", "Hugo", "Pablo", "Victor", "Raul", "Antonio",
	        "Manuel", "Jorge", "Oscar", "Ramiro", "Esteban", "Tomas", "Nicolas",
	        "Bruno", "Leonardo", "Maximiliano", "Joaquin", "Emilio", "Renato",
	        "Salvador", "Octavio", "Gonzalo", "Agustin", "Facundo",
	        "Messi", "Neymar", "Ronaldinho", "Pele", "Mbappe", "Haaland",
	        "Modric", "Benzema", "Kante", "Pirlo", "Xavi", "Iniesta", "Kaka",
	        "Zidane", "Ronaldo", "Maradona", "Suarez", "Cavani", "Falcao",
	        "Lewandowski", "Salah", "Kroos", "Busquets", "Casillas", "Puyol",
	        "Bono", "Bonucci", "Chiellini", "Buffon", "Totti", "Baggio",
	        "Bowie", "Lennon", "Elvis", "Prince", "Madonna", "Beyonce",
	        "Adele", "Eminem", "Drake", "Rihanna", "Shakira", "Maluma",
	        "Bizarrap", "Residente", "Ricky", "Manu", "Vicente", "Santiago",
	        "Emiliano", "Benjamin", "Cristobal", "Maximo", "Ignacio",
	        "Rafael", "Leandro", "Mauricio", "Jeremias", "Patricio",
	        "Aaron", "Brayan", "Cesar", "Damian"
		};

        string passwords[] = {
            "verde", "ruta", "clave", "taxi", "seguro", "admin",
            "123456", "password", "qwerty", "abc123", "letmein", "welcome",
            "Pass2024", "Lynx_2024", "Taxi123", "Ruta_55", "verde99", "Clave#1",
            "admin123", "Seguro_2025", "P@ssw0rd", "Master_99", "Control123",
            "Sistema!23", "Panel_2024", "lynx_admin", "Driver2024", "rideOn99",
            "Camino_45", "Viaje#2024", "rapido123", "Conductor_1", "Pasajero99",
            "azul_55", "rojo2024", "Naranja#7", "negro_123", "blanco99",
            "estrella1", "luna_2024", "sol123!", "monte_77", "rio2024",
            "Lince_99", "gato_2024", "perro123", "leon_55", "tigre2024",
            "Ciudad99", "Calle_45", "Avenida1", "Plaza2024", "Centro_99",
            "miClave1", "superSecreta", "noLoSabras", "diasFelices", "vamosYa2024",
            "12345", "55555", "99999", "00000_lynx", "777lucky",
            "Roberto23", "Marisol_99", "Camila2024", "Andrea_55", "Vanesa99",
            "QWE123!", "asdf2024", "zxcv_99", "poiu123", "lkjh2024",
            "tunel_negro", "puente55", "estacion2024", "parada_99", "destino1",
            "Token_2024", "Hash#123", "Sesion99", "Acceso_2024", "Cuenta55",
            "GHI789", "JKL456_", "MNO321", "PQR654!", "STU987",
            "viento99", "tormenta2024", "lluvia_55", "nube123", "trueno2024",
            "fuego_77", "hielo99", "tierra2024", "agua_123", "aire55",
            "matrix99", "phoenix2024", "dragon_55", "fenix123", "kraken2024",
            "Bahia_99", "Costa2024", "Valle_55", "Sierra99", "Bosque2024",
            "Codigo_1", "Llave99!", "Puerta2024", "Candado_55", "Cerradura1"
        };

        // Calculamos la cantidad real de elementos en los arreglos
        int numUserNames = sizeof(userNames) / sizeof(userNames[0]);
        int numPasswords = sizeof(passwords) / sizeof(passwords[0]);

        std::vector<AdminPreview> listaDeAdmins;

        vector<string> usernamesUsados;
        vector<string> passwordsUsados;

        listaDeAdmins.push_back({ "ADM-03","Melissa","hola9" });
        usernamesUsados.push_back("Melissa");
        passwordsUsados.push_back("hola9");

        listaDeAdmins.push_back({ "ADM-01", "Yeremy", "admin777" });
        usernamesUsados.push_back("Yeremy");
        passwordsUsados.push_back("admin777");

        listaDeAdmins.push_back({ "ADM-02", "Salvador", "hola123" });
        usernamesUsados.push_back("Salvador");
        passwordsUsados.push_back("hola123");

        int idContador = 4; // pa que no agarre nuestros passwords y users

        for (int i = 0; i < 111; i++) {
            // generar el ID secuencial 
            string id = generarIdAdmin(idContador);
            string username;

            // usar la variable con el tamaño del arreglo para el rand()
            do {
                username = userNames[rand() % numUserNames];
            } while (contieneString(usernamesUsados, username));

            string password;
            do {
                password = passwords[rand() % numPasswords];
            } while (contieneString(passwordsUsados, password));

            // enviar los 3 parametros requeridos
            listaDeAdmins.push_back({ id, username, password });

            // actualizar vectores usados
            usernamesUsados.push_back(username);
            passwordsUsados.push_back(password);

            // Aumentar el contador para la siguiente iteración
            idContador++;
        }

        return guardarAdminsTXT(listaDeAdmins);

    }

};
