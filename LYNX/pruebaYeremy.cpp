#include <iostream>
#include <vector>
#include "src/Driver.h"         // Driver, Vehicle, User agregar
#include "include/FileManager.h"
#include "include/LinkedDoubleList.h" // ESTRUCTURA DE DATO A UTILIZAR LO AGREGAN
#include <filesystem>

using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

//  El flujo es:
//  1. Al INICIAR el programa  -> leer TXT -> meter en LinkedList
//  2. Trabajar con la LinkedList durante el programa
//  3. Al CERRAR el programa   -> pasar LinkedList a vector -> guardar TXT

/*
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
}*/