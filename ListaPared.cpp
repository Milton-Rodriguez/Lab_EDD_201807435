#include "ListaPared.h"
#include "Puntos.h";

void ListaPared::add(string id_Proyecto, string nombre_nivel, int no_pared, Puntos* inicio, Puntos* final, string color)
{
	Pared* nuevo = new Pared(id_Proyecto,nombre_nivel,no_pared,inicio,final,color);

	if (root2 == nullptr) {
		root2 = nuevo;
	}
	else {
		Pared* aux = root2;
		Pared* temp = root2;
		while (aux != nullptr) {
			
			temp = aux;
			aux = aux->siguiente;
		}
		nuevo->anterior = temp;
		temp->siguiente = nuevo;



	}
}

void ListaPared::Print(string id_Proyecto, string nombre_nivel)
{
	if (root2 != nullptr) {
		Pared* aux = root2;
		while (aux != nullptr) {
			if (aux->id_Proyecto == id_Proyecto && aux->nombre_nivel == nombre_nivel)
			{
				cout << "Proyecto: " << aux->id_Proyecto << "  Nivel: " << aux->nombre_nivel << "\n";
				Puntos* ini = aux->inicio;
				Puntos* fin = aux->final;
				cout << "Inicio: " << ini->x <<"," <<ini->y << "\n";
				cout << "Final: " << fin->x << "," << fin->y << "\n";
				cout << "Color: " << aux->color << "\n";
			}
			
			aux = aux->siguiente;
		}
	}
} 