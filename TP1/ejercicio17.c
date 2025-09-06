/* 
 * Ejercicio 17
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int descomposicion_en_factores(int numero)
{
    int divisor = 2;
    while(numero > 1)
    {
        if (numero % divisor == 0)
        {
            printf("%d",divisor);
            numero = numero / divisor;
            if (numero > 1)
            {
                printf(" x ");
            }
        }
        else
        {
            divisor ++ ;
        }
    }
}

int main ()
{
    int numero ;
    printf("ingrese un numero: ");
    scanf("%d",&numero);
    descomposicion_en_factores(numero);
    return 0;
}