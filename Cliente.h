#pragma once
#include "Persona.h"
#include<iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include<string>

using namespace std;

class Cliente : Persona{
	//atributos
private: string nit;
	   //constructor
public:
	Cliente() {

	}

	Cliente(string name, string lastname, string adress, string birth, int tel, string n) : Persona(name, lastname, adress, birth, tel) {
		nit = n;
	}
	//Metodos set y get

	//Set (modificar el atributo)
	void setNit(string n) { nit = n; }
	void setNombres(string name) { nombres = name; }
	void setApellido(string lastname) { apellidos = lastname; }
	void setDireccion(string adress) { direccion = adress; }
	void setCumpleanos(string birth) { fecha_nacimiento = birth; }
	void setel(int tel) { telefono = tel; }
	//Get
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellido() { return apellidos; }
	string getDireccion() { return direccion; }
	string getCumpleanos() { return fecha_nacimiento; }
	int getTel() { return telefono; }

	void leer() {
		system("cls");
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tClientes" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "____________________________________________" << endl;
					cout << "ID de cliente: " << fila[0] << endl;
					cout << "Nit del cliente: " << fila[1] << endl;
					cout << "Nombre del cliente: " << fila[2] << endl;
					cout << "Apellidos del cliente: " << fila[3] << endl;
					cout << "Direccion del cliente: " << fila[4] << endl;
					cout << "Telefono del cliente: " << fila[5] << endl;
					cout << "Fecha de nacimiento del cliente: " << fila[6] << endl;
				}
			}
			else {
				cout << "Error al ingresar informacion" << endl;
			}
		}
		else {
			cout << "Hubo un erro en la conexion" << endl;

		}
		cout << "____________________________________________" << endl;
		cn.cerrar_conexion();
		system("pause");

	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		
		
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insertar = "INSERT INTO  `clientes`(nit, nombres, apellidos, direccion, telefono, fecha_nacimiento) VALUES('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (q_estado) {
				system("cls");
				cout << "Ingreso exitoso" << endl;
				system("pause");
			}
		}else {
			cout << "Hubo un erro en la conexion" << endl;
			system("pause");
		}
			

	}
};

