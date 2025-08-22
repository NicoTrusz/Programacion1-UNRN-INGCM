/* 
 * Ejercicio 5
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int suma_lenta (int numero1, int numero2) // funcion de suma lenta
{
    while (numero2 != 0) 
    {
        if (numero2 > 0)
        {
            numero1++;
            numero2--;
        }
        else
        {
            numero1--;
            numero2++;
        }
    } 
    return numero1;
}

int main ()
{
    int a = 0;
    int b = 0;
    int resultado = 0;
    // Entrada
    printf ("Ingrese el primer numero: ");
    scanf("%d",&a);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&b);
    //Salida
    resultado = suma_lenta(a,b);
    printf(" El resultado de la suma es : %d", resultado);
    return 0;
}