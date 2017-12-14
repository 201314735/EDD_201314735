#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H

typedef struct colaPasajerosDesabordaje{
    struct colaPasajerosDesabordaje* siguiente;
    struct colaPasajerosDesabordaje* anterior;
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
    pasajeros -> anterior = NULL;

    if(cabeza == NULL)
    {
        cabeza = pasajeros;
        ultimo = cabeza;
    }

    else
    {
        ultimo -> siguiente = pasajeros;
        pasajeros -> anterior = ultimo;
        ultimo = pasajeros;
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
        resultado -> anterior = NULL;
        return resultado;
    }
}


#endif // COLAPASAJEROS_H
