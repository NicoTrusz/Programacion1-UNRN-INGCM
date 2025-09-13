/* 
 * Ejercicio 1.1
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define CADENA_SIN_TERMINADOR -1

int largo_seguro(size_t capacidad , char cadena[])
{
    size_t i;
    int bandera = CADENA_SIN_TERMINADOR;
    for (i =0 ; i<capacidad; i++)
    {
        if (cadena[i] == '\0')
        {
            bandera = (int)i;
            break;
        }
    }
    return bandera;
}

int main()
{
    char cadena1[]="Hola";
    char cadena2[5] = {'H','o','l','a','x'}; // sin terminador '\0'

    printf("Largo cadena1: %d\n",largo_seguro(10,cadena1));
    printf("Largo cadena2: %d\n",largo_seguro(5,cadena2));
    return 0;
}