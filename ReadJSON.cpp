#include <iostream>
#include <fstream>
#include "json/json.h"
#include "Proyecto.h";
#include "ArbolAVL.h";
#include "ListaNivel.h";
#include "ListaPared.h";
#include "ListaObjeto.h";
#include "Puntos.h";
using namespace std;
#pragma warning(disable : 4996)
class ReadJSON
{
public:
   
    void anadir(string url);
    void anadir1(string nombreproyecto, string ruta);

private:

};

inline void ReadJSON::anadir(string url) {
    ifstream ifs(url);
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    const Json::Value& characters = obj["proyectos"]; // array of characters
    for (int i = 0; i < characters.size(); i++) {
        cout << "\nnombre: " << characters[i]["nombre"].asString();

        //niveles 
        const Json::Value& characters1 = characters[i]["niveles"];

        //agregar Proyecto
        Proyecto* nuevo = new Proyecto(""+ characters[i]["niveles"].size(), characters[i]["nombre"].asString());
        ArbolAVL* anadir = new ArbolAVL();
        anadir->add1(characters[i]["niveles"].size(), nuevo);
        
        //fin de agregar proyecto
        for (int j = 0; j < characters[i]["niveles"].size(); j++) {
            int xbus = 0;
            int ybus = 0;
            //agregar nivel
            ListaNivel* andirlista = new ListaNivel();
            string valornivel = to_string(characters1[j]["nivel"].asInt());
            
            //fin de agregar nivel
            cout << endl;
            cout << "\nNivel: " << characters1[j]["nivel"].asInt();
           
            //Paredes
            const Json::Value& characters2 = characters1[j]["paredes"];
            for (int k = 0; k < characters2.size(); k++) {
                cout << endl;
                cout << k << " ";
                //inicio
                cout << endl;
                const Json::Value& characters3 = characters2[k]["inicio"];
                cout << characters3[0].asInt() << "\n";
                cout << characters3[1].asInt() << "\n";
                if (xbus < characters3[0].asInt())
                {
                    xbus = characters3[0].asInt();

                }
                if (ybus < characters3[1].asInt())
                {
                    ybus = characters3[1].asInt();

                }
                //fin inicio
                //final
                cout << endl;
                const Json::Value& characters4 = characters2[k]["final"];
                cout << characters4[0].asInt() << "\n";
                cout << characters4[1].asInt() << "\n";
                if (xbus < characters4[0].asInt())
                {
                    xbus = characters4[0].asInt();

                }
                if (ybus < characters4[1].asInt())
                {
                    ybus = characters4[1].asInt();

                }
                //fin final
                cout << "\nColor: " << characters2[k]["color"].asString();
                //agregar Pared
                ListaPared* andirlista = new ListaPared();
                Puntos* ini = new Puntos(characters3[0].asInt(), characters3[1].asInt());
                Puntos* fin = new Puntos(characters4[0].asInt(), characters4[1].asInt());
                
                andirlista->add(characters[i]["nombre"].asString(), valornivel,k,ini,fin, characters2[k]["color"].asString());
                //fin de agregar Pared
            }
            //Fin PAredes
            //Objetos
            const Json::Value& characters5 = characters1[j]["objetos"];
            for (int p = 0; p < characters5.size(); p++) {
                cout << endl;
                cout << p << " ";
                cout << "\nIdentificador: " << characters5[p]["identificador"].asInt();
                cout << "\nNombre: " << characters5[p]["nombre"].asString();
                cout << "\nLetra: " << characters5[p]["letra"].asString();
                cout << "\nColor: " << characters5[p]["color"].asString();
                cout << "\nPuntos";
                //Puntos
                cout << endl;
                const Json::Value& characters6 = characters5[p]["puntos"];
                Puntos** arr = new Puntos*[characters6.size()];
                for (int m = 0; m < characters6.size(); m++)
                {
                    cout << "\n" << m;
                    cout << "\nX: " << characters6[m]["x"].asInt() << "\n";
                    cout << "\nY: " << characters6[m]["y"].asInt() << "\n";
                    if (xbus < characters6[m]["x"].asInt())
                    {
                        xbus = characters6[m]["x"].asInt();

                    }
                    if (ybus < characters6[m]["y"].asInt())
                    {
                        ybus = characters6[m]["y"].asInt();

                    }
                    Puntos* newpoint = new Puntos(characters6[m]["x"].asInt(), characters6[m]["y"].asInt());
                    arr[m] = newpoint;
                }
                //agregar Objeto
                ListaObjeto* andirlista7 = new ListaObjeto();
                andirlista7->add(characters[i]["nombre"].asString(), valornivel, characters5[p]["identificador"].asInt(), arr, characters6.size(),characters5[p]["color"].asString(),characters5[p]["nombre"].asString(), characters5[p]["letra"].asString());
                //fin de agregar Objeto

                //fin Puntos



            }
            //Fin de Objetos 
            Puntos* tamano = new Puntos(xbus,ybus);
            
            andirlista->add(characters[i]["nombre"].asString(), valornivel,tamano);
        }
        //fin niveles
        cout << endl;
    }
}

