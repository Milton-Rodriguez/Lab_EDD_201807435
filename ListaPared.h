#pragma once
#include "Pared.h"

static Pared* root2;
class ListaPared
{
public:


	ListaPared() {

	}

	void add(string id_Proyecto, string nombre_nivel, int no_pared, string inicio, string final, string color);
	void Print();
};
