#include"cola.h"

int main(){
    primero = NULL;
    ultimo = NULL;

    menu();

    return 0;
}

void menu(){
    char opcion=' ';
    while(opcion != 'T'){
        printf("Elija opcion \n (I)nsertar (E)liminar (L)istar: ");
        opcion = toupper(getchar());
        switch(opcion){
            case 'I':   printf("\nIngrese numero: ");
                        scanf("%d", &n);
                        insertar (&primero, &ultimo, n);
                        break;
            case 'L':   listar(primero);
                        break;
            case 'E':   eliminar(&primero, &ultimo);
                        break;
        }
    }
}

void insertar (pnodo *p, pnodo *u, int dato){
    pnodo aux; // puntero auxiliar
    aux = (pnodo) malloc(sizeof(nodo)); //pido memoria para nuevo nodo
    if(aux == NULL){
        printf("Memoria insuficiente...");
        exit(1);
    }
    
    aux->info = dato;
    aux->siguiente = NULL;

    if (*p == NULL)
        *p = aux;
    else
        (*u)->siguiente = aux;

    *u = aux;
}

void listar(pnodo p){
    if (p == NULL)
        printf("Cola vacia\n");
    else{
        printf("Contenido de la cola\n");
        while(p != NULL){
            printf("%d\n", p->info);
            p = p->siguiente;
        }
    }
}

void eliminar(pnodo *p, pnodo *u){
    pnodo aux;
    aux = *p;
    *p = (*p)->siguiente;
    if(*p == NULL)
        *u = NULL;
    printf("\nEliminando el nodo %d", aux->info);
    free(aux);

}

