#include<stdio.h>

void duplicar(int *numero)
{
    *numero = (*numero) * 2;
}

int main ()
{
    int valor = 7;
    int *puntero_valor = &valor; // sin esta asignacion a puntero
    duplicar (puntero_valor); // duplicar (&valor) 

    printf("valor duplicado %d\n",*puntero_valor); // , valor
    return 0;
}