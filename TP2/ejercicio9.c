/* 
 * Ejercicio 9
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include <stdio.h>
#include <math.h> 
 int es_fibonacci(int numero)
 {
    int a =0;
    int b = 1;
    int temp ;
    while (b<numero)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return ( numero == b || numero == 0);
 }

int es_cuadrado(int n)
{
    int raiz = (int)sqrt(n);
    return raiz * raiz == n;
}

int es_fibonacci_matemarico(int numero)
{
    return es_cuadrado(5 * numero * numero +4) || es_cuadrado(5*numero*numero-4);
}

int main ()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    if (es_fibonacci(numero))
    {
        printf("Metodo interativo: %d pertenece a la serie de fibonacci.\n",numero);
    }
    else
    {
        printf("Método iterativo: %d NO pertenece a la serie de Fibonacci.\n", numero);
    }
    if (es_fibonacci_matematico(numero))
    {
        printf("Método matemático: %d pertenece a la serie de Fibonacci.\n", numero);
    }
    else
    {
        printf("Método matemático: %d NO pertenece a la serie de Fibonacci.\n", numero);
    }
    return 0;
}