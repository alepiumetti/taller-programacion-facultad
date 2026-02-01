#include <stdio.h>

int main () {

    int i = 10;
    int *pi = &i; // Referencia de pi a i 

    printf("%d\n",*pi); // Desreferencia de pi para que muestre valor de i


    *pi = 20;

    printf("%d\n",i);

    return 0;
}