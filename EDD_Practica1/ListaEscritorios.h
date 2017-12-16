#ifndef LISTAESCRITORIOS_H
#define LISTAESCRITORIOS_H

#endif // LISTAESCRITORIOS_H

typedef struct colaEscritorios{
    struct colaEscritorios* siguiente;
  //  int id;
   // int maletas;
   // int documentos;
   // int tRegistro;
}colaEscritorios;

colaEscritorios* primeroCola = NULL;
colaEscritorios* ultimoCola = NULL;



void agregarPasajerosEscritorios(colaEscritorios* pasajeros)
{
    int contadorPasajeros;
    bool acceso = true;

  /*  while(pasajeros!=NULL)
    {
        if(pasajeros==primeroCola)
        {
            contadorPasajeros++;
            pasajeros=pasajeros->siguiente;
        }

        else
        {
            contadorPasajeros++;
            pasajeros=pasajeros->siguiente;
        )
    }*/

    pasajeros -> siguiente = NULL;
    if(contadorPasajeros !=10){

    if(primeroCola == NULL)
    {
        primeroCola = pasajeros;
        ultimoCola = primeroCola;
        contadorPasajeros++;
    }

    else
    {
        ultimoCola -> siguiente = pasajeros;
        ultimoCola = pasajeros;
        contadorPasajeros++;
    }
    }
    else
    {
acceso = false;
    }
}

typedef struct listaEscritorios{
    struct listaEscritorios* siguiente;
    struct listaEscritorios* anterior;
    char nombre;
    colaEscritorios* cola;
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


