#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Driver.h"
#include "Passenger.h"
#include "Trip.h"
#include "AdministratorMenu.h"
#include "../include/FileManager.h"

using namespace System;
using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

/*
class Menu
{
public:
	Menu();
	~Menu();
	
	void lynx(); // crea logo
	void principal(int& opcion);	// primer menu secuencia, primera pantalla que se muestra
	void passengerMenu(int& opcion);	// menu del pasajero, solo iniciar o registrar o salir
	void passengerLogin(string& DNI, string& name, string& password);	// login es cuando inicia sesion del pasajero
	void passengerSignIn(string& DNI, string& name, string& password);	// sign in es cuando se registra el pasajero
	void passengerOptions(int& opcion);	// menu de opciones que puede hacer el pasajero
	void passengerSendTrip(string& origen, string& destino, int& tipo, float& km);	// menu para solicitar viaje
	void passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip);	// confirm trip es para la pantalla de confirmar viaje
	void passengerProfile(int& option, Passenger passenger);	// perfil del pasajero


	void driverMenu(int& opcion);
	void driverLogin(string& DNI, string& name, string& password);
	void driverOptions(int& opcion, string name, string placa, bool estado, float rating);
	void driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo);
	void driverSingIn(string& DNI, string& name, string& password);
	void driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano); // registrar el carro para el driver
	void driverGains(int& option, Driver driver);	// pantalla de ver ganancias al conductor
	void driverProfile(int& option, Driver driver);	// perfil del driver

	void tripHistory(int& option, Trip trips[], int s, string title);	// historial del pasajero y driver
	

	void LYNX();	// funcion principal
private:

};

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::lynx() {
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(45,5);std::cout << (char)219 << (char)219 << "     " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 6);std::cout << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 7);std::cout << (char)219 << (char)219 << "       " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 8);std::cout << (char)219 << (char)219 << "        " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << (char)219 << "\n";
	Console::SetCursorPosition(45, 9);std::cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "\n";

	Console::ForegroundColor = ConsoleColor::White;
}

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

void Menu::principal(int& opcion) {
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
		Console::SetCursorPosition(56, 10); cout << "Pasajero";
		Console::SetCursorPosition(46, 11); cout << "----------------------------";

		Console::SetCursorPosition(50, 12);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion"; }

		Console::SetCursorPosition(50, 13);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(46, 14); cout << "----------------------------";
		Console::SetCursorPosition(50, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal "; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal "; }

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

void Menu::passengerLogin(string& DNI, string& name, string& password) // Login: input DNI, name, password
{
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(50, y++); cout << "Pasajero > Iniciar Sesion";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
};

void Menu::passengerSignIn(string& DNI, string& name, string& password) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(50, y++); cout << "Pasajero > Registro";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
};

void Menu::passengerOptions(int& opcion) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(56, 11); cout << "Pasajero";
		Console::SetCursorPosition(46, 12); cout << "----------------------------";

		Console::SetCursorPosition(48, 13);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Solicitar un viaje"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Solicitar un viaje"; }

		Console::SetCursorPosition(48, 14);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver viaje activo"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver viaje activo"; }

		Console::SetCursorPosition(48, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Historial de viajes"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Historial de viajes"; }

		Console::SetCursorPosition(48, 16);
		if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Calificar ultimo conductor"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Calificar ultimo conductor"; }

		Console::SetCursorPosition(48, 17);
		if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(46, 18); cout << "----------------------------";
		Console::SetCursorPosition(48, 19);
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
	Console::SetCursorPosition(50, y++); cout << "Pasajero > Solicitar Viaje";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	cin.ignore();
	Console::SetCursorPosition(48, y++); cout << "Origen   : "; std::getline(cin, origen);
	Console::SetCursorPosition(48, y++); cout << "Destino  : "; std::getline(cin, destino);
	
	int yPrompt = y;
	Console::SetCursorPosition(48, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
	while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
		Console::SetCursorPosition(48, y); cout << "Error: Elija 1-3.         ";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(80, yPrompt); cout << "   ";
		Console::SetCursorPosition(80, yPrompt);
	}
	y++;

	int yKm = y;
	Console::SetCursorPosition(48, y++); cout << "Distancia (km): ";
	while (!(cin >> km) || km <= 0) {
		Console::SetCursorPosition(48, y); cout << "Error: Ingrese un dato valido (km > 0)";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(64, yKm); cout << "                             ";
		Console::SetCursorPosition(64, yKm);
	}
};

void Menu::passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		int y = 11;
		Console::SetCursorPosition(50, y++); cout << "Pasajero > Confirmar Viaje";
		Console::SetCursorPosition(46, y++); cout << "----------------------------";
		trip.mostrar(52, y);

		y++;
		Console::SetCursorPosition(48, y);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Confirmar viaje"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Confirmar viaje"; }

		Console::SetCursorPosition(48, y + 1);
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
	Console::SetCursorPosition(50, y++); cout << "Pasajero > Perfil";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	passenger.mostrar(48, y);
	y++;
	Console::SetCursorPosition(56, y++); cout << "Volver";
	int get = _getch();
	if (get == 13)option = 0;
};

void Menu::driverMenu(int& opcion) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(50, 10); cout << "Conductor";
		Console::SetCursorPosition(46, 11); cout << "----------------------------";

		Console::SetCursorPosition(48, 12);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Iniciar Sesion"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Iniciar Sesion"; }

		Console::SetCursorPosition(48, 13);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrarme"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrarme"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(46, 14); cout << "----------------------------";
		Console::SetCursorPosition(48, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Volver al menu principal "; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Volver al menu principal "; }

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
	Console::SetCursorPosition(50, y++); cout << "Conductor > Iniciar Sesion";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::driverOptions(int& opcion, string name, string placa, bool estado, float rating) {
	opcion = 1;
	while (true) {
		std::system("cls");
		lynx();
		Console::SetCursorPosition(50, 11); cout << "Conductor";
		Console::SetCursorPosition(46, 12); cout << "----------------------------";

		Console::SetCursorPosition(48, 13);
		if (opcion == 1) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Registrar Viaje"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Registrar Viaje"; }

		Console::SetCursorPosition(48, 14);
		if (opcion == 2) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver Carreras Hechas"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver Carreras Hechas"; }

		Console::SetCursorPosition(48, 15);
		if (opcion == 3) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Cambiar a Disponible"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Cambiar a Disponible"; }

		Console::SetCursorPosition(48, 16);
		if (opcion == 4) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Ver mis Ganancias"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Ver mis Ganancias"; }

		Console::SetCursorPosition(48, 17);
		if (opcion == 5) { Console::ForegroundColor = ConsoleColor::Yellow; cout << " >> Perfil"; }
		else { Console::ForegroundColor = ConsoleColor::White; cout << "    Perfil"; }

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(46, 18); cout << "----------------------------";
		Console::SetCursorPosition(48, 19);
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
	Console::SetCursorPosition(50, y++); cout << "Conductor > Registrar Viaje";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	cin.ignore();
	Console::SetCursorPosition(48, y++); cout << "Origen   : "; std::getline(cin, partida);
	Console::SetCursorPosition(48, y++); cout << "Destino  : "; std::getline(cin, llegada);

	int yT = y;
	Console::SetCursorPosition(48, y++); cout << "Tipo [1:Eco, 2:Std, 3:Pre]: ";
	while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
		Console::SetCursorPosition(48, y); cout << "Error: Elija 1-3.         ";
		cin.clear();
		cin.ignore(10000, '\n');
		Console::SetCursorPosition(80, yT); cout << "   ";
		Console::SetCursorPosition(80, yT);
	}
	y++;

	int yKm = y;
	Console::SetCursorPosition(48, y++); cout << "Distancia (km): ";
	while (!(cin >> km) || km <= 0) {
		Console::SetCursorPosition(48, y); cout << "Error: Km > 0.            ";
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
	Console::SetCursorPosition(50, y++); cout << "Conductor > Registro";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	Console::SetCursorPosition(48, y++); cout << "DNI             : "; cin >> DNI;
	cin.ignore();
	Console::SetCursorPosition(48, y++); cout << "Nombre Completo : "; std::getline(cin, name);
	Console::SetCursorPosition(48, y++); cout << "Contrasena      : "; cin >> password;
}

void Menu::driverRegisterCar(string& placa, string& marca, string& modelo, string& color, int& ano) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(50, y++); cout << "Conductor > Registrar Carro";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	Console::SetCursorPosition(48, y++); cout << "Placa           : "; cin >> placa;
	Console::SetCursorPosition(48, y++); cout << "Marca           : "; cin >> marca;
	Console::SetCursorPosition(48, y++); cout << "Modelo          : "; cin >> modelo;
	Console::SetCursorPosition(48, y++); cout << "Color           : "; cin >> color;
	Console::SetCursorPosition(48, y++); cout << "Anio            : "; cin >> ano;
}

void Menu::driverGains(int& option, Driver driver) {
	std::system("cls");
	lynx();
	int y = 11;
	Console::SetCursorPosition(50, y++); cout << "Conductor > Ganancias";
	Console::SetCursorPosition(46, y++); cout << "----------------------------";
	Console::SetCursorPosition(48, y++); cout << "Viajes           : "; std::cout << driver.getTotalTrips();
	Console::SetCursorPosition(48, y++); cout << "Ganancia Bruta  : "; std::cout << driver.getTotalEarnings();
	Console::SetCursorPosition(48, y++); cout << "Comision (20%)  : "; std::cout << driver.getTotalEarnings()*0.20;
	Console::SetCursorPosition(48, y++); cout << "Ganancia Neta   : "; std::cout << driver.getNetEarnings();
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
	Console::SetWindowSize(160, 30);
	
	// declaracion de variables y constructors
	AuthManager* authMgr = new AuthManager(); 
	TripManager* tripMgr = new TripManager();
	AdministratorMenu* Admin = new AdministratorMenu(authMgr,tripMgr);
	
	Trip* trip = new Trip();

	/* 

	Trip trips[100];
	int s = 0;

	Trip tripc[100];
	int r = 0;
	*/

	System::Random f;
	int option, tipo = 0;	// important
	string password = "", DNI = "", name = "", origen = "", destino = ""; // se usa
	string id = ""; float km = 0;


	string partida = "", llegada = "";	// se usa
	string placa = "", marca = "", color = "", modelo = ""; // se usa
	int anio = 0; //se usa

	

	// logica del menu
	do {
		principal(option);
		switch (option) {
		case 1:
			do {
				passengerMenu(option);
				switch (option) {
					// =========================
					// LOGIN PASAJERO
					// =========================
				case 1:
					passengerLogin(DNI, name, password);
					if (!authMgr->loginUserValid(DNI, password)) {

						std::system("cls");
						lynx();

						Console::SetCursorPosition(48, 11);
						cout << "DNI o contrasena incorrectos";

						Console::SetCursorPosition(48, 13);
						std::system("pause");

						option = 6;
						break;
					}

					// Obtener pasajero real
					Passenger passenger = authMgr->getUserByDni(DNI);

					do {
						passengerOptions(option);
						switch (option) {

							// =========================
							// SOLICITAR VIAJE
							// =========================
						case 1: {
							passengerSendTrip(origen, destino, tipo, km);
							if (origen == "" || destino == "" || tipo < 1 || tipo > 3 || km < 0.1) {
								std::system("cls"); lynx();
								Console::SetCursorPosition(48, 11); cout << "Datos invalidos";
								Console::SetCursorPosition(48, 13); std::system("pause");
								option = 6;
								break;
							}

							trip->setOrigin(origen);
							trip->setDestination(destino);
							trip->setTipe(tipo);

							// pasajero actual
							trip->setPassengerDni(passenger.getDni());

							// buscar conductor disponible
							string driverDni = authMgr->findAvailableDriver();

							if (driverDni == "") {

								std::system("cls");
								lynx();

								Console::SetCursorPosition(48, 11);
								cout << "No hay conductores disponibles";

								Console::SetCursorPosition(48, 13);
								std::system("pause");

								option = 6;
								break;
							}

							Driver driver = authMgr->getDriverByDni(driverDni);

							trip->setDriverName(driver.getName());

							id = "TRP" + to_string(rand() % 900 + 100);

							trip->setTripId(id);
							trip->setPrice(trip->calcPrice(tipo, km));

							do {
								passengerConfirmTrip(option, trip->getOrigin(), trip->getDestination(), trip->getTipe(), *trip);
							} while (option > 2 || option < 1);

							// =========================
							// CONFIRMADO
							// =========================
							if (option == 1) {

								trip->setStatus("en_curso");

								// guardar viaje (falta)


								// actualizar pasajero
								authMgr->addTripToUser(
									passenger.getDni(),
									trip->getPrice()
								);

								// actualizar conductor
								authMgr->driverAcceptRide(
									driver.getDni(),
									trip->getPrice()
								);


								std::system("cls"); lynx();
								Console::SetCursorPosition(48, 11); cout << "[OK] Viaje solicitado!";
								Console::SetCursorPosition(48, 12); cout << "Conductor: " << driver.getName();
								Console::SetCursorPosition(48, 13); cout << "Precio: S/ " << trip->getPrice();

								Console::SetCursorPosition(48, 15); std::system("pause");

							}
							// =========================
							// CANCELADO
							// =========================
							else {
								trip->setStatus("cancelado");
								std::system("cls"); lynx();
								Console::SetCursorPosition(48, 11); cout << "[XX] Viaje cancelado";
								Console::SetCursorPosition(48, 13); std::system("pause");
							}
							option = 6;
							break;
						}


							  // ========================
							  // VER VIAJE ACTIVO
							  // =========================
						case 2:
						{
							Trip activeTrip = tripMgr->getLastTripByPassenger(passenger.getDni());

							if (activeTrip.getStatus() == "en_curso") {
								int subOpt = 1;
								while (subOpt != 0) {
									std::system("cls"); lynx();
									int y = 11;
									Console::SetCursorPosition(48, y++); cout << "Viaje en curso";
									Console::SetCursorPosition(48, y++); cout << "--------------";
									activeTrip.mostrar(48, y);
									y++;
									Console::SetCursorPosition(48, y++); cout << "[0] - Volver";
									Console::SetCursorPosition(48, y - 1); cin >> subOpt;
								}
							}
							else {
								std::system("cls"); lynx();
								Console::SetCursorPosition(52, 11); cout << "No hay viaje activo.";
								Console::SetCursorPosition(52, 13); std::system("pause");
							}
							option = 6;
							break;
						}
						
						/*
						// =========================
						// HISTORIAL
						// =========================
						case 3: {
							
							LinkedList<Trip> historial = tripMgr->getLastTripByPassenger(passenger.getDni());

							std::system("cls");
							lynx();

							int y = 11;

							Console::SetCursorPosition(48, y++);
							cout << "Historial de viajes";

							Console::SetCursorPosition(48, y++);
							cout << "---------------------";

							if (historial.getSize() == 0) {

								Console::SetCursorPosition(48, y++);
								cout << "No hay viajes registrados";
							}
							else {

								for (int i = 0; i < historial.getSize(); i++) {

									historial.get(i).mostrar(48, y);

									y += 6;
								}
							}

							Console::SetCursorPosition(48, y++);
							std::system("pause");

							option = 6;
							break;
						}*/
						/*case 4:
						{
							float rating = 0;
							do {
								std::system("cls"); lynx();
								int y = 11;
								Console::SetCursorPosition(48, y++); cout << "Calificar Conductor";
								Console::SetCursorPosition(48, y++); cout << "-------------------";
								Console::SetCursorPosition(48, y++); cout << "[1] - * Muy malo";
								Console::SetCursorPosition(48, y++); cout << "[2] - ** Malo";
								Console::SetCursorPosition(48, y++); cout << "[3] - *** Regular";
								Console::SetCursorPosition(48, y++); cout << "[4] - **** Bueno";
								Console::SetCursorPosition(48, y++); cout << "[5] - ***** Excelente";
								Console::SetCursorPosition(48, y++); cout << "[0] - Omitir";
								Console::SetCursorPosition(48, y++); cout << "Opcion: "; cin >> rating;
							} while (rating < 1 || rating < 5);
							option = 6;
							break;
						}
						
					} while (option != 0);
					option = 6;
					break;
					*/
				/*
				case 2:
					do { passengerSignIn(DNI, name, password); } while (DNI == "" || password == "" || name == "");
					passenger = Passenger(name, DNI, password);
					authMgr->registerUser(name, DNI, password);


					std::system("cls"); lynx();
					Console::SetCursorPosition(48, 11); cout << "Cuenta creada exitosamente.";
					Console::SetCursorPosition(48, 13); std::system("pause");
					option = 6;
					break;
					
				}
			} while (option != 0);
			break;
			*/
		/*case 2:
			do {
				driverMenu(option);
				switch (option) {
				case 1:
					driverLogin(DNI, name, password);
					if (!(DNI == driver->getDni() && password == driver->getPassword() && name == driver->getName())) {
						std::system("cls"); lynx();
						Console::SetCursorPosition(48, 11); cout << "Datos incorrectos";
						Console::SetCursorPosition(48, 13); std::system("pause");
						option = 6;
						break;
					}

					do {
						driverOptions(option, driver->getName(), driver->getVehicle().getPlate(), driver->getIsAvailable(), rating);
						switch (option) {
						case 1:
							driverRegisterTrip(partida, llegada, km, tipo);
							if (partida == "" || llegada == "" || km < 0.1 || tipo > 3 || tipo < 1) {
								std::system("cls"); lynx();
								Console::SetCursorPosition(48, 11); cout << "Datos invalidos";
								Console::SetCursorPosition(48, 13); std::system("pause");
								option = 7;
								break;
							}
							trip.setOrigin(partida);
							trip.setDestination(llegada);
							trip.setTipe(tipo);
							trip.setPassengerDni(exppassenger.getDni());
							id = (r + s < 9 ? "TRP0" : "TRP") + to_string(r + s + 1);
							trip.setTripId(id);
							trip.setDriverName(driver->getName());
							trip.setPrice(trip.calcPrice(tipo, km));
							tripc[r++] = trip;
							driver->acceptRide(trip.getPrice());
							option = 7;
							break;

						case 2:
							option = 1;
							while (option != 0) { tripHistory(option, tripc, r, "Conductor"); }
							option = 7;
							break;

						case 3:
							driver->finishRide();
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
								Console::SetCursorPosition(48, y++); cout << "Mi Vehiculo";
								Console::SetCursorPosition(48, y++); cout << "-----------";
								driver->getVehicle().mostrar(48, y);
								y++;
								Console::SetCursorPosition(48, y++); cout << "[0] - Volver";
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
					do { driverSingIn(DNI, name, password);
					} while (DNI == "" || password == "" || name == "");
					driver->setDni(DNI); driver->setName(name); driver->setPassword(password);

					do { driverRegisterCar(placa, marca, modelo, color, ano); 
					} while (placa == "" || marca == "" || modelo == "" || color == "" || ano < 2005 || ano > 2026);

					vehicle.setPlate(placa); vehicle.setBrand(marca); vehicle.setModel(modelo); vehicle.setColor(color); vehicle.setYear(ano);

					driver->setVehicle(vehicle);
					std::system("cls"); lynx();
					Console::SetCursorPosition(48, 11); cout << "Cuenta de conductor creada.";
					Console::SetCursorPosition(48, 13); std::system("pause");
					option = 6;
					break;
				}
			} while (option != 0);
			break;
		case 3:
			do {
				//Menu de administrador
				Admin->run(option);
				switch (option) {
				case 1:
					//Listar todos los usuarios
					Admin->listarUsuarios();
					option = 8;
					break;

				case 2:
					//Listar todos los conductores
					Admin->listarConductores();
					option = 8;
					break;
				case 3:
					//Listar todos los viajes
					Admin->listarViajes();
					option = 8;
					break;

				case 4:
					//Buscar usuuario por DNI
					Admin->buscarUsuario();
					option = 8;
					break;
				case 5:
					//Ordenar conductores por rating
					Admin->ordenarConductores();
					option = 8;
					break;

				case 6:
					//top conductores del mes
					Admin->topConductores();
					option = 8;
					break;
				case 7:
					//estadisticas generales
					Admin->estadisticas();
					option = 8;
					break;

				case 0:
					break;
				}

			} while (option != 0);
			break;
		}
	} while (option != 4);
	std::system("pause");
	*/
	//Injection of data in the txt

	cout << "Hasta la proxima" << endl << endl;
	std::cin.ignore();
	std::cin.get();
};
*/