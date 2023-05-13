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


    //MENUS TEMPORALES ocupan muchas correciones

    string opcion;
    string subOpcion;
    while (opcion != "6"){
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. Estado de las colas" << endl;
        cout << "2. Tiquetes" << endl;
        cout << "3. Atender" << endl;
        cout << "4. Administracion" << endl;
        cout << "5. Estadisticas del sistema" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion seleccionada: ";
        getline(cin, opcion);
        cin.clear();

        while (opcion == "2" && subOpcion != "2"){
             //SUBMENU TIQUETES
            cout << "\nSUBMENU TIQUETES" << endl;
            cout << "1. Seleccionar tipo de tiquete y servicio" << endl;
            cout << "2. Regresar" << endl;
            cout << "Opcion seleccionada: ";
            getline(cin, subOpcion);
            cin.clear();
        }

        while (opcion == "4" && subOpcion != "5"){
            //SUBMENU ADMINISTRACION
            cout << "\nSUBMENU ADMINISTRACION" << endl;
            cout << "1. Tipos de usuario" << endl;
            cout << "2. Areas" << endl;
            cout << "3. Servicios disponibles" << endl;
            cout << "4. Limpiar colas y estadisticas" << endl;
            cout << "5. Regresar" << endl;
            cout << "Opcion seleccionada: ";
            getline(cin, subOpcion);
            cin.clear();
        }


    }


    return 0;
}
