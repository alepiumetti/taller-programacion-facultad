#include <stdio.h>
#include <string.h>

int main() {
    char saludo[30] = "Hola"; // Búfer con suficiente espacio
    char nombre[] = "Mundo";
    
    // Concatenar de forma segura
    strncat(saludo, ", ", sizeof(saludo) - strlen(saludo) - 1);
    strncat(saludo, nombre, sizeof(saludo) - strlen(saludo) - 1);
    
    printf("Cadena concatenada: '%s'\n", saludo); // Salida: 'Hola, Mundo'

    // Copiar de forma segura
    char destino[20];
    strncpy(destino, saludo, sizeof(destino) - 1);
    
    // ¡MUY IMPORTANTE! strncpy no garantiza el terminador nulo si la fuente es más grande.
    // Hay que asegurarlo manualmente.
    destino[sizeof(destino) - 1] = '\0';
    
    printf("Cadena copiada: '%s'\n", destino); // Salida: 'Hola, Mundo'

    return 0;
}