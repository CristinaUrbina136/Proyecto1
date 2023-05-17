#ifndef SERVICIOS_H
#define SERVICIOS_H


//Esta clase representa los servicios y posee sus atributos y metodos
//Fue trabajada por Andres Canossa y Cristina Urbina.

class Servicios
{
public:
    string descripcion;
    string codigoArea;
    int prioridad;
    int tiquetesSolicitados;

    Servicios(){
        tiquetesSolicitados = 0;
    }

    void setCodigoArea(string codigoArea){
        this->codigoArea = codigoArea;
    }

    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
    }

    void setPrioridad(int prioridad){
        this->prioridad = prioridad;
    }

    int getPrioridad(){
        return prioridad;
    }

    string getCodigoArea(){
        return codigoArea;
    }

    string getDescripcion(){
        return descripcion;
    }
    void agregarTiqueteSolicitado() {
        tiquetesSolicitados++;
    }
    int getTiquetesSolicitados() {
        return tiquetesSolicitados;
    }
};

ostream& operator <<(ostream &os, const Servicios &s) {
    os << "Servicios (" << s.descripcion << ", " << s.prioridad << ", " << s.codigoArea << ", " << s.tiquetesSolicitados << ")";
    return os;
}

#endif // SERVICIOS_H
