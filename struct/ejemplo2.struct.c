#include <stdio.h>


typedef struct contacto { 
    char *nombre;
    char *apellido;
    int telefono;
} Contacto;

void mostrar (Contacto);

int main (void) {
    
    
    Contacto alejandro;
    
    alejandro.nombre = "Alejandro";
    alejandro.apellido = "Pedrin";
    alejandro.telefono = 1234321;
    
    printf("%s\n",alejandro.nombre);
    printf("%s\n",alejandro.apellido);
    printf("%d\n",alejandro.telefono);
    
    mostrar(alejandro);

    

    return 0;
}

void mostrar (Contacto c){

}