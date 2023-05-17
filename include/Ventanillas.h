#ifndef VENTANILLAS_H
#define VENTANILLAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include <ostream>
#include "DNode.h"
#include "Tiquetes.h"

using namespace std;

//Esta clase representa al objeto Ventanilla y posee sus atributos y metodos.
//Fue trabajada por Andres Canossa y Cristina Urbina.

class Ventanillas {
public:
    string codigoVentanilla;
    string codigoArea;
    string ultimoTiquete;
    int tiquetesAtendidos;

    Ventanillas(){
        tiquetesAtendidos = 0;
        ultimoTiquete = "Ventanilla sin tiquete";
    }

    void setCodigoVentanilla(string codigoVentanilla){
        this->codigoVentanilla = codigoVentanilla;
    }
    string getCodigoVentanilla() {
        return codigoVentanilla;
    }
    void setCodigoArea(string codigoArea){
        this->codigoArea = codigoArea;
    }
    string getCodigoArea() {
        return codigoArea;
    }

    int getTiquetesAtendidos() {
        return tiquetesAtendidos;
    }
    void agregarTiqueteAtendido(){
        tiquetesAtendidos++;
    }
};

ostream& operator <<(ostream &os, const Ventanillas &v) {
    os << "Ventanilla (Codigo " << v.codigoVentanilla << ", " << v.ultimoTiquete << ")";
    return os;
}

#endif // VENTANILLA_H