inline void ReadJSON::anadir1(string nombreproyecto,string ruta) {
    ifstream ifs(ruta);
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    
        cout << "\nNombre del Proyecto: " << nombreproyecto;

        //niveles 
        const Json::Value& characters1 = obj["niveles"];

        for (int j = 0; j < characters1.size(); j++) {
            int xbus = 0;
            int ybus = 0;
            //agregar nivel
            ListaNivel* andirlista = new ListaNivel();
            string valornivel = to_string(characters1[j]["nivel"].asInt());

            //fin de agregar nivel
            cout << endl;
            cout << "\nNivel: " << characters1[j]["nivel"].asInt();

            //Paredes
            const Json::Value& characters2 = characters1[j]["paredes"];
            for (int k = 0; k < characters2.size(); k++) {
                cout << endl;
                cout << k << " ";
                //inicio
                cout << endl;
                const Json::Value& characters3 = characters2[k]["inicio"];
                cout << characters3[0].asInt() << "\n";
                cout << characters3[1].asInt() << "\n";
                if (xbus < characters3[0].asInt())
                {
                    xbus = characters3[0].asInt();

                }
                if (ybus < characters3[1].asInt())
                {
                    ybus = characters3[1].asInt();

                }
                //fin inicio
                //final
                cout << endl;
                const Json::Value& characters4 = characters2[k]["final"];
                cout << characters4[0].asInt() << "\n";
                cout << characters4[1].asInt() << "\n";
                if (xbus < characters4[0].asInt())
                {
                    xbus = characters4[0].asInt();

                }
                if (ybus < characters4[1].asInt())
                {
                    ybus = characters4[1].asInt();

                }
                //fin final
                cout << "\nColor: " << characters2[k]["color"].asString();
                //agregar Pared
                ListaPared* andirlista = new ListaPared();
                Puntos* ini = new Puntos(characters3[0].asInt(), characters3[1].asInt());
                Puntos* fin = new Puntos(characters4[0].asInt(), characters4[1].asInt());

                andirlista->add(nombreproyecto, valornivel, k, ini, fin, characters2[k]["color"].asString());
                //fin de agregar Pared
            }
            //Fin PAredes
            //Objetos
            const Json::Value& characters5 = characters1[j]["objetos"];
            for (int p = 0; p < characters5.size(); p++) {
                cout << endl;
                cout << p << " ";
                cout << "\nIdentificador: " << characters5[p]["identificador"].asInt();
                cout << "\nNombre: " << characters5[p]["nombre"].asString();
                cout << "\nLetra: " << characters5[p]["letra"].asString();
                cout << "\nColor: " << characters5[p]["color"].asString();
                cout << "\nPuntos";
                //Puntos
                cout << endl;
                const Json::Value& characters6 = characters5[p]["puntos"];
                Puntos** arr = new Puntos * [characters6.size()];
                for (int m = 0; m < characters6.size(); m++)
                {
                    cout << "\n" << m;
                    cout << "\nX: " << characters6[m]["x"].asInt() << "\n";
                    cout << "\nY: " << characters6[m]["y"].asInt() << "\n";
                    if (xbus < characters6[m]["x"].asInt())
                    {
                        xbus = characters6[m]["x"].asInt();

                    }
                    if (ybus < characters6[m]["y"].asInt())
                    {
                        ybus = characters6[m]["y"].asInt();

                    }
                    Puntos* newpoint = new Puntos(characters6[m]["x"].asInt(), characters6[m]["y"].asInt());
                    arr[m] = newpoint;
                }
                //agregar Objeto
                ListaObjeto* andirlista7 = new ListaObjeto();
                andirlista7->add(nombreproyecto, valornivel, characters5[p]["identificador"].asInt(), arr, characters6.size(), characters5[p]["color"].asString(), characters5[p]["nombre"].asString(), characters5[p]["letra"].asString());
                //fin de agregar Objeto

                //fin Puntos



            }
            //Fin de Objetos 
            Puntos* tamano = new Puntos(xbus, ybus);

            andirlista->add(nombreproyecto, valornivel, tamano);
        }
        //fin niveles
        cout << endl;
    
}
