#ifndef TIQUETES_H
#define TIQUETES_H

#include<stdexcept>
#include<iostream>
#include<string>
#include <ctime>
#include <ostream>
#include "Areas.h"

using namespace std;

//Esta clase representa al objeto Tiquete y posee sus atributos y metodos.
//Fue trabajada por Andres Canossa y Cristina Urbina.

class Tiquetes
{
public:
    string codigoTiquete;
    int prioridadFinal;
    //Para impresion
    char *fechaSolicitado;
    //Para hacer el calculo de tiempo transcurrido hasta la atencion
    int tiempoSolicitado;
    int tiempoAtendido;

    void setCodigoTiquete(string codigoArea, int tiquetesGlobal) {
        this->codigoTiquete = codigoArea + to_string(tiquetesGlobal);
    }

    void setPrioridadFinal(int prioridadUsuario, int prioridadServicio){
        this->prioridadFinal = (prioridadUsuario * 10) + prioridadServicio;
    }

    //Pone la fecha en tiempo local
    void setFechaSolicitado(){
        time_t now = time(0);
        tiempoSolicitado = now;
        fechaSolicitado = ctime(&now);
    }

    void verTiquete(){
        cout << "Tiquete (Codigo" << codigoTiquete << ", Fecha solicitado " << fechaSolicitado << ", Prioridad " << to_string(prioridadFinal) << ")" << endl;
    }




};

ostream& operator <<(ostream &os, const Tiquetes &t) {
    os << "TIQUETE (" << t.codigoTiquete << ", " << t.fechaSolicitado << ", " << t.prioridadFinal << ")";
    return os;
}

#endif // TIQUETES_H
