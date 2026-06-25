#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../include/LinkedList.h"
#include "../include/Queue.h"
#include "../include/FileManager.h"
#include "Passenger.h"
#include "Driver.h"
#include "Trip.h"

using std::vector; using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

//  Guarda y gestiona las listas de pasajeros y conductores.
class AuthManager {
private:
    LinkedList<Passenger>* passengerList = new LinkedList<Passenger>();
    LinkedList<Driver>* driverList = new LinkedList<Driver>();
    FileManager* fileManager = new FileManager();
    LinkedList<FileManager::AdminPreview>* adminList = new LinkedList<FileManager::AdminPreview>();

    // Busca la posicion de un pasajero por DNI
    int indexOfUser(string dni) {
        for (int i = 0; i < passengerList->getSize(); i++)
            if (passengerList->get(i).getDni() == dni)
                return i;
        return -1;
    }

    // Busca la posicion de un conductor por DNI
    int indexOfDriver(string dni) {
        for (int i = 0; i < driverList->getSize(); i++)
            if (driverList->get(i).getDni() == dni)
                return i;
        return -1;
    }

    // Busca la posicion de un admin por ID
    int indexOfAdmin(string id)
    {
        for ( int i = 0; i < adminList->getSize(); i++)
            if (adminList->get(i).id == id)
                return i;
        return -1;
    }

    // Busca la posicion de un admin por username
    int nameOfAdmin(string username)
    {
        for (int i = 0; i < adminList->getSize(); i++)
            if (adminList->get(i).username == username)
                return i;
        return -1;
    }

    // Retorna el numero del id del admin correspondiente 
    int extractAdminID(string adminId)
    {
        size_t pos = adminId.find("-");
        if (pos == string::npos) return 0;

        string numberPart = adminId.substr(pos + 1);

        try {
            return std::stoi(numberPart);
        }
        catch (...) {
            return 0;
        }
    }

    // Si contiene un string
    bool containsString(const vector<string>& lista, const string& valor) {
        for (int i = 0; i < (int)lista.size(); i++) {
            if (lista[i] == valor)
                return true;
        }
        return false;
    }

    // El maximo de pasajeros segun su id
    int maxPassengerIdNumber() {
        int maxId = 0;
        for (int i = 0; i < passengerList->getSize(); i++) {
            int actual = Passenger::extractPassengerNumber(passengerList->get(i).getPassengerId());
            if (actual > maxId)
                maxId = actual;
        }
        return maxId;
    }

    // El maximo de drivers segun su id
    int maxDriverIdNumber() {
        int maxId = 0;
        for (int i = 0; i < driverList->getSize(); i++) {
            int actual = Driver::extractDriverNumber(driverList->get(i).getDriverId());
            if (actual > maxId) maxId = actual;
        }
        return maxId;
    }

    // El maximo de admins segun su id
    int maxAdminIdNumber()
    {
        int maxId = 0;

        for (int i = 0; i < adminList->getSize(); i++) {
            int actual = extractAdminID(adminList->get(i).id);
            if (actual > maxId)
                maxId = actual;
        }

        return maxId;
    }

    int nextAdminId = 1;

    // Sincronizar Ids
    void syncNextGeneratedIds() {
        Passenger::syncNextPassengerId(maxPassengerIdNumber() + 1);
        Driver::syncNextDriverId(maxDriverIdNumber() + 1);
        nextAdminId = maxAdminIdNumber() + 1;
    }

    // corregir ids pasajeros cargados
    bool sanitizeLoadedPassengers() {
        bool changed = false;
        vector<string> usedIds;
        vector<string> usedDnis;
        LinkedList<Passenger>* limpia = new LinkedList<Passenger>();
        int nextId = maxPassengerIdNumber() + 1;

        for (int i = 0; i < passengerList->getSize(); i++) {
            Passenger p = passengerList->get(i);

            if (containsString(usedDnis, p.getDni())) {
                changed = true;
                continue;
            }

            string currentId = p.getPassengerId();
            bool invalidId = Passenger::extractPassengerNumber(currentId) <= 0;
            bool duplicateId = containsString(usedIds, currentId);

            if (invalidId || duplicateId) {
                Passenger::syncNextPassengerId(nextId);
                p.setPassengerId(Passenger::generateNextPassengerId());
                nextId = Passenger::extractPassengerNumber(p.getPassengerId()) + 1;
                changed = true;
            }

            usedIds.push_back(p.getPassengerId());
            usedDnis.push_back(p.getDni());
            limpia->pushBack(p);
        }

        if (changed) {
            delete passengerList;
            passengerList = limpia;
        }
        else {
            delete limpia;
        }

        return changed;
    }

