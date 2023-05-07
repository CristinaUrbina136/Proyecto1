#ifndef AREAS_H
#define AREAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include "HeapPriorityQueue.h"
#include "DLinkedList.h"

using namespace std;

class Areas
{
private:
    //pensandolo
    string descipcion;
    string codigo;
    int cantVentanillas;
    DLinkedList listaVentanillas;
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
    void setVentanillas(int ventanillas){
        this->ventanillas = ventanillas;
    }
    string getCodigo(){
        return codigo;
    }



};

#endif // AREAS_H
