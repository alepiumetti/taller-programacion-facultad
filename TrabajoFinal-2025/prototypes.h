
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// srand(time(NULL));

#define SIZE_NOMBRE_ESTADO 15
#define SIZE_SCHEDULER 10
#define ADD_PRIORITY priority += 1;
#define NEW_ID rand() % 10000;
#define SIN_ASIGNAR -1;
#define TRUE 0
#define FALSE 1

#define CLEAR_CONSOLE system("clear")

typedef struct proceso
{
    int procesador;
    int proceso;
    int prioridad;
    char estado[SIZE_NOMBRE_ESTADO];
} proceso;

static int id = 0;
int priority = 0;

proceso *scheduling[SIZE_SCHEDULER];

int pop();
int push();

void asignaEstado(proceso *);
void ingresaProceso();
int terminaProceso();
void recorreCola();
void mostrarScheduler();
void listarFile();
int procesadorLibre();
void asignaProcesador(proceso *);
void limpiar_buffer();