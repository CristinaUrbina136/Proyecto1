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
    }
};

#endif // VENTANILLA_H
