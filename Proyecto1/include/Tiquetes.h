#ifndef TIQUETES_H
#define TIQUETES_H

#include<stdexcept>
#include<iostream>
#include<string>
#include <ctime>
#include <ostream>
#include "Areas.h"

using namespace std;

//Esta clase representa al objeto Tiquete
class Tiquetes
{
public:
    string codigoArea;
    string codigoTiquete;
    char *fechaSolicitados;
    int prioridadUsuario;
    int prioridadServicio;
    int prioridadFinal;

    void setPrioridadFinal(){
        this->prioridadFinal = this->prioridadUsuario * 10 + this->prioridadServicio;
    }




};

ostream& operator <<(ostream &os, const Tiquetes &t) {
    os << "TIQUETE (" << t.codigoTiquete << ", " << t.fechaSolicitados << ", " << t.prioridadFinal << ")";
    return os;
}

#endif // TIQUETES_H
