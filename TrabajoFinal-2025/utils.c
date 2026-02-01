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
        if (scheduling[i] == NULL)
        {
            scheduling[i] = malloc(sizeof(proceso));
            asignaEstado(scheduling[i]);
            scheduling[i]->procesador = -1;
            scheduling[i]->proceso = NEW_ID;
            ADD_PRIORITY;
            scheduling[i]->prioridad = priority;
            return TRUE;
        }
    }
    return FALSE;
}

int procesadorLibre()
{

    int index = 0;
    int cantidadCorriendo = 0;

    while (strcmp(scheduling[index]->estado, "Corriendo") != 0 && index < SIZE_SCHEDULER && cantidadCorriendo < 2)
    {
        if (strcmp(scheduling[index]->estado, "Corriendo") == 0)
        {
            cantidadCorriendo += 1;
        }
    }

    return cantidadCorriendo < 2 ? TRUE : FALSE;
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
