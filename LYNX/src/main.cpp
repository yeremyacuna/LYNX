#include <iostream>
#include "forms/MainMenuForm.h"
#include "../src/MainMenu.h"

using std::cout;

// main
// aqui se crea el menu principal y se arranca todo el flujo del sistema

[System::STAThread]
int main()
{
    // Debo cambiar linker Console to variado

    std::cout << "1. Consola\n";
    std::cout << "2. Windows Forms\n";
    std::cout << "Opcion: ";
    int opcion; std::cin >> opcion;

    if (opcion == 1)
    {
        //EJECUTAR APP CONSOLA:

        ConsoleMenu menu;
        menu.LYNXConsoleMenu();

    }
    else if (opcion == 2)
    {
        //EJECUTAR APP WINDOWS FORM:

     System::Windows::Forms::Application::EnableVisualStyles();

     System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

     // Crear formulario principal
     LYNX::FormsStatus::mainMenu = gcnew LYNX::MainMenuForm();

     // Ejecutar aplicación
     System::Windows::Forms::Application::Run(LYNX::FormsStatus::mainMenu);
    
    }
   

    return 0;
}