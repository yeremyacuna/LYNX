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

    Menu menu;
    menu.LYNX();

    System::Windows::Forms::Application::Run(gcnew LYNX::MainMenuForm());

    return 0;
}
