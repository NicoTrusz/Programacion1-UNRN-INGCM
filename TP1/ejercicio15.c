/* 
 * Ejercicio 15
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int numero_invertido(int numero)
{
    int invertido = 0;
    while (numero > 0)
    {
        int digito = numero % 10; // extrae el ultimo digito
        invertido = invertido *10 + digito ; // lo agrega el invertido
        numero = numero /10; // elimina el ultimo digito

    }
    return invertido;
}

int main ()
{
    int numero;
    int invertido; 
    printf ("ingrese un numero: ");
    scanf("%d",&numero);
    invertido = numero_invertido(numero);
    printf("el numero invertido es: %d", invertido);
    return 0;
}