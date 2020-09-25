#include <iostream>
using namespace std;
#include "Proyecto.h";
#include "arbolavl.cpp";
#include "ReadJSON.cpp";
#include "ListaNivel.h";
#include "ListaPared.h";
#include "ListaObjeto.h";
#include "Matriz.h";

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
            string nombreproyecto;
            cout << "\nIngrese el Nombre del Proyecto al que desea ingresar:\n";
            ArbolAVL* anadir12 = new ArbolAVL();
            anadir12->inOrden();
            cin >> nombreproyecto;


            string numeronivel;
            cout << "\nIngrese el Numero de Nivel:\n";
            ListaNivel* consulta = new ListaNivel();
            consulta->Print(nombreproyecto);
            cin >> numeronivel;

            cout << "\nParedes:\n";
            ListaPared* consulta2 = new ListaPared();
            consulta2->Print(nombreproyecto, numeronivel);


            cout << "\nObjetos:\n";
            ListaObjeto* consulta3 = new ListaObjeto();
            consulta3->Print(nombreproyecto, numeronivel);

            string leer;
            cin >> leer;

        }
        else if (menu_opcion == 2) {
            //Editar Proyectos
        }
        else if (menu_opcion == 3) {
            //Cargar Proyectos
           
            
            string ele;




            //Cargar Archivo JSON
            string archivo;
            cout << "Ingrese la ruta del archivo";
            cin >> archivo;
            ReadJSON* cargar = new ReadJSON();
            cargar->anadir(archivo);
            cout << "0. Salir\n";
            cin >> ele;
            //Fin de Cargar Archivo JSON

        }
        else if (menu_opcion == 4) {
            //Graficar Proyectos
            Matriz* mat = new Matriz();
            mat->graficar();
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