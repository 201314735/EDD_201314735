#ifndef COLAAVIONES_H
#define COLAAVIONES_H
using namespace std;

typedef struct colaAviones{
    struct colaAviones* siguiente;
    struct colaAviones* anterior;
    int tipo;
    int pasajeros;
    int desabordaje;
    int mantenimiento;
}colaAviones;

colaAviones* primerAvion = NULL;
colaAviones* ultimoAvion = NULL;

void agregarAvion(colaAviones* avion)
{
    avion -> siguiente = NULL;
    avion -> anterior = NULL;

    if(primerAvion == NULL)
    {
        primerAvion = avion;
        ultimoAvion = primerAvion;
    }

    else
    {
        ultimoAvion -> siguiente = avion;
        avion -> anterior = ultimoAvion;
        ultimoAvion = avion;

    }
}

colaAviones* sacarAvion()
{
    if (primerAvion == NULL)
    {
        return NULL;
    }

    else
    {
        colaAviones* resultado = primerAvion;
        primerAvion = primerAvion -> siguiente;
        resultado -> siguiente = NULL;
        resultado -> anterior = NULL;
        return resultado;
    }
}

bool hayCola(){
    if(primerAvion==NULL){
        return false;
    }else{
        return true;
    }
}

#endif // COLAAVIONES_H
