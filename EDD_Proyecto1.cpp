
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
        bool repetidor_ver = true;
        while (repetidor_ver)
        {
            system("cls");
       
        int nodo;
        string nombre;

        controlador_avl opciones;
        opciones.mostrar();
        cout << "\n0.Ingrese un proyecto\n";
        cout << "555. Regresar\n";
        int menu_mostrar;
        cin >> menu_mostrar;
        if (menu_mostrar == 555)
        {
            repetidor_ver = false;

        }
        else if (menu_mostrar ==0)
        {
            cout << "Ingrese el id del Proyecto:\n";
            cin >> nodo;
            cout << "Ingrese el nombre del Proyecto:\n";
            cin >> nombre;
            opciones.insertar(nodo,nombre);
            cout << "Insertado correctamente";
            cin.get();
        }
        }
        
        
        
        
        
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

