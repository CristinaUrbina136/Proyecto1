#ifndef AREAS_H
#define AREAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include "HeapPriorityQueue.h"
#include "DLinkedList.h"
#include "Ventanillas.h"

using namespace std;

//Esta clase representa al objeto Area
class Areas
{
private:
    //pensandolo
    //Principales propiedades
    string descripcion;
    string codigo;
    //Para manejar las ventanillas
    int cantVentanillas;
    DLinkedList<Ventanillas> listaVentanillas;
    //Cola de prioridad de tiquetes
    HeapPriorityQueue<Tiquetes> tiquetes;

public:
    //Se agregaran las restricciones despues
    //Crea un Area (es el constructor)
    void Area(string descripcion, string codigo, int cantVentanillas){
        this->descripcion = descripcion;
        this->codigo = codigo;
        this->cantVentanillas = cantVentanillas;
    }
    //Elimina un area, para hacerlo previamente en el sistema se pedira el codigo para
    //identificar el objeto, esta funcion solo elimina la ventanilla (es el destructor)

    //Modifica la cantidad de ventanillas de un area, para hacerlo previamente en el sistema se pedira el codigo para
    //identificar el objeto, esta funcion solo modifica la cantidad de ventanillas
    void setCantVentanillas(int ventanillas){
        this->cantVentanillas = cantVentanillas;
    }
    //Llena la lista de ventanillas con la cantidad de ventanillas solicitada
    void setListaVentanillas(int cantVentanillas){
        int numVentanilla = 1;
        string codVentanilla = getCodigo();

    }
    string getCodigo(){
        return codigo;
    }




};

#endif // AREAS_H
