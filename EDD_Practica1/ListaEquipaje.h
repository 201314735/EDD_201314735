#ifndef LISTAEQUIPAJE_H
#define LISTAEQUIPAJE_H

#endif // LISTAEQUIPAJE_H


typedef struct listaEquipaje{
    struct listaEquipaje* siguiente;
    struct listaEquipaje* anterior;
    char nombre;
}listaEquipaje;

listaEquipaje* primerEquipaje = NULL;
listaEquipaje* ultimoEquipaje = NULL;

void agregarEquipaje(listaEquipaje* equipaje)
{
    equipaje -> siguiente = NULL;
    equipaje -> anterior = NULL;

    if(primerEquipaje == NULL)
    {
        primerEquipaje = equipaje;
        ultimoEquipaje = primerEquipaje;
        primerEquipaje->siguiente = primerEquipaje;
        primerEquipaje->anterior = ultimoEquipaje;
    }

    else
    {
        ultimoEquipaje -> siguiente = equipaje;
        equipaje -> anterior = ultimoEquipaje;
        equipaje -> siguiente = primerEquipaje;
        ultimoEquipaje = equipaje;
        primerEquipaje -> anterior = ultimoEquipaje;
    }
}

listaEquipaje* sacarEquipaje()
{
    if (primerEquipaje == NULL)
    {
        return NULL;
    }

    else
    {
        listaEquipaje* resultado = primerEquipaje;
        primerEquipaje = primerEquipaje -> siguiente;
        primerEquipaje -> anterior = ultimoEquipaje;
        ultimoEquipaje -> siguiente = primerEquipaje;
        resultado -> siguiente = NULL;
        resultado -> anterior = NULL;


        return resultado;
    }
}

bool hayListaEquipaje(){
    if(primerEquipaje==NULL){
        return false;
    }else{
        return true;
    }
}
