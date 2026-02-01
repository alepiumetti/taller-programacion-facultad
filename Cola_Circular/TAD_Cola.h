#ifndef TAD_COLA_H
#define TAD_COLA_H
#define TAMMAX 5

typedef struct {
	int lis[TAMMAX];
	int ini, fin;
}tCola;

tCola inicializaCola();
int SiEstaVacia(tCola cola);
int SiEstaLlena(tCola cola);
void push(tCola *cola, int elemento);
int pop(tCola *cola);
#endif
