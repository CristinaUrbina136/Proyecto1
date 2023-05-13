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
    void insertarCola(Tiquetes tiquete, string codigo){
        listaAreas.goToStart();
        while (!listaAreas.atEnd()){
            Areas *tempArea = listaAreas.getElement();
            if(tempArea->codigo == codigo){
                tempArea->tiquetes->insert(tiquete,tiquete.prioridadFinal);
            }
            listaAreas.next();
        }
    }

    int getPrioridadServicio(int pos){
        listaServicios.goToPos(pos);
        Servicios *tempServicio = listaServicios.getElement();
        return tempServicio->prioridad;
    }

    int getPrioridadUsuario(int pos){
        listaTiposUsuario.goToPos(pos);
        TiposUsuario *tempUsuario = listaTiposUsuario.getElement();
        return tempUsuario->prioridad;
    }

    string getCodAreaServicio(int pos){
        listaServicios.goToPos(pos);
        Servicios *tempServicio = listaServicios.getElement();
        return tempServicio->codigoArea;
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

};

#endif // SISTEMA_H
