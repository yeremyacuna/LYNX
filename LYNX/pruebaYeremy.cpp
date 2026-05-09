#include <iostream>
#include <vector>
#include "src/Driver.h"         // Driver, Vehicle, User agregar
#include "FileManager.h"
#include "include/LinkedDoubleList.h" // ESTRUCTURA DE DATO A UTILIZAR LO AGREGAN
#include <filesystem>

using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

//  El flujo es:
//  1. Al INICIAR el programa  -> leer TXT -> meter en LinkedList
//  2. Trabajar con la LinkedList durante el programa
//  3. Al CERRAR el programa   -> pasar LinkedList a vector -> guardar TXT


//hola
int main()
{
    cout << std::filesystem::current_path() << endl;

    FileManager* fileManager = new FileManager(); // 1. cargar objeto de filemanager
    
    LinkedDoubleList<Driver>* listaDobleDrivers = new LinkedDoubleList<Driver>();

    cout << "\n--- [1] Cargando drivers desde archivo ---\n";

    vector<Driver> driversCargados = fileManager->leerDriversTXT(); //  leer drivers.txt y cargar en la LinkedDoubleList
                                                                    //     Esto lo haces AL INICIAR el programa (una sola vez)

    for (int i = 0; i < (int)driversCargados.size(); i++)
    {
        listaDobleDrivers->pushBack(driversCargados[i]);
    }

    cout << "Drivers cargados en lista: " << listaDobleDrivers->getSize() << "\n";

    // =================================================
    //   registrar nuevos conductores
    //  Creas Vehicle* y Driver*, los agregas a la lista
    //  con pushBack luego haces delete del puntero porque ya no lo necesitas.
    // ==========================================================
    cout << "\n--- [2] Registrando nuevos conductores ---\n";

    // --- Driver 1 ---
    Vehicle* v1 = new Vehicle("B3K-447", "Toyota", "Corolla", "Plata", 2022);
    Driver* d1 = new Driver("Pedro Quispe", "45678901", "pass123", *v1);

    listaDobleDrivers->pushBack(*d1);        // *d1 pasa la copia al nodo interno
    cout << "Registrado: " << d1->getName() << "\n";

    delete v1;                   
    delete d1;                   


    // --- Driver 2 ---
    Vehicle* v2 = new Vehicle("A1P-885", "Honda", "Civic", "Negro", 2021);
    Driver* d2 = new Driver("Salvador Rivera", "50193847", "rosa456", *v2);

    listaDobleDrivers->pushBack(*d2);
    cout << "Registrado: " << d2->getName() << "\n";

    delete v2;
    delete d2;


    // --- Driver 3 ---
    Vehicle* v3 = new Vehicle("C7M-219", "Hyundai", "Tucson", "Blanco", 2023);
    Driver* d3 = new Driver("Luis Mamani", "38201947", "luis789", *v3);

    listaDobleDrivers->pushBack(*d3);
    cout << "Registrado: " << d3->getName() << "\n";

    delete v3;
    delete d3;


    // =======================================================
    //   mostrar todos los drivers de la lista  
    // =========================================================
    cout << "\n--- [3] Conductores en memoria ---\n";

    for (int i = 0; i < listaDobleDrivers->getSize(); i++)
    {
        Driver d = listaDobleDrivers->get(i);
        cout << "  " << d.toString() << "\n";
    }

    // ================================================
    //  guardar la lista en el TXT
    // ========================================================
    cout << "\n--- [4] Guardando en archivo ---\n";

    vector<Driver> paraGuardarDrivers = listaDobleDrivers->linkedDoubleListToVector(*listaDobleDrivers);
    fileManager->guardarDriversTXT(paraGuardarDrivers);


    // =================================================
    //  verificacion (saltar)
    // ==========================================================
    cout << "\n--- [5] Verificacion: leyendo archivo ---\n";

    vector<Driver> verificacion = fileManager->leerDriversTXT();

    for (int i = 0; i < (int)verificacion.size(); i++)
    {
        Driver* d = new Driver(verificacion[i]);   
        cout << "  [" << d->getDriverId() << "] "
            << d->getName()
            << " | Placa: " << d->getVehicle().getPlate()
            << " | Rating: " << d->getRating()
            << " | Disponible: " << (d->getIsAvailable() ? "SI" : "NO")
            << "\n";
        delete d;
    }

    delete listaDobleDrivers;
    delete fileManager;

    cout << "\n[DONE] Prueba completada sin fugas de memoria.\n\n";

    cin.get();
    return 0;
}
