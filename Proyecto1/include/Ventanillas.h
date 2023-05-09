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
<<<<<<< HEAD
    int atendidos = 0;
    string codigoVentana;
    string codigoArea;
    tiquete *ultimoTiquete;

public:
    Ventanillas(string codigoVentana, string codigoArea, tiquete *ultimoTiquete = nullptr) {
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
=======
    string nombre;
    Tiquetes tiqueteActual;

public:
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setTiqueteActual(Tiquetes tiqueteActual){
        this->tiqueteActual = tiqueteActual;
    }
    string getNombre(){
        return nombre;
    }
    Tiquetes getTiqueteActual(){
        return tiqueteActual;
>>>>>>> a1620ebdb4a002c276f8514eca1ccfc3f88f69af
    }
};

#endif // VENTANILLA_H
