#include <iostream>
#include<stdexcept>
#include<iostream>
#include "Sistema.h"

using namespace std;

int main()
{
    Sistema sistema;

    //MENU TEMPORAL

    string opcion;
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Estado de las colas" << endl;
    cout << "2. Tiquetes" << endl;

    //SUBMENU TIQUETES

    cout << "\nSUBMENU TIQUETES" << endl;
    cout << "1. Seleccionar tipo de tiquete y servicio" << endl;
    cout << "2. Regresar" << endl;

    return 0;
}
