#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Nodo
{
int valor;
int id;
struct Nodo* siguiente;
struct Nodo* anterior;
} Nodo;

id = 1;
Nodo* cabeza = NULL;
Nodo* ultimo = NULL;

void InsertarNodo()
{

Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));


printf("\n Ingrese numero a insertar. \n\n");

scanf("%d", &nuevo->valor);


    if(cabeza == NULL)
    {
        id = 1;
        nuevo -> id = id;
        cabeza = nuevo;
        cabeza -> siguiente = NULL;
        cabeza -> anterior = NULL;
        ultimo = cabeza;
    }
    else
    {
        id++;
        nuevo -> id = id;
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = NULL;
        nuevo -> anterior = ultimo;
        ultimo = nuevo;
    }



printf("\n Insertado Correctamente. \n\n");
}

void Mostrar()
{
    Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
    actual = cabeza;

    if (cabeza == NULL)
    {
        printf("\n Lista Vacia. \n\n");
    }
    else
    {
        while(actual != NULL)
        {
            printf("\n %d. ", actual -> id);
            printf("%d", actual -> valor);
            actual = actual -> siguiente;
        }
        printf("\n\n");
    }

}

void Eliminar()
{
    int nodoSeleccionado = 0;
    int encontrado = 0;
    Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
    Nodo* atras = (Nodo*)malloc(sizeof(Nodo));

    actual = cabeza;
    atras = NULL;

    if (cabeza == NULL)
    {
        printf("\n Lista Vacia. \n\n");
    }

    else
    {
        printf("\n Seleccionar nodo a eliminar. \n\n");


        while(actual != NULL)
        {
            printf("\n %d. ", actual -> id);
            printf("%d", actual -> valor);
            actual = actual -> siguiente;
        }
        printf("\n");

        actual = cabeza;

        scanf("%d", &nodoSeleccionado);



        while(actual != NULL && encontrado != 1)
        {

            if (actual -> id == nodoSeleccionado)
            {

                if(actual == cabeza)
                {
                    if (actual == ultimo)
                    {
                    cabeza = cabeza -> siguiente;
                    }

                    else
                    {
                    cabeza = cabeza -> siguiente;

                    cabeza -> anterior = NULL;
                    }
                }

                else if (actual == ultimo)
                {
                    atras -> siguiente = NULL;
                    ultimo = atras;
                }

                else
                {
                    atras -> siguiente = actual -> siguiente;
                    actual -> siguiente -> anterior = atras;
                }

                encontrado = 1;

            }

            atras = actual;
            actual = actual -> siguiente;


        }

        printf("\n Eliminado Exitosamente. \n\n");

        if (encontrado != 1)
        {
             printf("\n Elemento no encontrado. \n\n");
        }
        else
        {
            free(atras);
        }

    }
}


int menu()
{

    int seleccion;

    while(1)
    {

        printf("Seleccionar Opción: \n");
        printf("1. Insertar a Lista. \n");
        printf("2. Eliminar en Lista. \n");
        printf("3. Mostrar Lista. \n");
        printf("0. Salir. \n");

        scanf("%d", &seleccion);

    switch(seleccion)
    {
        case (1):
            InsertarNodo();
        break;

        case (2):
            Eliminar();
        break;

        case (3):
            Mostrar();
        break;

        case (0):
            exit (EXIT_SUCCESS);
        break;

        default:
            printf("Seleccione una opción correcta \n\n");
        break;
    }
    }
//return 0;
}

#endif // LISTA_H_INCLUDED
