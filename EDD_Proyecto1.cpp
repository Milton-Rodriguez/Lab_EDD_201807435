
#include <iostream>
using namespace std;
#include "controlador_avl.cpp";
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
        int nodo;
        cout << "Ingrese el nombre del nodo\n";
        cin >> nodo;
        controlador_avl opciones;
        opciones.insertar(nodo);
        
        opciones.mostrar();
        
        int nodo1;
        cout << "\nVer\n";
        cin >> nodo1;
    }
    else if (menu_opcion == 2) {
        //Editar Proyectos
    }
    else if (menu_opcion == 3) {
        //Cargar Proyectos
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

