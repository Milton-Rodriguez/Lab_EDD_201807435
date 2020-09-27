#include "ListaObjeto.h"
#include "ListaPared.h";
#include "ListaNivel.h";
#include "Puntos.h";
#include "Matriz.h";
#include "Elemento.h";

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
	ListaNivel* busquedNivel = new ListaNivel();
	Nivel* ta =busquedNivel->Buscar(id_Proyecto, nombre_nivel);
	Puntos* ta1 = ta->tamano;
	
	
	Matriz* matt = new Matriz();
	if (root3 != nullptr) {
		Objeto* aux = root3;
		while (aux != NULL) {
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
					Elemento* nn = new Elemento(aux->id_Proyecto, aux->nombre_nivel, ini[0]->x, ini[0]->y);
					nn->setObjeto(aux);
					matt->add(nn);
				}
				else {
					for (int i = 0; i < longitud; i++)
					{
						
						cout << " X: " << ini[i]->x << " Y: " << ini[i]->y << "\n";
						Elemento* nn = new Elemento(aux->id_Proyecto, aux->nombre_nivel, ini[i]->x, ini[i]->y);
						nn->setObjeto(aux);
						matt->add(nn);



					}
				}
				

			}

			aux = aux->siguiente;
		}
	}

	//graficar paredes

	//graficar paredes
	ListaPared* nuevalistapared = new ListaPared();
	Pared* root2aux = nuevalistapared->returnroot();
	if (root2aux != nullptr) {
		Pared* aux = root2aux;
		
		while (aux != nullptr) {
			if (aux->id_Proyecto == id_Proyecto && aux->nombre_nivel == nombre_nivel)
			{
				
				cout << "Proyecto: " << aux->id_Proyecto << "  Nivel: " << aux->nombre_nivel << "\n";
				Puntos* ini = aux->inicio;
				Puntos* fin = aux->final;
				cout << "Inicio: " << ini->x << "," << ini->y << "\n";
				cout << "Final: " << fin->x << "," << fin->y << "\n";
				cout << "Color: " << aux->color << "\n";
				if (ini->x == fin->x)
				{
					int a = ini->x;
					int b = fin->x;
					while (a !=b)
					{
						
						Elemento* nn = new Elemento(id_Proyecto, nombre_nivel, ini->x, a);
						nn->setPared(aux);
						matt->add(nn);
						a = a + 1;
					}
				}
				else if (ini->y == fin->y)
				{
					int a = ini->x;
					int b = fin->x;
					while (a != b)
					{
						
						Elemento* nn = new Elemento(id_Proyecto, nombre_nivel, a, ini->y);
						nn->setPared(aux);
						matt->add(nn);
						a = a + 1;
					}
				}
				else {
					int a = ini->x;
					int b = fin->x;
					int c = ini->y;
					int d = fin->y;
					while ((a == b) && c ==d)
					{
						
						Elemento* nn = new Elemento(id_Proyecto, nombre_nivel, a, c);
						nn->setPared(aux);
						matt->add(nn);
						a = a + 1;
						c = c + 1;
					}
				}
			}

			aux = aux->siguiente;
		}
	}
	matt->graficar();
}