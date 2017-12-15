#ifndef LISTAESCRITORIOS_H
#define LISTAESCRITORIOS_H

#endif // LISTAESCRITORIOS_H
typedef struct listaEscritorios{
    struct listaEscritorios* siguiente;
    struct listaEscritorios* anterior;
    char nombre;
}listaEscritorios;

listaEscritorios* primerEscritorio = NULL;
listaEscritorios* ultimoEscritorio = NULL;


void agregarEscritorio(listaEscritorios* escritorio)
{
    escritorio -> siguiente = NULL;
    escritorio -> anterior = NULL;

    if(primerEscritorio == NULL)
    {
        primerEscritorio = escritorio;
        ultimoEscritorio = primerEscritorio;
    }

    else
    {
        ultimoEscritorio -> siguiente = escritorio;
        escritorio -> anterior = ultimoEscritorio;
        ultimoEscritorio = escritorio;

    }
}

bool hayListaEscritorios(){
    if(primerEscritorio==NULL){
        return false;
    }else{
        return true;
    }
}
