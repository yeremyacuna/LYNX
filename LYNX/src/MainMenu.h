#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <string>
#include "Driver.h"
#include "Passenger.h"
#include "Trip.h"
#include "../include/LinkedList.h"
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/LinkedDoubleList.h"

using namespace System;
using std::cout; using std::cin; using std::function;

class Menu
{
public:
	Menu();
	~Menu();
	
	void lynx();
	void principal(int& opcion);
	void principal2(int& opcion);
	void passengerMenu(int& opcion);
	void passengerLogin(string& DNI, string& name, string& password);
	void passengerSignIn(string& DNI, string& name, string& password);
	void passengerOptions(int& opcion);
	void passengerSendTrip(string& origen, string& destino, int& tipo, float& km);
	void passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip);

	void driverMenu(int& opcion);
	void driverLogin(string& DNI, string& name, string& password);
	void driverOptions(int& opcion, string name, string placa, bool estado, float rating);
	void driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo);
	void driverSingIn(string& DNI, string& name, string& password);
	void driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano);
	void driverGains(int& option, Driver driver);
	void passengerProfile(int& option, Passenger passenger);
	void driverProfile(int& option, Driver driver);
	void tripHistory(int& option, Trip trips[], int s, string title);

	void LYNX();

private:

};

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::lynx() {
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(45,5);std::cout << (char)219 << (char)219 << "     " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 6);std::cout << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 7);std::cout << (char)219 << (char)219 << "       " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 8);std::cout << (char)219 << (char)219 << "        " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 9);std::cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";

	Console::ForegroundColor = ConsoleColor::White;
}

void Menu::principal(int& opcion) {
	std::system("cls");
	cout << "LYNX\n";
	cout << "1. Soy pasajero\n";
	cout << "2. Soy conductor\n";
	cout << "3. Panel BackOffice\n";
	cout << "4. Salir\n";
	cout << "\nIngrese opcion: "; cin >> opcion;
};

void Seleccion(int keycode, int& inicio, int min, int max) {
	switch (keycode) {
	case 72:
		if (inicio > min) {
			inicio--;
		}
		break;
	case 80:
		if (inicio < max) {
			inicio++;
		}
		break;
	}
}

void Menu::principal2(int& opcion) {
	std::system("cls");
	
	opcion = 1;
	int o;
	bool terminado = false;
	while (!terminado) {
		if (_kbhit()) {
			int keycode = _getch();
			Seleccion(keycode, opcion,1,4);
		}
		switch (opcion) {
		case 1:
			std::system("cls");
			lynx();
			
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(52, 11);cout << " >> Soy pasajero <<\n";
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(52, 12);cout << "Soy conductor\n";
			Console::SetCursorPosition(52, 13);cout << "Administracion\n";
			Console::SetCursorPosition(52, 14);cout << "Salir\n";
			o = _getch();
			if (o == 13) {
				return;
			}
			break;
		case 2:
			std::system("cls");
			lynx();
			
			
			Console::SetCursorPosition(52, 11);cout << "Soy pasajero\n";
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(52, 12);cout << ">> Soy conductor <<\n";
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(52, 13);cout << "Administracion\n";
			Console::SetCursorPosition(52, 14);cout << "Salir\n";
			o = _getch();
			if (o == 13) {
				return;
			}
			break;

		case 3:
			std::system("cls");
			lynx();
			
			Console::SetCursorPosition(52, 11);cout << "Soy pasajero\n";
			
			Console::SetCursorPosition(52, 12);cout << "Soy conductor\n";
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(52, 13);cout << " >> Administracion <<\n";
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(52, 14);cout << "Salir\n";
			o = _getch();
			if (o == 13) {
				return;
			}
			break;
		case 4:
			std::system("cls");
			lynx();

			Console::SetCursorPosition(52, 11);cout << "Soy pasajero\n";

			Console::SetCursorPosition(52, 12);cout << "Soy conductor\n";
			
			Console::SetCursorPosition(52, 13);cout << "Administracion\n";
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(52, 14);cout << ">> Salir <<\n";
			Console::ForegroundColor = ConsoleColor::White;
			o = _getch();
			if (o == 13) {
				return;
			}
			break;
		}
		if (opcion == 5) {

			opcion = 1;
			return;
			break;
		}
		if (opcion == 6) {
			opcion = 2;
		}
		if (opcion == 7) {
			opcion = 3;
		}
		if (opcion == 8) {
			opcion = 4;
		}
	}
	
	
	
};

