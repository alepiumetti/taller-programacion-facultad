
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./types.h"
#include "./prototypes.h"
#include "./auxiliar.c"

int main()
{
    puntero_votante chicos_buenos, chicos_malos;
    chicos_buenos = NULL;
    chicos_malos = NULL;

    // carga_nombre(votante)
    char opcion = ' ';
    while (opcion != 'T')
    {
        clear();
        printf("Elija opcion \n (I)nsertar (E)liminar (L)istar (T)erminar: ");
        opcion = toupper(getchar());
        limpia_buffer();
        switch (opcion)
        {
        case 'I':
            puntero_votante nuevo_votante = malloc(sizeof(Votante));
            if (nuevo_votante == NULL)
            {
                printf("Memoria insuficiente...");
                exit(1);
            }

            carga_nombre(nuevo_votante);
            int voto = carga_voto(nuevo_votante);
            if (
                miembro(chicos_buenos, nuevo_votante->nombre) && voto == F)
            {
                printf("%s ya voto Favorable. No puede repetir el voto", nuevo_votante->nombre);
                free(nuevo_votante);
                pausa();
            }
            else if (
                miembro(chicos_malos, nuevo_votante->nombre) && voto == D)
            {
                printf("%s ya voto Desavorable. No puede repetir el voto", nuevo_votante->nombre);
                free(nuevo_votante);
                pausa();
            }
            else if (
                (miembro(chicos_buenos, nuevo_votante->nombre) && voto == D) || (miembro(chicos_malos, nuevo_votante->nombre) && voto == F))
            {
                printf("El voto de %s fue el contrario\n", nuevo_votante->nombre);
                char cambia_voto = ' ';
                while (cambia_voto != 'S' && cambia_voto != 'N')
                {
                    clear();
                    printf("Desea cambiar el voto?\n");
                    printf("(S) o (N): ");
                    cambia_voto = toupper(getchar());
                }

                if (cambia_voto == 'S')
                {
                    if (!voto)
                    { // Favorable
                        eliminar(nuevo_votante->nombre, &chicos_malos);
                        insertar(&chicos_buenos, nuevo_votante);
                    }
                    else
                    { // Desfavorable
                        eliminar(nuevo_votante->nombre, &chicos_buenos);
                        insertar(&chicos_malos, nuevo_votante);
                    }
                }
                else
                {
                    free(nuevo_votante);
                }
            }
            else
            {
                if (!voto)
                { // Favorable
                    insertar(&chicos_buenos, nuevo_votante);
                }
                else
                { // Desfavorable
                    insertar(&chicos_malos, nuevo_votante);
                }
            }

            break;
        case 'L':
            listar(chicos_buenos, "Chicos Buenos");
            listar(chicos_malos, "Chicos Malos");
            break;
        case 'E':

            char opcion_lista = ' ';
            while (opcion_lista != 'F' && opcion_lista != 'D')
            {
                clear();
                printf("Elija la lista de donde quiere eliminar un voto\n");
                printf("Chicos buenos (Votos favorables) -> F\n");
                printf("Chicos malos (Votos desfavorables) -> D\n");
                opcion_lista = (getchar());
            }

            if(opcion_lista == 'F'){
                listar(chicos_buenos, "Chicos buenos");
            }else{
                listar(chicos_malos, "Chicos malos");
            }

            char *nombre_a_buscar = malloc(MAX_NAME);
            if (nombre_a_buscar == NULL)
            {
                printf("Error al reservar memoria\n");
                return 1;
            }

            printf("Ingrese el nombre que quiere eliminar:");
            if (fgets(nombre_a_buscar, MAX_NAME, stdin) != NULL)
            {
                // Elimina el salto de línea final si existe
                size_t len = strlen(nombre_a_buscar);
                if (len > 0 && (nombre_a_buscar)[len - 1] == '\n')
                {
                    nombre_a_buscar[len - 1] = '\0';
                }

                for (size_t i = 0; i < len; ++i)
                {
                    unsigned char c = (unsigned char)nombre_a_buscar[i];
                    nombre_a_buscar[i] = (char)toupper(c);
                }
            }

            eliminar(nombre_a_buscar, &chicos_buenos);
            break;
        }
    }

    return 0;
}

