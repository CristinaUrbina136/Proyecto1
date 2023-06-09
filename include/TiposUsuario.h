#ifndef TIPOSUSUARIO_H
#define TIPOSUSUARIO_H

#include<stdexcept>
#include<iostream>
#include<string>
#include<ostream>

using namespace std;

//Esta clase representa los tipos de usuario y posee sus atributos y metodos.
//Fue trabajada por Gabriel Calvo, Cristina Urbina.

class TiposUsuario
{
public:
    string descripcion;
    int prioridad;
    int tiquetesSolicitados;

    TiposUsuario(){
        tiquetesSolicitados = 0;
    }

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

    void agregarTiqueteSolicitado() {
        tiquetesSolicitados++;
    }


};

ostream& operator <<(ostream &os, const TiposUsuario &tu) {
    os << "Tipo de usuario (" << tu.descripcion << ", " << tu.prioridad << "," << tu.tiquetesSolicitados << ")";
    return os;
}

#endif // TIPOSUSUARIO_H
