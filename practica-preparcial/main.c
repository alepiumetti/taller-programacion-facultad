#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int filas = 5;
    int columnas = 10;

    int **matrix = malloc(sizeof(matrix) * filas);

    for (int i = 0; i < filas; i++)
    {
        *(matrix + i) = malloc(sizeof(matrix) * columnas);
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) =  j;
        }
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {

            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < filas; i++)
    {
        free(*(matrix + i));
    }

    free(matrix);

    return 0;
}
