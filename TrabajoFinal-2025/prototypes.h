
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
#define IS_DEBUG 0
#define FILE_NAME "tareas_finalizadas.txt"

#define CLEAR_CONSOLE system("clear")

typedef struct Proceso
{
    int procesador;
    int proceso;
    int prioridad;
    char estado[SIZE_NOMBRE_ESTADO];
} proceso;

// static int id = 0;
int priority = 0;

int inicio = 0;
int fin = 0;

int cpu1 = -1;
int cpu2 = -1;

proceso *scheduling[SIZE_SCHEDULER];

FILE *archivo;

int pop();
int push();
int getTamanoScheduler();
int getInicio();
int getFin();
int addFin();
int addInicio();

void asignaEstado(proceso *, int i);
void ingresaProceso();
int terminaProceso();
void recorreCola();
void mostrarScheduler();
void listarFile();
int procesadorLibre();
void limpiar_buffer();
int buscaProcesoPrioritario();
int abreArchivo();