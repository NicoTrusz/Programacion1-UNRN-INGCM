/* 
 * Ejercicio 2
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */

#include<stdio.h>
/*
igual que en el ejercicio anterior si se quieren sumar mas de 10 digitos
deberan cambiar las variables int por long long o unsigned long long 
o rearmar el problemna para entrar por cadena[]
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

int main ()
{
    int numero;
    int funcion ;
    // entrada
    printf("Ingrese un numero entero positivo: ");
    scanf("%d",&numero);
    funcion = suma_digitos(numero);
    // salida
    printf("La suma de los digitos es: %d\n",funcion);
    return 0;
}