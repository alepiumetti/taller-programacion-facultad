#include <stdio.h>

int main()
{

    int tamano = 0;

    do
    {
        printf("Ingrese el tamano de la matriz:");
        scanf("%d", &tamano);
    } while (tamano < 0);

    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            printf(" %d ", i == j ? 1 : 0);
        }
        printf("\n");
    }

    return 0;
}