    // corregir ids drivers cargados
    bool sanitizeLoadedDrivers() {
        bool changed = false;
        vector<string> usedIds;
        vector<string> usedDnis;
        LinkedList<Driver>* limpia = new LinkedList<Driver>();
        int nextId = maxDriverIdNumber() + 1;

        for (int i = 0; i < driverList->getSize(); i++) {
            Driver d = driverList->get(i);

            if (containsString(usedDnis, d.getDni())) {
                changed = true;
                continue;
            }

            string currentId = d.getDriverId();
            bool invalidId = Driver::extractDriverNumber(currentId) <= 0;
            bool duplicateId = containsString(usedIds, currentId);

            if (invalidId || duplicateId) {
                Driver::syncNextDriverId(nextId);
                d.setDriverId(Driver::generateNextDriverId());
                nextId = Driver::extractDriverNumber(d.getDriverId()) + 1;
                changed = true;
            }

            usedIds.push_back(d.getDriverId());
            usedDnis.push_back(d.getDni());
            limpia->pushBack(d);
        }

        if (changed) {
            delete driverList;
            driverList = limpia;
        }
        else {
            delete limpia;
        }

        return changed;
    }

    // corregir ids admins cargados
    bool sanitizeLoadedAdmins()
    {
        bool changed = false;
        vector<string> usedIds;
        vector<string> usedUsernames;

        LinkedList<FileManager::AdminPreview>* limpia = new LinkedList<FileManager::AdminPreview>();
        int nextId = maxAdminIdNumber() + 1;

        for (int i = 0; i < adminList->getSize(); i++) {
            FileManager::AdminPreview admin = adminList->get(i);

            bool duplicateUsername = containsString(usedUsernames, admin.username);
            bool duplicateId = containsString(usedIds, admin.id);
            bool invalidId = extractAdminID(admin.id) <= 0;

            if (duplicateUsername) {
                changed = true;
                continue;
            }

            if (invalidId || duplicateId) {
                admin.id = fileManager->generarIdAdmin(nextId);
                nextId++;
                changed = true;
            }

            usedIds.push_back(admin.id);
            usedUsernames.push_back(admin.username);
            limpia->pushBack(admin);
        }

        if (changed) {
            delete adminList;
            adminList = limpia;
        }
        else {
            delete limpia;
        }

        return changed;
    }

    // Reasigna IDs secuencialmente sin huecos (PAS-0001, 0002, 0003...)
    // Debe llamarse DESPUES de sortPassengersById()
    bool compactPassengerIds() {
        bool changed = false;

        for (int i = 0; i < passengerList->getSize(); i++) {
            Passenger p = passengerList->get(i);
            int expectedId = i + 1;  // posición 0 → PAS-0001, posición 1 → PAS-0002...
            int currentId = Passenger::extractPassengerNumber(p.getPassengerId());

            if (currentId != expectedId) {
                Passenger::syncNextPassengerId(expectedId);
                p.setPassengerId(Passenger::generateNextPassengerId());
                passengerList->remove(i);
                passengerList->insert(i, p);
                changed = true;
            }
        }

        // Dejar el contador apuntando al siguiente disponible
        Passenger::syncNextPassengerId(passengerList->getSize() + 1);
        return changed;
    }

    bool compactDriverIds() {
        bool changed = false;

        for (int i = 0; i < driverList->getSize(); i++) {
            Driver d = driverList->get(i);
            int expectedId = i + 1;
            int currentId = Driver::extractDriverNumber(d.getDriverId());

            if (currentId != expectedId) {
                Driver::syncNextDriverId(expectedId);
                d.setDriverId(Driver::generateNextDriverId());
                driverList->remove(i);
                driverList->insert(i, d);
                changed = true;
            }
        }

        Driver::syncNextDriverId(driverList->getSize() + 1);
        return changed;
    }

