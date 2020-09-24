#include "ListaNivel.h"


 void ListaNivel::add(string id_Proyecto, string nombre_nivel)
{
	Nivel* nuevo = new Nivel(id_Proyecto,nombre_nivel);
	
	if (root1 == nullptr) {
		root1 = nuevo;
	}
	else {
		Nivel* aux = root1;
		Nivel* temp = root1;
		while (aux != nullptr) {
			cout << "Si entra"<<aux->id_Proyecto;
			temp = aux;
			aux = aux->siguiente;
		}
		nuevo->anterior = temp;
		temp->siguiente = nuevo;
		

		
	}
}

 void ListaNivel::Print()
{
	if (root1 != nullptr) {
		Nivel* aux = root1;
		while (aux != nullptr) {
			cout << "Proyecto: "<<aux->id_Proyecto <<"  Nivel: "<<aux->nombre_nivel;
			aux = aux->siguiente;
		}
	}
}