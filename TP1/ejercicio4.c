/* 
 * Ejercicio 4
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>
int compara ( int numero, int otro_numero)
{
    if(numero < otro_numero)
    {
        return -1;
    }
    else if (numero == otro_numero)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main ()
{
    int a , b; 
    // Entrada
    printf("Ingrese el primer numero: ");
    scanf("%d",&a);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&b);

    // Salida 
    int resultado = compara(a,b);
    printf("Resultado de la comparacion: %d \n", resultado);
    return 0;
}