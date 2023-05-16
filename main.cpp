#include <iostream>
#include<stdexcept>
#include<iostream>
#include "Sistema.h"
#include "TiposUsuario.h"

using namespace std;

bool esNum(string num) {
    //Si es un espacio vacio
    if (num == ""){
        return false;
    }
    //Recorre el string
    for (int i = 0; num[i] != '\0'; i++) {
        //Si el caracter no es un digito
        if (!isdigit(num[i])) {
            return false;
        }
        //Si el caracter no es un entero
        if (num[i] == ',' || num [i] == '.') {
            return false;
        }
    }
    return true;
}

int main()
{

    Sistema sistema;

    sistema.appendListaTiposUsuario("Adulto mayor", 1);
    sistema.appendListaTiposUsuario("Discapacitado", 0);
    sistema.appendListaTiposUsuario("Usuario regular", 3);
    sistema.appendListaTiposUsuario("Representante organizacional", 2);

    sistema.appendListaAreas("Area de cajas", "C", 3);
    sistema.appendListaAreas("Area de servicio al cliente", "S", 4);
    sistema.appendListaAreas("Area de informacion", "I", 5);

    sistema.appendListaServicios("Comprar boleto", 0, "C");
    sistema.appendListaServicios("Cambiar boleto", 1, "I");
    sistema.appendListaServicios("Solicitar informacion", 1, "I");
    sistema.appendListaServicios("Realizar un reclamo", 2, "S");



    //Contador global de tiquetes
    int tiquetesGlobal = 100;

    //Variables de opcion
    string opcion = "0";
    string subOpcion = "0";
    string subSubOpcion = "0";

    //*Se usan tantas variables para intentar que el codigo sea mas facil de seguir

    //Variables para almacenar datos
    string descripcion;
    string prioridad;
    string codigo;
    string cantidad;

    //Mas variables para almacenar datos
    string temp1;
    string temp2;

    //Todavia mas variables para almacenar datos
    int prioridadU;
    int prioridadS;
    string descU;
    string descS;

    //Para validar
    bool continuar = true;

    //MENU
    while (opcion != "6"){
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. Estado de las colas" << endl;   //HECHO
        cout << "2. Tiquetes" << endl;          //CASI TERMINADO
        cout << "3. Atender" << endl;           //PENDIENTE
        cout << "4. Administracion" << endl;    //CASI TERMINADO
        cout << "5. Estadisticas del sistema" << endl;  //CASI TERMINADO
        cout << "6. Salir" << endl;
        cout << "Opcion seleccionada: ";
        getline(cin, opcion);
        cin.clear();

        //SUBMENU ESTADO DE LAS COLAS
        if (opcion == "1"){
            sistema.printEstadoColas();
        }

        //SUBMENU ATENDER
        if (opcion == "3"){
            cout << endl;
            cout << "Lista de areas" << endl;
            sistema.printDescCodArea();
            cout << "\nIndique el codigo del area en el que desea atender un tiquete: ";
            getline(cin, temp1);
            cin.clear();
            while (temp1 != "0" && temp1 != "1" && temp1 != "2"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                    cout << "\nIndique el codigo del area en el que desea atender un tiquete: ";
                    getline(cin, temp1);
                    cin.clear();
            }
            cout << endl;
            cout << "Lista de ventanillas del area" << endl;
            sistema.verVentanillas(temp1);
            cout << "\nIndique el numero de ventanilla en el que desea atender un tiquete: ";
            getline(cin, temp2);
            cin.clear();

            sistema.atender(temp1, temp2);
        }

        //SUBMENU TIQUETES
        while (opcion == "2" && subOpcion != "2"){
            cout << "\nSUBMENU TIQUETES" << endl;
            cout << "1. Seleccionar tipo de usuario y servicio" << endl;
            cout << "2. Regresar" << endl;
            cout << "Opcion seleccionada: ";
            getline(cin, subOpcion);
            cin.clear();

            if (subOpcion == "1"){
                cout << "\nLista de tipos de usuario" << endl;
                sistema.printDescUsuarios();
                cout << "\nIngrese su tipo de usuario: ";
                getline(cin, temp1);
                cin.clear();
                continuar = true;
                while (continuar == true){
                    if (esNum(temp1) == false){
                        cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                        cout << "\nIngrese su tipo de usuario: ";
                        getline(cin, temp1);
                        cin.clear();
                    } else if (stoi(temp1) > sistema.getSizeTiposUsuario()-1){
                        cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                        cout << "\nIngrese su tipo de usuario: ";
                        getline(cin, temp1);
                        cin.clear();
                    } else {
                        continuar = false;
                    }
                }

                cout << "\nLista de tipos de servicios" << endl;
                sistema.printDescServicios();
                cout << "\nIngrese el servicio al que desea acceder: ";
                getline(cin, temp2);
                cin.clear();
                continuar = true;
                while (continuar == true){
                    if (esNum(temp2) == false){
                        cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                        cout << "\nIngrese el servicio al que desea acceder: ";
                        getline(cin, temp2);
                        cin.clear();
                    } else if (stoi(temp2) > sistema.getSizeServicios()-1){
                        cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                        cout << "\nIngrese el servicio al que desea acceder: ";
                        getline(cin, temp2);
                        cin.clear();
                    } else {
                        continuar = false;
                    }
                }

                //Obtiene el codigo de area del servicio, a partir del numero (posicion en lista) seleccionado por el usuario
                codigo = sistema.getCodAreaServicio(stoi(temp2));
                //Obtiene la prioridad del usuario, a partir del numero (posicion en lista) seleccionado por el usuario
                prioridadU = sistema.getPrioridadUsuario(stoi(temp1));
                //Obtiene la prioridad del servicio, a partir del numero (posicion en lista) seleccionado por el usuario
                prioridadS = sistema.getPrioridadServicio(stoi(temp2));

                //Crea el tiquete a meter en la cola
                Tiquetes *tempTiquete = new Tiquetes();
                //Genera el codigo del tiquete utilizando el codigo de area y el contador global de tiquetes
                tempTiquete->setCodigoTiquete(codigo, tiquetesGlobal);
                //Genera la prioridad del tiquete a partir de la prioridad de usuario y prioridad de servicio
                tempTiquete->setPrioridadFinal(prioridadU, prioridadS);
                //Genera la fecha de solicitado del tiquete
                tempTiquete->setFechaSolicitado();

                //Obtiene la descripcion del usuario, a partir del numero (posicion en lista) seleccionado por el usuario
                descU = sistema.getDescUsuario(stoi(temp1));
                //Obtiene la descripcion del servicio, a partir del numero (posicion en lista) seleccionado por el usuario
                descS = sistema.getDescServicio(stoi(temp2));
                //Agrega los tiquetes a las estadisticas respectivas
                sistema.agregarEstadistica(descU, descS, codigo);

                //Inserta el tiquete en la cola
                sistema.insertarCola(tempTiquete, codigo);
                //Suma al contador de tiquetes global
                tiquetesGlobal++;
                cout << "Tiquete generado con exito!" << endl;
                continuar == true;
            } else if (subOpcion != "1" && subOpcion != "2"){
                cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
            }
        }

        //SUBMENU ADMINISTRACION
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

            //TIPOS DE USUARIO
            while(subOpcion == "1" && subSubOpcion != "3"){
                cout << "\nTIPOS DE USUARIO" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Eliminar" << endl;
                cout << "3. Regresar" << endl;
                cout << "Opcion seleccionada: ";
                getline(cin, subSubOpcion);
                cin.clear();

                //Agrega un tipo de usuario a la lista de tipos de usuario
                if (subSubOpcion == "1"){
                    cout << "\nIngrese la descripcion del tipo de usuario a agregar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    cout << "\nIngrese la prioridad del tipo de usuario a agregar: ";
                    getline(cin, prioridad);
                    cin.clear();
                    sistema.appendListaTiposUsuario(descripcion, stoi(prioridad));
                    cout << "Tipo de usuario creado con exito!\n";
                }

                //Elimina un tipo de usuario de la lista de tipos de usuario
                if (subSubOpcion == "2"){
                    cout << "\nIngrese la descripcion del tipo de usuario a eliminar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    sistema.removeListaTiposUsuario(descripcion);
                    cout << "Tipo de usuario eliminado con exito!\n";
                } else if (subSubOpcion != "1" && subSubOpcion != "2"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                }
            }

            //AREAS
            while(subOpcion == "2" && subSubOpcion != "4"){
                cout << "\nAREAS" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Modificar cantidad de ventanillas" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Regresar" << endl;
                cout << "Opcion seleccionada: ";
                getline(cin, subSubOpcion);
                cin.clear();

                //Agrega un area a la lista de areas
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
                    cout << "Area creada con exito!\n";
                }

                //Modifica la cantidad de ventanillas del area indicada
                if (subSubOpcion == "2"){
                    cout << "\nIngrese el codigo del area a modificar: ";
                    getline(cin, codigo);
                    cin.clear();
                    cout << "\nIngrese la nueva cantidad de ventanillas del area: ";
                    getline(cin, cantidad);
                    cin.clear();
                    sistema.modVentanillasArea(codigo, stoi(cantidad));
                    cout << "Area modificada con exito!\n";
                }

                //Elimina un area de la lista de areas
                if (subSubOpcion == "3"){
                    //Se tiene que trabajar pensando en que cuando se elimina un area se eliminan sus servicios asociados
                    cout << "\nIngrese el codigo del area a eliminar: ";
                    getline(cin, codigo);
                    cin.clear();
                    sistema.removeListaAreas(codigo);
                    cout << "\nArea eliminada con exito!";
                } else if (subSubOpcion != "1" && subSubOpcion != "2" && subSubOpcion != "3"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                }
            }

            //SERVICIOS
            while(subOpcion == "3" && subSubOpcion != "4"){
                cout << "\nSERVICIOS" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Eliminar" << endl;
                cout << "3. Reordenar" << endl;
                cout << "4. Regresar" << endl;
                cout << "Opcion seleccionada: ";
                getline(cin, subSubOpcion);
                cin.clear();

                //Agrega un servicio a la lista de servicios
                if (subSubOpcion == "1"){
                    //se tiene que trabajar pensando en que no se puede asignar un area que no existe a un servicio
                    cout << "\nIngrese la descripcion del servicio a agregar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    cout << "\nIngrese la prioridad del servicio a agregar: ";
                    getline(cin, prioridad);
                    cin.clear();
                    cout << "\nIngrese el codigo del area del servicio a agregar: ";
                    getline(cin, codigo);
                    cin.clear();
                    sistema.appendListaServicios(descripcion, stoi(prioridad), codigo);
                    cout << "Servicio agregado con exito!\n";
                }

                //Elimina un servicio de la lista de servicios
                if (subSubOpcion == "2"){
                    cout << "\nIngrese la descripcion del servicio a eliminar: ";
                    getline(cin, descripcion);
                    cin.clear();
                    sistema.removeListaServicios(descripcion);
                    cout << "Servicio eliminado con exito!\n";
                }

                //Reordena la lista de servicios
                if (subSubOpcion == "3"){
                    cout << endl;
                    sistema.printDescServicios();
                    cout << "\nIngrese la posicion del servicio a reubicar en la lista: ";
                    getline(cin, temp1);
                    cin.clear();
                    cout << "\nIngrese la posicion destino: ";
                    getline(cin, temp2);
                    cin.clear();
                    sistema.reorderServicios(stoi(temp1), stoi(temp2));
                    cout << "\nServicio reubicado con exito!";
                } else if (subSubOpcion != "1" && subSubOpcion != "2" && subSubOpcion != "3"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                }
            }

            //LIMPIAR COLAS Y ESTADISTICAS
            if(subOpcion == "4"){
                sistema.limpiarEstadisticas();
                cout << "Las colas y estadisticas han sido limpiadas con exito! \n" << endl;
            } else if (subOpcion != "1" && subOpcion != "2" && subOpcion != "3" && subOpcion != "4" && subOpcion != "5"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                }
        }

        //SUBMENU ESTADISTICAS DEL SISTEMA
        if (opcion == "5"){
            sistema.printEstadisticas();
        }

        if (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4" && opcion != "5" && opcion != "6"){
            cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
        }

        subOpcion = "0";
        subSubOpcion = "0";

    }

    cout << "\nADIOS :)" << endl;

    return 0;
}
