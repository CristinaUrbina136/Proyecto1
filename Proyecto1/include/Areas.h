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
    string descripcion;
    string codigo;
    int cantVentanillas;
    DLinkedList<Ventanillas*> listaVentanillas;
    HeapPriorityQueue<Tiquetes> *tiquetes;

    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
    }

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
    string getDescripcion(){
        return descripcion;
    }
    string getCodigo(){
        return codigo;
    }
    int getCantVentanillas(){
        return cantVentanillas;
    }






};



#endif // AREAS_H