void Menu::passengerMenu(int& opcion) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(52, 10); cout << "Pasajero\n";
		Console::SetCursorPosition(52, 11); cout << "---------------------\n";

		Console::SetCursorPosition(52, 12);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion\n"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion\n"; }

		Console::SetCursorPosition(52, 13);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme\n"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme\n"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(52, 14); cout << "---------------------------\n";
		Console::SetCursorPosition(52, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal \n"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal \n"; }

		Console::ForegroundColor = ConsoleColor::White;

		int key = _getch();
		if (key == 13) {
			if (opcion == 3) opcion = 0;
			return;
		}
		if (key == 0 || key == 224) key = _getch();
		Seleccion(key, opcion, 1, 3);
	}
};

void Menu::passengerLogin(string& DNI, string& name, string& password) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Lynx > Pasajero > Iniciar Sesion";
	Console::SetCursorPosition(52, y++); cout << "--------------------------------";
	Console::SetCursorPosition(52, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(52, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(52, y++); cout << "Contrasena      : "; cin >> password;
};

void Menu::passengerSignIn(string& DNI, string& name, string& password) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Lynx > Pasajero > Registro";
	Console::SetCursorPosition(52, y++); cout << "--------------------------------";
	Console::SetCursorPosition(52, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(52, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(52, y++); cout << "Contrasena      : "; cin >> password;
};

void Menu::passengerOptions(int& opcion) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(52, 11); cout << "Pasajero";
		Console::SetCursorPosition(52, 12); cout << "---------------------";

		Console::SetCursorPosition(52, 13);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Solicitar un viaje"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Solicitar un viaje"; }

		Console::SetCursorPosition(52, 14);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver viaje activo"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver viaje activo"; }

		Console::SetCursorPosition(52, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Historial de viajes"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Historial de viajes"; }

		Console::SetCursorPosition(52, 16);
		if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Calificar ultimo conductor"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Calificar ultimo conductor"; }

		Console::SetCursorPosition(52, 17);
		if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(52, 18); cout << "---------------------------";
		Console::SetCursorPosition(52, 19);
		if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cerrar sesion"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cerrar sesion"; }

		Console::ForegroundColor = ConsoleColor::White;

		int key = _getch();
		if (key == 13) {
			if (opcion == 6) opcion = 0;
			return;
		}
		if (key == 0 || key == 224) key = _getch();
		Seleccion(key, opcion, 1, 6);
	}
};

void Menu::passengerSendTrip(string& origen, string& destino, int& tipo, float& km) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Pasajero > Solicitar Viaje";
	Console::SetCursorPosition(52, y++); cout << "--------------------------";
	cin.ignore();
	Console::SetCursorPosition(52, y++); cout << "Origen   : "; std::getline(cin, origen);
	Console::SetCursorPosition(52, y++); cout << "Destino  : "; std::getline(cin, destino);
	
	int yPrompt = y;
	Console::SetCursorPosition(52, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
	while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
		Console::SetCursorPosition(52, y); cout << "Error: Elija 1-3.         ";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(80, yPrompt); cout << "   ";
		Console::SetCursorPosition(80, yPrompt);
	}
	y++;

	int yKm = y;
	Console::SetCursorPosition(52, y++); cout << "Distancia (km): ";
	while (!(cin >> km) || km <= 0) {
		Console::SetCursorPosition(52, y); cout << "Error: Km > 0.            ";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(68, yKm); cout << "   ";
		Console::SetCursorPosition(68, yKm);
	}
};

