/* 
 * Ejercicio 8
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
// me queda pendiente a ver porque no pasa del if (es_defectivo(numero))
#include <stdio.h>
#include <stdbool.h>
 bool es_defectivo(int numero)
 {
    int suma = 0;
    for (int i = 0; i < numero; i++  )
    {
        if (numero % i == 0)
        {
            suma +=i;
        }
    }
    return suma < numero;
 }
 void imprimir(int numero) /******* bandera */
 {
    if (es_defectivo(numero)) /******* bandera*/
    {
        printf("Es defectivo\n");
    }
    else
    {
        printf("No es defectivo\n");
    }
 }

 int main ()
 {
    int numero;
    printf("ingrese un numero: ");
    scanf("%d", &numero);
    imprimir(numero);
    return 0;
 }