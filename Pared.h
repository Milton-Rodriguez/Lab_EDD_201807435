#pragma once
#include <iostream>
using namespace std;
class Pared
{
public:

	string id_Proyecto;
	string nombre_nivel;
	int no_pared;
	string inicio;
	string final;
	string color;
	Pared* siguiente;
	Pared* anterior;


	Pared(string id_Proyecto, string nombre_nivel,int no_pared,string inicio,string final,string color) {
		this->nombre_nivel = nombre_nivel;
		this->id_Proyecto = id_Proyecto;
		this->no_pared = no_pared;
		this->inicio = inicio;
		this->final = final;
		this->color = color;
		this->siguiente = nullptr;
		this->anterior = nullptr;

	}


private:

};