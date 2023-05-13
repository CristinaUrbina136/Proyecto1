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
    string tipo;
    string descripcion;
    int prioridad;

    void setTipo(string tipo){
        this->tipo = tipo;
    }

    string getTipo(){
        return tipo;
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

};

#endif // TIPOSUSUARIO_H
