#include <stdio.h>
#include <string.h>

int main() {
    char frase[] = "El lenguaje C es un lenguaje potente.";
    char caracter_a_buscar = 'j';
    char subcadena_a_buscar[] = "lenguaje";
    
    // Buscar un carácter
    char* resultado_char = strchr(frase, caracter_a_buscar);
    
    if (resultado_char != NULL) {
        printf("Carácter '%c' encontrado en la posición: %ld\n", caracter_a_buscar, resultado_char - frase);
    } else {
        printf("Carácter '%c' no encontrado.\n", caracter_a_buscar);
    }

    // Buscar una subcadena
    char* resultado_sub = strstr(frase, subcadena_a_buscar);

    if (resultado_sub != NULL) {
        printf("Subcadena '%s' encontrada en la posición: %ld\n", subcadena_a_buscar, resultado_sub - frase);
        printf("El resto de la cadena desde ahí es: '%s'\n", resultado_sub);
    } else {
        printf("Subcadena '%s' no encontrada.\n", subcadena_a_buscar);
    }

    return 0;
}