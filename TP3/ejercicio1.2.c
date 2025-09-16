/* 
 * Ejercicio 1.2
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define ERROR_SIN_TERMINADOR -1
#define ERROR_CAPACIDAD_INSUFICIENTE -2

int copiar_seguro (char origen[], char destino[], size_t capacidad)
{
    size_t i = 0;
    int bandera= ERROR_SIN_TERMINADOR;
    //buscador del termino '\0'

    while (i<capacidad)
    {
        destino[i] = origen [i];
        if (origen[i] == '\0')
        {
            bandera = i; // retorno de la longitud sin \0
        }
        i++;
    }
    // error de sobredimencion o no tiene fin la cadena
    destino[0] = '\0';
    return bandera;
}

int main ()
{
    char origen[] = "hola mundo";
    char destino[20];

    int resultado = copiar_seguro(origen, destino, sizeof(destino));

    if (resultado >= 0)
    {
        printf("copia exitosa\n Cadena destino : \"%s\" (largo: %d)\n",destino,resultado);
    }
    else
    {
        printf("Error al copiar la cadena. error %d\n", resultado);
    }
    return 0;
}