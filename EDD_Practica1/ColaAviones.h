#ifndef COLAAVIONES_H
#define COLAAVIONES_H

typedef struct colaAviones{
    struct colaAviones* siguiente;
    struct colaAviones* anterior;
    int tipo;
    int pasajeros;
    int desabordaje;
    int mantenimiento;
}colaAviones;

colaAviones* cabeza = NULL;
colaAviones* ultimo = NULL;

void agregarAvion(colaAviones* avion)
{
    avion -> siguiente = NULL;
    avion -> anterior = NULL;

    if(cabeza == NULL)
    {
        cabeza = avion;
        ultimo = cabeza;
    }

    else
    {
        ultimo -> siguiente = avion;
        avion -> anterior = ultimo;
        ultimo = avion;
    }
}

colaAviones* sacarAvion()
{
    if (cabeza == NULL)
    {
        return NULL;
    }

    else
    {
        colaAviones* resultado = cabeza;
        cabeza = cabeza -> siguiente;
        cabeza -> anterior = ultimo;
        resultado -> siguiente = NULL;
        resultado -> anterior = NULL;
        return resultado;
    }
}

#endif // COLAAVIONES_H
