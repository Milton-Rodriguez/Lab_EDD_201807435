#pragma once
#include <iostream>
using namespace std;
class Nivel
{
public:
	
	string id_Proyecto;
	string nombre_nivel;
	Nivel* siguiente;
	Nivel* anterior;


	Nivel(string id_Proyecto, string nombre_nivel) {
		this->nombre_nivel = nombre_nivel;
		this->id_Proyecto = id_Proyecto;
		this->siguiente = nullptr;
		this->anterior = nullptr;
		
	}


private:

};

