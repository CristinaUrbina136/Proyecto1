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


    //MENUS TEMPORALES

    string opcion;
    string subOpcion;
    string subSubOpcion;

    string descripcion;
    string prioridad;
    string codigo;
    string cantidad;

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

        //SUBMENU ESTADO DE LAS COLAS
        if (opcion == "1"){
            cout << "\nINSERTAR ESTADO DE LAS COLAS" << endl;
        }

        if (opcion == "3"){
            cout << "\nINSERTAR MECANICA DE ATENDER" << endl;
        }

        //SUBMENU TIQUETES
        while (opcion == "2" && subOpcion != "2"){
            cout << "\nSUBMENU TIQUETES" << endl;
            cout << "1. Seleccionar tipo de tiquete y servicio" << endl;
            cout << "2. Regresar" << endl;
            cout << "Opcion seleccionada: ";
            getline(cin, subOpcion);
            cin.clear();
        }

        //SUBMENU ADMINISTRACION
        //ES EL PRIMERO QUE SE ESTA TRABAJANDO
        while (opcion == "4" && subOpcion != "5"){
            cout << "\nSUBMENU ADMINISTRACION" << endl;
            cout << "1. Tipos de usuario" << endl;
            cout << "2. Areas" << endl;
            cout << "3. Servicios disponibles" << endl;
            cout << "4. Limpiar colas y estadisticas" << endl;
            cout << "5. Regresar" << endl;
            cout << "Opcion seleccionada: ";
            getline(cin, subOpcion);
            cin.clear();

            while(subOpcion == "1" && subSubOpcion != "3"){
                cout << "\nTIPOS DE USUARIO" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Eliminar" << endl;
                cout << "3. Regresar" << endl;
                cout << "Opcion seleccionada: ";
                getline(cin, subSubOpcion);
                cin.clear();

                if (subSubOpcion == "1"){
                    cout << "\nIngrese la descripcion del tipo de usuario a agregar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    cout << "\nIngrese la prioridad del tipo de usuario a agregar: ";
                    getline(cin, prioridad);
                    cin.clear();
                    sistema.appendListaTiposUsuario(descripcion, stoi(prioridad));
                }

                if (subSubOpcion == "2"){
                    cout << "\nIngrese la descripcion del tipo de usuario a eliminar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    sistema.removeListaTiposUsuario(descripcion);
                }
            }

            while(subOpcion == "2" && subSubOpcion != "4"){
                cout << "\nAREAS" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Modificar cantidad de ventanillas" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Regresar" << endl;
                cout << "Opcion seleccionada: ";
                getline(cin, subSubOpcion);
                cin.clear();

                if (subSubOpcion == "1"){
                    cout << "\nIngrese la descripcion del area a agregar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    cout << "\nIngrese el codigo del area a agregar: ";
                    getline(cin, codigo);
                    cin.clear();
                    cout << "\nIngrese la cantidad de ventanillas del area a agregar: ";
                    getline(cin, cantidad);
                    cin.clear();
                    sistema.appendListaAreas(descripcion, codigo, stoi(cantidad));
                }

                if (subSubOpcion == "2"){
                    cout << "\nIngrese el codigo del area a modificar: ";
                    getline(cin, codigo);
                    cin.clear();
                    cout << "\nIngrese la nueva cantidad de ventanillas del area: ";
                    getline(cin, cantidad);
                    cin.clear();
                    sistema.modVentanillasTiposUsuario(codigo, stoi(cantidad));
                }
                sistema.printAreas();
            }

            while(subOpcion == "3" && subSubOpcion != "4"){
                cout << "\nSERVICIOS" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Eliminar" << endl;
                cout << "3. Reordenar" << endl;
                cout << "4. Regresar" << endl;
                cout << "Opcion seleccionada: ";
                getline(cin, subSubOpcion);
                cin.clear();
            }

            if(subOpcion == "4"){
                cout << "\nLIMPIAR COLAS Y ESTADISTICAS" << endl;
                cout << "INSERTAR MECANICA DE LIMPIA DE COLAS Y ESTADISTICAS" << endl;

            }
        }

        if (opcion == "5"){
            cout << "\nINSERTAR ESTADISTICAS DEL SISTEMA" << endl;
        }


    }


    return 0;
}
