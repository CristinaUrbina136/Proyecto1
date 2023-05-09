#ifndef TIPOSUSUARIO_H
#define TIPOSUSUARIO_H


class TiposUsuario
{
private:
    string tipo;
    string descripcion;
    int prioridad;

public:
    TiposUsuario(string tipo string descripcion int prioridad) {
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->prioridad = prioridad;

    ~TiposUsuario() {}

    void setTipo(string tipo){
        this->tipo = tipo;
    }

    string getTipo()){
        return tipo;
    }

    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
    }

    string getDescripcion(){
        return descripcion;
    }

    void setPrioridad(string prioridad){
        this->prioridad = prioridad;
    }

    string getPrioridad()){
        return prioridad;
    }

};

#endif // TIPOSUSUARIO_H
