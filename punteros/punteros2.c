#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap2(int x, int y) {
    int temp = x;
    x = y;
    y = temp;

    printf("Funcion swap sin pasar punteos: a = %d, b = %d\n", x, y);
}

int main() {
    int a = 5;
    int b = 10;
    
    printf("Antes del swap: a = %d, b = %d\n", a, b);
    swap(&a, &b); // llamada a funcion por referencia 
    swap2(a,b); // lamada a funcion por valor
    printf("Despues del swap: a = %d, b = %d\n", a, b);

    return 0;
}