void insertar(puntero_votante *lista, Votante *votante)
// Pasar el nombre y la lista y que se haga toda la logica de agregar aca.
{

    if (*lista == NULL)
    {
        printf("No hay ningun elemento\n");
        votante->siguiente = NULL;
    }
    else
    {
        votante->siguiente = *lista;
    };
    *lista = votante;
}

void carga_nombre(Votante *votante)
{

    votante->nombre = malloc(MAX_NAME);

    if (votante->nombre == NULL)
    {
        printf("Error al reservar memoria\n");
        return;
    }

    clear();
    printf("Ingrese el nombre del votante: ");
    if (fgets(votante->nombre, MAX_NAME, stdin) != NULL)
    {

        // Elimina el salto de línea final si existe
        size_t len = strlen(votante->nombre);
        if (len > 0 && votante->nombre[len - 1] == '\n')
        {
            votante->nombre[len - 1] = '\0';
        }

        for (size_t i = 0; i < len; ++i)
        {
            unsigned char c = (unsigned char)votante->nombre[i];
            votante->nombre[i] = (char)toupper(c);
        }
    }
}

int carga_voto(Votante *votante)
{
    clear();
    printf("Ingrese el voto de %s \n(F)avorable | (D)esfavorable : ", votante->nombre);
    char opcion = '0';
    while (opcion != 'F' && opcion != 'D')
    {
        opcion = toupper(getchar());
        limpia_buffer();
    }

    if (opcion == 'F')
    {
        return F;
    }
    else
    {
        return D;
    }
}

void listar(puntero_votante lista, char nombre_lista[])
{
    if (lista == NULL)
        printf("Cola vacia\n");
    else
    {
        printf("Contenido de la lista %s: \n", nombre_lista);
        while (lista != NULL)
        {
            printf("%s\n", lista->nombre);
            lista = lista->siguiente;
        }
        pausa();
    }
}

int miembro(puntero_votante lista, char *nombre_votante)
{
    // Devuelve 1 si encuentra un votante con el mismo nombre, 0 en caso contrario
    while (lista != NULL)
    {
        if (strcmp(lista->nombre, nombre_votante) == 0)
        {
            return 1; // encontrado
        }
        lista = lista->siguiente;
    }
    return 0; // no encontrado
}

void eliminar(char *nombre, puntero_votante *lista)
{
    if (lista == NULL || *lista == NULL)
    {
        printf(" La lista esta vacia \n ");
        pausa();
        return;
    }

    if (!strcmp((*lista)->nombre, nombre))
    { // elimino al primero
        printf("Elimino el primero \n");
        puntero_votante aux = (*lista);
        (*lista) = (*lista)->siguiente;
        free(aux->nombre);
        free(aux);
        printf(" Elimino a %s \n ", nombre);
        pausa();
        return;
    }

    puntero_votante actual = *lista;

    while (actual->siguiente != NULL && strcmp(actual->siguiente->nombre, nombre) != 0)
    {
        actual = actual->siguiente;
    }

    if (actual->siguiente == NULL)
    {
        printf("No existe el elemento a eliminar\n");
        pausa();
        return;
    }

    // if (strcmp(actual->siguiente->nombre, nombre))
    // {
    //     // if((*lista)->siguiente != NULL){
            puntero_votante aux = actual->siguiente;
            actual->siguiente = aux->siguiente;
            printf("Elimino a %s\n", nombre);
            free(aux->nombre);
            free(aux);
            pausa();
        // }else{
        //     free(*lista)
        // }
    // }

    return;
}