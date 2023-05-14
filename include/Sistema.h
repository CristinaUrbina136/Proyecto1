#ifndef SISTEMA_H
#define SISTEMA_H

#include<stdexcept>
#include<iostream>
#include<string>
#include<ostream>
#include"TiposUsuario.h"
#include"Servicios.h"
#include"Areas.h"

using namespace std;

class Sistema
{
public:
    DLinkedList<TiposUsuario*> listaTiposUsuario;
    DLinkedList<Servicios*> listaServicios;
    DLinkedList<Areas*> listaAreas;


    //Agregar un tipo de usuario a la lista de tipos de usuario
    void appendListaTiposUsuario(string descripcion, int prioridad){
        TiposUsuario *tempUsuario = new TiposUsuario();
        tempUsuario->setDescripcion(descripcion);
        tempUsuario->setPrioridad(prioridad);
        listaTiposUsuario.append(tempUsuario);
    }

    //Agregar un servicio a la lista de tipos de servicios
    void appendListaServicios(string descripcion, int prioridad, string codigoArea){
        Servicios *tempServicio = new Servicios();
        tempServicio->setDescripcion(descripcion);
        tempServicio->setPrioridad(prioridad);
        tempServicio->setCodigoArea(codigoArea);
        listaServicios.append(tempServicio);
    }

    //Agregar un area a la lista de areas
    void appendListaAreas(string descripcion, string codigo, int cantVentanillas){
        Areas *tempArea = new Areas();
        tempArea->setDescripcion(descripcion);
        tempArea->setCodigo(codigo);
        tempArea->setListaVentanillas(cantVentanillas);
        listaAreas.append(tempArea);
    }

    //Eliminar un tipo de usuario de la lista de tipos de usuario
    void removeListaTiposUsuario(string descripcion){
        listaTiposUsuario.goToStart();
        while (!listaTiposUsuario.atEnd()){
            TiposUsuario *tempUsuario = listaTiposUsuario.getElement();
            if(tempUsuario->descripcion == descripcion){
                listaTiposUsuario.remove();
            }
            listaTiposUsuario.next();
        }
    }

