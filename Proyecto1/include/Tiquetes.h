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
    string codigoTiquete;
    char *fechaSolicitados;
    int prioridadFinal;

    void setCodigoTiquete(string codigoArea, int tiquetesGlobal) {
        this->codigoTiquete = codigoArea + to_string(tiquetesGlobal);
    }

    void setPrioridadFinal(int prioridadUsuario, int prioridadServicio){
        this->prioridadFinal = prioridadUsuario * 10 + prioridadServicio;
    }





};

ostream& operator <<(ostream &os, const Tiquetes &t) {
    os << "TIQUETE (" << t.codigoTiquete << ", " << t.fechaSolicitados << ", " << t.prioridadFinal << ")";
    return os;
}

#endif // TIQUETES_H
