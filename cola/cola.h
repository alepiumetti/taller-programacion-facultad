#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Definición de los tipos de datos

typedef struct Nodo{
    int info;
    struct Nodo* siguiente;  
}nodo;

typedef struct Nodo *pnodo;
pnodo primero, ultimo;
int n;

// prototipos

void menu();
void insertar(pnodo*, pnodo*, int);
void listar();
void eliminar(pnodo*, pnodo*);
