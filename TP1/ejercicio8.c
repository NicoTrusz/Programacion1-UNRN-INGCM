/* 
 * Ejercicio 8
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int suma_por_partes(int n,int m)
{  
    int i = 0;
    int suma = 0;
    for ( i=n; i < m; i++)
    {
        suma += i;
    }
    return suma ;
}

int main ()
{
    int numero1 = 10;
    int numero2 = 20;
    int sumatotal = 0;
    sumatotal = suma_por_partes(numero1,numero2);
    printf("La suma entre %d y %d (excluyendo %d) es: %d \n", numero1,numero2,numero2,sumatotal);
    return 0;
}