void Menu::passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		int y = 11;
		Console::SetCursorPosition(52, y++); cout << "Pasajero > Confirmar Viaje";
		Console::SetCursorPosition(52, y++); cout << "--------------------------";
		trip.mostrar(52, y);

		y++;
		Console::SetCursorPosition(52, y);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Confirmar viaje"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Confirmar viaje"; }

		Console::SetCursorPosition(52, y + 1);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cancelar"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cancelar"; }

		Console::ForegroundColor = ConsoleColor::White;

		int key = _getch();
		if (key == 13) return;
		if (key == 0 || key == 224) key = _getch();
		Seleccion(key, opcion, 1, 2);
	}
};

void Menu::passengerProfile(int& option, Passenger passenger) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Lynx > Pasajero > Perfil";
	Console::SetCursorPosition(52, y++); cout << "------------------------";
	passenger.mostrar(52, y);
	y++;
	Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
	Console::SetCursorPosition(65, y-1); cin >> option;
};

void Menu::driverMenu(int& opcion) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(52, 10); cout << "Conductor\n";
		Console::SetCursorPosition(52, 11); cout << "---------------------\n";

		Console::SetCursorPosition(52, 12);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion\n"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion\n"; }

		Console::SetCursorPosition(52, 13);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme\n"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme\n"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(52, 14); cout << "---------------------------\n";
		Console::SetCursorPosition(52, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal \n"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal \n"; }

		Console::ForegroundColor = ConsoleColor::White;

		int key = _getch();
		if (key == 13) {
			if (opcion == 3) opcion = 0;
			return;
		}
		if (key == 0 || key == 224) key = _getch();
		Seleccion(key, opcion, 1, 3);
	}
}

void Menu::driverLogin(string& DNI, string& name, string& password) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Conductor > Iniciar Sesion";
	Console::SetCursorPosition(52, y++); cout << "--------------------------------";
	Console::SetCursorPosition(52, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(52, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(52, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::driverOptions(int& opcion, string name, string placa, bool estado, float rating) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(52, 11); cout << "Conductor";
		Console::SetCursorPosition(52, 12); cout << "---------------------";

		Console::SetCursorPosition(52, 13);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Solicitar un viaje"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Solicitar un viaje"; }

		Console::SetCursorPosition(52, 14);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver viaje activo"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver viaje activo"; }

		Console::SetCursorPosition(52, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Historial de viajes"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Historial de viajes"; }

		Console::SetCursorPosition(52, 16);
		if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Calificar ultimo conductor"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Calificar ultimo conductor"; }

		Console::SetCursorPosition(52, 17);
		if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(52, 18); cout << "---------------------------";
		Console::SetCursorPosition(52, 19);
		if (opcion == 6) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cerrar sesion"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cerrar sesion"; }

		Console::ForegroundColor = ConsoleColor::White;

		int key = _getch();
		if (key == 13) {
			if (opcion == 6) opcion = 0;
			return;
		}
		if (key == 0 || key == 224) key = _getch();
		Seleccion(key, opcion, 1, 6);
	}
}

void Menu::driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Conductor > Solicitar Viaje";
	Console::SetCursorPosition(52, y++); cout << "--------------------------";
	cin.ignore();
	Console::SetCursorPosition(52, y++); cout << "Origen   : "; std::getline(cin, partida);
	Console::SetCursorPosition(52, y++); cout << "Destino  : "; std::getline(cin, llegada);

	int yT = y;
	Console::SetCursorPosition(52, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
	while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
		Console::SetCursorPosition(52, y); cout << "Error: Elija 1-3.         ";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(80, yT); cout << "   ";
		Console::SetCursorPosition(80, yT);
	}
	y++;

	int yKm = y;
	Console::SetCursorPosition(52, y++); cout << "Distancia (km): ";
	while (!(cin >> km) || km <= 0) {
		Console::SetCursorPosition(52, y); cout << "Error: Km > 0.            ";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(68, yKm); cout << "   ";
		Console::SetCursorPosition(68, yKm);
	}
}

