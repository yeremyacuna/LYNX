#include <iostream>
#include "forms/MainMenuForm.h"



using std::cout;

// main
// aqui se crea el menu principal y se arranca todo el flujo del sistema

[System::STAThread]
int main()
{
    System::Windows::Forms::Application::EnableVisualStyles();

    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    // Crear formulario principal
    LYNX::FormsStatus::mainMenu = gcnew LYNX::MainMenuForm();

    // Ejecutar aplicación
    System::Windows::Forms::Application::Run(LYNX::FormsStatus::mainMenu);

    return 0;
}