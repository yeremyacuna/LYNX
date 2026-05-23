#include <iostream>
#include "MainMenu.h"

using namespace System;
using std::cout;


// main: punto de entrada del programa
// aqui se crea el menu principal y se arranca todo el flujo del sistema
int main()
{
	// menu principal que controla pasajero, conductor y admin
	Menu menu = Menu();

	// inicia la interfaz actual en consola
	menu.LYNX();

	return 0;
}
