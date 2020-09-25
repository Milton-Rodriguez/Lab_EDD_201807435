#pragma once
#include <iostream>
#include "Puntos.h";
using namespace std;
class Nivel
{
public:
	
	string id_Proyecto;
	string nombre_nivel;
	Nivel* siguiente;
	Nivel* anterior;
	Puntos* tamano;



	Nivel(string id_Proyecto, string nombre_nivel, Puntos* tamano) {
		this->nombre_nivel = nombre_nivel;
		this->id_Proyecto = id_Proyecto;
		this->tamano = tamano;
		this->siguiente = nullptr;
		this->anterior = nullptr;
		
	}


private:

};

