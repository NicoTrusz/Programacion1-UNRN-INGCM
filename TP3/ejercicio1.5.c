/* 
 * Ejercicio 1.5
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

#include<stdio.h>
#include<stddef.h>

#define CADENA_SIN_TERMINADOR -1
#define CADENA_DESTINO_INSUFICIENTE -2

int es_alfanumerico(char c)
{
    int bandera = 0;
    if (c >= 'A' && c <= 'Z')
    {
        bandera = 1;
    }
    if (c >= 'a' && c <= 'z')
    {
        bandera = 1;
    }
    if (c >= '0' && c <= '9') 
    {
        bandera = 1;
    }

    return bandera;
}

int limpiar_cadena(size_t capacidad_origen,char origen[],size_t capacidad_destino, char destino[])
{
    size_t i = 0;
    size_t j = 0;
    int bandera = 0;
    int tiene_terminador = 0;

    while (i< capacidad_origen)
    {
        if (origen[i] == '\0')
        {
        tiene_terminador = 1;
        break;
        }
        if (es_alfanumerico(origen[i]))
        {
            if (j>= capacidad_destino -1)
            {
                bandera = CADENA_DESTINO_INSUFICIENTE ;
            }
            destino[j++] = origen[i];
        }
        i++;
    }
    if (!tiene_terminador)
    {
        bandera = CADENA_SIN_TERMINADOR;
    }
    destino[j] = '\0';
    bandera = (int) j;
    return bandera;
}

int main ()
{
    char origen [] = "Hola, mundo! 123.";
    char destino[100];
    int resultado = limpiar_cadena(sizeof(origen),origen,sizeof(destino),destino);

    if (resultado >= 0)
    {
        printf("Cadena limpia: %s\n",destino);
        printf("Largo: %d\n",resultado);
    }
    else
    {
        printf("Error: %d\n",resultado);
    }
    return 0;
}