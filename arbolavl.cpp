using namespace std;
#include <iostream>
 struct arbolavl
{
	int id_nodo;
	string nombre;
	int nderecha=0;
	int nizquierda=0;
	arbolavl *izquierda;
	arbolavl *derecha;
};
