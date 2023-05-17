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
            continuar = true;
            while (continuar == true){
                cout << "\nLista de areas" << endl;
                sistema.printDescCodArea();
                cout << "\nIndique el codigo del area en el que desea atender un tiquete: ";
                getline(cin, temp1);
                cin.clear();
                if (sistema.encontrarElementoListaAreas(temp1) == true){
                    continuar = false;
                } else {
                    cout << "No se encontro el area que selecciono, intente nuevamente!" << endl;
                }
            }
            continuar = true;
            while (continuar == true){
                cout << "Lista de ventanillas del area" << endl;
                sistema.verVentanillas(temp1);
                cout << "\nIndique el numero de ventanilla en el que desea atender un tiquete: ";
                getline(cin, temp2);
                cin.clear();
                if (esNum(temp2) == false){
                        cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                    } else if (stoi(temp2) > sistema.getSizeAreas() || temp2 == "0"){
                        cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                    } else {
                        sistema.atender(temp1, temp2);
                        cout << "El tiquete se atendio con exito!" << endl;
                        continuar = false;
                    }
            }
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
            cout << "3. Servicios" << endl;
            cout << "4. Limpiar colas y estadisticas" << endl;
            cout << "5. Regresar" << endl;
            cout << "Opcion seleccionada: ";
            getline(cin, subOpcion);
            cin.clear();

            //TIPOS DE USUARIO
            subSubOpcion = "1";
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
                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la descripcion del tipo de usuario a agregar: ";
                        getline(cin, descripcion);
                        cin.clear();
                        if (descripcion == ""){
                            cout << "Debe ingresar una descripcion valida!" << endl;
                        } else {
                            continuar = false;
                        }
                    }
                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la prioridad del tipo de usuario a agregar: ";
                        getline(cin, prioridad);
                        cin.clear();
                        if (esNum(prioridad) == true){
                            sistema.appendListaTiposUsuario(descripcion, stoi(prioridad));
                            cout << "Tipo de usuario creado con exito!\n";
                            continuar = false;
                        } else {
                            cout << "La prioridad debe ser un numero entero!\n";
                            }
                    }

                }

                //Elimina un tipo de usuario de la lista de tipos de usuario
                if (subSubOpcion == "2"){
                    continuar = true;
                    while (continuar == true){
                        cout << "\nLista de Tipos de usuario:" << endl;
                        sistema.printDescUsuarios();
                        cout << "\nIngrese la descripcion del tipo de usuario a eliminar: ";
                        getline(cin, descripcion);
                        cin.clear();
                        if (sistema.encontrarElementoListaTiposUsuario(descripcion) == true){
                            sistema.removeListaTiposUsuario(descripcion);
                            cout << "Tipo de usuario eliminado con exito!\n";
                            continuar = false;
                        } else {
                            cout << "No se encontro el usuario que selecciono, intente nuevamente!" << endl;
                        }
                    }
                } else if (subSubOpcion != "1" && subSubOpcion != "2" && subSubOpcion != "3"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                }
            }

            //AREAS
            subSubOpcion = "0";
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
                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la descripcion del area a agregar: ";
                        getline(cin, descripcion);
                        cin.clear();
                        if (descripcion == ""){
                            cout << "Debe ingresar una descripcion valida!" << endl;
                        } else {
                            continuar = false;
                        }
                    }
                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese el codigo del area a agregar: ";
                        getline(cin, codigo);
                        cin.clear();
                        if (codigo == ""){
                            cout << "Debe ingresar un codigo valido!" << endl;
                        } else {
                            continuar = false;
                        }
                    }
                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la cantidad de ventanillas del area a agregar: ";
                        getline(cin, cantidad);
                        cin.clear();
                        if (esNum(cantidad) == true){
                            sistema.appendListaAreas(descripcion, codigo, stoi(cantidad));
                            cout << "Area creada con exito!\n";
                            continuar = false;
                        } else {
                            cout << "La cantidad debe ser un numero entero!\n";
                        }
                    }
                }

                //Modifica la cantidad de ventanillas del area indicada
                if (subSubOpcion == "2"){
                    continuar = true;
                    while (continuar == true){
                        cout << "\nLista de Areas:" << endl;
                        sistema.printDescCodArea();
                        cout << "\nIngrese el codigo del area a modificar: ";
                        getline(cin, codigo);
                        cin.clear();
                        if (sistema.encontrarElementoListaAreas(codigo) == true){
                            continuar = false;
                        } else {
                            cout << "No se encontro el area que selecciono, intente nuevamente!" << endl;
                        }
                    }

                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la nueva cantidad de ventanillas del area: ";
                        getline(cin, cantidad);
                        cin.clear();
                        if (esNum(cantidad) == true){
                            sistema.modVentanillasArea(codigo, stoi(cantidad));
                            cout << "Area modificada con exito!\n";
                            continuar = false;
                        } else {
                            cout << "La cantidad debe ser un numero entero!" << endl;
                        }
                    }
                }

                //Elimina un area de la lista de areas
                if (subSubOpcion == "3"){
                    continuar = true;
                    while (continuar == true){
                        cout << "\nLista de Areas:" << endl;
                        sistema.printDescCodArea();
                        cout << "\nIngrese el codigo del area a eliminar: ";
                        getline(cin, codigo);
                        cin.clear();
                        if (sistema.encontrarElementoListaAreas(codigo) == true){
                            sistema.removeListaAreas(codigo);
                            cout << "\nArea eliminada con exito!";
                            continuar = false;
                        } else {
                            cout << "No se encontro el area que selecciono, intente nuevamente!" << endl;
                        }
                    }
                } else if (subSubOpcion != "1" && subSubOpcion != "2" && subSubOpcion != "3" && subSubOpcion != "4"){
                    cout << "Opcion invalida! Debe elegir una de las opciones presentadas anteriormente!" << endl;
                }
            }

            //SERVICIOS
            subSubOpcion = "0";
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
                    continuar = true;
                    while (continuar == true){
                        //se tiene que trabajar pensando en que no se puede asignar un area que no existe a un servicio
                        cout << "\nIngrese la descripcion del servicio a agregar: ";
                        getline(cin, descripcion);
                        cin.clear();
                        if (descripcion == ""){
                            cout << "Debe ingresar una descripcion valida!" << endl;
                        } else {
                            continuar = false;
                        }
                    }
                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la prioridad del servicio a agregar: ";
                        getline(cin, prioridad);
                        cin.clear();
                        if (esNum(prioridad) == true){
                            continuar = false;
                        } else {
                            cout << "La prioridad debe ser un numero entero!\n";
                        }
                    }
                    continuar = true;
                    while (continuar == true){
                        cout << "\nLista de Areas:" << endl;
                        sistema.printDescCodArea();
                        cout << "\nIngrese el codigo del area del servicio a agregar: ";
                        getline(cin, codigo);
                        cin.clear();
                        if (sistema.encontrarElementoListaAreas(codigo) == true){
                            sistema.appendListaServicios(descripcion, stoi(prioridad), codigo);
                            cout << "Servicio agregado con exito!\n";
                            continuar = false;
                        } else {
                            cout << "No se encontro el area que selecciono, intente nuevamente!" << endl;
                        }
                    }
                }

                //Elimina un servicio de la lista de servicios
                if (subSubOpcion == "2"){
                    continuar = true;
                    while (continuar == true){
                        cout << "\nLista de Servicios:" << endl;
                        sistema.printDescServicios();
                        cout << "Ingrese la descripcion del servicio a eliminar: ";
                        getline(cin, descripcion);
                        cin.clear();
                        if (sistema.encontrarElementoListaServicios(descripcion) == true){
                            sistema.removeListaServicios(descripcion);
                            cout << "Servicio eliminado con exito!\n";
                            continuar = false;
                        } else {
                            cout << "No se encontro el servicio que selecciono, intente nuevamente!" << endl;
                        }
                    }
                }

                //Reordena la lista de servicios
                if (subSubOpcion == "3"){
                    continuar = true;
                    while (continuar == true){
                        cout << "\nLista de Servicios:" << endl;
                        sistema.printDescServicios();
                        cout << "\nIngrese la posicion del servicio a reubicar en la lista: ";
                        getline(cin, temp1);
                        cin.clear();
                        if (esNum(temp1) == true){
                            if (stoi(temp1) < sistema.getSizeServicios()){
                                continuar = false;
                            } else {
                                cout << "Posicion invalida! Debe elegir una de las posiciones presentadas anteriormente!" << endl;
                            }
                        } else {
                            cout << "Posicion invalida! Debe elegir una de las posiciones presentadas anteriormente!" << endl;
                        }
                    }

                    continuar = true;
                    while (continuar == true){
                        cout << "\nIngrese la posicion destino: ";
                        getline(cin, temp2);
                        cin.clear();
                        if (esNum(temp2) == true){
                            if (stoi(temp2) < sistema.getSizeServicios()){
                                sistema.reorderServicios(stoi(temp1), stoi(temp2));
                                cout << "\nServicio reubicado con exito!";
                                continuar = false;
                            } else {
                                cout << "Posicion invalida! Debe elegir una de las posiciones presentadas anteriormente!" << endl;
                            }
                        } else {
                            cout << "Posicion invalida! Debe elegir una de las posiciones presentadas anteriormente!" << endl;
                        }
                    }
                } else if (subSubOpcion != "1" && subSubOpcion != "2" && subSubOpcion != "3" && subSubOpcion != "4"){
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
