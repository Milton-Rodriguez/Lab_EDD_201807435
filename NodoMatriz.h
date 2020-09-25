#pragma once
#include "Objeto.h"
#include "Pared.h"
class NodoMatriz
{
public:
	
	NodoMatriz();
	void setNorte(NodoMatriz* n);
	void setSur(NodoMatriz* n);
	void setEste(NodoMatriz* n);
	void setOeste(NodoMatriz* n);
	NodoMatriz* getNorte();
	NodoMatriz* getSur();
	NodoMatriz* getEste();
	NodoMatriz* getOeste();
	
private:
	
	NodoMatriz* sur;
	NodoMatriz* norte;
	NodoMatriz* este;
	NodoMatriz* oeste;
};
