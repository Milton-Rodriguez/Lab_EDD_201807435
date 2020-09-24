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
			temp = aux;
			aux = aux->siguiente;
		}
		nuevo->anterior = temp;
		temp->siguiente = nuevo;
		

		
	}
}

 void ListaNivel::Print(string id_Proyecto)
{
	if (root1 != nullptr) {
		Nivel* aux = root1;
		while (aux != nullptr) {
			if (aux->id_Proyecto ==id_Proyecto)
			{
				cout << "Nivel: " << aux->nombre_nivel << "\n";
			}
			
			aux = aux->siguiente;
		}
	}
}