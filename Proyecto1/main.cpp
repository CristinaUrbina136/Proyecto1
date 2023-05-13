#include <iostream>
#include<stdexcept>
#include<iostream>
#include "Sistema.h"

using namespace std;

int main()
{
    //Para probar
    Sistema sistema;

    cout << "\nTIPOS USUARIO" << endl;
    sistema.appendListaTiposUsuario("Adulto mayor", 1);
    sistema.appendListaTiposUsuario("Discapacitado", 0);
    sistema.appendListaTiposUsuario("Usuario regular", 3);
    sistema.appendListaTiposUsuario("Representante organizacional", 2);
    sistema.printTiposUsuario();

    cout << "\nAREAS" << endl;
    sistema.appendListaAreas("Area de cajas", "C", 3);
    sistema.appendListaAreas("Area de servicio al cliente", "S", 4);
    sistema.appendListaAreas("Area de informacion", "I", 5);
    sistema.printAreas();

    //ESTO SE TIENE QUE ARREGLAR el codigo de area debe ser tipo area
    cout << "\nSERVICIOS" << endl;
    sistema.appendListaServicios("Comprar boleto", 0, "C");
    sistema.appendListaServicios("Cambiar boleto", 1, "I");
    sistema.appendListaServicios("Solicitar informacion", 1, "I");
    sistema.appendListaServicios("Realizar un reclamo", 2, "S");
    sistema.printServicios();


    //MENU TEMPORAL

    string opcion;
    cout << "\nMENU PRINCIPAL" << endl;
    cout << "1. Estado de las colas" << endl;
    cout << "2. Tiquetes" << endl;

    //SUBMENU TIQUETES

    cout << "\nSUBMENU TIQUETES" << endl;
    cout << "1. Seleccionar tipo de tiquete y servicio" << endl;
    cout << "2. Regresar" << endl;

    return 0;
}
