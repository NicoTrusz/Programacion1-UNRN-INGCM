#include<stdio.h>
#include<stddef.h>


void estadisticas(int arr[], size_t n, int *min, int *max, double *prom)
{
    if (n != 0)
    {
        *min = arr[0];
        *max = arr[0];
        int suma = arr[0];

        for (size_t i = 1; i< n; i++)
        {
            if (arr[i]< *min)
            {
                *min = arr[i];
            }
            if (arr[i]> *max)
            {
                *max = arr[i];
            }
            suma += arr[i];
        }
        *prom = (double)suma /n;
    }
}

int main ()
{
    int datos [] = {5, 8, 2, 9, 4};
    size_t n = sizeof(datos)/sizeof(datos[0]);
    int minimo, maximo;
    double promedio;
    
    estadisticas(datos, n, &minimo,&maximo,&promedio);

    printf("min: %d,  max: %d,  promedio: %.2f\n",minimo,maximo,promedio);

    return 0;
}