#include <iostream>
#include <windows.h>
#include "Stack.h"
#include "Queue.h"
#include "ListaE.h"
#include <cstdio>

using namespace System;

int main()
{
	int opcion, dni = 0;
	string contra = "", name="";
	do {
		cout << "LYNX\n";
		cout << "1. Soy pasajero\n";
		cout << "2. Soy coductor\n";
		cout << "3. Panel BackOffice\n";
		cout << "4. Salir\n";
		cin >> opcion;

		
		switch (opcion) {
		case 1:
			do {
				cout << "Lynx > Modo Usuario\n---------------------";
				cout << "\n[1] - Iniciar Sesion\n";
				cout << "[2] - Registrarme\n";
				cout << "---------------------------\n[0] - Volver al menu principal \n";
				cin >> opcion;
			} while (opcion > 2 || opcion < 0);

			switch (opcion) {
			case 1:
				do {
					cout << "Lynx > Modo Usuario\n---------------------";
					cout << "\nDNI : ";cin >> dni;
					cin.ignore();
					cout << "\nNombre Completo : ";getline(cin,name);
					cout << "Contrasena : ";cin >> contra;
				} while (dni == 0 || contra == "" || name == "");

				printf("Sesion iniciada. Bienvenido, %s", name);
				break;
			case 2:
				break;
			case 0:
				break;
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}

		
	} while (opcion <1||opcion>4);

	
	
	
	system("pause");
	return 0;
}