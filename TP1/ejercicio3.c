/* 
 * Ejercicio 3
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int IndicaPositivoNegativoCero (int numero) // funcion que compara si el numero ingresado es + - o 0
{
    if (numero > 0)
    {
        return 1;
    }
    else if (numero == 0)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
}

int main()
{
    int n;
    // entrada
    printf("Ingrese el Numero:");
    scanf("%d",&n);
    // salida
    int resultado = IndicaPositivoNegativoCero(n);
    printf("Resultado %d\n",resultado);
    return 0;
}