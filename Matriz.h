#pragma once
#include "NodoMatriz.h"
#include "Objeto.h"
#include "Pared.h"
#include "Cabecera.h";
#include "Elemento.h";
#include <vector>
using namespace std;
class Matriz
{
public:
	Matriz();
	~Matriz();
	
	void codigo();
	void add(Elemento* nuevo);
	void graficar();

private:
	Cabecera* horizontal;
	Cabecera* vertical;
	Cabecera* getVertical(Elemento* nombre);
	Cabecera* getHorizontal(Elemento* nombre);
	Cabecera* crearVertical(Elemento* nombre);
	Cabecera* crearHorizontal(Elemento* nombre);
	NodoMatriz* obtenerultimoV(Cabecera* cabecera, int y);
	NodoMatriz* obtenerultimoH(Cabecera* cabecera, int y);
	

};



