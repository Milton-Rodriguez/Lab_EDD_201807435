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
    ifstream ifs("camaras.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    const Json::Value& characters = obj["camaras"]; // array of characters
    for (int i = 0; i < characters.size(); i++) {
        cout << "\nNombre: " << characters[i]["nombre"].asString();
        cout << "\nIP: " << characters[i]["ip"].asString();
        cout << endl;
    }
}
inline ReadJSON::ReadJSON()
{
	

}

inline ReadJSON::~ReadJSON()
{
}