#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
} tipoNodo;

tipoNodo *pila;
// funciones
void push(tipoNodo **, int);
int pop(tipoNodo **);
void cargar();
void listar();

int main()
{
    pila = NULL;
    cargar();
    listar();
    return 0;
}

void cargar()
{
    int n = 1;
    while (n != 0)
    {
        printf("Ingrese Nro (0 = fin):");
        scanf("%i", &n);
        if (n != 0)
            push(&pila, n);
    }
}

void listar()
{
    tipoNodo *z = pila;
    printf("\nContenido de la Pila\n");
    while (z != NULL)
        printf("%i\n", pop(&z));
}

void push(tipoNodo **pila, int v)
{
    tipoNodo *nuevo;
    /*crear el nuevo nodo*/
    nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
    nuevo->valor = v;
    /*Agregamos la pila a continuacion del nuevo nodo*/
    nuevo->siguiente = *pila;
    /*Ahora ponemos el comienzo en el nuevo*/
    *pila = nuevo;
}

int pop(tipoNodo **pila)
{
    tipoNodo *nodo; // variable auxiliar
    int v;          // variable de retorno
    /*nodo apunta a primer elemeto que sacaremos*/
    nodo = *pila;
    /*asignamos pila, toda la pila menos el primer elemento*/
    *pila = nodo->siguiente;
    /*guardamos el valor de retorno*/
    v = nodo->valor;
    /*liberamos la memoria*/
    free(nodo);
    return v;
}