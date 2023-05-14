#ifndef VENTANILLAS_H
#define VENTANILLAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include <ostream>
#include "DNode.h"
#include "Tiquetes.h"

using namespace std;

//Esta clase representa al objeto Ventanilla
class Ventanillas {
public:
    string codigoVentanilla;
    string codigoArea;
    Tiquetes *ultimoTiquete;
    int tiquetesAtendidos;

    Ventanillas(){
        tiquetesAtendidos = 0;
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
    os << "Ventanilla (" << v.codigoVentanilla << ", " << v.ultimoTiquete << ")";
    return os;
}

#endif // VENTANILLA_H
