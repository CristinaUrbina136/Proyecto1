#ifndef VENTANILLAS_H
#define VENTANILLAS_H

#include<stdexcept>
#include<iostream>
#include<string>
#include "DNode.h"
#include "Tiquetes.h"

using namespace std;

//Esta clase representa al objeto Ventanilla
class Ventanillas {
private:
    int atendidos = 0;
    string codigoVentanilla;
    string codigoArea;
    tiquete *ultimoTiquete;

public:
    Ventanillas(string codigoVentanilla, string codigoArea, tiquete *ultimoTiquete = nullptr) {
        this->codigoVentanilla = codigoVentanilla;
        this->codigoArea = codigoArea;
        this->ultimoTiquete = ultimoTiquete;
    }
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
    void setUltimoTiquete(tiquete *ultimoTiquete){
        atendidos++;
        this->ultimoTiquete = ultimoTiquete;
    }
    tiquete* getUltimoTiquete() {
        return ultimoTiquete;
    }
};

ostream& operator <<(ostream &os, const Ventanillas &v) {
    os << "Ventanilla (" << v.codigoVentanilla << ", " << v.codigoArea << ", " << v.ultimoTiquete << ")";
    return os;
}

#endif // VENTANILLA_H
