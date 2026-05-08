#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <string>
#include "LinkedList.h"
#include "LinkedDoubleList.h"
#include "Queue.h"
#include "Stack.h"

using namespace System;
using namespace std;


int main()
{
	Random f;
	//Pasajero
	int opcion, dni = 0, tipo = 0;
	string contra = "", name = "", origen = "", destino = "";
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
		system("cls");
		cout << "LYNX\n";
		cout << "1. Soy pasajero\n";
		cout << "2. Soy conductor\n";
		cout << "3. Panel BackOffice\n";
		cout << "4. Salir\n";
		cout << "\nIngrese opcion: "; cin >> opcion;



		switch (opcion) {
		case 1:
			do {
				//Menu del pasajero
				system("cls");
				cout << "Lynx > Modo Usuario\n---------------------\n";
				cout << "[1] - Iniciar Sesion\n";
				cout << "[2] - Registrarme\n";
				cout << "---------------------------\n[0] - Volver al menu principal \n";
				cin >> opcion;

				switch (opcion) {
				case 1:
					if (creada) {
						do {
							//inicio de sesion (verificacion de cuenta existente
							system("cls");
							cout << "Lynx > Modo Usuario\n---------------------\n";
							cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.\n";
							cout << "DNI : "; cin >> dni2;
							cin.ignore();
							cout << "Nombre Completo : "; getline(cin, name2);
							cout << "Contrasena : "; cin >> contra2;

						} while (!(dni2 == dni && contra2 == contra && name2 == name));

						cout << "Sesion iniciada. Bienvenido, " << name << "\n";
						system("pause");
						do {
							//menu del pasajero con sus opciones
							system("cls");
							cout << "Lynx > Modo Usuario\n---------------------\n";
							cout << "[1] - Solicitar un viaje\n";
							cout << "[2] - Ver viaje activo\n";
							cout << "[3] - Historial de viajes\n";
							cout << "[4] - Calificar ultimo conductor\n";
							cout << "[5] - Perfil\n";
							cout << "---------------------------\n[0] - Cerrar sesion \n";
							cin >> opcion;

							switch (opcion) {
							case 1:
								do {
									//Aqui el usuario crea un viaje con sus respectivos datos (pueden ser mas)
									system("cls");
									cout << "Lynx > Modo Usuario > Solicitar Viaje\n---------------------\n";
									cout << "Origen: "; cin >> origen;
									cout << "Destino: "; cin >> destino;
									cout << "Tipo: [1] Economico  [2] Estandar  [3] Premium -> "; cin >> tipo;
								} while (origen == "" || destino == "" || tipo < 1 || tipo > 3);

								do {
									//Ver el resumen para confirmar o no
									system("cls");
									cout << "Lynx > Modo Usuario > Confirmar Viaje\n---------------------\n";
									cout << "Origen: " << origen;
									cout << "\nDestino: " << destino;
									cout << "\nTipo: [1] Economico  [2] Estandar  [3] Premium -> "; cout << tipo;
									cout << "\nPrecio est. : S/ " << f.Next(8, 21) << "." << f.Next(0, 10) << "0";
									cout << "\nConductor : " << "Emiliano   -  " << "BKW-3F3  -  " << "4.8";
									cout << "\n---------------------\n";
									cout << "[1] - Confirmar viaje\n";
									cout << "[2] - Cancelar\n";
									cout << "\nIngrese opcion: "; cin >> opcion;
								} while (opcion > 2 || opcion < 1);
								switch (opcion) {
								case 1:
									activo = true;
									system("cls");
									cout << "[OK] Viaje solicitado! Tu conductor esta en camino.\n";
									system("pause");
									break;
								case 2:
									break;
								}
								opcion = 6;

								break;

							case 2:
								if (activo) {
									do {
										//Ver el ultimo viaje hecho aceptado (contando como activo)
										system("cls");
										cout << "Lynx > Modo Usuario > Viaje activo\n---------------------\n";
										cout << "ID Viaje: " << "TRP-" << f.Next(10000, 99999);
										cout << "\nOrigen: " << origen;
										cout << "\nDestino: " << destino;
										cout << "\nTipo: [1] Economico  [2] Estandar  [3] Premium -> "; cout << tipo;
										cout << "\nPrecio est. : S/ " << f.Next(8, 21) << "." << f.Next(0, 10) << "0";
										cout << "\nConductor : " << "Emiliano   -  " << "BKW-3F3  -  " << "4.8";
										cout << "\n---------------------\n";
										cout << "[0] - Volver al panel"; cin >> opcion;
									} while (opcion != 0);
								}
								else {
									system("cls");
									cout << "No hay viaje activo.\n";
									system("pause");
								}
								opcion = 6;
								break;

							case 3:
								do {
									system("cls");
									cout << "Lynx > Modo Usuario > Historial de Viajes\n---------------------\n";
									//Aqui deberia integrarse un for donde muestre en consola cada viaje hecho si ha sido completado o cancelado (ID, origen, destino, precio y estado)
									//Despues de mostrar el historial que se muestre el total de viajes y cuanto dinero ha sido gastado de solo los completados
									cout << "[0] - Volver al panel"; cin >> opcion;
								} while (opcion != 0);

								break;

							case 4:
								//Supongo que aqui usaremos aqui pila ya que es el ultimo objeto de la lista
								do {
									system("cls");
									cout << "Lynx > Modo Usuario > Calificar Conductor\n---------------------\n";
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
									system("cls");
									cout << "Lynx > Modo Usuario > Perfil\n---------------------\n";
									cout << "Nombre: " << name;
									cout << "DNI: " << dni;
									cout << "Rating: " << f.Next(0, 5) << "." << f.Next(0, 10);
									cout << "Viajes: ";//cantidad de viajes;
									//Puede haber mas datos
									cout << "[0] - Volver"; cin >> opcion;
								} while (opcion != 0);
								opcion = 6;
								break;
							case 0:
								break;
							}
						} while (opcion > 5 || opcion < 0);
					}
					else {
						system("cls");
						cout << "No existe ninguna cuenta\n";
						system("pause");
					}
					opcion = 6;
					break;
				case 2:
					do {
						system("cls");
						cout << "Lynx > Modo Usuario\n---------------------";
						cout << "\nDNI : "; cin >> dni;
						cin.ignore();
						cout << "Nombre Completo : "; getline(cin, name);
						cout << "Contrasena : "; cin >> contra;
					} while (dni == 0 || contra == "" || name == "");

					creada = true;

					system("cls");
					cout << "Cuenta creada.\n";
					system("pause");
					opcion = 6;
					break;
				case 0:
					break;
				}
			} while (opcion > 2 || opcion < 0);

			opcion = 6;
			break;
		case 2:
			do {
				//Menu del conductor
				system("cls");
				cout << "Lynx > Modo Conductor\n---------------------\n";
				cout << "[1] - Iniciar Sesion\n";
				cout << "[2] - Registrarme como conductor\n";
				cout << "---------------------------\n[0] - Volver al menu principal \n";
				cin >> opcion;

				switch (opcion) {
				case 1:
					if (creada2) {
						do {
							//inicio de sesion (verificacion de cuenta existente)
							system("cls");
							cout << "Lynx > Modo Conductor\n---------------------\n";
							cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.\n";
							cout << "DNI : "; cin >> dni2;
							cin.ignore();
							cout << "Nombre Completo : "; getline(cin, name2);
							cout << "Contrasena : "; cin >> contra2;

						} while (!(dni2 == dni && contra2 == contra && name2 == name));

						cout << "Sesion iniciada. Bienvenido, " << name2 << "\n";
						system("pause");
						do {
							//menu del conductor con sus opciones
							system("cls");
							cout << "Lynx > Panel Conductor\n";
							cout << name2 << "   Placa: " << placa << "\n";
							cout << "Estado: "; if (estado) { cout << "Disponible  "; }
							else { cout << "No Disponible  "; }cout << "Rating: " << rating << "\n";
							cout << "---------------------\n";
							cout << "[1] - Registrar viaje\n";
							cout << "[2] - Ver carreras hechas\n";
							cout << "[3] - Alternar disponibilidad\n";
							cout << "[4] - Ver mis ganancias\n";
							cout << "[5] - Gestionar vehiculo\n";
							cout << "[6] - Ver perfil y estadisticas\n";
							cout << "---------------------------\n[0] - Cerrar sesion \n";
							cin >> opcion;

							switch (opcion) {
							case 1:
								do {
									//Aqui el conductor registra un viaje con sus respectivos datos (pueden ser mas)
									system("cls");
									cout << "Lynx > Panel Conductor > Registrar viaje\n---------------------\n";
									cin.ignore();
									cout << "pasajero: "; getline(cin, nombre);
									cout << "Partida: "; cin >> partida;
									cout << "llegada: "; cin >> llegada;
									cout << "km: "; cin >> km;
									cout << "precio: S/"; cin >> precio;
									cout << "estrellas: "; cin >> estrellas;
								} while (nombre == "" || partida == "" || llegada == "" || km < 0.1 || precio < 0.1 || estrellas < 0 || estrellas>5);
								ganacias += precio;
								opcion = 7;

								break;

							case 2:
								//Aqui podria ver todas las carreras que ha registrado el conductor
								opcion = 7;
								break;

							case 3:
								estado = !estado;
								opcion = 7;
								break;

							case 4:
								do {
									system("cls");
									cout << "Lynx > Panel Conductor > Ganancias\n---------------------\n";
									cout << "Viajes: \n"//cantidad de viajes
										;
									cout << "Ganancias brutas: S/" << ganacias;
									cout << "Comision LYNX (10%): S/" << ganacias * 0.10;
									cout << "Ganancias netas: S/" << ganacias * 0.90;
									//Puede haber mas datos
									cout << "[0] - Volver"; cin >> opcion;
								} while (opcion != 0);
								opcion = 7;
								break;

							case 5:
								do {
									system("cls");
									cout << "Lynx > Panel Conductor > Mi Vehiculo\n---------------------\n";
									cout << "Placa: " << placa;
									cout << "Marca: " << marca;
									cout << "Modelo: " << modelo;
									cout << "Color: " << color;
									cout << "Anio: " << ano;
									cout << "Km recorridos: " << recokm;

									//Puede haber mas datos
									cout << "[0] - Volver"; cin >> opcion;
								} while (opcion != 0);
								opcion = 7;
								break;
							case 0:
								break;
							}
						} while (opcion > 5 || opcion < 0);
					}
					else {
						system("cls");
						cout << "No existe ninguna cuenta\n";
						system("pause");
					}
					opcion = 6;
					break;
				case 2:
					do {
						system("cls");
						cout << "Lynx > Modo Conductor >> registro\n---------------------";
						cout << "\nDNI : "; cin >> dni;
						cin.ignore();
						cout << "Nombre Completo : "; getline(cin, name);
						cout << "Contrasena : "; cin >> contra;
					} while (dni == 0 || contra == "" || name == "");

					do {
						system("cls");
						cout << "Lynx > Modo Conductor >> registro vehiculo\n---------------------\n";
						cout << "placa : "; cin >> placa;
						cout << "marca : "; cin >> marca;
						cout << "modelo : "; cin >> modelo;
						cout << "color : "; cin >> color;
						cout << "anio : "; cin >> ano;
					} while (placa == "" || marca == "" || modelo == "" || color == "" || ano > 2000);

					creada2 = true;

					system("cls");
					cout << "Cuenta creada.\n";
					system("pause");
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




	system("pause");
	return 0;
}