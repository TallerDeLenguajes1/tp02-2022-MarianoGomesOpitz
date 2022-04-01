#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CANT 5

struct compu
{
    int velocidad;  // entre 1 y 3 Gherz
    int anio;       // entre 2000 y 2017
    int cantidad;   // entre 1 y 4
    char *tipo_cpu; // valores del arreglo tipos
} typedef compu;

void mostrar(compu *computadoras);
void vieja(compu *computadoras);
void rapida(compu *computadoras);

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

int main()
{
    compu miPC[CANT], *p_miPC;
    p_miPC = miPC;
    srand(time(NULL));
    for (int i = 0; i < CANT; i++)
    {
        p_miPC->velocidad = (rand() % 3) + 1;
        p_miPC->anio = (rand() % (2022 - 2015 + 1)) + 2015;
        p_miPC->cantidad = (rand() % 8) + 1;
        p_miPC->tipo_cpu = tipos[rand() % 5];
        p_miPC++;
    }
    p_miPC = miPC;

    mostrar(p_miPC);

    vieja(p_miPC);

    rapida(p_miPC);

    getchar();
    return 0;
}

void mostrar(compu *computadoras)
{
    puts("Pcs:\n");
    for (int i = 0; i < CANT; i++)
    {
        printf("Datos de la PC %d\n", i);
        printf("Velocidad: %d Gherz\n", computadoras->velocidad);
        printf("Anio de fabricacion: %d\n", computadoras->anio);
        printf("Cantidad de nucleos: %d\n", computadoras->cantidad);
        printf("Tipo de procesador: %s\n\n", computadoras->tipo_cpu);
        computadoras++;
    }
}

void vieja(compu *computadoras)
{
    int anioFabric = 2023, masVieja;
    for (int i = 0; i < CANT; i++)
    {
        if ((computadoras + i)->anio < anioFabric)
        {
            masVieja = i;
            anioFabric = (computadoras + i)->anio;
        }
    }
    printf("La computadora mas vieja es: La PC N%c%d\n", 167, masVieja);
    printf("Velocidad: %d Gherz\n", (computadoras + masVieja)->velocidad);
    printf("Anio de fabricacion: %d\n", (computadoras + masVieja)->anio);
    printf("Cantidad de nucleos: %d\n", (computadoras + masVieja)->cantidad);
    printf("Tipo de procesador: %s\n\n", (computadoras + masVieja)->tipo_cpu);
}

void rapida(compu *computadoras)
{
    int velo = 0, masRapida;
    for (int i = 0; i < CANT; i++)
    {
        if ((computadoras + i)->velocidad > velo)
        {
            masRapida = i;
            velo = (computadoras + i)->velocidad;
        }
    }
    printf("La computadora mas rapida es: La PC N%c%d\n", 167, masRapida);
    printf("Velocidad: %d Gherz\n", (computadoras + masRapida)->velocidad);
    printf("Anio de fabricacion: %d\n", (computadoras + masRapida)->anio);
    printf("Cantidad de nucleos: %d\n", (computadoras + masRapida)->cantidad);
    printf("Tipo de procesador: %s\n\n", (computadoras + masRapida)->tipo_cpu);
}