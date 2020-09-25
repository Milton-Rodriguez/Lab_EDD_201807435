#include "Matriz.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>


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
		}
		else if (nombre->getPared() != NULL)
		{
			nueva->setPared(nombre->getPared());
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
			}
			else if (nombre->getPared() != NULL)
			{
				nueva->setPared(nombre->getPared());
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
				}
				else if (nombre->getPared() != NULL)
				{
					nueva->setPared(nombre->getPared());
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
		NodoMatriz* x = this->horizontal;
		NodoMatriz* y = this->vertical;
		Elemento* hola = (Elemento*)x;
		if (hola->getObjeto()!=NULL)
		{
			Objeto* tmm = hola->getObjeto();
			file << x << "[label=" << tmm->letra << "]\n";
			file << "A->"<<x<<"\n";
			file <<x <<"->C\n";
		}else if (hola->getPared() != NULL)
		{
			
			file << x << "[label=" << "P" << "]\n";
			file << "A->C\n";
		}
		file << "A[label="<<"Ajk"<<"]\n";
		file << "B[label=" << "B" << "]\n";
		file << "C[label=" << "C" << "]\n";
		file << "D[label=" << "D" << "]\n";
		file << "A->B\n";
		file << "B->A\n";
		file << "B->C\n";
		file << "C->B\n";
		file << "C->D\n";
		file << "D->C\n";
		file << "C->A\n";
		file << "A->C\n";
		file << "{rank = same; A; C; \n}";
		file << "{rank = same; B; D; \n}";
		
		file << "}";
	}
	file.close();
	system("dot.exe -Tpng Matriz.dot -o Matriz.png");
	cout << "Se genero reporte\n";
}