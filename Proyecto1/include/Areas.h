#ifndef AREAS_H
#define AREAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include "HeapPriorityQueue.h"
#include "DLinkedList.h"

using namespace std;

//Esta clase representa al objeto Area
class Areas
{
private:
    //pensandolo
    //Principales propiedades
    string descipcion;
    string codigo;
    //Para manejar las ventanillas
    int cantVentanillas;
    DLinkedList<Ventanillas> listaVentanillas;
    //Cola de prioridad de tiquetes
    HeapPriorityQueue tiquetes;

public:
    //Se agregaran las restricciones despues
    //Crea un Area (es el constructor)
    void Area(string descipcion, string codigo, int ventanillas){
        this->descipcion = descripcion;
        this->codigo = codigo;
        this->ventanillas = ventanillas;
    }
    //Elimina un area, para hacerlo previamente en el sistema se pedira el codigo para
    //identificar el objeto, esta funcion solo elimina la ventanilla (es el destructor)
    ~Area(){
        //pensandolo
    }
    //Modifica la cantidad de ventanillas de un area, para hacerlo previamente en el sistema se pedira el codigo para
    //identificar el objeto, esta funcion solo modifica la cantidad de ventanillas
    void setCantVentanillas(int ventanillas){
        this->ventanillas = ventanillas;
    }
    //Llena la lista de ventanillas con la cantidad de ventanillas solicitada
    void setListaVentanillas(int cantVentanillas){
        numVentanilla = 1;
        codVentanilla = getCodigo();
        Ventanilla tVentanilla;
        for(i = 0; i < cantVentanillas; i++){

            listaVentanillas.append();
        }
    }
    string getCodigo(){
        return codigo;
    }




};

#endif // AREAS_H
