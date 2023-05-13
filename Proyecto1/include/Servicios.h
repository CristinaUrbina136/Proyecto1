#ifndef SERVICIOS_H
#define SERVICIOS_H


class Servicios
{
public:
    string descripcion;
    string codigoArea;
    int prioridad;
    int tiquetes;

    void operator =(const Servicios &s) {
        this->codigoArea = s.codigoArea;
        this->descripcion = s.descripcion;
        this->tiquetes = s.tiquetes;
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
    void tiqueteAgregado() {
        tiquetes += 1;
    }
    int getTiquetes() {
        return tiquetes;
    }
};

ostream& operator <<(ostream &os, const Servicios &s) {
    os << "Servicios (" << s.descripcion << ", " << s.prioridad << ", " << s.codigoArea << ")";
    return os;
}

#endif // SERVICIOS_H
