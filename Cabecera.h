#pragma once
#include "NodoMatriz.h";
class Cabecera:public NodoMatriz
{
public:
	Cabecera(string nombreproyecto, string nombrenivel,int x,int y);
	void setnombreproyecto(string nombreproyecto);
	void setnombrenivel(string nombrenivel);
	void setPared(Pared* pared);
	void setObjeto(Objeto* objeto);
	
	string getNombreproyecto();
	string getNombreNivel();
	Pared* getPared();
	Objeto* getObjeto();

	int getPosicionx();
	int getPosiciony();
	void setPoiscionx(int x);
	void setPoisciony(int y);


private:
	string nombre;
	string nombreproyecto;
	string nombrenivel;
	Pared* pared;
	Objeto* objeto;
	int posicionx;
	int posiciony;
};

