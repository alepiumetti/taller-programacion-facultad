/*

PARCIAL 06-11-2025
ALEJANDRO PIUMETTI
COMISION 2

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Dados las siguientes definiciones y prototipos

#define SIZE_NOMBRE_ESTADO 15

#define CLEAR_CONSOLE system("clear")

void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

typedef struct
{
    char nombre[SIZE_NOMBRE_ESTADO];
    int nro;
} persona;

// Se pretende programar una agenda
persona *agenda[6] = {NULL};

int buscar(char *);
int pop(char *);
int push(char *, int);

int main()
{

    char opcion = 'I';

    do
    {
        printf("\n");
        printf("(I)nsertar | (B)uscar | (E)liminar| (T)erminar: ");
        opcion = toupper(getchar());

        limpiar_buffer();
        switch (opcion)
        {
        case 'I':
            char *nombre = malloc(sizeof(nombre) * SIZE_NOMBRE_ESTADO);
            if (nombre == NULL)
            {
                printf("Error al obtener memoria\n");
            }

            printf("Ingrese el nombre que quiere agendar: ");
            fgets(nombre, SIZE_NOMBRE_ESTADO, stdin);

            size_t len_insertar = strlen(nombre);
            if (len_insertar > 0 && nombre[len_insertar - 1] == '\n')
            {
                nombre[len_insertar - 1] = '\0';
            }

            printf("Ingrese el numero de telefono de %s: ", nombre);
            int telefono = 0;
            scanf("%d", &telefono);
            limpiar_buffer();

            if (push(nombre, telefono) == 0)
            {
                printf("El contacto %s fue guardado con el numero %d\n", nombre, telefono);
            }
            else
            {
                printf("No tiene mas lugar en la agenda");
            };
            free(nombre);

            break;
        case 'E':
            char *eliminar_nombre = NULL;
            eliminar_nombre = malloc(sizeof(eliminar_nombre) * SIZE_NOMBRE_ESTADO);
            printf("Ingrese el nombre de la persona que quiere eliminar: ");
            fgets(eliminar_nombre, SIZE_NOMBRE_ESTADO, stdin);
            size_t len_eliminar = strlen(eliminar_nombre);
            if (len_eliminar > 0 && eliminar_nombre[len_eliminar - 1] == '\n')
            {
                eliminar_nombre[len_eliminar - 1] = '\0';
            }
            pop(eliminar_nombre);

            free(eliminar_nombre);

            break;
        case 'T':

            break;
        case 'B':
            char *buscar_nombre = NULL;
            buscar_nombre = malloc(sizeof(buscar_nombre) * SIZE_NOMBRE_ESTADO);
            printf("Ingrese el nombre de la persona que quiere buscar: ");
            fgets(buscar_nombre, SIZE_NOMBRE_ESTADO, stdin);
            size_t len = strlen(buscar_nombre);
            if (len > 0 && buscar_nombre[len - 1] == '\n')
            {
                buscar_nombre[len - 1] = '\0';
            }
            if (buscar(buscar_nombre) != 0)
            {
                printf("La persona %s NO fue encontrada\n", buscar_nombre);
            };

            free(buscar_nombre);
            break;

        default:
            break;
        }

    } while (opcion != 'T');
    return 0;
}

int push(char *nombre, int nro)
{
    for (int i = 0; i < 6; i++)
    {
        if (agenda[i] == NULL)
        {
            agenda[i] = malloc(sizeof(persona));
            strcpy(agenda[i]->nombre, nombre);
            agenda[i]->nro = nro;
            return 0;
        }
    }
    return 1;
}

int buscar(char *nombre)
{
    for (int i = 0; i < 6; i++)
    {
        if (agenda[i] != NULL)
        {
            if (strcmp(agenda[i]->nombre, nombre) == 0)
            {
                printf("encontro el nombre: %s con el nro: %d \n", agenda[i]->nombre, agenda[i]->nro);

                return 0;
            }
        }
    }

    return 1;
}

int pop(char *nombre)
{
    for (int i = 0; i < 6; i++)
    {
        if (agenda[i] != NULL)
        {
            if (strcmp(agenda[i]->nombre, nombre) == 0)
            {

                printf("Se elimino el contacto %s con el numero %d\n", agenda[i]->nombre, agenda[i]->nro);
                free(agenda[i]);
                return 0;
            }
        }
    }
    return 1;
}

/**
Implementar una agenda, la cual guardará personas.
a) Esta formada por un arreglo de estructuras persona.
b) La función buscar recibe el nombre de la persona y recorrerá a la agenda, si encuentra a la
persona la muestra por pantalla y retorna 0 como OK. Cualquier otro numero como error o registro
no encontrado.
c) Pop elimina a la persona, si es que existe en la agenda (antes muestra los datos por pantalla)
retorna 0 si la operacion se realizó correctamente cualquier otro valor para cualquier otro error.
d) push inserta, alocando previamente la memoria, una persona en la agenda.
Los parametros de entrada son el nombre y la edad respectivamente.
Retorna 0 en caso que el insert sea correcto, y cuaquier otro valor en caso de cualquier otro error.

*/
