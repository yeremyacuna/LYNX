#include <iostream>
#include <windows.h>
#include "Stack.h"
#include "Queue.h"
#include "ListaE.h"
#include <cstdio>
#include <conio.h>

using namespace System;


int main()
{
	Random f;
	int opcion, dni = 0, dni2 = 0, tipo=0;
	string contra = "", name = "", origen = "", destino = "", contra2 = "", name2 = "";
	char op;
	bool activo = false, creada=false;
	do {
		system("cls");
		cout << "LYNX\n";
		cout << "1. Soy pasajero\n";
		cout << "2. Soy coductor\n";
		cout << "3. Panel BackOffice\n";
		cout << "4. Salir\n";
		cout << "\nIngrese opcion: ";cin >> opcion;
	

		
		switch (opcion) {
		case 1:
			do {
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
							system("cls");
							cout << "Lynx > Modo Usuario\n---------------------";
							cout << "\nDNI : ";cin >> dni2;
							cin.ignore();
							cout << "Nombre Completo : ";getline(cin, name2);
							cout << "Contrasena : ";cin >> contra2;
							cout << "En caso no se coloquen bien los datos se volvera a generar el formulario.";
						} while (dni2 ==dni || contra2 == contra || name2 == name);

						cout << "Sesion iniciada. Bienvenido, " << name << "\n";
						system("pause");
						do {
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
									system("cls");
									cout << "Lynx > Modo Usuario > Solicitar Viaje\n---------------------\n";
									cout << "Origen: ";cin >> origen;
									cout << "Destino: ";cin >> destino;
									cout << "Tipo: [1] Economico  [2] Estandar  [3] Premium -> "; cin >> tipo;
								} while (origen == "" || destino == "" || tipo < 1 || tipo > 3);

								do {
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
									cout << "\nIngrese opcion: ";cin >> opcion;
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
						cout<< "No existe ninguna cuenta\n";
						system("pause");
					}
					opcion = 6;
					break;
				case 2:
					do {
						system("cls");
						cout << "Lynx > Modo Usuario\n---------------------";
						cout << "\nDNI : ";cin >> dni;
						cin.ignore();
						cout << "Nombre Completo : ";getline(cin, name);
						cout << "Contrasena : ";cin >> contra;
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