using namespace std;
#include <iostream>
class arbolavl
{
	string nodo;
	arbolavl izquierda();
	arbolavl derecha();
	int nizquierda;
	int nderecha;

public:
	arbolavl(string nodo,arbolavl izquierda, arbolavl derecha,int nizquierda,int nderecha);
	~arbolavl();
	

private:

};

arbolavl::arbolavl(string nodo, arbolavl izquierda, arbolavl derecha, int nizquierda, int nderecha) {
	this->nodo = nodo;
	this->izquierda = izquierda;
	this->derecha = derecha;
	this->nizquierda = nizquierda;
	this->nderecha = nderecha;
}


arbolavl::~arbolavl()
{
}