/* 
 * Ejercicio 14
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int suma_divisores_propios(int numero)
{
    int suma = 0;
    for (int i =1; i < numero; i++)
    {
        if (numero % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

void verificar_amistad (int a, int b)
{
    int sumaA = suma_divisores_propios(a);
    int sumaB = suma_divisores_propios(b);
    if (sumaA == b && sumaB == a)
    {
        printf("%d y %d son numeros amigos \n", a,b);
    }
    else
    {
        printf("%d y %d no son numeros amigos \n", a,b);
    }
}

int main ()
{
    int numero1 ;
    int numero2 ;
    printf("Ingrese dos numeros positivos: ");
    scanf("%d %d", &numero1,&numero2);
    verificar_amistad(numero1 , numero2);
    return 0;
}