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

    scheduling[fin] = malloc(sizeof(proceso));
    asignaEstado(scheduling[fin], fin);
    scheduling[fin]->procesador = 0;
    scheduling[fin]->proceso = NEW_ID;
    scheduling[fin]->prioridad = priority;
    ADD_PRIORITY;
    printf("Se agregó un nuevo proceso en el índice %d con ID %d y prioridad %d.\n", fin, scheduling[fin]->proceso, scheduling[fin]->prioridad);
    addFin();

    return TRUE;
}

/*
Busca los procesos que están corriendo y busca si hay procesadores libres para asignarles, si no hay procesadores libres.
*/

int procesadorLibre()
{

    if (cpu1 == -1 && cpu2 == -1)
    {
        return 2;
    }
    else if (cpu1 != -1 && cpu2 != -1)
    {
        return 0;
    }
    else
    {
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

    int tempInicio = inicio;
    int cantidadProcesos = getTamanoScheduler();
    int revisados = 0;

    do
    {
        if (scheduling[tempInicio] != NULL && strcmp(scheduling[tempInicio]->estado, "Terminado") == 0)
        {

            char tempEstado[SIZE_NOMBRE_ESTADO];
            strcpy(tempEstado, scheduling[tempInicio]->estado);
            int tempProceso = scheduling[tempInicio]->proceso;

            int archivoEscrito = fprintf(archivo, "[%d] -> {%d;%d;%d;%s}\n", tempInicio, scheduling[tempInicio]->procesador == -1 ? 0 : scheduling[tempInicio]->procesador, scheduling[tempInicio]->proceso, scheduling[tempInicio]->prioridad, scheduling[tempInicio]->estado);
            if (archivoEscrito < 0)
            {
                printf("Error al escribir en el archivo.\n");
                fclose(archivo);
                return FALSE;
            }
            free(scheduling[tempInicio]);
            scheduling[tempInicio] = NULL; // Para limpiar el espacio en la cola, se asigna NULL al índice correspondiente
            // Sumo uno al inicio para mantener la coherencia de la cola
            // Agrego 1 al tempInicio para seguir manipulando los datos correctamente
            tempInicio = addInicio();

            printf("Se elimino el proceso con el id %d\n", tempProceso);
            printf("Archivo escrito: %d bytes\n", archivoEscrito);
        }
        else
        {
            tempInicio += 1;
            if (tempInicio >= SIZE_SCHEDULER)
            {
                tempInicio = 0;
            }
        }

        revisados++;

    } while (revisados < cantidadProcesos);
    fclose(archivo);
    return TRUE;
}

int abreArchivo()
{

    archivo = fopen(FILE_NAME, "a+");

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
            tamano++;
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