/* 
 * Ejercicio 11
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int contador_circular(int i, int limite) // Función que implementa el contador circular
{
    if (i == limite)
    {
        return 0;
    }
    else
    {
        return i+1;
    }
}

int main ()
{
    int i, limite;
    int resultado =0;
    // entrada
    printf("ingrese el contador");
    scanf("%d",i);
    printf("Ingrese el limite");
    scanf("%d",limite);
    resultado = contador_circular(i, limite);
    // salida
    printf("%d\n", resultado);
    return 0;
}