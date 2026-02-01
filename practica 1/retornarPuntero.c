// Escribir una funci´on que tome como argumento un entero positivo entre 1 y 7
// y retorne un puntero a cadena con el nombre del d´ıa de la semana correspondiente
// al argumento. Probar dicha funci´on.
#include <stdio.h>


char * dias(input)
{
    switch (input)
    {
    case 0:
        return "Lunes";
    case 1:
        return "Martes";
    case 3:
        return "Miercoles";
    case 4:
        return "Jueves";
    case 5:
        return "Viernes";
    case 6:
        return "Sabado";
    case 7:
        return "Domingo";
    default:
        break;
    }
}

int main() {

    int input;

    do
    {
        printf("Ingrese un entero entre 1 y 7: ");
        scanf("%d", &input);
    } while (input < 1 || input > 7);

    char * dia = dias(input);

    printf("El nro ingresado es: %d | La direccion es: %p | El dia es: %c \n",input,dia,*dia);

    return 0;
}