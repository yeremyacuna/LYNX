#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <string>
#include "Driver.h"
#include "Passenger.h"
#include "Trip.h"

using namespace System;
using std::cout; using std::cin; using std::function;

class Menu
{
public:
	Menu();
	~Menu();


	void principal(int& opcion);
	void pasajero(int& opcion);
	void pasajeroLogin(string& DNI, string& name, string& password);
	void pasajeroOpciones(int& opcion);
	void solicitarViaje(string& origen, string& destino, int& tipo, float& km);
	void confirmarViaje(int& opcion, string origen, string destino, int tipo, float precio);

	void conductor(int& opcion);
	void conductorLogin(string& DNI, string& name, string& password);
	void conductorOpciones(int& opcion, string name, string placa, bool estado, float rating);

	void LYNX();

private:

};

Menu::Menu()
{
}

Menu::~Menu()
{
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

void Menu::pasajero(int& opcion) {
	std::system("cls");
	cout << "Lynx > Modo Usuario\n---------------------\n";
	cout << "[1] - Iniciar Sesion\n";
	cout << "[2] - Registrarme\n";
	cout << "---------------------------\n[0] - Volver al menu principal \n";
	cin >> opcion;
};

void Menu::pasajeroLogin(string& DNI, string& name, string& password) {
	std::system("cls");
	cout << "Lynx > Modo Usuario\n---------------------\n";
	cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.\n";
	cout << "DNI : "; cin >> DNI;
	cin.ignore();
	cout << "Nombre Completo : "; std::getline(cin, name);
	cout << "Contrasena : "; cin >> password;
};

void Menu::pasajeroOpciones(int& opcion) {
	std::system("cls");
	cout << "Lynx > Modo Usuario\n---------------------\n";
	cout << "[1] - Solicitar un viaje\n";
	cout << "[2] - Ver viaje activo\n";
	cout << "[3] - Historial de viajes\n";
	cout << "[4] - Calificar ultimo conductor\n";
	cout << "[5] - Perfil\n";
	cout << "---------------------------\n[0] - Cerrar sesion \n";
	cin >> opcion;
};

void Menu::solicitarViaje(string& origen, string& destino, int& tipo, float& km) {
	std::system("cls");
	cout << "Lynx > Modo Usuario > Solicitar Viaje\n---------------------\n";
	cout << "Origen: "; cin >> origen;
	cout << "Destino: "; cin >> destino;
	cout << "Tipo: [1] Economico  [2] Estandar  [3] Premium -> "; cin >> tipo;
	cout << "km: "; cin >> km;
};

void Menu::confirmarViaje(int& opcion, string origen, string destino, int tipo, float precio) {
	System::Random f;
	std::system("cls");
	cout << "Lynx > Modo Usuario > Confirmar Viaje\n---------------------\n";
	cout << "Origen: " << origen;
	cout << "\nDestino: " << destino;
	cout << "\nTipo: [1] Economico  [2] Estandar  [3] Premium -> "; cout << tipo;
	cout << "\nPrecio est. : S/ " << precio;
	cout << "\nConductor : " << "Emiliano   -  " << "BKW-3F3  -  " << "4.8";
	cout << "\n---------------------\n";
	cout << "[1] - Confirmar viaje\n";
	cout << "[2] - Cancelar\n";
	cout << "\nIngrese opcion: "; cin >> opcion;
};

void Menu::conductor(int& opcion) {
	std::system("cls");
	cout << "Lynx > Modo Conductor\n---------------------\n";
	cout << "[1] - Iniciar Sesion\n";
	cout << "[2] - Registrarme como conductor\n";
	cout << "---------------------------\n[0] - Volver al menu principal \n";
	cin >> opcion;
};

void Menu::conductorLogin(string& DNI, string& name, string& password) {
	std::system("cls");
	cout << "Lynx > Panel Conductor\n---------------------\n";
	cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.\n";
	cout << "DNI : "; cin >> DNI;
	cin.ignore();
	cout << "Nombre Completo : "; std::getline(cin, name);
	cout << "Contrasena : "; cin >> password;
};

void Menu::conductorOpciones(int& opcion, string name, string placa,bool estado, float rating) {
	std::system("cls");
	cout << "Lynx > Panel Conductor\n";
	cout << name << "   Placa: " << placa << "\n";
	cout << "Estado: "; if (estado) { cout << "Disponible  "; }
	else { cout << "No Disponible  "; }cout << "Rating: " << rating << "\n";
	cout << "---------------------\n";
	cout << "[1] - Registrar viaje\n";
	cout << "[2] - Ver carreras hechas\n";
	cout << "[3] - Cambiar a disponible\n";
	cout << "[4] - Ver mis ganancias\n";
	cout << "[5] - Gestionar vehiculo\n";
	cout << "[6] - Ver perfil y estadisticas\n";
	cout << "---------------------------\n[0] - Cerrar sesion \n";
	cin >> opcion;
};




void Menu::LYNX() {

	Passenger passenger = Passenger();
	Driver driver = Driver();
	Trip trip = Trip();
	Vehicle vehicle = Vehicle();

	//linked list of passenger
	//linked list of driver


	System::Random f;
	//Pasajero
	int opcion, tipo = 0;
	string password = "", DNI = "", name = "", origen = "", destino = "";
	bool activo = false, creada = false;

	//Conductor
	int dni2 = 0;
	float rating = f.Next(0, 26) / 5, ganacias = 0, recokm = 0;
	string contra2 = "", name2 = "";
	bool creada2 = false, estado = false;

	//Conductor viaje
	float km = 0, precio = 0, estrellas = 10;
	string nombre = "", partida = "", llegada = "";

	//Vehiculo
	string placa = "", marca = "", color = "", modelo = "";
	int ano = 0;


	do {
		//Menu principal
		principal(opcion);
		switch (opcion) {
		case 1:
			do {
				//Menu del pasajero
				pasajero(opcion);
				switch (opcion) {
				case 1:
					do {
						//inicio de sesion (verificacion de cuenta existente
						pasajeroLogin(DNI, name, password);
					} while (!(DNI == passenger.getDni() && password == passenger.getPassword() && name == passenger.getName()));

					cout << "Sesion iniciada. Bienvenido, " << name << "\n";
					std::system("pause");
					do {
						//menu del pasajero con sus opciones
						pasajeroOpciones(opcion);

						switch (opcion) {
						case 1:
							do {
								//Aqui el usuario crea un viaje con sus respectivos datos (pueden ser mas)
								solicitarViaje(origen, destino, tipo,km);
							} while (origen == "" || destino == "" || tipo < 1 || tipo > 3 || km<0.1);

							trip.setOrigin(origen);
							trip.setDestination(destino);
							trip.setTipe(tipo);
							

							do {
								//Ver el resumen para confirmar o no
								confirmarViaje(opcion, trip.getOrigin(), trip.getDestination(), trip.getTipe(), trip.calcPrice(trip.getTipe(), km));
							} while (opcion > 2 || opcion < 1);
							switch (opcion) {
							case 1:
								trip.setStatus("en_curso");
								std::system("cls");
								cout << "[OK] Viaje solicitado! Tu conductor esta en camino.\n";
								std::system("pause");
								break;
							case 2:
								trip.setStatus("cancelado");
								std::system("cls");
								cout << "[XX] Viaje cancelado\n";
								std::system("pause");
								break;
							}
							opcion = 6;

							break;

						case 2:
							if (trip.getStatus() == "en_curso") {
								do {
									//Ver el ultimo viaje hecho aceptado (contando como activo)
									confirmarViaje(opcion, trip.getOrigin(), trip.getDestination(), trip.getTipe(), trip.calcPrice(trip.getTipe(), km));
								} while (opcion != 0);
							}
							else {
								std::system("cls");
								cout << "No hay viaje activo.\n";
								std::system("pause");
							}
							opcion = 6;
							break;

						case 3:
							do {
								std::system("cls");
								cout << "Lynx > Modo Usuario > Historial de Viajes\n---------------------\n";
								//Aqui deberia integrarse un for donde muestre en consola cada viaje hecho si ha sido completado o cancelado (ID, origen, destino, precio y estado)
								//Despues de mostrar el historial que se muestre el total de viajes y cuanto dinero ha sido gastado de solo los completados
								cout << "[0] - Volver al panel"; cin >> opcion;
							} while (opcion != 0);

							break;

						case 4:
							//Supongo que aqui usaremos aqui pila ya que es el ultimo objeto de la lista
							do {
								std::system("cls");
								cout << "Lynx > Modo Pasajero > Calificar Conductor\n---------------------\n";
								cout << "[1] - ★ Muy malo\n";
								cout << "[2] - ★★ malo\n";
								cout << "[3] - ★★★ Regular\n";
								cout << "[4] - ★★★★ Bueno\n";
								cout << "[5] - ★★★★★ Excelente\n";
								cout << "[0] - Omitir"; cin >> opcion;
							} while (opcion > 5 || opcion < 0);
							switch (opcion) {
							case 1:
								//asignar al ultimo conductor una estrella
								break;
							case 2:
								//asignar al ultimo conductor dos estrellas
								break;
							case 3:
								//asignar al ultimo conductor tres estrellas
								break;
							case 4:
								//asignar al ultimo conductor cuatro estrellas
								break;
							case 5:
								//asignar al ultimo conductor cinco estrellas
								break;
							case 0:
								break;
							}
							opcion = 6;
							break;

						case 5:
							do {

								
								std::system("cls");
								cout << "Lynx > Modo Passenger > Perfil\n---------------------\n";
								passenger.mostrar();
								cout << "[0] - Volver"; cin >> opcion;
							} while (opcion != 0);
							opcion = 6;
							break;
						case 0:
							break;
						}
					} while (opcion > 5 || opcion < 0);


					opcion = 6;
					break;

				case 2:
					do {
						std::system("cls");
						cout << "Lynx > Modo Pasajero\n---------------------";
						cout << "\nDNI : "; cin >> DNI;
						cin.ignore();
						cout << "Nombre Completo : "; std::getline(cin, name);
						cout << "Contrasena : "; cin >> password;
					} while (DNI == "" || password == "" || name == "");

					passenger = Passenger(name, DNI, password);


					std::system("cls");
					cout << "Cuenta creada.\n";
					std::system("pause");
					opcion = 6;
					break;
				case 0:
					break;

				};

				opcion = 6;
				
			} while (opcion < 0 || opcion>2);














		case 2:
			do {
				//Menu del conductor
				conductor(opcion);

				switch (opcion) {
				case 1:
					
						do {
							//inicio de sesion (verificacion de cuenta existente)
							conductorLogin(DNI, name, password);

						} while (!(DNI == DNI && password == password && name == name));

						cout << "Sesion iniciada. Bienvenido, " << name2 << "\n";
						std::system("pause");
						do {
							//menu del conductor con sus opciones


							conductorOpciones(opcion, name, placa, estado, rating);

							switch (opcion) {
							case 1:
								do {
									//Aqui el conductor registra un viaje con sus respectivos datos (pueden ser mas)
									std::system("cls");
									cout << "Lynx > Panel Conductor > Registrar viaje\n---------------------\n";
									cout << "Partida: "; cin >> partida;
									cout << "llegada: "; cin >> llegada;
									cout << "km: "; cin >> km;
									cout << "precio: S/"; cin >> precio;
								} while ( partida == "" || llegada == "" || km < 0.1 || precio < 0.1);

								driver.acceptRide(precio);
								opcion = 7;

								break;

							case 2:
								//Aqui podria ver todas las carreras que ha registrado el conductor
								opcion = 7;
								break;

							case 3:
								driver.finishRide();
								opcion = 7;
								break;

							case 4:
								do {
									std::system("cls");
									cout << "Lynx > Panel Conductor > Ganancias\n---------------------\n";
									
									cout << "Viajes: \n" << driver.getTotalTrips();
									cout << "Ganancias brutas: S/" << driver.getTotalEarnings();
									cout << "Comision LYNX (20%): S/" << driver.getTotalEarnings() * 0.20;
									cout << "Ganancias netas: S/" << driver.getNetEarnings();
									//Puede haber mas datos
									cout << "[0] - Volver"; cin >> opcion;
								} while (opcion != 0);
								opcion = 7;
								break;

							case 5:
								do {
									std::system("cls");
									cout << "Lynx > Panel Conductor > Mi Vehiculo\n---------------------\n";
									driver.getVehicle().mostrar();

									//Puede haber mas datos
									cout << "[0] - Volver"; cin >> opcion;
								} while (opcion != 0);
								

								opcion = 7;
								break;
							case 6:
								do {
									std::system("cls");
									cout << "Lynx > Panel Conductor > Perfil\n---------------------\n";
									driver.mostrar();

									//Puede haber mas datos
									cout << "[0] - Volver"; cin >> opcion;
								} while (opcion != 0);


								opcion = 7;
								break;
							case 0:
								break;
							}
						} while (opcion > 5 || opcion < 0);
					
					
					opcion = 6;
					break;
				case 2:
					do {
						std::system("cls");
						cout << "Lynx > Panel Conductor >> registro\n---------------------";
						cout << "\nDNI : "; cin >> DNI;
						cin.ignore();
						cout << "Nombre Completo : "; std::getline(cin, name);
						cout << "Contrasena : "; cin >> password;
					} while (DNI == "" || password == "" || name == "");

					driver.setDni(DNI);
					driver.setName(name);
					driver.setPassword(password);

					do {
						std::system("cls");
						cout << "Lynx > Panel Conductor >> Registro Vehiculo\n---------------------\n";
						cout << "placa : "; cin >> placa;
						cout << "marca : "; cin >> marca;
						cout << "modelo : "; cin >> modelo;
						cout << "color : "; cin >> color;
						cout << "anio : "; cin >> ano;
					} while (placa == "" || marca == "" || modelo == "" || color == "" || ano > 2000);
					vehicle.setPlate(placa);
					vehicle.setBrand(marca);
					vehicle.setModel(modelo);
					vehicle.setColor(color);
					vehicle.setYear(ano);
					driver.setVehicle(vehicle);

					std::system("cls");
					cout << "Cuenta creada.\n";
					std::system("pause");
					opcion = 6;
					break;
				case 0:
					break;
				}
			} while (opcion > 2 || opcion < 0);

			opcion = 6;
			break;
		case 3:

			break;
		case 4:
			break;
		}


	} while (opcion != 4);

	//Injection of data in the txt

	
	std::system("pause");
};