    bool compactAdminIds()
    {
        bool changed = false;

        for (int i = 0; i < adminList->getSize(); i++) {
            FileManager::AdminPreview admin = adminList->get(i);

            string expectedId = fileManager->generarIdAdmin(i + 1);

            if (admin.id != expectedId) {
                admin.id = expectedId;

                adminList->remove(i);
                adminList->insert(i, admin);

                changed = true;
            }
        }

        return changed;
    }
public:
    // construye todo solo de pasejero y drivers
    // al iniciar, carga desde archivos, limpia datos repetidos y reordena ids
    AuthManager() {
        fileManager->generarAdminsTXT();
        reloadAdmins();

        vector<FileManager::AdminPreview> adminsCargados = fileManager->leerAdminsTXT();
        for (int i = 0; i < (int)adminsCargados.size(); i++) {
            adminList->pushBack(adminsCargados[i]);
        }

        vector<Driver> driversCargados = fileManager->leerDriversTXT();
        for (int i = 0; i < (int)driversCargados.size(); i++) {
            driverList->pushBack(driversCargados[i]);
        }

        vector<Passenger> passengersCargados = fileManager->leerPassengersTXT();
        for (int i = 0; i < (int)passengersCargados.size(); i++) {
            passengerList->pushBack(passengersCargados[i]);
        }

        bool driversChanged = sanitizeLoadedDrivers();
        bool passengersChanged = sanitizeLoadedPassengers();

        sortDriversById();
        sortPassengersById();

        bool driversCompacted = compactDriverIds();
        bool passengersCompacted = compactPassengerIds();

        syncNextGeneratedIds();

        if (driversChanged || passengersChanged || driversCompacted || passengersCompacted) {
            saveAll();
        }
    }

    // ~AuthManager: libera las estructuras dinamicas principales del modulo
    ~AuthManager() {
        delete passengerList;
        delete driverList;
        delete fileManager;
        delete adminList;
    }

    // getters: exponen las listas y contadores globales de usuarios y conductores
    LinkedList<Passenger>*& getPassengerList() { return passengerList; }
    LinkedList<Passenger>*& getUserList() { return passengerList; }
    LinkedList<Driver>*& getDriverList() { return driverList; }

    int getTotalUsers() { return passengerList->getSize(); }
    int getTotalDrivers() { return driverList->getSize(); }

    LinkedList<Driver>* copyDriverList()
    {
        LinkedList<Driver>* original = driverList;

        LinkedList<Driver>* nueva = new LinkedList<Driver>();

        for (int i = 0; i < original->getSize(); i++)
        {
            Driver d = original->get(i);
            nueva->pushBack(d);
        }

        return nueva;
    }

    //  FUNCIONES DE GUARDADO
    // savePassengers: ordena y guarda la lista de pasajeros en txt
    void savePassengers() {
        sortPassengersById();
        vector<Passenger> pasajeros = exportPassengerVector();
        fileManager->guardarPassengersTXT(pasajeros);
        fileManager->guardarPasswordsBIN(pasajeros, exportDriverVector());
        fileManager->guardarPasswordsTXT();
    }

    // saveDrivers: ordena y guarda la lista de conductores en txt
    void saveDrivers() {
        sortDriversById();
        vector<Driver> drivers = exportDriverVector();
        fileManager->guardarDriversTXT(drivers);
        fileManager->guardarPasswordsBIN(exportPassengerVector(), drivers);
        fileManager->guardarPasswordsTXT();
    }

    // saveAdmins: ordena y guarda la lista de conductores en txt
    void saveAdmins()
    {
        sortAdminsById();
        vector<FileManager::AdminPreview> admins = exportAdminVector();
        fileManager->guardarAdminsTXT(admins);
    }

    // saveAll: persiste pasajeros y conductores juntos
    void saveAll() // guardar ambos pasajero y conductor
    {
        sortPassengersById();
        sortDriversById();
        vector<Passenger> pasajeros = exportPassengerVector();
        vector<Driver> drivers = exportDriverVector();
        fileManager->guardarPassengersTXT(pasajeros);
        fileManager->guardarDriversTXT(drivers);
        fileManager->guardarPasswordsBIN(pasajeros, drivers);
        fileManager->guardarPasswordsTXT();
    }

    // savePasswordsBinary: genera el archivo binario de passwords para consulta admin
    bool savePasswordsBinary() {
        return fileManager->guardarPasswordsBIN(exportPassengerVector(), exportDriverVector());
    }

    // reloadPassengers: vuelve a leer el archivo TXT y reemplaza la lista en memoria
    void reloadPassengers() {
        passengerList->clear();
        vector<Passenger> cargados = fileManager->leerPassengersTXT();
        for (int i = 0; i < (int)cargados.size(); i++)
            passengerList->pushBack(cargados[i]);

        bool a = sanitizeLoadedPassengers();
        sortPassengersById();
        bool b = compactPassengerIds();
        syncNextGeneratedIds();

        if (a || b) 
            saveAll();
    }
    
