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
    int atendidos = 0;
    string codigoVentanilla;
    string codigoArea;
    Tiquetes *ultimoTiquete;


    ~Ventanillas(){
        delete [] ultimoTiquete;
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
    int getAtendidos() {
        return atendidos;
    }
    void setUltimoTiquete(Tiquetes *ultimoTiquete){
        atendidos++;
        this->ultimoTiquete = ultimoTiquete;
    }
    Tiquetes *getUltimoTiquete() {
        return ultimoTiquete;
    }
};

ostream& operator <<(ostream &os, const Ventanillas &v) {
    os << "Ventanilla (" << v.codigoVentanilla << ", " << v.codigoArea << ", " << v.ultimoTiquete << ")";
    return os;
}

#endif // VENTANILLA_H
