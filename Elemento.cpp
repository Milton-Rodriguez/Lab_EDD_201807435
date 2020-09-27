#include "Elemento.h";
Elemento::Elemento(string nombreproyecto, string nombrenivel,int x,int y) {
	this->nombreproyecto = nombreproyecto;
	this->nombrenivel = nombrenivel;
	this->pared = NULL;
	this->objeto = NULL;
	this->posicionx = x;
	this->posiciony = y;


}
Pared* Elemento::getPared() { return this->pared; }
Objeto* Elemento::getObjeto() { return this->objeto; }
string Elemento::getNombreproyecto() { return this->nombreproyecto; }
string  Elemento::getNombreNivel() { return this->nombrenivel; }
void Elemento::setnombrenivel(string nombrenivel) {
	this->nombrenivel = nombrenivel;
}
void Elemento::setnombreproyecto(string nombreproyecto) {
	this->nombreproyecto = nombreproyecto;
}

void Elemento::setPared(Pared* pared) {
	this->pared = pared;
}

void Elemento::setObjeto(Objeto* objeto) {
	this->objeto = objeto;
}
int Elemento::getPosicionx() { return this->posicionx; }
int Elemento::getPosiciony() { return this->posiciony; }
void Elemento::setPoiscionx(int x) {
	this->posicionx = x;
}
void Elemento::setPoisciony(int y) {
	this->posiciony = y;
}