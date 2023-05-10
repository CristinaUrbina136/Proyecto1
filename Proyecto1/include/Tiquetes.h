#ifndef TIQUETES_H
#define TIQUETES_H

#include<stdexcept>
#include<iostream>
#include<string>
#include <ctime>
#include "Areas.h"

using namespace std;

//Esta clase representa al objeto Tiquete
class Tiquetes
{
public:
    string codigo;
    char *fechaSolicitados;
    int prioridadFinal;



};

ostream& operator <<(ostream &os, const Tiquetes &t) {
    os << "TIQUETE (" << t.codigo << ", " << t.fechaSolicitados << ", " << t.prioridadFinal << ")";
    return os;
}

#endif // TIQUETES_H
