#ifndef SERVICIOS_H
#define SERVICIOS_H


class Servicios
{
private:
    string nombre;
    string codigoArea;
    string descripcion;
    int tiquetes;
public:
    Servicios(string nombre, string codigoArea, string descripcion) {
        this->nombre = nombre;
        this->codigoArea = codigoArea;
        this->descripcion = descripcion;
        tiquetes = 0;
        }

    ~Servicios() {}

    void setNombre(string nombre){
        this->nombre = nombre;
    }

    string getNombre(){
        return nombre;
    }

    void setCodigoArea(string codigoArea){
        this->codigoArea = codigoArea;
    }

    string getCodigoArea(){
        return codigoArea;
    }

    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
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

#endif // SERVICIOS_H
