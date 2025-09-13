/* 
 * Ejercicio 2.1
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

#include<stdio.h>
#include<stdlib.h>

#define ARREGLO_VACIO -1

int buscar_minimo(int arreglo[], size_t tamaño)
{
    int minimo;
    if (tamaño == 0)
    {
        minimo = ARREGLO_VACIO;
    }
    else
    {
        minimo = arreglo[0];
        for (size_t i=1; i < tamaño; i++)
        {
            if (arreglo[i]<minimo)
            {
                minimo = arreglo[i];
            }
        }
    }
    return minimo;
}

int main ()
{
    int arreglo[]={1,2,3};
    int minimo = buscar_minimo(arreglo,3);
    printf("el minimo es: %d",minimo);
    return 0;
}