/*

TRABAJO FINAL 2025
ALEJANDRO PIUMETTI
COMISION 2

*/

#include "./prototypes.h"
#include "./utils.h"

int main()
{
    char opcion = 'I';
    do
    {
        CLEAR_CONSOLE;
        printf("===== SCHEDULER DE PROCESOS =====\n");
        printf("\n");
        printf(" Procesos en Scheduler: %d | Inicio: %d | Fin: %d | Tamaño Scheduler %d\n", getTamanoScheduler(), inicio, fin, getTamanoScheduler());
        printf("Procesadores disponibles: %d | CPU1: %s (%d) | CPU2: %s (%d)\n", procesadorLibre(), cpu1 == -1 ? "Libre" : "Ocupado", cpu1, cpu2 == -1 ? "Libre" : "Ocupado", cpu2);
        printf("\n");
        printf("(I)ngresa proceso | (T)ermina proceso | (R)ecorre cola | (M)ostrar Scheduler | (L)istar File | (G)uardar y Salir | (S)alir: ");
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
        if (opcion != 'S' && opcion != 'G')
        {
            pausa();
        }

    } while (opcion != 'S' && opcion != 'G');

    if (opcion == 'S')
    {
        if (remove(FILE_NAME) == 0)
        {
            printf("Programa terminado con éxito y el archivo '%s' ha sido eliminado.\n", FILE_NAME);
        }
        else
        {
            printf("Programa terminado con error\n Error al eliminar archivo '%s'.\n", FILE_NAME);
            return 1;
        }
    }
    else
    {
        printf("Programa terminado con éxito y el archivo '%s' ha sido guardado.\n", FILE_NAME);
        return 0;
    }
}

/* Asigna el siguiente estado según el orden Nuevo->Listo->Esperando->Corriendo->Terminado */
void asignaEstado(proceso *pproceso, int i)
{

    if (strcmp(pproceso->estado, "Terminado") == 0)
    {
        printf("El proceso está terminado. No se puede cambiar su estado.\n");
        return;
    }

    if (strcmp(pproceso->estado, "Nuevo") == 0)
    {
        strcpy(pproceso->estado, "Listo");
    }
    else if (strcmp(pproceso->estado, "Listo") == 0)
    {
        strcpy(pproceso->estado, "Esperando");
    }
    else if (strcmp(pproceso->estado, "Esperando") == 0)
    {

        if (cpu1 != -1 && cpu2 != -1)
        {
            printf("No hay procesadores libres. El proceso permanecerá en estado 'Esperando'.\n");
            return;
        }
        // Antes de hacer el cambio de estado a "Corriendo" se verifica el proceso con la prioridad más baja.
        // int prioritario = buscaProcesoPrioritario();

        if (cpu1 == -1)
        {
            cpu1 = pproceso->proceso;
            pproceso->procesador = 1;
            strcpy(pproceso->estado, "Corriendo");
        }
        else if (cpu2 == -1)
        {
            cpu2 = pproceso->proceso;
            pproceso->procesador = 2;
            strcpy(pproceso->estado, "Corriendo");
        }
    }
    else if (strcmp(pproceso->estado, "Corriendo") == 0)
    {
        strcpy(pproceso->estado, "Terminado");
        pproceso->procesador = -1;
        if (cpu1 == pproceso->proceso)
        {
            cpu1 = -1;
        }
        else if (cpu2 == pproceso->proceso)
        {
            cpu2 = -1;
        }
    }
    else
    {
        strcpy(pproceso->estado, "Nuevo");
    }

    printf("[%d] -> El nuevo estado del proceso %d es: %s\n", i, pproceso->proceso, pproceso->estado);
}

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

int terminaProceso()
{
    if (getTamanoScheduler() == 0)
    {
        printf("No hay procesos para terminar.\n");
        return FALSE;
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

/*Recorrerá todos los procesos de la cola, haciendo el cambio del estado de los mismos*/

void recorreCola()
{
    int cantidadProcesos = getTamanoScheduler();
    if (cantidadProcesos == 0)
    {
        printf("No hay procesos en el scheduler para recorrer.\n");
        return;
    }

    int tempInicio = inicio;
    int procesados = 0;

    while (procesados < cantidadProcesos)
    {
        if (scheduling[tempInicio] != NULL)
        {
            asignaEstado(scheduling[tempInicio], tempInicio);
            procesados++;
        }

        tempInicio += 1;
        if (tempInicio >= SIZE_SCHEDULER)
        {
            tempInicio = 0;
        }
    }
}
/*Lista los proceso de la cola */
void mostrarScheduler()
{
    int cantidadProcesos = getTamanoScheduler();
    if (cantidadProcesos == 0)
    {
        printf("No hay procesos en el scheduler.\n");
        return;
    }

    int tempInicio = inicio;
    int mostrados = 0;
    while (mostrados < cantidadProcesos)
    {
        if (scheduling[tempInicio] != NULL)
        {
            printf("[%d] -> {%d;%d;%d;%s}", tempInicio, scheduling[tempInicio]->procesador == -1 ? 0 : scheduling[tempInicio]->procesador, scheduling[tempInicio]->proceso, scheduling[tempInicio]->prioridad, scheduling[tempInicio]->estado);
            printf("\n");
            mostrados++;
        }

        tempInicio += 1;
        if (tempInicio >= SIZE_SCHEDULER)
        {
            tempInicio = 0;
        }
    }
}

/*Lista los procesos registrados en el archivo*/
void listarFile()
{

    if (abreArchivo() == FALSE)
    {
        printf("No se pudo abrir el archivo para listar los procesos terminados.\n");
        return;
    }

    char linea[100];
    printf("Procesos terminados:\n");
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        printf("%s", linea);
    }
    fclose(archivo);
}
