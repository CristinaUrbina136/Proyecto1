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
public:
    string nombre;
    Tiquetes tiqueteActual;

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

ostream& operator <<(ostream &os, const Ventanillas &v) {
    os << "Ventanilla (" << v.nombre << ", " << v.tiqueteActual << ")";
    return os;
}

#endif // VENTANILLA_H
