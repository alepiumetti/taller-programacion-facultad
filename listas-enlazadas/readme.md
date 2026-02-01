# Listas enlazadas 

Tenemos un puntero a una lista y el siguiente apunta a otra 

```c
struct {
    int dato;
    struct nodo * sgte;
} list;

void listar (lista * i){
    if( i != NULL){
        printf(" elemento := %d \n ", i -> dato);
        listar (i -> sgte);
    }
}
```

