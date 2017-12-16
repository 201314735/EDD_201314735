#ifndef LISTAMANTENIMIENTO_H
#define LISTAMANTENIMIENTO_H

#endif // LISTAMANTENIMIENTO_H

typedef struct listaMantenimiento{
    struct listaMantenimiento* siguiente;
    int numero;
    int tipo;
    int turnos;
    char ocupado = 'L';
}listaMantenimiento;

listaMantenimiento* primerMantenimiento = NULL;
listaMantenimiento* ultimoMantenimiento = NULL;

void agregarMantenimiento(listaMantenimiento* mantenimiento)
{
    mantenimiento -> siguiente = NULL;

    if(primerMantenimiento == NULL)
    {
        primerMantenimiento = mantenimiento;
        ultimoMantenimiento = primerMantenimiento;
    }

    else
    {
        ultimoMantenimiento -> siguiente = mantenimiento;
        ultimoMantenimiento = mantenimiento;

    }
}

listaMantenimiento* agregar(listaMantenimiento* mantenimiento)
{
    listaMantenimiento* actual = new listaMantenimiento();
    actual = primerMantenimiento;

    if(actual!=NULL){

    if(actual->ocupado == 'L')
    {
        actual ->tipo = mantenimiento->tipo;
        actual->turnos = mantenimiento->turnos;
        actual->ocupado='O';
        return actual;
    }

    else
    {
        actual = actual->siguiente;

    }
    }
    else{}
}
listaMantenimiento* sacar()
{
    listaMantenimiento* actual = new listaMantenimiento();
    actual = primerMantenimiento;

    if(actual!=NULL){

    if(actual->ocupado == 'L')
    {
        actual->ocupado='O';
        return actual;
    }

    else
    {
        actual = actual->siguiente;

    }
    }
    else{}
}



bool hayListaMantenimiento(){
    if(primerMantenimiento==NULL){
        return false;
    }else{
        return true;
    }
}
