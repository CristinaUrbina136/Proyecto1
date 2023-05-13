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
    char *fechaSolicitado;
    int prioridadFinal;

    void setCodigoTiquete(string codigoArea, int tiquetesGlobal) {
        this->codigoTiquete = codigoArea + to_string(tiquetesGlobal);
    }

    void setPrioridadFinal(int prioridadUsuario, int prioridadServicio){
        this->prioridadFinal = prioridadUsuario * 10 + prioridadServicio;
    }

    //Pone la fecha en tiempo local
    void setFechaSolicitado(){
        time_t now = time(0);
        fechaSolicitado = ctime(&now);
    }

    void verTiquete(){
        cout << "TIQUETE (" << codigoTiquete << "," << fechaSolicitado << ", " << to_string(prioridadFinal) << ")" << endl;
    }


};

ostream& operator <<(ostream &os, const Tiquetes &t) {
    os << "TIQUETE (" << t.codigoTiquete << ", " << t.fechaSolicitado << ", " << t.prioridadFinal << ")";
    return os;
}

#endif // TIQUETES_H
