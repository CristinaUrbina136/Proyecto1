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
    DLinkedList<Ventanillas*> listaVentanillas;
    HeapPriorityQueue<Tiquetes*> colaTiquetes;
    int tiquetesSolicitados;
    int tiempoTotal;
    int tiempoEsperaPromedio;

    Areas(){
        tiquetesSolicitados = 0;
        tiempoTotal = 0;
        tiempoEsperaPromedio = 0;
    }


    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
    }

    void setCodigo(string codigo){
        this->codigo = codigo;
    }

    void setListaVentanillas(int cantVentanillas){
        listaVentanillas.clear();
        int numVentanilla = 1;
        string codVentanilla = getCodigo();
        for(int i=0; i<cantVentanillas; i++){
            string tempCodigo = codigo + to_string(numVentanilla);
            Ventanillas *tempVentanilla = new Ventanillas();
            tempVentanilla->setCodigoVentanilla(tempCodigo);
            listaVentanillas.append(tempVentanilla);
            numVentanilla++;
        }
    }

    void insertarCola(Tiquetes *tiquete, int prioridad){
        colaTiquetes.insert(tiquete, prioridad);
    }

    Tiquetes* atenderCola(){
        Tiquetes *tempTiquete = colaTiquetes.removeMin();
        tempTiquete->tiempoAtendido = time(0) - tempTiquete->tiempoSolicitado;
        tiempoTotal += tempTiquete->tiempoAtendido;
        return tempTiquete;
    }

    string getDescripcion(){
        return descripcion;
    }
    string getCodigo(){
        return codigo;
    }

    void verVentanillas(){
        listaVentanillas.printP();
    }

    void verCola(){
        colaTiquetes.print();
    }
    void agregarTiqueteSolicitado() {
        tiquetesSolicitados++;
    }
    int getTiquetesSolicitados() {
        return tiquetesSolicitados;
    }

    int calcularTiempoEsperaPromedio() {
        if (tiquetesSolicitados == 0){
            return 0;
        }
        else {
            return tiempoEsperaPromedio = tiempoTotal/tiquetesSolicitados;
        }
    }

};


ostream& operator <<(ostream &os, const Areas &a) {
    os << "AREA (" << a.descripcion << ", " << a.codigo << ")";
    return os;
}


#endif // AREAS_H
