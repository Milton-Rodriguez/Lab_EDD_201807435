#pragma once
#include "NodoArbol.h"
#include "Proyecto.h"

class ArbolAVL
{
public:
	NodoArbol* root;

	ArbolAVL() {
		root = nullptr;
	}

	void add(int key, Proyecto* value);
	void inOrden(NodoArbol* node);
};
