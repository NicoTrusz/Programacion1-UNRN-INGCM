/* 
 * Ejercicio 10
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>
unsigned long long factorial (int n) // Función que calcula el factorial de un número entero positivo
{   
    int i;
    unsigned long long resultado =1;
    for (i=1; i<=n; i++ )
    {
    resultado *=i;
    }
    return resultado;
}
int main ()
{
    int numero;
    unsigned long long resultado;
    //Entrada
    printf("Ingrese un numero entero positivo: ");
    scanf("%d",numero);

    if (numero< 0 )
    {
        printf("Error numero negativo");
        return 1;
    }
    resultado = factorial(numero);
    // salida
    printf("El factorial de %d es %llu\n", numero, resultado);
    return 0;
}