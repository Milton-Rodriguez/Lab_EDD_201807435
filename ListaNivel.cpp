#include "ListaNivel.h"


 void ListaNivel::add(string id_Proyecto, string nombre_nivel, Puntos*tamano)
{
	Nivel* nuevo = new Nivel(id_Proyecto,nombre_nivel,tamano);
	
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

 Nivel* ListaNivel::Buscar(string id_Proyecto, string nombre_nivel)
 {
	 if (root1 != nullptr) {
		 Nivel* aux = root1;
		 while (aux != nullptr) {
			 if (aux->id_Proyecto == id_Proyecto && aux->nombre_nivel == nombre_nivel)
			 {
				 return aux;
			 }

			 aux = aux->siguiente;
		 }
	 }
 }

 Nivel* ListaNivel::Eliminar(string id_Proyecto, string nombre_nivel)
 {
	 if (root1 != nullptr) {
		 Nivel* aux = root1;
		 while (aux != nullptr) {
			 if (aux->id_Proyecto == id_Proyecto && aux->nombre_nivel == nombre_nivel)
			 {
				 Nivel* anterior = aux->anterior;
				 Nivel* siguiente = aux->siguiente;
				 if (anterior != NULL)
				 {
					 anterior->siguiente = siguiente;
					 siguiente->anterior = anterior;
				 }
				 else {
					 root1 = siguiente;
				 }
				 if (siguiente != NULL)
				 {
					 anterior->siguiente = siguiente;
					 siguiente->anterior = anterior;
				 }
				 else {
					 anterior->siguiente = NULL;
				 }
				 return aux;
			 }

			 aux = aux->siguiente;
		 }
	 }
 }