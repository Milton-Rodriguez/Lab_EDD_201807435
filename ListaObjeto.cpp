#include "ListaObjeto.h"
#include "Puntos.h";


void ListaObjeto::add(string id_Proyecto, string nombre_nivel, int identificador, Puntos** arreglo, int tamanoarreglo, string color, string nombre, string letra)
{
	Objeto* nuevo = new Objeto(id_Proyecto,nombre_nivel,identificador, arreglo,tamanoarreglo,color,nombre,letra);

	if (root3 == nullptr) {
		root3 = nuevo;
	}
	else {
		Objeto* aux = root3;
		Objeto* temp = root3;
		while (aux != nullptr) {
			
			temp = aux;
			aux = aux->siguiente;
		}
		nuevo->anterior = temp;
		temp->siguiente = nuevo;



	}
}

void ListaObjeto::Print(string id_Proyecto, string nombre_nivel)
{
	if (root3 != nullptr) {
		Objeto* aux = root3;
		while (aux != nullptr) {
			if (aux->id_Proyecto == id_Proyecto && aux->nombre_nivel == nombre_nivel)
			{
				cout << "Proyecto: " << aux->id_Proyecto << "  Nivel: " << aux->nombre_nivel << "\n";
				Puntos** ini = aux->arreglo;
				cout << "Identificador: " << aux->identificador<< "\n";
				cout << "Nombre: " << aux->nombre << "\n";
				cout << "Letra: " << aux->letra << "\n";
				cout << "Color: " << aux->color << "\n";
				cout << "Puntos: " <<  "\n";
				int longitud = aux->tamanoarreglo;
				if (longitud == 1)
				{
					cout << " X: " << ini[0]->x << " Y: " << ini[0]->y << "\n";
				}
				else {
					for (int i = 0; i < longitud; i++)
					{

						cout << " X: " << ini[i]->x << " Y: " << ini[i]->y << "\n";


					}
				}
				

			}

			aux = aux->siguiente;
		}
	}
}