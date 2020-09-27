#include "Matriz.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>


Matriz::Matriz() {
	this->horizontal = NULL;
	this->vertical = NULL;
}
Matriz::~Matriz() {
	NodoMatriz* aux, * aux2, * temp, * temp2,*extra,*extra2;
	aux = this->vertical;
	temp = this->horizontal;
	while (aux != NULL) {
		extra = aux->getSur();
		aux2 = aux->getEste();
		while (aux2 != NULL) {
			extra2 = aux->getEste();
			delete aux2;
			aux2 = extra2;
		}
		delete aux;
		aux = extra;
	}
	while (temp != NULL) {
		temp2 = temp->getEste();
		delete temp;
		temp = temp2;
	}
}

Cabecera* Matriz::crearHorizontal(Elemento* nombre) {
	if (this->horizontal == NULL) {
		Cabecera* nueva = new Cabecera(nombre->getNombreproyecto(),nombre->getNombreNivel(),nombre->getPosicionx(),nombre->getPosiciony());
		if (nombre->getObjeto() != NULL)
		{
			nueva->setObjeto(nombre->getObjeto());
		}else if (nombre->getPared() != NULL)
		{
			nueva->setPared(nombre->getPared());
		}
		this->horizontal = nueva;
		return nueva;
	}
	else {
		Cabecera* aux = this->horizontal;
		if (aux->getPosicionx() >= nombre->getPosicionx()) {
			Cabecera* nueva = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
			if (nombre->getObjeto() != NULL)
			{
				nueva->setObjeto(nombre->getObjeto());
			}
			else if (nombre->getPared() != NULL)
			{
				nueva->setPared(nombre->getPared());
			}
			nueva->setEste(aux);
			this->horizontal->setOeste(nueva);
			this->horizontal=nueva;
			return  nueva;
		}
		while (aux->getEste()!=NULL) {
			if (nombre->getPosicionx() > aux->getPosicionx() && nombre->getPosicionx()== ((Cabecera*)aux->getEste())->getPosicionx())
			{
				Cabecera* nueva = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
				if (nombre->getObjeto() != NULL)
				{
					nueva->setObjeto(nombre->getObjeto());
				}
				else if (nombre->getPared() != NULL)
				{
					nueva->setPared(nombre->getPared());
				}
				Cabecera* tmp= (Cabecera*)aux->getEste();
				tmp->setOeste(nueva);
				nueva->setEste(tmp);
				aux->setEste(nueva);
				nueva->setOeste(aux);
				return nueva;
			}
			aux = (Cabecera*)aux->getEste();
		}
		Cabecera* nuevo = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
		if (nombre->getObjeto() != NULL)
		{
			nuevo->setObjeto(nombre->getObjeto());
		}
		else if (nombre->getPared() != NULL)
		{
			nuevo->setPared(nombre->getPared());
		}
		aux->setEste(nuevo);
		nuevo->setOeste(aux);
		return nuevo;
	}
}

Cabecera* Matriz::crearVertical(Elemento* nombre) {
	if (this->vertical == NULL) {
		Cabecera* nueva = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
		if (nombre->getObjeto() != NULL)
		{
			nueva->setObjeto(nombre->getObjeto());
			cout << "Creador Objeto Vertical Cabeza";
		}
		else if (nombre->getPared() != NULL)
		{
			nueva->setPared(nombre->getPared());
			cout << "Creador PAred Vertical Cabeza";
		}
		this->vertical = nueva;
		return nueva;
	}
	else {
		Cabecera* aux = this->vertical;
		if (aux->getPosiciony() >= nombre->getPosiciony()) {
			Cabecera* nueva = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
			if (nombre->getObjeto() != NULL)
			{
				nueva->setObjeto(nombre->getObjeto());
				cout << "Creador Objeto Horizontal Cabeza";
			}
			else if (nombre->getPared() != NULL)
			{
				nueva->setPared(nombre->getPared());
				cout << "Creador Pared Horizonatal Cabeza";
			}
			nueva->setSur(aux);
			this->vertical->setNorte(nueva);
			this->vertical = nueva;
			return  nueva;
		}
		while (aux->getSur() != NULL) {
			if (nombre->getPosiciony() > aux->getPosiciony() && nombre->getPosiciony() == ((Cabecera*)aux->getSur())->getPosiciony())
			{
				Cabecera* nueva = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
				
				if (nombre->getObjeto() != NULL)
				{
					nueva->setObjeto(nombre->getObjeto());
					cout << "Creador Objeto Horizontal eNMEDIO";
				}
				else if (nombre->getPared() != NULL)
				{
					nueva->setPared(nombre->getPared());
					cout << "Creador Objeto vetical enmedio";
				}
				Cabecera* tmp = (Cabecera*)aux->getSur();
				tmp->setNorte(nueva);
				nueva->setSur(tmp);
				aux->setSur(nueva);
				nueva->setNorte(aux);
				return nueva;
			}
			aux = (Cabecera*)aux->getSur();
		}
		Cabecera* nuevo = new Cabecera(nombre->getNombreproyecto(), nombre->getNombreNivel(), nombre->getPosicionx(), nombre->getPosiciony());
		if (nombre->getObjeto() != NULL)
		{
			nuevo->setObjeto(nombre->getObjeto());
		}
		else if (nombre->getPared() != NULL)
		{
			nuevo->setPared(nombre->getPared());
		}
		aux->setSur(nuevo);
		nuevo->setNorte(aux);
		return nuevo;
	}
}
NodoMatriz* Matriz::obtenerultimoH(Cabecera* cabecera, int y) {
	if (cabecera->getEste() == NULL) { return cabecera; }
	NodoMatriz* aux = cabecera->getEste();
	while (aux->getEste() != NULL)
	{
		if (y <= ((Elemento*)aux)->getPosicionx())
		{
			return aux;
		}
		aux = aux->getEste();
	}
	if (y <= ((Elemento*)aux)->getPosicionx())
	{
		return aux->getOeste();
	}
	return aux;
}
NodoMatriz* Matriz::obtenerultimoV( Cabecera* cabecera, int y) {
	if (cabecera->getSur() == NULL) { return cabecera; }
	NodoMatriz* aux = cabecera->getSur();
	while (aux->getSur() != NULL)
	{
		if (y <= ((Elemento*)aux)->getPosiciony())
		{
			return aux;
		}
		aux = aux->getSur();
	}
	if (y <= ((Elemento*)aux)->getPosiciony())
	{
		return aux->getNorte();
	}
	return aux;
}
void Matriz::add(Elemento* nuevo) {
	Cabecera* vertical = this->getVertical(nuevo);
	Cabecera* horizontal = this->getHorizontal(nuevo);
	if (vertical == NULL)
	{
		vertical = crearVertical(nuevo);
	}
	if (horizontal == NULL)
	{
		horizontal = crearHorizontal(nuevo);
	}
	NodoMatriz* izquierda = obtenerultimoH(vertical,nuevo->getPosicionx());
	NodoMatriz* superior = obtenerultimoH(horizontal, nuevo->getPosiciony());
	if (izquierda->getEste() == NULL)
	{
		izquierda->setEste(nuevo);
		nuevo->setOeste(izquierda);
	}
	else {
		NodoMatriz* tmp = izquierda->getEste();
		izquierda->setEste(nuevo);
		nuevo->setOeste(izquierda);
		tmp->setOeste(nuevo);
		nuevo->setEste(tmp);
	}
	if (superior->getSur() == NULL)
	{
		superior->setSur(nuevo);
		nuevo->setNorte(superior);

	}
	else {
		NodoMatriz* tmp = superior->getSur();
		superior->setSur(nuevo);
		nuevo->setNorte(superior);
		tmp->setNorte(nuevo);
		nuevo->setSur(tmp);
	}
}

