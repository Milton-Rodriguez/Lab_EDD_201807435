#pragma once
#include "Objeto.h"
#include "Puntos.h"


static Objeto* root3;
class ListaObjeto
{
public:


	ListaObjeto() {

	}

	void add(string id_Proyecto, string nombre_nivel, int identificador, Puntos** arreglo, int tamanoarreglo, string color, string nombre, string letra);
	void Print(string id_Proyecto, string nombre_nivel);
	void Print1(string id_Proyecto, string nombre_nivel);
	void eliminar(string id_Proyecto, string nombre_nivel, int identificador);
};
