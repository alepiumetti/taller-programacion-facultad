/*

TRABAJO FINAL 2025
ALEJANDRO PIUMETTI
COMISION 2

*/

#include "./prototypes.h"
#include "./utils.c"

int main()
{
    char opcion = 'I';
    do
    {
        CLEAR_CONSOLE;
        printf("===== SCHEDULER DE PROCESOS =====\n");
        printf("\n");
        printf("(I)ngresa proceso | (T)ermina proceso | (R)ecorre cola | (M)ostrar Scheduler | (L)istar File | (S)alir: ");
        opcion = toupper(getchar());

        limpiar_buffer();
        switch (opcion)
        {
        case 'I':
            ingresaProceso();
            break;
        case 'T':
            terminaProceso();
            break;
        case 'R':
            recorreCola();
            break;
        case 'M':
            mostrarScheduler();
            break;
        case 'L':
            listarFile();
            break;
        default:
            break;
        }
        if (opcion != 'S')
            pausa();

    } while (opcion != 'S');
    return 0;
}

/* Asigna el siguiente estado según el orden Nuevo->Listo->Esperando->Corriendo->Terminado */
void asignaEstado(proceso *proceso)
{

    if (strcmp(proceso->estado, "Terminado") == 0)
    {
        printf("El proceso está terminado. No se puede cambiar su estado.\n");
        return;
    }

    if (strcmp(proceso->estado, "Nuevo") == 0)
    {
        strcpy(proceso->estado, "Listo");
    }
    else if (strcmp(proceso->estado, "Listo") == 0)
    {
        strcpy(proceso->estado, "Esperando");
    }
    else if (strcmp(proceso->estado, "Esperando") == 0)
    {

        int procesador = procesadorLibre();
        if (procesador == 0)
        {
            printf("No hay procesadores libres. El proceso permanecerá en estado 'Esperando'.\n");
            return;
        }
        // Antes de hacer el cambio de estado a "Corriendo" se verifica el proceso con la prioridad más baja.
        int prioritario = buscaProcesoPrioritario();

        proceso->procesador = procesador;

        strcpy(proceso->estado, "Corriendo");
    }
    else if (strcmp(proceso->estado, "Corriendo") == 0)
    {
        strcpy(proceso->estado, "Terminado");
        proceso->procesador = -1;
    }
    else
    {
        strcpy(proceso->estado, "Nuevo");
    }

    printf("El nuevo estado del proceso es: %s\n", proceso->estado);
};

/* Ingresa el proceso al Scheduler en el primer espacio libre que
encuentre*/
void ingresaProceso()
{
    if (push() == TRUE)
    {
        printf("Proceso ingresado correctamente.\n");
    }
    else
    {
        printf("Scheduler lleno. No se puede ingresar el proceso.\n");
    }
}
/*Quita el proceso de la cola liberando y retornando el lugar
liberado*/

int terminaProceso()
{
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            asignaEstado(scheduling[i]);
        }
        printf("\n");
    }

    if (pop() == TRUE)
    {
        printf("Proceso terminado correctamente.\n");
        return TRUE;
    }
    else
    {
        printf("No se pudo terminar el proceso.\n");
        return FALSE;
    }
}
/*Recorrera todos los procesos de la cola, haciendo el cambio del
estado de los mismos*/
void recorreCola()
{
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            // [index]-> {procesador;id;prioridad;estado}
            printf("[%d] -> {%d;%d;%d;%s}", i, scheduling[i]->procesador == -1 ? 0 : scheduling[i]->procesador, scheduling[i]->proceso, scheduling[i]->prioridad, scheduling[i]->estado);
        }
        printf("\n");
    }
};

/*Lista los procesos de la cola*/
void mostrarScheduler()
{
    printf("Mostrar Scheduler\n");
};

/*Lista los procesos registrados en el archivo*/
void listarFile()
{
    printf("Listar File\n");
};
