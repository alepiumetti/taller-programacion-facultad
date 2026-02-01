#include <stdio.h>

typedef int sopa;

struct contacto { 
    char *nombre;
    char *apellido;
    int telefono;
} pedro;

int main (void) {

    sopa nuevoEntero = 55;

    printf("sopa: %d\n",nuevoEntero);

    struct contacto alejandro;
    
    alejandro.nombre = "Alejandro";
    pedro.nombre = "Pedro";
    alejandro.apellido = "Pedrin";
    pedro.apellido = "Piumetti";
    alejandro.telefono = 1234321;
    pedro.telefono = 32152;

    printf("%s\n",pedro.nombre);
    printf("%s\n",pedro.apellido);
    printf("%d\n",pedro.telefono);
    printf("%s\n",alejandro.nombre);
    printf("%s\n",alejandro.apellido);
    printf("%d\n",alejandro.telefono);

    return 0;
}