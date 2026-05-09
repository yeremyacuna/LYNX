#pragma once
#include <iostream>
#include <string>
#include "Driver.h"
#include "Passenger.h"
#include "Trip.h"

using namespace System;
using std::string; using std::cout; using std::cin; using std::getline; using std::endl; using std::to_string;

class Menu
{
public:
	Menu();
	~Menu();


	void principal(int& opcion);
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

void Menu::passengerMenu(int& opcion) {
	std::system("cls");
	cout << "Lynx > Pasajero\n---------------------\n";
	cout << "[1] - Iniciar Sesion\n";
	cout << "[2] - Registrarme\n";
	cout << "---------------------------\n[0] - Volver al menu principal \n";
	cin >> opcion;
};

void Menu::passengerLogin(string& DNI, string& name, string& password) {
	std::system("cls");
	cout << "Lynx > Pasajero\n---------------------\n";
	cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.\n";
	cout << "DNI : "; cin >> DNI;
	cin.ignore();
	cout << "Nombre Completo : "; std::getline(cin, name);
	cout << "Contrasena : "; cin >> password;
};

void Menu::passengerSignIn(string& DNI, string& name, string& password) {
	std::system("cls");
	cout << "Lynx > Pasajero\n---------------------";
	cout << "\nDNI : "; cin >> DNI;
	cin.ignore();
	cout << "Nombre Completo : "; std::getline(cin, name);
	cout << "Contrasena : "; cin >> password;
};



void Menu::passengerOptions(int& opcion) {
	std::system("cls");
	cout << "Lynx > Pasajero\n---------------------\n";
	cout << "[1] - Solicitar un viaje\n";
	cout << "[2] - Ver viaje activo\n";
	cout << "[3] - Historial de viajes\n";
	cout << "[4] - Calificar ultimo conductor\n";
	cout << "[5] - Perfil\n";
	cout << "---------------------------\n[0] - Cerrar sesion \n";
	cin >> opcion;
};

void Menu::passengerSendTrip(string& origen, string& destino, int& tipo, float& km) {
	std::system("cls");
	cout << "Lynx > Pasajero > Solicitar Viaje\n---------------------\n";
	cin.ignore();
	cout << "Origen: "; std::getline(cin,origen);
	cout << "Destino: "; std::getline(cin,destino);
	cout << "Tipo: [1] Economico  [2] Estandar  [3] Premium -> "; cin >> tipo;
	cout << "km: "; cin >> km;
};

void Menu::passengerConfirmTrip(int& opcion, string origen, string destino, int tipo, Trip trip) {
	System::Random f;
	std::system("cls");
	cout << "Lynx > Pasajero > Confirmar Viaje\n---------------------\n";
	trip.mostrar();
	cout << "\n---------------------\n";
	cout << "[1] - Confirmar viaje\n";
	cout << "[2] - Cancelar\n";
	cout << "\nIngrese opcion: "; cin >> opcion;
};

void Menu::driverMenu(int& opcion) {
	std::system("cls");
	cout << "Lynx > Conductor\n---------------------\n";
	cout << "[1] - Iniciar Sesion\n";
	cout << "[2] - Registrarme como conductor\n";
	cout << "---------------------------\n[0] - Volver al menu principal \n";
	cin >> opcion;
};

void Menu::driverLogin(string& DNI, string& name, string& password) {
	std::system("cls");
	cout << "Lynx > Conductor\n---------------------\n";
	cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.\n";
	cout << "DNI : "; cin >> DNI;
	cin.ignore();
	cout << "Nombre Completo : "; std::getline(cin, name);
	cout << "Contrasena : "; cin >> password;
};

void Menu::driverOptions(int& opcion, string name, string placa,bool estado, float rating) {
	std::system("cls");
	cout << "Lynx > Conductor\n";
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

void Menu::driverRegisterTrip(string& partida, string& llegada, float& km, int& tipo) {
	std::system("cls");
	cout << "Lynx > Conductor > Registrar viaje\n---------------------\n";
	cout << "Partida: "; cin >> partida;
	cout << "llegada: "; cin >> llegada;
	cout << "Tipo: [1] Economico  [2] Estandar  [3] Premium -> "; cin >> tipo;
	cout << "km: "; cin >> km;
};

void Menu::driverSingIn(string& DNI, string& name, string& password) {
	std::system("cls");
	cout << "Lynx > Conductor >> registro\n---------------------";
	cout << "\nDNI : "; cin >> DNI;
	cin.ignore();
	cout << "Nombre Completo : "; std::getline(cin, name);
	cout << "Contrasena : "; cin >> password;
};


void Menu::LYNX() {

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

	//linked list of passenger
	//linked list of driver


	System::Random f;
	//Pasajero
	int option, tipo = 0;
	string password = "", DNI = "", name = "", origen = "", destino = "";
	bool activo = false, creada = false;
	string id = "";

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
		principal(option);
		switch (option) {
		case 1:
			do {
				//Menu del pasajero
				passengerMenu(option);
				switch (option) {
				case 1:
					do {
						//Inicio de sesion 
						passengerLogin(DNI, name, password);
					} while (!(DNI == passenger.getDni() && password == passenger.getPassword() && name == passenger.getName()));

					cout << "Sesion iniciada. Bienvenido, " << passenger.getName() << "\n";
					std::system("pause");
					do {
						//Menu del pasajero con sus opciones
						passengerOptions(option);

						switch (option) {
						case 1:
							do {
								//Registrar viaje
								passengerSendTrip(origen, destino, tipo,km);
							} while (origen == "" || destino == "" || tipo < 1 || tipo > 3 || km<0.1);

							trip.setOrigin(origen);
							trip.setDestination(destino);
							trip.setTipe(tipo);
							trip.setPassengerDni(passenger.getDni());
							if(s+r<10)id = "TRP0" + to_string(s+r+1);
							else id = "TRP" + to_string(s+r + 1);
							trip.setTripId(id);
							trip.setDriverName(expdriver.getName());
							trip.setPrice(trip.calcPrice(trip.getTipe(), km));
							trips[s] = trip;


							passenger.addTrip(trip.calcPrice(trip.getTipe(), km));
							s++;
							

							do {
								//Confimar viaje
								passengerConfirmTrip(option, trip.getOrigin(), trip.getDestination(), trip.getTipe(),trip);
							} while (option > 2 || option < 1);
							switch (option) {
							case 1:
								trip.setStatus("en_curso");
								std::system("cls");
								cout << "[OK] Viaje solicitado! Tu conductor esta en camino.\n";
								std::system("pause");

								for (int i = s - 2;i >= 0;i--) {
									if(trips[i].getStatus()=="en_curso")trips[i].setStatus("completado");
								}
								break;
							case 2:
								trip.setStatus("cancelado");
								std::system("cls");
								cout << "[XX] Viaje cancelado\n";
								std::system("pause");
								break;
							}
							option = 6;

							break;

						case 2:
							//Ver viaje en curso
							if (trip.getStatus() == "en_curso") {
								do {
									passengerConfirmTrip(option, trip.getOrigin(), trip.getDestination(), trip.getTipe(), trip);
								} while (option != 0);
							}
							else {
								std::system("cls");
								cout << "No hay viaje activo.\n";
								std::system("pause");
							}
							option = 6;
							break;

						case 3:
							do {
								std::system("cls");
								cout << "Lynx > Pasajero > Historial de Viajes\n---------------------\n";
								
								for (int i = 0;i < s;i++) {
									trips[i].mostrar();
									cout << endl;
								}
								cout << "[0] - Volver al panel"; cin >> option;
							} while (option != 0);
							option = 6;
							break;

						case 4:
							//Supongo que aqui usaremos aqui pila ya que es el ultimo objeto de la lista
							do {
								std::system("cls");
								cout << "Lynx > Pasajero > Calificar Conductor\n---------------------\n";
								cout << "[1] - ★ Muy malo\n";
								cout << "[2] - ★★ malo\n";
								cout << "[3] - ★★★ Regular\n";
								cout << "[4] - ★★★★ Bueno\n";
								cout << "[5] - ★★★★★ Excelente\n";
								cout << "[0] - Omitir"; cin >> option;
							} while (option > 5 || option < 0);
							switch (option) {
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
							option = 6;
							break;

						case 5:
							do {
								//Ver perfin
								std::system("cls");
								cout << "Lynx > Pasajero > Perfil\n---------------------\n";
								passenger.mostrar();
								cout << "[0] - Volver"; cin >> option;
							} while (option != 0);
							option = 6;
							break;
						case 0:
							break;
						}
					} while (option > 5 || option < 0);


					option = 6;
					break;

				case 2:
					do {
						//registrar pasajero
						passengerSignIn(DNI,name,password);
					} while (DNI == "" || password == "" || name == "");

					passenger = Passenger(name, DNI, password);


					std::system("cls");
					cout << "Cuenta creada.\n";
					std::system("pause");
					option = 6;
					break;
				case 0:
					break;

				};

				option = 6;
				
			} while (option < 0 || option>2);














		case 2:
			do {
				//Menu del conductor
				driverMenu(option);

				switch (option) {
				case 1:
					
						do {
							driverLogin(DNI, name, password);

						} while (!(DNI == driver.getDni() && password == driver.getPassword() && name == driver.getName()));

						cout << "Sesion iniciada. Bienvenido, " << driver.getName() << "\n";
						std::system("pause");
						do {
							driverOptions(option, driver.getName(), driver.getVehicle().getPlate(), driver.getIsAvailable(), rating);

							switch (option) {
							case 1:
								do {
									driverRegisterTrip(partida, llegada, km, tipo);
								} while ( partida == "" || llegada == "" || km < 0.1 || tipo>3||tipo<1);
								trip.setOrigin(partida);
								trip.setDestination(llegada);
								trip.setTipe(tipo);
								trip.setPassengerDni(exppassenger.getDni());
								if (r+s < 10)id = "TRP0" + to_string(r+s + 1);
								else id = "TRP" + to_string(r+s + 1);
								trip.setTripId(id);
								trip.setDriverName(driver.getName());
								trip.setPrice(trip.calcPrice(trip.getTipe(), km));
								tripc[r] = trip;

								r++;
								
								driver.acceptRide(trip.calcPrice(tipo, km));
								option = 7;

								break;

							case 2:
								do {
									std::system("cls");
									cout << "Lynx > Conductor > Historial de Carreras\n---------------------\n";

									for (int i = 0;i < r;i++) {
										tripc[i].mostrar();
										cout << endl;
									}
									cout << "[0] - Volver al panel"; cin >> option;
								} while (option != 0);
					
								option = 7;
								break;

							case 3:
								driver.finishRide();
								option = 7;
								break;

							case 4:
								do {
									std::system("cls");
									cout << "Lynx > Conductor > Ganancias\n---------------------\n";
									
									cout << "Viajes: " << driver.getTotalTrips();
									cout << "Ganancias brutas: S/" << driver.getTotalEarnings();
									cout << "Comision LYNX (20%): S/" << driver.getTotalEarnings() * 0.20;
									cout << "Ganancias netas: S/" << driver.getNetEarnings();
									cout << "[0] - Volver"; cin >> option;
								} while (option != 0);
								option = 7;
								break;

							case 5:
								do {
									std::system("cls");
									cout << "Lynx > Conductor > Mi Vehiculo\n---------------------\n";
									driver.getVehicle().mostrar();
									cout << "[0] - Volver"; cin >> option;
								} while (option != 0);
								

								option = 7;
								break;
							case 6:
								do {
									std::system("cls");
									cout << "Lynx > Conductor > Perfil\n---------------------\n";
									driver.mostrar();
									cout << "[0] - Volver"; cin >> option;
								} while (option != 0);


								option = 7;
								break;
							case 0:
								break;
							}
						} while (option > 5 || option < 0);
					
					
					option = 6;
					break;
				case 2:
					do {
						driverSingIn(DNI, name, password);
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
					} while (placa == "" || marca == "" || modelo == "" || color == "" || ano < 2005 || ano>2026);

					vehicle.setPlate(placa);
					vehicle.setBrand(marca);
					vehicle.setModel(modelo);
					vehicle.setColor(color);
					vehicle.setYear(ano);
					driver.setVehicle(vehicle);

					std::system("cls");
					cout << "Cuenta creada.\n";
					std::system("pause");
					option = 6;
					break;
				case 0:
					break;
				}
			} while (option > 2 || option < 0);

			option = 6;
			break;
		case 3:


			break;
		case 4:
			break;
		}


	} while (option != 4);

	//Injection of data in the txt

	cout << "Hasta la proxima" << endl << endl;
	std::cin.ignore();
	std::cin.get();
};