    void reloadDrivers()
    {
        driverList->clear();
        vector<Driver> cargados = fileManager->leerDriversTXT();
        for (int i = 0; i < (int)cargados.size(); i++)
            driverList->pushBack(cargados[i]);

        bool a = sanitizeLoadedDrivers();
        sortDriversById();
        bool b = compactDriverIds();
        syncNextGeneratedIds();

        if (a || b)
            saveAll();
    }

    void reloadAdmins()
    {
       
            adminList->clear();

            vector<FileManager::AdminPreview> cargados = fileManager->leerAdminsTXT();

            for (int i = 0; i < (int)cargados.size(); i++)
                adminList->pushBack(cargados[i]);

            bool a = sanitizeLoadedAdmins();

            sortAdminsById();

            bool b = compactAdminIds();

            if (a || b)
                saveAdmins();
    }

    // FUNCION QUE PASA LA ESTRCUTURA PARA QUE GUARDE DE PASAJERO Y DRIVER SUS CONTRAS
    // readPasswordsBinary: lee el archivo binario y devuelve una vista amigable
    vector<FileManager::PasswordPreview> readPasswordsBinary() {
        return fileManager->leerPasswordsBIN();
    }

    // linked list to vector
    // exportPassengerVector: convierte la lista enlazada de pasajeros a vector
    vector<Passenger> exportPassengerVector() {
        vector<Passenger> pasajeros;
        for (int i = 0; i < passengerList->getSize(); i++) {
            pasajeros.push_back(passengerList->get(i));
        }
        return pasajeros;
    }

    // linked list to vector
    // exportDriverVector: convierte la lista enlazada de conductores a vector
    vector<Driver> exportDriverVector() {
        vector<Driver> drivers;
        for (int i = 0; i < driverList->getSize(); i++) {
            drivers.push_back(driverList->get(i));
        }
        return drivers;
    }

    vector<FileManager::AdminPreview> exportAdminVector()
    {
        vector<FileManager::AdminPreview> admins;

        for (int i = 0; i < adminList->getSize(); i++) {
            admins.push_back(adminList->get(i));
        }

        return admins;
    }



    // PASAJEROS
    // userExists: verifica si ya existe un pasajero con ese DNI
    bool userExists(string dni) { return indexOfUser(dni) != -1; }

    // dniExistsAnyRole: evita que el mismo DNI aparezca como pasajero y conductor a la vez
    bool dniExistsAnyRole(string dni) { return userExists(dni) || driverExists(dni); }

    // Registra pasajero nuevo si el DNI no existe
    bool registerPassenger(string name, string dni, string password) {
        if (dniExistsAnyRole(dni)) { cout << "  [!] DNI ya registrado.\n"; return false; }
        passengerList->pushBack(Passenger(name, dni, password));
        sortPassengersById();
        syncNextGeneratedIds();
        savePassengers();
        return true;
    }

    // registerUser: alias simple para registrar pasajero desde otros modulos
    bool registerUser(string name, string dni, string password) {
        return registerPassenger(name, dni, password);
    }

    // Valida credenciales
    bool loginUserValid(string dni, string password) {
        int i = indexOfUser(dni);
        if (i == -1) 
            return false;
        return 
            passengerList->get(i).login(dni, password);
    }

    // getUserByDni: busca y devuelve el pasajero correspondiente o uno vacio si no existe
    Passenger getUserByDni(string dni) {
        int i = indexOfUser(dni);
        if (i == -1) return Passenger();
        return passengerList->get(i);
    }

    // Registra un viaje al pasajero y lo actualiza en la lista
    void addTripToUser(string dni, float precio) {
        int i = indexOfUser(dni);
        if (i == -1) return;
        Passenger p = passengerList->get(i);
        p.addTrip(precio);
        passengerList->remove(i);
        passengerList->insert(i, p);
        savePassengers();
    }

    // updatePassengerData: cambia nombre y contra de un pasajero ya registrado
    void updatePassengerData(string dni, string newName, string newPass) {
        int i = indexOfUser(dni);
        if (i == -1) return;
        Passenger p = passengerList->get(i);
        p.setName(newName);
        p.setPassword(newPass);
        passengerList->remove(i);
        passengerList->insert(i, p);
        savePassengers();
    }

    // Actualiza el rating
    void updateUserRating(string dni, float nuevaCalif) {
        int i = indexOfUser(dni);
        if (i == -1) return;
        Passenger p = passengerList->get(i);
        p.updateRating(nuevaCalif);
        passengerList->remove(i);
        passengerList->insert(i, p);
        savePassengers();
    }

