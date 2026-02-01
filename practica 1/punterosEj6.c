#include <stdio.h>

int main(){

    int i = 5, j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char x = 'a', pal[] = "texto en c";
    int *pi = &i;
    int *pj = j;
    char *pc;

    printf("Por variable: 'i' | Valor: %d | Direccion: %p\n",i,&i);
    printf("Por puntero: 'pi' | Valor: %d | Direccion: %p\n",*pi,&pi);
    printf("Por variable: 'j[0]' | Valor: %d | Direccion: %p\n",j[0],j);
    printf("Por puntero: 'pi (=j) +0' | Valor: %d | Direccion: %p\n",*pj,pj);
    printf("Por variable: 'j[1]' | Valor: %d | Direccion: %p\n",j[1],j + 1);
    printf("Por puntero: 'pi (=j) +1' | Valor: %d | Direccion: %p\n",*(pj + 1),pj + 1);
    printf("Por variable: 'j[9]' | Valor: %d | Direccion: %p\n",j[9],j + 9);
    printf("Por puntero: 'pi (=j) +9' | Valor: %d | Direccion: %p\n",*(pj + 9),pj + 9);
    pc = &x;
    printf("Por variable: 'x' | Valor: %c | Direccion: %p\n",x,&x);
    printf("Por puntero: 'pc' | Valor: %c | Direccion: %p\n",*pc,pc);
    return 0;
}