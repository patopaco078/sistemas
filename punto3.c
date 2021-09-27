#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROMEDIO(cantidad, total) total/cantidad

int size = 30;
int main()
{
    FILE * flujo = fopen("entrada.txt", "r");
    if(flujo == NULL)
    {
        perror("el archivo entrada.txt no existe");
        return 1;
    }

    char caracter[size];
    fgets(caracter, size, flujo);

    char *token = strtok(caracter, " "); //dividir el arreglo
    int *arr = malloc(sizeof(int) * size); //memoria dinamica
    int cantidad = 0;

    while (token != NULL)
    {
        sscanf(token, "%d", &arr[cantidad]);
        token = strtok(NULL, " ");//evita la sobreescritura
        cantidad++;
    }

    int minimo = 32767;

    for (int i = 0; i < cantidad; i++)
    {
        if(arr[i] < minimo)
        {
            minimo = arr[i];
        }
    }

    int maximo = -32768;

    for (int i = 0; i < cantidad; i++)
    {
        if(arr[i] > maximo)
        {
            maximo = arr[i];
        }
    }

    float Total;


    for (int i = 0; i < cantidad; i++)
    {
        Total += arr[i];
    }

    float prom = PROMEDIO(cantidad, Total);

    FILE *salida = fopen("./salida.out", "w");

    fprintf(salida, "el minimo es %i\nel maximo es %i\nel promedio es %.3f", minimo, maximo, prom);
    fclose(flujo);
    fclose(salida);
}
