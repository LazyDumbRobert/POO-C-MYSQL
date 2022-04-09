
#include <iostream>
#include "Cliente.h"
#include <string>

using namespace std;

void ingresar_cliente();
Cliente c;

int main(){
	int op;

	do {
		system("cls");
		cout << "1.Ingresar cliente" << endl;
		cout << "2.Leer clientes" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: ingresar_cliente(); break;
		case 2: c.leer(); break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);
	
	
}

void ingresar_cliente() {

	system("cls");

	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;

	cout << "Ingrese el nit del cliente: ";
	fflush(stdin);
	cin.ignore();
	getline(cin, nit);
	cout << "Ingrese los nombres del cliente: ";
	getline(cin, nombres);
	cout << "Ingrese elos apellidos del cliente: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion del cliente: ";
	getline(cin, direccion);
	cout << "Ingrese la fecha de nacimiento del cliente: ";
	cin >> fecha_nacimiento;
	cout << "Ingrese el numero de telefono del cliente: ";
	cin >> telefono;
	cin.ignore();

	Cliente c = Cliente(nombres, apellidos, direccion, fecha_nacimiento, telefono, nit);
	c.crear();
}
