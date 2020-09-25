#include "Cabecera.h";
Cabecera::Cabecera(string nombreproyecto, string nombrenivel,int x,int y) {
	this->nombreproyecto = nombreproyecto;
	this->nombrenivel = nombrenivel;
	this->pared = NULL;
	this->objeto = NULL;
	this->posicionx = x;
	this->posiciony = y;

}
Pared* Cabecera::getPared() { return this->pared; }
Objeto* Cabecera::getObjeto() { return this->objeto; }
string Cabecera::getNombreproyecto() { return this->nombreproyecto; }
string  Cabecera::getNombreNivel() { return this->nombrenivel; }
void Cabecera::setnombrenivel(string nombrenivel) {
	this->nombrenivel = nombrenivel;
}
void Cabecera::setnombreproyecto(string nombreproyecto) {
	this->nombreproyecto = nombreproyecto;
}

void Cabecera::setPared(Pared* pared) {
	this->pared = pared;
}

void Cabecera::setObjeto(Objeto* objeto) {
	this->objeto = objeto;
}
int Cabecera::getPosicionx() { return this->posicionx; }
int Cabecera::getPosiciony() { return this->posiciony; }
void Cabecera::setPoiscionx(int x) {
	this->posicionx = x;
}
void Cabecera::setPoisciony(int y) {
	this->posiciony = y;
}