Cabecera* Matriz::getVertical(Elemento* nombre) {
	if (this->vertical == NULL) { return NULL; }
	Cabecera* aux = this->vertical;
	while (aux!=NULL)
	{
		if (((int)aux->getPosiciony()) == nombre->getPosiciony())
		{
			return aux;
		}
		aux = (Cabecera*)aux->getSur();
	}
	return NULL;
	
}
Cabecera* Matriz::getHorizontal(Elemento* nombre) {
	if (this->horizontal == NULL) { return NULL; }
	Cabecera* aux = this->horizontal;
	while (aux != NULL)
	{
		if (((int)aux->getPosicionx()) == nombre->getPosicionx())
		{
			return aux;
		}
		aux = (Cabecera*)aux->getEste();
	}
	return NULL;

}
void Matriz::graficar()
{
	ofstream file;
	file.open("Matriz.dot", ios::out);
	if (file.fail()) {
		return;
	}
	else
	{
		file << "digraph G {\n";
		file << "node [shape=box];\n";
		string alinear = "{rank=same;";
		Cabecera* x = this->horizontal;
		Cabecera* y = this->vertical;
		Elemento* hola = ((Elemento*)x);
		
		//Graficar Horizontal
		Cabecera* nombre = this->horizontal;
		Cabecera* nombre1 = this->vertical;
			
			while (nombre != NULL) {

				Cabecera* nombre1 = (Cabecera*)nombre->getSur();
				while (nombre1 != NULL) {

					if (nombre1->getObjeto() != NULL)
					{
						Objeto* tmm = nombre1->getObjeto();
						file << "O" << nombre1 << "[label=" << "Objeto" << "]\n";

					}
					 if (nombre1->getPared() != NULL)
					{
						Pared* tmm = nombre1->getPared();
						file << "O" << nombre1 << "[label=" << "P" << "]\n";
					}
					if ((Cabecera*)nombre1->getSur() != NULL)
					{
						if (nombre1->getPosiciony() == ((Cabecera*)nombre1->getSur())->getPosiciony())
						{
							file << "O" << nombre1 << "->" << "O" << (Cabecera*)nombre1->getSur() << "\n";
							file << "O" << (Cabecera*)nombre1->getSur() << "->O" << nombre1 << "\n";
						}
						if (nombre1->getPosicionx() == ((Cabecera*)nombre1->getEste())->getPosicionx())
						{
							file << "O" << nombre1 << "->" << "O" << (Cabecera*)nombre1->getEste() << "\n";
							file << "O" << (Cabecera*)nombre1->getEste() << "->O" << nombre1 << "\n";
						}

						

					}

					nombre1 = (Cabecera*)nombre1->getSur();
				}
				nombre = (Cabecera*)nombre->getEste();

				
			}
			
		
		//fin de graficar Horizontal

		
			//Graficar Vertical
			

			//fin de graficar Vertical
		
		file << "}";
	}
	file.close();
	system("dot.exe -Tpng Matriz.dot -o Matriz.png");
	cout << "Se genero reporte\n";
}