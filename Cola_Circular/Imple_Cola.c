#include "TAD_Cola.h"
#include <stdio.h>

tCola inicializaCola(){
	tCola cola;
	cola.ini = cola.fin = 0;
	return cola;
}

// SI LA COLA ESTA VACIA...

int SiEstaVacia(tCola cola){
	return cola.ini == cola.fin;
}

// SI LA COLA ESTA LLENA o no.. (else)

int SiEstaLlena(tCola cola){
	if(cola.fin == TAMMAX - 1 && cola.ini == 0)
		return 1;
	else
		return cola.fin == cola.ini - 1;
}

//PUSH por si no esta llena donde se puede insertar

void push(tCola *cola, int elemento){
	if(!SiEstaLlena(*cola)){
		cola->lis[cola->fin] = elemento;
		if(cola->fin == TAMMAX - 1)
			cola->fin = 0;
		else
			cola->fin = cola->fin + 1;
	}
	else
		printf("Cola llena.\n");
}

//POP lo mismo que PUSH, preguntando si esta vacia, guardamos elemento y analizamos casos y quitamos

int pop(tCola *cola){
	int elemento;

	if(!SiEstaVacia(*cola)){
		elemento = cola->lis[cola->ini];
		if(cola->ini == TAMMAX - 1)
			cola->ini = 0;
		else
			cola->ini = cola->ini + 1;

		return elemento;
	}

	else{
		printf("Cola vacia.\n");
		return -1;
	}
}
