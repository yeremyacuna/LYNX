#include <iostream>
#include "MainMenu.h"
#include "forms/MainMenuForm.h"


using std::cout;

// main
// aqui se crea el menu principal y se arranca todo el flujo del sistema
[STAThread]
int main()
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    // Inicializar el orquestador global (Pasajeros, Conductores y Viajes)
  


    
    //menu.LYNX();

    System::Windows::Forms::Application::Run(gcnew LYNX::MainMenuForm());

    // Guardar datos al salir
  

    return 0;
}
