#ifndef AREAS_H
#define AREAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include<ostream>
#include "HeapPriorityQueue.h"
#include "DLinkedList.h"
#include "Ventanillas.h"

using namespace std;

//Esta clase representa al objeto Area
class Areas
{
public:
    //pensandolo
    //Principales propiedades
    string descripcion;
    string codigo;
    //Para manejar las ventanillas
    int cantVentanillas;
    DLinkedList<Ventanillas*> listaVentanillas;
    //Cola de prioridad de tiquetes
    HeapPriorityQueue<Tiquetes> *tiquetes;


    //Se agregaran las restricciones despues
    //Crea un Area (es el constructor)

    //Elimina un area, para hacerlo previamente en el sistema se pedira el codigo para
    //identificar el objeto, esta funcion solo elimina la ventanilla (es el destructor)

    void setCodigo(string codigo){
        this->codigo = codigo;
    }

    void setCantVentanillas(int cantVentanillas){
        this->cantVentanillas = cantVentanillas;
    }

    void setListaVentanillas(int cantVentanillas){
        int numVentanilla = 1;
        string codVentanilla = getCodigo();
        for(int i=0; i<cantVentanillas; i++){
            string tempCodigo = codigo + to_string(numVentanilla);
            Ventanillas *tempVentanilla = new Ventanillas();
            tempVentanilla->setCodigoVentanilla(tempCodigo);
            listaVentanillas.append(tempVentanilla);
            numVentanilla++;
        }
        listaVentanillas.printP();

    }
    string getCodigo(){
        return codigo;
    }




};



#endif // AREAS_H
