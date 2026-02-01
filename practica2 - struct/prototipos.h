int compara_tiempos(Tiempo *t1, Tiempo *t2);
void imprime_tiempo(Tiempo t);
void carga_tiempo(Tiempo *time, char name[]);
int calcula_dias(int mes);

void ordena_alfa( Archivo * lista, int n );
void ordena_temporal(Archivo * lista, int n );
int funcion_numeros();
void ordena_alfa( Archivo * lista, int n ); // (utilice la función strcmp de la biblioteca estándar para comparar los nombres de los archivos al ordenarlos alfabéticamente).
void ordena_temporal(Archivo * lista, int n ); //(utilice la función compara_tiempos para comparar los tiempos de última modificación de los archivos).

void carga_datos (Archivo * archivo);