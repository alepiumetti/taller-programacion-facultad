#include <stdio.h>
#include "TAD_Cola.h"

int main(){
	tCola cola;
	int i;

	// 0 -> 4
	//ingreso 4 elementos (por el tammax que fue 5)
	//si ingreso mas de 5, sale el msj de COLA LLENA
	//lo mismo si saco 5 o +, pone COLA VACIA

	cola = inicializaCola();

	//COLOCAR

	for(i=1; i<=4; i++){
		push(&cola, i);
	}

	//Caso donde saco 2 elementos y inserto 2 elementos, probando la cola circular
	//por que si saco 2 elementos, salen los de la posicion 0 y 1
	// y al meter se pondran en la posicion 5 y 0 respectivamente

    pop(&cola);
	pop(&cola);
	push(&cola, 50);
	push(&cola, 100);

	//QUITAR

	for(i=1; i<=4; i++){
		printf("%d\n", pop(&cola));
	}

	return 0;
}
