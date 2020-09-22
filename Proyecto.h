#pragma once
#include <iostream>
using namespace std;
class Proyecto
{
public:
	string id;
	string nombre;
	
	bool disponibilidad;

	Proyecto(string id, string nombre) {
		this->id = id;
		this->nombre = nombre;
		this->disponibilidad = true;
	}

	string toString();
	string graficar();
};
