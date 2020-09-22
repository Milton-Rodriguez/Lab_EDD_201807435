
#include <iostream>
using namespace std;
#include "Proyecto.h";
#include "arbolavl.cpp";

int main()
{
    string enter;
    cout << "USAC\n";
    cout << "Estructura de Datos\n";
    cout << "Seccion A\n";
    cout << "Milton Josue Rodriguez Valdez\n";
    cout << "201807435\n";
    cin.get();
    
    int menu_opcion;
    bool repetidor_menu = true;
    while (repetidor_menu)
    {
        system("cls");
    
    cout << "*************************MENU*******************************\n";
    cout << "1. Ver Proyectos\n";
    cout << "2. Editar Proyectos\n";
    cout << "3. Cargar Proyecto\n";
    cout << "4. Graficar Proyecto\n";
    cout << "5. Guardar Proyectos\n";
    cout << "6. Cargar Librerias\n";
    cout << "0. Salir\n";
    cin >> menu_opcion;
    if (menu_opcion == 1) {
       
        
        
        
    }
    else if (menu_opcion == 2) {
        //Editar Proyectos
    }
    else if (menu_opcion == 3) {
        //Cargar Proyectos
        Proyecto* nuevo = new Proyecto("1","Hola");
        Proyecto* nuevo1 = new Proyecto("6", "Proyecto 2");
        Proyecto* nuevo2 = new Proyecto("7", "Proyecto 3");
        Proyecto* nuevo3 = new Proyecto("3", "Proyectoe 4");
        ArbolAVL* anadir = new ArbolAVL();
        anadir->add(1,nuevo);
        anadir->add(6, nuevo1);
        anadir->add(5, nuevo2);
        anadir->add(10, nuevo3);
        NodoArbol* busqueda;
        busqueda = anadir->root;
        anadir->inOrden(busqueda);
        string ele;
        cout << "0. Salir\n";
        cin >> ele;
        
        
        
    }
    else if (menu_opcion == 4) {
        //Graficar Proyectos
    }
    else if (menu_opcion == 5) {
        //Guardar Proyectos
    }
    else if (menu_opcion == 6) {
        //Cargar Librerias
    }
    else {
        repetidor_menu = false;
    }

    }
    
}

