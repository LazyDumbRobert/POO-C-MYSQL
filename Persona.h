#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Persona
{
	// atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0;

		 // metodos
protected:
	Persona() {

	}
	//constructor (manda parametros a la clase)
	Persona(string name, string lastname, string adress, string birth, int tel) {
		nombres = name;
		apellidos = lastname;
		direccion = adress;
		fecha_nacimiento = birth;
		telefono = tel;
	}
};

