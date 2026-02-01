void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pausa()
{
    printf("\nPresione Enter para continuar...\n");
    getchar();
}

int push()
{
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        printf("Buscando espacio en índice %d...\n", i);
        if (scheduling[i] == NULL)
        {
            scheduling[i] = malloc(sizeof(proceso));
            asignaEstado(scheduling[i]);
            scheduling[i]->procesador = -1;
            scheduling[i]->proceso = NEW_ID;
            scheduling[i]->prioridad = priority;
            ADD_PRIORITY;
            printf("Se agregó un nuevo proceso en el índice %d con ID %d y prioridad %d.\n", i, scheduling[i]->proceso, scheduling[i]->prioridad);
            return TRUE;
        }
    }
    return FALSE;
}

int procesadorLibre()
{

    int index = 0;
    int cantidadCorriendo = 0;

    while (scheduling[index] != NULL && index < SIZE_SCHEDULER && cantidadCorriendo < 2)
    {
        printf("Revisando índice %d | Proceso en estado %s...\n", index, scheduling[index]->estado);
        if (strcmp(scheduling[index]->estado, "Corriendo") == 0)
        {
            cantidadCorriendo += 1;
        }
        index += 1;
    }

    return cantidadCorriendo < 2 ? TRUE : FALSE;
}

void asignaProcesador (proceso * proceso){

// TODO: Asignar un procesador libre al proceso haciendo el módulo 2 del ID del proceso +1 , resultando en 1 o 2. 
    
}

/*


int buscar(char *nombre)
{
    for (int i = 0; i < 6; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (strcmp(scheduling[i]->nombre, nombre) == 0)
            {
                printf("encontro el nombre: %s con el nro: %d \n", scheduling[i]->nombre, agenda[i]->nro);

                return 0;
            }
        }
    }

    return 1;
}
*/

int pop()
{
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (strcmp(scheduling[i]->estado, "Terminado") == 0)
            {
                free(scheduling[i]);
                printf("Se elimino el proceso con el id %d\n", scheduling[i]->proceso);
            }
        }
    }
    return 0;
}
