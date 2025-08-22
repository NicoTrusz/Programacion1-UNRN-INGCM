/* 
 * Ejercicio 7
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int Primo (int numero)
{
    if (numero < 2)
    {
        return false;
    }
    for (int i = 2; i < numero; i++)
    {
        int local = numero; 
        while (local >= i)
        {
            local -=i;
        }
        if (local == 0)
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    int numero;
    //Entrada
    printf("Ingrese el Numero: ");
    scanf("%d",numero);
    // Salida
    if (Primo (numero))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}