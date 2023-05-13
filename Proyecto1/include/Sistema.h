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
