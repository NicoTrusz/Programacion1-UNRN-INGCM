/* 
 * Ejercicio 13
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
#include<stdlib.h>

void mostrar_triangulo_pascal (int n)
{
    int i;
    int j;
    for (i=0; i< n; i++)
    {
        long val = 1;
        for (j=0; j<= i; j++)
        {
            printf("%ld",val);
            val = val* (i-j)/(j+1);
        }
        printf("\n");
    }
}

int main()
{
    int filas;
    printf("Ingrese el numero de filas: ");
    scanf("%d",&filas);
    mostrar_triangulo_pascal(filas);
    return 0;
}