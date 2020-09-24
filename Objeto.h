#pragma once
#include <iostream>
#include "Puntos.h"
using namespace std;
class Objeto
{
public:

	string id_Proyecto;
	string nombre_nivel;
	int identificador;
	string nombre;
	string letra;
	string color;
	Puntos** arreglo;
	int tamanoarreglo;
	
	
	Objeto* siguiente;
	Objeto* anterior;


	Objeto(string id_Proyecto, string nombre_nivel, int identificador, Puntos** arreglo, int tamanoarreglo, string color,string nombre,string letra) {
		this->nombre_nivel = nombre_nivel;
		this->id_Proyecto = id_Proyecto;
		this->identificador = identificador;
		this->nombre = nombre;
		this->letra = letra;
		this->color = color;
		this->arreglo = arreglo;
		this->siguiente = nullptr;
		this->anterior = nullptr;
		this->tamanoarreglo = tamanoarreglo;

	}


private:

};