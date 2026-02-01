#include <stdio.h>
#include <string.h>

int main() {
    // El arreglo tiene espacio para 19 caracteres + el terminador nulo '\0'
    char mi_ciudad[20] = "Rosario";

    // strlen() cuenta los caracteres HASTA encontrar el '\0'.
    size_t longitud = strlen(mi_ciudad);

    // sizeof() devuelve el tamaño total en bytes del arreglo, sin importar su contenido.
    size_t tamano_buffer = sizeof(mi_ciudad);

    printf("Cadena: '%s'\n", mi_ciudad);
    printf("La longitud de la cadena (strlen) es: %zu\n", longitud);         // Salida: 7
    printf("El tamaño del búfer (sizeof) es: %zu bytes\n", tamano_buffer); // Salida: 20

    return 0;
}
