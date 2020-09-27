#pragma once
#include "Pared.h"
#include "Puntos.h"


static Pared* root2;
class ListaPared
{
public:


	ListaPared() {

	}

	void add(string id_Proyecto, string nombre_nivel, int no_pared, Puntos* inicio, Puntos* final, string color);
	Pared* returnroot();
	void Print(string id_Proyecto, string nombre_nivel);
};
