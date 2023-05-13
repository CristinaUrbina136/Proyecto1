#ifndef TIPOSUSUARIO_H
#define TIPOSUSUARIO_H

#include<stdexcept>
#include<iostream>
#include<string>
#include<ostream>

using namespace std;

class TiposUsuario
{
public:
    string descripcion;
    int prioridad;

    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
    }

    string getDescripcion(){
        return descripcion;
    }

    void setPrioridad(int prioridad){
        this->prioridad = prioridad;
    }

    int getPrioridad(){
        return prioridad;
    }

};

ostream& operator <<(ostream &os, const TiposUsuario &tu) {
    os << "TiposUsuario (" << tu.descripcion << ", " << tu.prioridad << ")";
    return os;
}

#endif // TIPOSUSUARIO_H