    //Eliminar un area de la lista de areas
    void removeListaAreas(string codigo){
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            if(tempArea->codigo == codigo){
                listaAreas.remove();
            }
            listaAreas.next();
        }
    }

    //Eliminar un servicio de la lista de servicios
    void removeListaServicios(string descripcion){
        listaServicios.goToStart();
        while (!listaServicios.atEnd()){
            Servicios *tempServicio = listaServicios.getElement();
            if(tempServicio->descripcion == descripcion){
                listaServicios.remove();
            }
            listaServicios.next();
        }
    }

    //Modifica la cantidad de ventanillas de un area
    void modVentanillasArea(string codigo, int cantVentanillas){
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            if(tempArea->codigo == codigo){
                tempArea->setListaVentanillas(cantVentanillas);
            }
            listaAreas.next();
        }
    }

    //Reordena los servicios, segun se indica en administracion
    void reorderServicios(int posActual, int posDestino){
        listaServicios.goToPos(posActual);
        Servicios *tempServicio = listaServicios.getElement();
        listaServicios.remove();
        listaServicios.goToPos(posDestino);
        listaServicios.insert(tempServicio);
    }

    //Inserta el tiquete en la cola de su respectiva area
    void insertarCola(Tiquetes *tiquete, string codigo){
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            int tempPrioridad = tiquete->prioridadFinal;
            if(tempArea->codigo == codigo){
                tempArea->insertarCola(tiquete, tempPrioridad);
            }
            listaAreas.next();
        }
    }

    //Obtiene la prioridad de un servicio en la lista segun la posicion indicada
    int getPrioridadServicio(int pos){
        listaServicios.goToPos(pos);
        Servicios *tempServicio = listaServicios.getElement();
        return tempServicio->prioridad;
    }

    //Obtiene la prioridad de un usuario en la lista segun la posicion indicada
    int getPrioridadUsuario(int pos){
        listaTiposUsuario.goToPos(pos);
        TiposUsuario *tempUsuario = listaTiposUsuario.getElement();
        return tempUsuario->prioridad;
    }

    //Obtiene el codigo de area de un servicio en la lista segun la posicion indicada
    string getCodAreaServicio(int pos){
        listaServicios.goToPos(pos);
        Servicios *tempServicio = listaServicios.getElement();
        return tempServicio->codigoArea;
    }

    //Obtiene la descripcion de un servicio en la lista segun la posicion indicada
    string getDescServicio(int pos){
        listaServicios.goToPos(pos);
        Servicios *tempServicio = listaServicios.getElement();
        return tempServicio->descripcion;
    }

    //Obtiene la descripcion de un tipo de usuario en la lista segun la posicion indicada
    string getDescUsuario(int pos){
        listaTiposUsuario.goToPos(pos);
        TiposUsuario *tempUsuario = listaTiposUsuario.getElement();
        return tempUsuario->descripcion;
    }

    void printTiposUsuario(){
        listaTiposUsuario.printP();
    }

    void printServicios(){
        listaServicios.printP();
    }

    void printAreas(){
        listaAreas.printP();
    }

    //Sirve para ver las ventanillas de un area a partir de su codigo
    void verVentanillas(string codigo){
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            if(tempArea->codigo == codigo){
                tempArea->verVentanillas();
            }
            listaAreas.next();
        }
    }

    //Sirve para ver la cola de tiquetes de un area a partir de su codigo
    void verCola(string codigo){
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            if(tempArea->codigo == codigo){
                tempArea->verCola();
            }
            listaAreas.next();
        }
    }

    //Agrega a la estadistica del tipo de usuario, servicio y area indicados
    void agregarEstadistica(string descUsuario, string descServicio, string codArea){
        //Agrega la estadistica a tipo de usuario
        listaTiposUsuario.goToStart();
        while (!listaTiposUsuario.atEnd()){
            TiposUsuario *tempUsuario = listaTiposUsuario.getElement();
            if(tempUsuario->descripcion == descUsuario){
                cout << "cantidad previa: " << tempUsuario->tiquetesSolicitados << endl;
                cout << "cantidad actual: " << tempUsuario->tiquetesSolicitados << endl;
                tempUsuario->agregarTiqueteSolicitado();
 ;
            }
            listaTiposUsuario.next();
        }
        //Agrega la estadistica a servicio
        listaServicios.goToStart();
        while (!listaServicios.atEnd()){
            Servicios *tempServicio = listaServicios.getElement();
            if(tempServicio->descripcion == descServicio){
                tempServicio->agregarTiqueteSolicitado();
            }
            listaServicios.next();
        }
        //Agrega la estadistica a area
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            if(tempArea->codigo == codArea){
                tempArea->agregarTiqueteSolicitado();
            }
            listaAreas.next();
        }
    }

    //Imprime las estadisticas
    void printEstadoColas(){
        cout << endl;
        cout << "Lista de areas" << endl;
        printAreas();
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            cout << endl;
            Areas *tempArea = listaAreas.getElement();
            cout << tempArea->descripcion << " con el codigo " << tempArea->codigo << " posee las siguientes ventanillas " << endl;
            tempArea->verVentanillas();
            cout << tempArea->descripcion << " con el codigo " << tempArea->codigo << " posee tiene la siguiente cola de tiquetes " << endl;
            tempArea->verCola();
            listaAreas.next();
            cout << endl;
        }
    }

    //Imprime una lista con los tipos de usuario
    void printDescUsuarios(){
        int i = 0;
        listaTiposUsuario.goToStart();
        while (!listaTiposUsuario.atEnd()){
            TiposUsuario *tempUsuario = listaTiposUsuario.getElement();
            cout << to_string(i) << ". " << tempUsuario->descripcion << endl;
            i++;
            listaTiposUsuario.next();
        }
    }

    //Imprime una lista con los servicios disponibles
    void printDescServicios(){
        int i = 0;
        listaServicios.goToStart();
        while (!listaServicios.atEnd()){
            Servicios *tempServicio = listaServicios.getElement();
            cout << to_string(i) << ". " << tempServicio->descripcion << endl;
            i++;
            listaServicios.next();
        }
    }

    //Imprime una lista con las areas y sus respectivos codigos
    void printDescCodArea(){
        int i = 0;
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            cout << to_string(i) << ". " << tempArea->descripcion << ", codigo " << tempArea->codigo << endl;
            i++;
            listaAreas.next();
        }
    }

    //Atiende un tiquete en el area y ventanilla indicados
    void atender(string codigo, string numVentanilla){
        listaAreas.goToStart();
        //Recorre la lista de areas
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            //Si el codigo de area coincide
            if(tempArea->codigo == codigo){
                //Saca un tiquete de la cola
                Tiquetes *tempTiquete = tempArea->atenderCola();
                tempArea->listaVentanillas.goToStart();
                //Recorre la lista de ventanillas del area
                while(!tempArea->listaVentanillas.atEnd()){
                    Ventanillas *tempVentanilla = tempArea->listaVentanillas.getElement();
                    //Si la ventanilla coincide en el codigo de area y numero
                    if(tempVentanilla->codigoVentanilla == codigo + numVentanilla){
                        //Le asigna el tiquete que ha sido sacado de la cola
                        tempVentanilla->ultimoTiquete = tempTiquete;
                    }
                    tempArea->listaVentanillas.next();
                }
            }
            listaAreas.next();
        }
    }

    void printEstadisticas(){

    }


};

#endif // SISTEMA_H
