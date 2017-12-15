#ifndef LISTAMANTENIMIENTO_H
#define LISTAMANTENIMIENTO_H

#endif // LISTAMANTENIMIENTO_H

typedef struct listaMantenimiento{
    struct listaMantenimiento* siguiente;
    int numero;
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

bool hayListaMantenimiento(){
    if(primerMantenimiento==NULL){
        return false;
    }else{
        return true;
    }
}
