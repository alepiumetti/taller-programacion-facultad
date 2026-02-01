/*
1 si *t1 es anterior a *t2
0 si *t1 es igual a *t2
-1 si *t1 es posterior a *t2
*/

int compara_tiempos(Tiempo *t1, Tiempo *t2)
{
   if (t1->anio != t2->anio)
        return (t1->anio > t2->anio) ? -1 : 1;
    if (t1->mes != t2->mes)
        return (t1->mes > t2->mes) ? -1 : 1;
    if (t1->dia != t2->dia)
        return (t1->dia > t2->dia) ? -1 : 1;
    if (t1->hora != t2->hora)
        return (t1->hora > t2->hora) ? -1 : 1;
    if (t1->minuto != t2->minuto)
        return (t1->minuto > t2->minuto) ? -1 : 1;
    if (t1->segundo != t2->segundo)
        return (t1->segundo > t2->segundo) ? -1 : 1;
    return 0;
}

//  "dia/mes/anio hora:minuto:segundo"
void imprime_tiempo(Tiempo t)
{
    printf("%d/%d/%d %d:%d:%d", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

int calcula_dias(int mes)
{
    switch (mes)
    {
    case 1:
        return 31;
    case 2:
        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return -1;
    }
}

void carga_tiempo(Tiempo *time, char name[]){
    do
    {
        printf("Carga anio '%s': ", name);
        scanf("%d", &(time->anio));
    } while (time->anio < 0 || time->anio > 2025);

    do
    {
        printf("Ingrese mes '%s': ", name);
        scanf("%d", &(time->mes));
    } while (time->mes < 0 || time->mes > 12);

    do
    {
        printf("Ingrese dia '%s': ", name);
        scanf("%d", &(time->dia));
    } while (time->dia < 0 || time->dia > calcula_dias(time->mes));

    do
    {
        printf("Ingrese hora '%s': ", name);
        scanf("%d", &(time->hora));
    } while (time->hora < 0 || time->hora > 24);

    do
    {
        printf("Ingrese minuto '%s': ", name);
        scanf("%d", &(time->minuto));
    } while (time->minuto < 0 || time->minuto > 59);

    do
    {
        printf("Ingrese segundo '%s': ", name);
        scanf("%d", &(time->segundo));
    } while (time->segundo < 0 || time->segundo > 59);
}

int funcion_numeros() {

    Tiempo time1, time2;

    printf("\nCargue los datos del primer tiempo\n");
    carga_tiempo(&time1, "time1");
    imprime_tiempo(time1);
    printf("\nCargue los datos del segundo tiempo\n");
    carga_tiempo(&time2, "time2");
    imprime_tiempo(time2);

    int comparador = compara_tiempos(&time1,&time2);

    if(comparador == -1){
        printf("\nLa fecha ");
        imprime_tiempo(time1);
        printf(" es mayor que ");
        imprime_tiempo(time2);
        printf("\n");
    }else if(comparador == 1){
        printf("\nLa fecha ");
        imprime_tiempo(time2);
        printf(" es mayor que ");
        imprime_tiempo(time1);
        printf("\n");
    }else{
        printf("\nLa fecha ");
        imprime_tiempo(time2);
        printf(" es igual que ");
        imprime_tiempo(time1);
        printf("\n");
    }

    return 0;
}