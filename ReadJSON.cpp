#include <iostream>
#include <fstream>
#include "json/json.h"
using namespace std;
#pragma warning(disable : 4996)
class ReadJSON
{
public:
	ReadJSON();
	~ReadJSON();
	void anadir(string url);

private:

};

inline void ReadJSON::anadir(string url) {
    ifstream ifs("Objetos.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    const Json::Value& characters = obj["proyectos"]; // array of characters
    for (int i = 0; i < characters.size(); i++) {
        cout << "\nnombre: " << characters[i]["nombre"].asString();
        
        //niveles 
        const Json::Value& characters1 = characters[i]["niveles"];
        for (int j = 0; j < characters[i]["niveles"].size(); j++) {
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
                
                //fin inicio
                //final
                cout << endl;
                const Json::Value& characters4 = characters2[k]["final"];
                cout << characters4[0].asInt() << "\n";
                cout << characters4[1].asInt() << "\n";
                //fin final
                cout << "\nColor: " << characters2[k]["color"].asString();

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
                for (int m = 0; m < characters6.size(); m++)
                {
                    cout << "\n"<<m;
                    cout << "\nX: " << characters6[m]["x"].asInt() << "\n";
                    cout << "\nY: " << characters6[m]["y"].asInt() << "\n";
                }
                

                //fin Puntos
                
                

            }
            //Fin de Objetos 
             
        }
        //fin niveles
        cout << endl;
    }
}
inline ReadJSON::ReadJSON()
{
	

}

inline ReadJSON::~ReadJSON()
{
}