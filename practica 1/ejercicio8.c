#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef enum
{
    MAYUSCULAS,
    MINUSCULAS
} may_min;

int strLargo(const char *origen); // Cantidad de caracteres
int strVacio(const char *origen); // retorna 1 si tiene al menos un caracter , 0 en otro caso

void strCopia(char *destino, const char *origen); // Copiador

/* prototipo modificado para permitir argumentos de tipo
string literales , en casi todos los compiladores un literal string es considerado una constante ,
o sea la ´ofuncin no ´ıpodra modificarlos pero , en algunos compiladores tales como GCC es
posible modificarlos (´usegn K&R el comportamiento es indefinido )*/

char *reverse(char *string); // retorna una cadena que es string invertida

void strIzq(char *destino, const char *origen); // Saca blancos Izq .

void strDer(char *destino, const char *origen); // Saca blancos Der

void strAmbos(char *destino, const char *origen); // Saca blancos Izq . y Der .

void strMayMin(char *destino, const char *origen, may_min m); // Convierte May. Min.

int main()
{
    char *text1 = " Sera Cierto ?? ";
    // char *text1 = "   ";
    int largo = strLargo(text1) + 1;
    char *result = (char *)malloc(largo);
    char *reves;
    if (result == NULL)
    return -1; // sino pudo reservar memoria para result
    printf(" La cadena : ");
    puts(text1);
    printf(" Se encuentra : %s \n ", (strVacio(text1) ? " No vacia "
                                                      : " Vacia "));
    printf(" Largo : %d \n ", strLargo(text1));
    strCopia(result, text1);
    printf(" Copia : [ %s ]\n ", result);
    strIzq(result, text1);
    printf(" Sin blancos a la Izq : ");
    puts(result);
    strDer(result, text1);
    printf(" Der : [ %s ]\n ", result);
    strAmbos(result, text1);
    printf(" Ambos : [ %s ] , sin blancos al principio ni al final.\n ", result);
    strMayMin(result, text1, MAYUSCULAS);
    printf(" Mayusculas : [ %s ]\n ", result);
    strMayMin(result, text1, MINUSCULAS);
    printf(" Minusculas : [ %s ]\n ", result);
    reves = reverse(text1);
    printf(" La cadena : %s invertida queda : %s \n ", text1, reves);
    
    return 0;
}

int strLargo(const char *origen){
    int i = 0, acumulador = FALSE;
    while ( *(origen + i) != '\0'  )
    {
        i++;
        acumulador++;
    }
    return acumulador;
}

int strVacio(const char *origen){
    int i = 0, esVacio = 0;
    while ( *(origen + i) != '\0' && (*(origen + i) == ' ' || *(origen + i) == '\n') )
    {
        i++;
        if( *(origen + i) != ' ' && *(origen + i) != '\n' && *(origen + i) != '\0' ){
            esVacio = TRUE;
        }
    }
    return esVacio;
}

void strCopia(char *destino, const char *origen){

    int i = 0;
    while ( *(origen + i) != '\0'  )
    {
        *(destino + i) = *(origen + i); // Por que se tiene que guardar asi y no se puede de la siguiente manera
        i++;
    }

} // Copiador


char *reverse(char *string){
    int largo = strLargo(string);

    int index = largo;
    char reversed[largo];

    while ( index != 0  )
    {
        printf("char: %c\n",*( string + index ));
        printf("reversed char: %c\n",*( reversed + index ));

        reversed[index] = *( string + index );
        index --;
    }

    reversed[largo] = '\0';

    return reversed;
} // retorna una cadena que es string invertida

void strIzq(char *destino, const char *origen){

} // Saca blancos Izq .

void strDer(char *destino, const char *origen){

} // Saca blancos Der

void strAmbos(char *destino, const char *origen){

} // Saca blancos Izq . y Der .

void strMayMin(char *destino, const char *origen, may_min m){

} // Convierte May. Min.
