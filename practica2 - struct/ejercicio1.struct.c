#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define SIZE_LISTA 2
#define MAX_NAME 20

#include "./types.h"
#include "./prototipos.h"
#include "./tiempo.h"   
#include "./archivo.h"


int main()
{

    Archivo lista[SIZE_LISTA];
    Archivo * plista = lista;

    for (int i = 0; i < SIZE_LISTA; i++)
    {
        carga_datos(plista + i);
        printf("Nombre: %s \n",(plista + i)->nombre);
        imprime_tiempo((plista + i)->ultima_mod);
        printf("\n");      
    }
    
    for (int i = 0; i < SIZE_LISTA; i++)
    {
        free((plista + i)->nombre);
    }
    
    return 0;
}






// Tiempo time
// cuado un struct es puntero para acceder uso 'time -> anio' = (*time).anio para acceder al valor
// scanf("%d",&(time.anio))