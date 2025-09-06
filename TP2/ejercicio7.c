/* 
 * Ejercicio 7
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
int multiplicacion(int numero1, int numero2)
{
    int resultado = 0;
    int i;
    for(i =0; i <numero2; i++)
    {
        resultado += numero1;
    }
    return resultado;
}

int potenciacion_lenta(int base, int exponente)
{
    int resultado = 1;
    int i;
    for (i=0; i < exponente; i++)
    {
        resultado = multiplicacion(resultado,base);
    }
    return resultado;
}

int main ()
{
 int base = 0;
 int exponente = 0;
 int resultado;
 // entrada
 printf("ingrese el numero que quiere elevar: ");
 scanf("%d",&base);
 printf("ingrese el exponenete: ");
 scanf("%d",&exponente);
resultado = potenciacion_lenta(base, exponente);
//salida
printf("%d elevado a %d es: %d",base,exponente,resultado);
 return 0;
}