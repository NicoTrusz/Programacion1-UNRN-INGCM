/* 
 * Ejercicio 9
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

/*
 * Retorna 1 si 'a' es múltiplo de 'b', 0 si no lo es.
 * Usa restas sucesivas, sin división ni módulo.
 */
int es_multiplo(int numero1, int numero2)
{
    if (numero2 == 0)
    {
        int n =0;
        n= (numero1 == 0) ? 1 : 0;
        return n ;
    }
    int A = 0; 
    A=(numero1 < 0) ? -numero1 : numero1;
    int B = 0;
    B = (numero2 < 0) ? -numero2 : numero2;
    while( A >= B) 
    {
        A -= B;
    }
    int m =0;
    m= (A==0) ? 1 : 0;
    return m ;
}

int main()
{
    int a;
    int b;
    // ENTRADA
    printf("Primer valor");
    scanf("%d",&a);
    printf("Segundo valor");
    scanf("%d",&b);

    if ((a && b)!= 2 )
    {
        return 1;
    }
    int resultado = 0;
    resultado = es_multiplo(a,b);
    // salida
    printf("%d\n",resultado);
    return 0;
}