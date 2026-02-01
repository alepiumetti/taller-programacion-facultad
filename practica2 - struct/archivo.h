void carga_datos (Archivo * archivo){

    archivo->nombre = malloc(MAX_NAME);

    if (archivo->nombre == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    printf("Ingrese el nombre del archivo: ");
    if (fgets(archivo->nombre, MAX_NAME, stdin) != NULL) {
        // Elimina el salto de línea final si existe
        size_t len = strlen(archivo -> nombre);
        if (len > 0 && archivo->nombre[len - 1] == '\n') {
            archivo->nombre[len - 1] = '\0';
        }
    }
    carga_tiempo(&archivo->ultima_mod,archivo->nombre);
}