/* 
 * Ejercicio 10
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
/*
calcula el n-esimo termino de la serie de Fibonacci
*/
int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int temp;
    if (n == 0)
    {
        b = 0;
    }
    if (n == 1)
    {
        b = 1;
    }
    for (int i=2; i<= n; i++ )
    {
        temp = a +b;
        a = b;
        b = temp;
    }
    return b;
}

/*
calcula la suma de los digitos de un numero entero
*/
int suma_digitos(int numero)
{
    int suma = 0;
    while(numero > 0)
    {
        suma += numero % 10;
        numero /= 10;
    }
    return suma;
}

/*
calcula la suma total de los digitos de los primeros n terminos
de la serie de Fibonacci
*/

int suma_digitos_fibonacci(int n)
{
    int suma_total = 0;
    for(int i=0; i<n;i++)
    {
        int terminos= fibonacci(i);
        suma_total += suma_digitos(terminos);
    }
    return suma_total;
}
/*
cuerpo principal del programa
*/
int main ()
{
    int numero;
    printf("Ingrese la cantidad de Fibonacci: ");
    scanf("%d",&numero);
    int resultados = suma_digitos(numero);
    printf("la suma de los digitos de los primeros %d terminos de Fibonacci es: %d\n ",numero,resultados);
    return 0;
}