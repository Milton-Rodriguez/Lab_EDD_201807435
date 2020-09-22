#pragma once
#include <iostream>
#include "Proyecto.h"
using namespace std;
class NodoArbol
{
public:
	NodoArbol* parent;
	NodoArbol* left;
	NodoArbol* right;
	int key;
	Proyecto* value;

	NodoArbol(int key) {
		this->key = key;
		this->value = nullptr;
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
};