/* 
 * Ejercicio 12
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int suma_digitos(int n)
{
    int suma =0;
    while (n>0)
    {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int main()
{
    int numero;
    int resultado;
    //entrada
    printf("ingrese numero: ");
    scanf("%d",numero);
    if (numero != 1 || numero < 0)
    {
        printf("Error");
        return 1;
    }
    resultado = suma_digitos(numero);
    // salida
    printf("%d\n", resultado);
    return 0;
}