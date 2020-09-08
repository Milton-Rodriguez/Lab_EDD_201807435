using namespace std;
#include <iostream>
#include "arbolavl.cpp";
static arbolavl* cabeza;
class controlador_avl
{
public:
	controlador_avl();
	~controlador_avl();
	void insertar(int);
	void mostrar();
	
	

private:
	
	
};

inline controlador_avl::controlador_avl()
{
	
}

inline controlador_avl::~controlador_avl()
{
}
inline void controlador_avl::insertar(int dato) {
	arbolavl* nuevo = new arbolavl();
	nuevo->id_nodo = dato;
	arbolavl* aux1 = cabeza;
	
	arbolavl* aux2 = NULL;
	while ((aux1!=NULL)) {
		aux2 = aux1;
		cout << "Busco para insertar "<<aux2->derecha<<"\n";
		aux1 = aux1->derecha;

	}
	if (cabeza == NULL) {
		cout << "La cabeza esta vacia";
		cabeza = nuevo;
		cabeza->derecha =NULL;
		
	}
	else {
		
		aux1 = nuevo;
		aux2->derecha=aux1;

		aux1->derecha = NULL;
	}
	




}
inline void controlador_avl::mostrar() {
	
	arbolavl* aux1 = cabeza;
	arbolavl* aux2;
	while ((aux1 != NULL)) {
		aux2 = aux1;
		cout << "Elemento: " << aux2->id_nodo;
		aux1 = aux1->derecha;

	}
	




}

