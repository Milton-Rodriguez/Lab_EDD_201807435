#include "Proyecto.h";

string Proyecto::toString()
{
    string enable = "Disponible";
    if (!disponibilidad) {
        enable = "No disponible";
    }
    return "ID: " + id + ", Nombre: " + nombre + ", Estado: " + enable;
}

string Proyecto::graficar()
{
    string enable = "Disponible";
    if (!disponibilidad) {
        enable = "No disponible";
    }
    return "\"ID: " + id + "\"+" + "\"\\nNombre: " + nombre + "\"+" + "\"\\nDiponibildad: " + enable + "\"";
}