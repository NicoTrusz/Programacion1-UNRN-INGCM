/* 
 * Ejercicio 1.3
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define CADENA_SIN_TERMINADOR -1
#define ERROR_CAPACIDAD_INSUFICIENTE -2

 int concatenar_seguro(char destino[],char origen[],size_t capacidad)
 {
    size_t i=0;
    int bandera = ERROR_CAPACIDAD_INSUFICIENTE;
    
    while (i< capacidad && destino[i] !='\0')
    {
        i++;
    }
    if (i == capacidad)
    {
        bandera = CADENA_SIN_TERMINADOR;
    }
    size_t j=0;
    while(i+j< capacidad)
    {
        destino[i+j] = origen[j];
        if(origen[j] =='\0')
        {
            bandera = i+j;
        }
        j++;
    }
    destino[i]='\0';

    return bandera;
}

int main ()
{
    char destino[20] = "hola";
    char origen[]= "mundo";
    int resultado = concatenar_seguro(destino,origen,sizeof(destino));

    if (resultado >= 0)
    {
        printf("concatenacion exitosa: \"%s\"(largo: %d)\n", destino,resultado);
    }
    else
    {
        printf("Error al concatenar. error: %d\n",resultado);
    }
    return 0;
}