#include "NodoMatriz.h";
NodoMatriz::NodoMatriz()
{
	this->este = NULL;
	this->oeste = NULL;
	this->sur = NULL;
	this->norte = NULL;
}
NodoMatriz* NodoMatriz::getNorte() { return this->norte; }
NodoMatriz* NodoMatriz::getEste() { return this->este; }
NodoMatriz* NodoMatriz::getOeste() { return this->oeste; }
NodoMatriz* NodoMatriz::getSur() { return this->sur; }
void NodoMatriz::setOeste(NodoMatriz* n) {
	this->oeste = n;
}
void NodoMatriz::setEste(NodoMatriz* n) {
	this->este = n;
}
void NodoMatriz::setNorte(NodoMatriz* n) {
	this->norte = n;
}
void NodoMatriz::setSur(NodoMatriz* n) {
	this->sur = n;
}