void Menu::driverSingIn(string& DNI, string& name, string& password) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Conductor > Registro";
	Console::SetCursorPosition(52, y++); cout << "--------------------------------";
	Console::SetCursorPosition(52, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(52, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(52, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Conductor > Registrar Carro";
	Console::SetCursorPosition(52, y++); cout << "--------------------------------";
	Console::SetCursorPosition(52, y++); cout << "Placa           : "; cin >> placa;
	Console::SetCursorPosition(52, y++); cout << "Marca           : "; cin >> marca;
	Console::SetCursorPosition(52, y++); cout << "Modelo          : "; cin >> modelo;
	Console::SetCursorPosition(52, y++); cout << "Color           : "; cin >> color;
	Console::SetCursorPosition(52, y++); cout << "Anio            : "; cin >> ano;
}

void Menu::driverGains(int& option, Driver driver) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Conductor > Ganancias";
	Console::SetCursorPosition(52, y++); cout << "--------------------------------";
	Console::SetCursorPosition(52, y++); cout << "Viajes           : "; std::cout << driver.getTotalTrips();
	Console::SetCursorPosition(52, y++); cout << "Ganancia Bruta  : "; std::cout << driver.getTotalEarnings();
	Console::SetCursorPosition(52, y++); cout << "Comision (20%)  : "; std::cout << driver.getTotalEarnings()*0.20;
	Console::SetCursorPosition(52, y++); cout << "Ganancia Neta   : "; std::cout << driver.getNetEarnings();
}

void Menu::driverProfile(int& option, Driver driver) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Conductor > Perfil";
	Console::SetCursorPosition(52, y++); cout << "-------------------------";
	driver.mostrar(52, y);
	y++;
	Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
	Console::SetCursorPosition(65, y-1); cin >> option;
};

void Menu::tripHistory(int& option, Trip trips[], int s, string title) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(52, y++); cout << "Lynx > " << title << " > Historial";
	Console::SetCursorPosition(52, y++); cout << "------------------------------------";
	if (s == 0) {
		Console::SetCursorPosition(52, y++); cout << "No hay registros disponibles.";
	} else {
		for (int i = 0; i < s; i++) {
			trips[i].mostrar(52, y);
			y++;
			if (y > 20) {
				Console::SetCursorPosition(52, y++); cout << "-- Presione una tecla para mas --";
				_getch();
				std::system("cls"); lynx(); y = 11;
				Console::SetCursorPosition(52, y++); cout << "Lynx > " << title << " > Historial (cont.)";
				Console::SetCursorPosition(52, y++); cout << "------------------------------------";
			}
		}
	}
	y++;
	Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
	Console::SetCursorPosition(65, y-1); cin >> option;
};

