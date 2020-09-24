#pragma once
#include "NodoArbol.h"
#include "Proyecto.h"

static NodoArbol* root;
class ArbolAVL
{
public:
	
	ArbolAVL() {
		

	}

	void add1(int key, Proyecto* value);
	void inOrden();
	void inOrden1(NodoArbol* node);
	
	
};
