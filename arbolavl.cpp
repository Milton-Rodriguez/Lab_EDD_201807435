#include "ArbolAVL.h"


inline void ArbolAVL::add1(int key, Proyecto* value)
{
	NodoArbol* nuevo = new NodoArbol(key);
	nuevo->value = value;

	if (root == nullptr) {
		root = nuevo;
	}
	else {
		NodoArbol* aux = root;
		while (aux != nullptr) {
			nuevo->parent = aux;
			if (nuevo->key >= aux->key) {
				aux = aux->right;
			}
			else {
				aux = aux->left;
			}
		}
		if (nuevo->key < nuevo->parent->key) {
			nuevo->parent->left = nuevo;
		}
		else {
			nuevo->parent->right = nuevo;
		}
	}
}
inline void ArbolAVL::inOrden()
{
	
	inOrden1(root);
		
}
inline void ArbolAVL::inOrden1(NodoArbol* node)
{
	if (node != nullptr) {
		inOrden1(node->left);
		cout << node->key << endl;
		inOrden1(node->right);
	}
}
