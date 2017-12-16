#ifndef COLAAVIONMANTENIMIENTO_H
#define COLAAVIONMANTENIMIENTO_H

#endif // COLAAVIONMANTENIMIENTO_H

typedef struct colaAvionMantenimiento{
    struct colaAvionMantenimiento* siguiente;
    int tipo;
    int mantenimiento;
}colaAvionMantenimiento;

colaAvionMantenimiento* primerAvionMantenimiento = NULL;
colaAvionMantenimiento* ultimoAvionMantenimiento = NULL;

void agregarAvionMantenimiento(colaAvionMantenimiento* avion)
{
    avion -> siguiente = NULL;

    if(primerAvionMantenimiento == NULL)
    {
        primerAvionMantenimiento = avion;
        ultimoAvionMantenimiento = primerAvionMantenimiento;
    }

    else
    {
        ultimoAvionMantenimiento -> siguiente = avion;
        ultimoAvionMantenimiento = avion;

    }
}

colaAvionMantenimiento* sacarAvionMantenimiento()
{
    if (primerAvionMantenimiento == NULL)
    {
        return NULL;
    }

    else
    {
        colaAvionMantenimiento* resultado = primerAvionMantenimiento;
        primerAvionMantenimiento = primerAvionMantenimiento -> siguiente;
        resultado -> siguiente = NULL;
        return resultado;
    }
}

bool hayColaMantenimiento(){
    if(primerAvionMantenimiento==NULL){
        return false;
    }else{
        return true;
    }
}