void Menu::LYNX() {
	Console::SetWindowSize(120, 30);

	LinkedList<int> passengers = LinkedList<int>();
	LinkedList<int> drivers = LinkedList<int>();
	LinkedList<int> tripsP = LinkedList<int>();
	LinkedList<int> tripsD = LinkedList<int>();

	Passenger passenger = Passenger();
	Driver driver = Driver();
	
	Trip trips[100];
	int s = 0;

	Trip tripc[100];
	int r = 0;

	Trip trip = Trip();
	Vehicle vehicle = Vehicle();

	Vehicle expvehicle = Vehicle("PER-422","Toyota,","RAV4","Azul",2019);
	Driver expdriver = Driver("Juan Valdez", "60473829", "123",expvehicle );
	Passenger exppassenger = Passenger("Yeremy Chavez", "52348623", "123");
	Passenger sa = Passenger("s", "s", "s");

	System::Random f;
	int option, tipo = 0;
	string password = "", DNI = "", name = "", origen = "", destino = "";
	string id = "";

	float rating = f.Next(0, 26) / 5;
	float km = 0;
	string partida = "", llegada = "";
	string placa = "", marca = "", color = "", modelo = "";
	int ano = 0;

	do {
		principal2(option);
		switch (option) {
		case 1:
			do {
				passengerMenu(option);
				switch (option) {
				case 1:
					passengerLogin(DNI, name, password);
					if (!(DNI == passenger.getDni() && password == passenger.getPassword() && name == passenger.getName())) {
						std::system("cls"); lynx();
						Console::SetCursorPosition(52, 11); cout << "Datos incorrectos";
						Console::SetCursorPosition(52, 13); std::system("pause");
						option = 6;
						break;
					}

					do {
						passengerOptions(option);
						switch (option) {
						case 1:
							passengerSendTrip(origen, destino, tipo, km);
							if (origen == "" || destino == "" || tipo < 1 || tipo > 3 || km < 0.1) {
								std::system("cls"); lynx();
								Console::SetCursorPosition(52, 11); cout << "Datos invalidos";
								Console::SetCursorPosition(52, 13); std::system("pause");
								option = 6;
								break;
							}
							trip.setOrigin(origen);
							trip.setDestination(destino);
							trip.setTipe(tipo);
							trip.setPassengerDni(passenger.getDni());
							id = (s + r < 9 ? "TRP0" : "TRP") + to_string(s + r + 1);
							trip.setTripId(id);
							trip.setDriverName(expdriver.getName());
							trip.setPrice(trip.calcPrice(tipo, km));
							
							do {
								passengerConfirmTrip(option, trip.getOrigin(), trip.getDestination(), trip.getTipe(), trip);
							} while (option > 2 || option < 1);

							if (option == 1) {
								trip.setStatus("en_curso");
								std::system("cls"); lynx();
								Console::SetCursorPosition(52, 11); cout << "[OK] Viaje solicitado!";
								Console::SetCursorPosition(52, 13); std::system("pause");
								trips[s++] = trip;
								passenger.addTrip(trip.getPrice());
								for (int i = s - 2; i >= 0; i--) {
									if (trips[i].getStatus() == "en_curso") trips[i].setStatus("completado");
								}
							} else {
								trip.setStatus("cancelado");
								std::system("cls"); lynx();
								Console::SetCursorPosition(52, 11); cout << "[XX] Viaje cancelado";
								Console::SetCursorPosition(52, 13); std::system("pause");
							}
							option = 6;
							break;

						case 2:
							if (trip.getStatus() == "en_curso") {
								int subOpt = 1;
								while(subOpt != 0) {
									std::system("cls"); lynx();
									int y = 11;
									Console::SetCursorPosition(52, y++); cout << "Viaje en curso";
									Console::SetCursorPosition(52, y++); cout << "--------------";
									trip.mostrar(52, y);
									y++;
									Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
									Console::SetCursorPosition(65, y - 1); cin >> subOpt;
								}
							} else {
								std::system("cls"); lynx();
								Console::SetCursorPosition(52, 11); cout << "No hay viaje activo.";
								Console::SetCursorPosition(52, 13); std::system("pause");
							}
							option = 6;
							break;

						case 3:
							option = 1;
							while (option != 0) { tripHistory(option, trips, s, "Pasajero"); }
							option = 6;
							break;

						case 4:
							do {
								std::system("cls"); lynx();
								int y = 11;
								Console::SetCursorPosition(52, y++); cout << "Calificar Conductor";
								Console::SetCursorPosition(52, y++); cout << "-------------------";
								Console::SetCursorPosition(52, y++); cout << "[1] - * Muy malo";
								Console::SetCursorPosition(52, y++); cout << "[2] - ** Malo";
								Console::SetCursorPosition(52, y++); cout << "[3] - *** Regular";
								Console::SetCursorPosition(52, y++); cout << "[4] - **** Bueno";
								Console::SetCursorPosition(52, y++); cout << "[5] - ***** Excelente";
								Console::SetCursorPosition(52, y++); cout << "[0] - Omitir";
								Console::SetCursorPosition(52, y++); cout << "Opcion: "; cin >> option;
							} while (option > 5 || option < 0);
							option = 6;
							break;

						case 5:
							option = 1;
							while (option != 0) { passengerProfile(option, passenger); }
							option = 6;
							break;
						}
					} while (option != 0);
					option = 6;
					break;

				case 2:
					do { passengerSignIn(DNI, name, password); } while (DNI == "" || password == "" || name == "");
					passenger = Passenger(name, DNI, password);
					std::system("cls"); lynx();
					Console::SetCursorPosition(52, 11); cout << "Cuenta creada exitosamente.";
					Console::SetCursorPosition(52, 13); std::system("pause");
					option = 6;
					break;
				}
			} while (option != 0);
			break;

		case 2:
			do {
				driverMenu(option);
				switch (option) {
				case 1:
					driverLogin(DNI, name, password);
					if (!(DNI == driver.getDni() && password == driver.getPassword() && name == driver.getName())) {
						std::system("cls"); lynx();
						Console::SetCursorPosition(52, 11); cout << "Datos incorrectos";
						Console::SetCursorPosition(52, 13); std::system("pause");
						option = 6;
						break;
					}

					do {
						driverOptions(option, driver.getName(), driver.getVehicle().getPlate(), driver.getIsAvailable(), rating);
						switch (option) {
						case 1:
							driverRegisterTrip(partida, llegada, km, tipo);
							if (partida == "" || llegada == "" || km < 0.1 || tipo > 3 || tipo < 1) {
								std::system("cls"); lynx();
								Console::SetCursorPosition(52, 11); cout << "Datos invalidos";
								Console::SetCursorPosition(52, 13); std::system("pause");
								option = 7;
								break;
							}
							trip.setOrigin(partida);
							trip.setDestination(llegada);
							trip.setTipe(tipo);
							trip.setPassengerDni(exppassenger.getDni());
							id = (r + s < 9 ? "TRP0" : "TRP") + to_string(r + s + 1);
							trip.setTripId(id);
							trip.setDriverName(driver.getName());
							trip.setPrice(trip.calcPrice(tipo, km));
							tripc[r++] = trip;
							driver.acceptRide(trip.getPrice());
							option = 7;
							break;

						case 2:
							option = 1;
							while (option != 0) { tripHistory(option, tripc, r, "Conductor"); }
							option = 7;
							break;

						case 3:
							driver.finishRide();
							option = 7;
							break;

						case 4:
							option = 1;
							while (option != 0) { driverGains(option, driver); }
							option = 7;
							break;

						case 5:
							option = 1;
							while (option != 0) {
								std::system("cls"); lynx();
								int y = 11;
								Console::SetCursorPosition(52, y++); cout << "Mi Vehiculo";
								Console::SetCursorPosition(52, y++); cout << "-----------";
								driver.getVehicle().mostrar(52, y);
								y++;
								Console::SetCursorPosition(52, y++); cout << "[0] - Volver";
								Console::SetCursorPosition(65, y - 1); cin >> option;
							}
							option = 7;
							break;

						case 6:
							option = 1;
							while (option != 0) { driverProfile(option, driver); }
							option = 7;
							break;
						}
					} while (option != 0);
					option = 6;
					break;

				case 2:
					do { driverSingIn(DNI, name, password); } while (DNI == "" || password == "" || name == "");
					driver.setDni(DNI); driver.setName(name); driver.setPassword(password);
					do { driverRegisterCar(placa, marca, modelo, color, ano); } while (placa == "" || marca == "" || modelo == "" || color == "" || ano < 2005 || ano > 2026);
					vehicle.setPlate(placa); vehicle.setBrand(marca); vehicle.setModel(modelo); vehicle.setColor(color); vehicle.setYear(ano);
					driver.setVehicle(vehicle);
					std::system("cls"); lynx();
					Console::SetCursorPosition(52, 11); cout << "Cuenta de conductor creada.";
					Console::SetCursorPosition(52, 13); std::system("pause");
					option = 6;
					break;
				}
			} while (option != 0);
			break;
		}
	} while (option != 4);
	std::system("pause");
};