/* 
 * Ejercicio 6
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

int dividir_por_restos(int numero1 , int numero2)
{
   int cociente = 0;
   while (numero1 >= numero2)
   {
    numero1 -= numero2;
    cociente++;
   }
   return cociente;
}

int main ()
{
    int a=0;
    int b=0;
    // Entrada
    printf("ingrese el numero a dividir: ");
    scanf("%d",&a);
    prinf("Ingrese el numero divisor: ");
    scanf("%d",&b);
    int cociente = dividir_por_restos(a,b);
    int resto = a-cociente*b;
    // Salida
    printf("Cociente: %d\n",cociente);
    printf("Resto: %d\n",resto);
    return 0; 
}