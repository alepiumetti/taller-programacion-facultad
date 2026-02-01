#define F 0
#define D 1
#define F_str "Favorable"
#define D_str "Desfavorable"
#define MAX_NAME 20

typedef struct votante
{
    char * nombre;
    struct votante *siguiente;
} Votante;

typedef Votante * puntero_votante;

