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

    if (getTamanoScheduler() == SIZE_SCHEDULER)
    {
        return FALSE;
    }

    addFin();

    scheduling[fin] = malloc(sizeof(proceso));
    asignaEstado(scheduling[fin]);
    scheduling[fin]->procesador = -1;
    scheduling[fin]->proceso = NEW_ID;
    scheduling[fin]->prioridad = priority;
    ADD_PRIORITY;
    printf("Se agregó un nuevo proceso en el índice %d con ID %d y prioridad %d.\n", fin, scheduling[fin]->proceso, scheduling[fin]->prioridad);

    return TRUE;
}

int procesadorLibre()
{

    int index = 0;
    int cantidadCorriendo = 0;
    int procesadorLibre = 0;

    while (scheduling[index] != NULL && index < SIZE_SCHEDULER && cantidadCorriendo < 2)
    {
        if (strcmp(scheduling[index]->estado, "Corriendo") == 0)
        {
            cantidadCorriendo += 1;
            procesadorLibre += scheduling[index]->procesador;
        }
        index += 1;
    }

    switch (procesadorLibre)
    {
    case 3: // En caso de que ambos procesadores están ocupados, se retorna FALSE
        return 0;
    case 1: // En caso de que el procesador 1 está ocupado, se asigna el procesador 2
        return 2;
    case 2: // En caso de que el procesador 2 está ocupado, se asigna el procesador 1
        return 1;
    default: // En caso de que ambos procesadores están libres, se asigna el procesador 1
        return 1;
    }
}

int buscaProcesoPrioritario()
{
    int menor = 999999;
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (strcmp(scheduling[i]->estado, "Esperando") == 0 && scheduling[i]->prioridad < menor)
            {
                menor = scheduling[i]->prioridad;
            }
        }
    }
    return menor;
}

int pop()
{

    if (abreArchivo() == FALSE)
    {
        printf("No se pudo abrir el archivo para guardar el proceso terminado.\n");
        return FALSE;
    }

    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (strcmp(scheduling[i]->estado, "Terminado") == 0)
            {
                int archivoEscrito = fprintf(archivo, "[%d] -> {%d;%d;%d;%s}", i, scheduling[i]->procesador == -1 ? 0 : scheduling[i]->procesador, scheduling[i]->proceso, scheduling[i]->prioridad, scheduling[i]->estado);
                if (archivoEscrito < 0)
                {
                    printf("Error al escribir en el archivo.\n");
                    fclose(archivo);
                    return FALSE;
                }
                free(scheduling[i]);
                // addInicio();
                printf("Se elimino el proceso con el id %d\n", scheduling[i]->proceso);
                printf("Archivo escrito: %d bytes\n", archivoEscrito);
            }
        }
    }
    fclose(archivo);
    return TRUE;
}

int abreArchivo()
{
    archivo = fopen("tareas_finalizadas.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return FALSE;
    }

    return TRUE;
}

int getTamanoScheduler()
{
    int tamano = 0;
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            tamano += 1;
        }
    }
    return tamano;
}

int getInicio()
{
    for (int i = 0; i < SIZE_SCHEDULER; i++)
    {
        if (scheduling[i] != NULL)
        {
            return i;
        }
    }
    return -1;
}

int getFin()
{
    for (int i = SIZE_SCHEDULER - 1; i >= 0; i--)
    {
        if (scheduling[i] != NULL)
        {
            return i;
        }
    }
    return -1;
}

int addFin()
{

    if (getTamanoScheduler() == SIZE_SCHEDULER)
    {
        return -1;
    }

    fin += 1;
    if (fin >= SIZE_SCHEDULER)
    {
        fin = 0;
    }
    return fin;
}

int addInicio()
{
    inicio += 1;
    if (inicio >= SIZE_SCHEDULER)
    {
        inicio = 0;
    }
    return inicio;
}