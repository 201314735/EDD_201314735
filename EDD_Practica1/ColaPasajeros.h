#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H
#include "QDebug"

typedef struct colaPasajerosDesabordaje{
    struct colaPasajerosDesabordaje* siguiente;
    int id;
    int maletas;
    int documentos;
    int tRegistro;
}colaPasajerosDesabordaje;

colaPasajerosDesabordaje* cabeza = NULL;
colaPasajerosDesabordaje* ultimo = NULL;

void agregarPasajeros(colaPasajerosDesabordaje* pasajeros)
{
    pasajeros -> siguiente = NULL;

    if(cabeza == NULL)
    {
        cabeza = pasajeros;
        ultimo = cabeza;
        qDebug ()<< "Cabeza "<<cabeza->id<<endl;

    }

    else
    {
        ultimo -> siguiente = pasajeros;
        ultimo = pasajeros;
        qDebug ()<< "Ultimo "<<ultimo->id<<endl;


    }
}


colaPasajerosDesabordaje* sacarPasajeros()
{
    if (cabeza == NULL)
    {
        return NULL;
    }

    else
    {
        colaPasajerosDesabordaje* resultado = cabeza;
        cabeza = cabeza -> siguiente;
        resultado -> siguiente = NULL;
        return resultado;
    }
}

bool hayColaPasajeros(){
    if(cabeza==NULL){
        return false;
    }else{
        return true;
    }
}


#endif // COLAPASAJEROS_H
