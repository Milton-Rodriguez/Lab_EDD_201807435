#include "ListaPared.h"


void ListaPared::add(string id_Proyecto, string nombre_nivel, int no_pared, string inicio, string final, string color)
{
	Pared* nuevo = new Pared(id_Proyecto,nombre_nivel,no_pared,inicio,final,color);

	if (root2 == nullptr) {
		root2 = nuevo;
	}
	else {
		Pared* aux = root2;
		Pared* temp = root2;
		while (aux != nullptr) {
			cout << "Si entra" << aux->id_Proyecto;
			temp = aux;
			aux = aux->siguiente;
		}
		nuevo->anterior = temp;
		temp->siguiente = nuevo;



	}
}

void ListaPared::Print()
{
	if (root2 != nullptr) {
		Pared* aux = root2;
		while (aux != nullptr) {
			cout << "Proyecto: " << aux->id_Proyecto << "  Nivel: " << aux->nombre_nivel << "\n";
			cout << "Inicio: " << aux->inicio << "\n";
			cout << "Final: " << aux->final << "\n";
			cout << "Color: " << aux->color << "\n";
			aux = aux->siguiente;
		}
	}
} 