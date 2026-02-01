typedef struct codigo_postal
{
    int codigo_postal;
    char localidad[20]
} CodigoPostal;

typedef struct fecha
{
    int mes;
    int dia;
    int anio;
} Fecha;


typedef struct persona
{
    CodigoPostal ciudad;
    Fecha nacimiento;

} Persona;