    // CONDUCTORES
    // driverExists: verifica si ya existe un conductor con ese DNI
    bool driverExists(string dni) { return indexOfDriver(dni) != -1; }

    // Registra conductor nuevo con su vehiculo
    bool registerDriver(string name, string dni, string password, Vehicle vehicle) {
        if (dniExistsAnyRole(dni)) { cout << "  [!] DNI ya registrado.\n"; return false; }
        driverList->pushBack(Driver(name, dni, password, vehicle));
        sortDriversById();
        syncNextGeneratedIds();
        saveDrivers();
        return true;
    }

    // Valida credenciales
    bool loginDriverValid(string dni, string password) {
        int i = indexOfDriver(dni);
        if (i == -1) return false;
        return driverList->get(i).login(dni, password);
    }

    // getDriverByDni: busca y devuelve el conductor correspondiente o uno vacio si no existe
    Driver getDriverByDni(string dni) {
        int i = indexOfDriver(dni);
        if (i == -1) return Driver();
        return driverList->get(i);
    }

    // setDriverAvailability: fuerza el estado libre/ocupado del conductor
    void setDriverAvailability(string dni, bool disponible) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList->get(i);
        d.setAvailable(disponible);
        driverList->remove(i);
        driverList->insert(i, d);
        saveDrivers();
    }

    // Actualiza el rating
    void updateDriverRating(string dni, float nuevaCalif) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList->get(i);
        d.updateRating(nuevaCalif);
        driverList->remove(i);
        driverList->insert(i, d);
        saveDrivers();
    }

    // driverAcceptRide: marca viaje aceptado y suma viajes/ganancias del conductor
    void driverAcceptRide(string dni, float precio) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList->get(i);
        d.acceptRide(precio);
        driverList->remove(i);
        driverList->insert(i, d);
        saveDrivers();
    }

    // driverFinishRide: regresa al conductor a estado disponible
    void driverFinishRide(string dni) {
        int i = indexOfDriver(dni);
        if (i == -1) return;
        Driver d = driverList->get(i);
        d.finishRide();
        driverList->remove(i);
        driverList->insert(i, d);
        saveDrivers();
    }

    // findAvailableDriver: devuelve el primer conductor libre encontrado
    string findAvailableDriver() {
        for (int i = 0; i < driverList->getSize(); i++)
            if (driverList->get(i).getIsAvailable())
                return driverList->get(i).getDni();
        return "";
    }

    // ADMINS
    bool adminExists(string id) { return indexOfAdmin(id) != -1; }

    // Valida credenciales
    bool loginAdminValid(string username, string password)
    {
        int i = nameOfAdmin(username);

        if (i == -1)
            return false;

        FileManager::AdminPreview admin = adminList->get(i);

        return admin.password == password;
    }

    // getters
    FileManager::AdminPreview getAdminID(string id)
    {
        int i = indexOfAdmin(id);
        if (i == -1) 
            return FileManager::AdminPreview();

        return adminList->get(i);
    }

    FileManager::AdminPreview getAdminUsername(string username)
    {
        int i = nameOfAdmin(username);
        if (i == -1)
            return FileManager::AdminPreview();

        return adminList->get(i);
    }

    //  LAMBDAS

    // LAMBDA 1: valida que el DNI tenga 8 digitos numericos
    bool validateDni(string dni) {
        auto esDniValido = [](string d) -> bool {
            if (d.size() != 8) return false;
            for (char c : d) if (c < '0' || c > '9') return false;
            return true;
            };
        return esDniValido(dni);
    }

    // LAMBDA 2: muestra totales de usuarios y conductores en consola
    void mostrarResumen() {
        Console::SetCursorPosition(50, 12); cout << "  Usuarios registrados   : " << passengerList->getSize();
        Console::SetCursorPosition(50, 13); cout << "  Conductores registrados: " << driverList->getSize();
    }

    // LAMBDA 3: usa filter() de LinkedList para obtener solo conductores disponibles
    LinkedList<Driver>* getConductoresDisponibles() {
        return driverList->filter([](Driver d) { return d.getIsAvailable(); }); 
    }

    /* LAMBDA 4: encola un viaje solo si el pasajero existe, con Queue::enqueueIf
    Evita encolar viajes de pasajeros no registrados sin verificar afuera
    Llamamos TripManager::createTrip para validar antes de encolar*/
    bool encolarSiPasajeroExiste(Queue<Trip>& cola, Trip t) {
        return cola.enqueueIf(t, [&](Trip viaje) {
            return userExists(viaje.getPassengerDni());
            });
    }

    /* RECURSIVIDAD
     Cuenta conductores disponibles en la lista
     Caso base: indice >= total de conductores -> return 0
     si el conductor en 'indice' esta disponible -> suma 1
     si no                                       -> no suma*/
    int contarConductoresDisponibles(int indice) {
        if (indice >= driverList->getSize()) return 0;
        int resto = contarConductoresDisponibles(indice + 1);
        if (driverList->get(indice).getIsAvailable()) return 1 + resto;
        return resto;
    }






    // sortDriversByRating: ordena conductores de mayor a menor rating usando Shell Sort
    void sortDriversByRating() {
        int n = driverList->getSize();
        if (n <= 1) return;

        Driver* arr = new Driver[n];
        for (int i = 0; i < n; i++) arr[i] = driverList->get(i);

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Driver temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap].getRating() < temp.getRating()) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }

        // Reconstruimos la lista con el orden nuevo
        driverList->clear();
        for (int i = 0; i < n; i++) driverList->pushBack(arr[i]);
        delete[] arr;
    }

    // sortUsersBySpent: ordena pasajeros de mayor a menor gasto total
    void sortUsersBySpent() {
        int n = passengerList->getSize();
        if (n <= 1) return;

        // Copiamos a arreglo auxiliar
        Passenger* arr = new Passenger[n];
        for (int i = 0; i < n; i++) arr[i] = passengerList->get(i);

        // Insertion Sort: inserta cada elemento en su posición correcta
        for (int i = 1; i < n; i++) {
            Passenger key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].getTotalSpent() < key.getTotalSpent()) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        // Reconstruimos la lista
        passengerList->clear();
        for (int i = 0; i < n; i++) passengerList->pushBack(arr[i]);
        delete[] arr;
    }

    // sortPassengersById: ordena pasajeros por su numero interno de id
    void sortPassengersById() {
        int n = passengerList->getSize();
        if (n <= 1) return;

        // Copiamos a arreglo auxiliar
        Passenger* arr = new Passenger[n];
        for (int i = 0; i < n; i++) arr[i] = passengerList->get(i);

        // Insertion Sort: inserta cada elemento en su posición correcta
        for (int i = 1; i < n; i++) {
            Passenger key = arr[i];
            int keyId = Passenger::extractPassengerNumber(key.getPassengerId());
            int j = i - 1;
            while (j >= 0 && Passenger::extractPassengerNumber(arr[j].getPassengerId()) > keyId) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        passengerList->clear();
        for (int i = 0; i < n; i++) passengerList->pushBack(arr[i]);
        delete[] arr;
    }

    // sortUsersById: alias para ordenar pasajeros por id
    void sortUsersById() {
        sortPassengersById();
    }

    // sortDriversById: ordena conductores por su numero interno de id
    void sortDriversById() {
        int n = driverList->getSize();
        if (n <= 1) return;

        // Copiamos a arreglo auxiliar
        Driver* arr = new Driver[n];
        for (int i = 0; i < n; i++) arr[i] = driverList->get(i);

        // Insertion Sort: inserta cada elemento en su posición correcta
        for (int i = 1; i < n; i++) {
            Driver key = arr[i];
            int keyId = Driver::extractDriverNumber(key.getDriverId());
            int j = i - 1;
            while (j >= 0 && Driver::extractDriverNumber(arr[j].getDriverId()) > keyId) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        driverList->clear();
        for (int i = 0; i < n; i++) driverList->pushBack(arr[i]);
        delete[] arr;
    }

    // sortAdminsById: ordena admins por su numero interno de id
    void sortAdminsById() {
        int n = adminList->getSize();
        if (n <= 1) return;

        // Copiamos a arreglo auxiliar
        FileManager::AdminPreview* arr = new FileManager::AdminPreview[n];
        
        for (int i = 0; i < n; i++) 
            arr[i] = adminList->get(i);

        // Insertion Sort: inserta cada elemento en su posición correcta
        for (int i = 1; i < n; i++) {
            FileManager::AdminPreview key = arr[i];
            int keyId = extractAdminID(key.id);
            int j = i - 1;
            while (j >= 0 && extractAdminID(arr[j].id) > keyId) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        adminList->clear();

        for (int i = 0; i < n; i++)
            adminList->pushBack(arr[i]);

        delete[] arr;
    }
};
