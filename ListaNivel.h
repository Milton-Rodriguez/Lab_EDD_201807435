#pragma once
#include "Nivel.h"

static Nivel* root1;
class ListaNivel
{
public:
	 

	ListaNivel() {
		
	}

	void add(string id_Proyecto, string nombre_nivel);
	void Print(string id_Proyecto);
};

