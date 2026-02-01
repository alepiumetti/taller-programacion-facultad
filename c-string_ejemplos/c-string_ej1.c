#include <stdio.h>
#include <string.h> // Necesario para las funciones de strings

int main() {
    char nombre[20] = "Juan"; // Deja espacio extra para modificaciones
    char apellido[] = " Pérez";

    // 1. Calcular la longitud (no incluye el \0)
    printf("Longitud del nombre: %zu\n", strlen(nombre)); // Salida: 4

    // 2. Concatenar (añadir) una cadena a otra
    // strncat es más seguro que strcat porque limita los bytes a añadir
    strncat(nombre, apellido, sizeof(nombre) - strlen(nombre) - 1);

    // 3. Imprimir la cadena completa
    printf("Nombre completo: %s\n", nombre); // Salida: Juan Pérez

    // 4. Comparar cadenas
    if (strcmp(nombre, "Juan Pérez") == 0) {
        printf("Los nombres son iguales.\n");
    }

    return 0;
}