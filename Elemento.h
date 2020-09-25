#pragma once
#include "NodoMatriz.h";
class Elemento:public NodoMatriz
{
public:
	Elemento(string nombreproyecto, string nombrenivel,int x,int y);
	void setnombreproyecto(string nombreproyecto);
	void setnombrenivel(string nombrenivel);
	void setPared(Pared* pared);
	void setObjeto(Objeto* objeto);
	void setPoiscionx(int x);
	void setPoisciony(int y);
	string getNombreproyecto();
	string getNombreNivel();
	int getPosicionx();
	int getPosiciony();
	Pared* getPared();
	Objeto* getObjeto();


private:
	string nombreproyecto;
	string nombrenivel;
	int posicionx;
	int posiciony;
	Pared* pared;
	Objeto* objeto;

};


