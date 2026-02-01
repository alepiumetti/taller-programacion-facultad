#include <stdio.h>
#include <string.h>

int main() {
    // OJO: Usamos un arreglo, no un puntero a un literal, porque strtok() lo modificará.
    char csv_data[] = "Juan,Perez,42,Rosario";
    const char delimitador[] = ",";

    // La primera llamada a strtok() requiere la cadena.
    char* token = strtok(csv_data, delimitador);

    printf("Datos desglosados:\n");
    while (token != NULL) {
        printf(" - %s\n", token);
        
        // Las llamadas siguientes usan NULL para continuar desde donde se quedó.
        token = strtok(NULL, delimitador);
    }

    return 0;
}