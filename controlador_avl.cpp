using namespace std;
#include <iostream>
#include "arbolavl.cpp";

static arbolavl* cabeza;
class controlador_avl
{
public:
	controlador_avl();
	~controlador_avl();
	void insertar(int,string);
	void mostrar();
	
	
	

private:
	
	
};

inline controlador_avl::controlador_avl()
{
	
}

inline controlador_avl::~controlador_avl()
{
}

inline void controlador_avl::insertar(int dato,string nombre) {
	arbolavl* nuevo = new arbolavl();
	nuevo->id_nodo = dato;
	nuevo->nombre = nombre;
	arbolavl* aux1 = cabeza;
	
	arbolavl* aux2 = NULL;
	while ((aux1!=NULL)) {
		aux2 = aux1;
		if (dato > aux2->id_nodo) {
			aux1 = aux1->derecha;
		}
		else {
			aux1 = aux1->izquierda;
		}
		
		

	}
	if (cabeza == NULL) {
		
		cabeza = nuevo;
		cabeza->derecha =NULL;
		cabeza->izquierda = NULL;
		
		
	}
	else {
		
		aux1 = nuevo;

		
		if (dato > aux2->id_nodo) {
			aux2->derecha = aux1;
			aux2->nderecha = aux2->nderecha + 1;
		}
		else {
			aux2->izquierda = aux1;
			aux2->nizquierda = aux2->nizquierda + 1;
		}
		aux1->derecha = NULL;
		aux1->izquierda = NULL;
	}
	




}
inline void controlador_avl::mostrar() {
	
	arbolavl* aux1 = cabeza;
	arbolavl* aux2;
	while ((aux1 != NULL)) {
		aux2 = aux1;
		cout  << aux2->id_nodo;
		cout << ".  " << aux2->nombre << "\n";

		
		aux1 = aux1->derecha;

	}
	




}

