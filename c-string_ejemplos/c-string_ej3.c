#include <stdio.h>
#include <string.h>

int main() {
    char nombre_usuario[50]; // Búfer de 50 bytes

    printf("Por favor, introduce tu nombre completo: ");

    // fgets lee hasta un máximo de sizeof(nombre_usuario) - 1 caracteres.
    // Siempre añade un '\0' y es seguro contra desbordamientos.
    // Lee desde la entrada estándar (stdin).
    if (fgets(nombre_usuario, sizeof(nombre_usuario), stdin) != NULL) {
        
        // Un problema común: fgets() también almacena el salto de línea (\n) si hay espacio.
        // Lo buscamos y lo eliminamos.
        size_t len = strlen(nombre_usuario);
        if (len > 0 && nombre_usuario[len - 1] == '\n') {
            nombre_usuario[len - 1] = '\0'; // Lo reemplazamos con el terminador nulo
        }

        printf("¡Hola, %s! Bienvenido.\n", nombre_usuario);
    }

    return 0;
}