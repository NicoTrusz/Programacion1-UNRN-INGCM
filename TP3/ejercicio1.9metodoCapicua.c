/* 
 * Ejercicio 1.9
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>
 #include<stdlib.h>

 
 #define TRUE 1
 #define FALSE 0
 #define CADENA_SIN_TERMINADOR -1

 int es_palindromo_seguro(size_t capacidad, char cadena[])
 {
    int bandera = TRUE;
    size_t largo = -1;
    // Busca el terminador de la cadena '\0' dentro del limite
    for (size_t i=0; i<capacidad; i++) // la funcion que cumple es verificar que el tamaño de la cadena es segura y no sobre dimencionar 
    {
        if (cadena[i] == '\0')
        {
            largo = i;
            printf("largo: %d\n", largo);
            break;
        }
    }
    if (largo == -1) // caso de que no tenga la posicion '\0' 
    {
        bandera = CADENA_SIN_TERMINADOR;
    }
    // comparo caracteres sin inportar si son mayuscula o minuscula
    for (size_t i =0; i<largo; i++)
    {
       char cadenab[i];
       cadenab[i] = cadena[largo -1 -i];
       
        /*
        con a recorro la primera mitad de la cadena y con b la segunda mitad
            largo = 6 
        Ej: a =[0 , 1 , 2] b= [5, 4, 3]
        */

        /*
        otra opcion que estoy analizando es la de capicua de copiar la cadena entera
        darla vuelta y comparar 
        for (size_t i =0; i<largo; i++)
        {
            cadenab[i] = cadena[largo-1-i];
        }
        if (cadenab[i]!=cadena[i])
        {
            bandera = FALSE;
        }
        */

        // Normalizar o pasar todo a minuscula
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] += 32; // esto lo realizo para pasar de 'A' a 'a' ya que en la tabla ASQUI hay una diferencia de 32 enteros
        } 
        if (cadenab[largo -1 -i] >= 'A' && cadena[largo -1 -i] <= 'Z')
        {
            cadenab[largo -1 -i] += 32; // esto lo realizo para pasar de 'A' a 'a' ya que en la tabla ASQUI hay una diferencia de 32 enteros
        }
        printf("%c",cadena[i]);
        printf("%c",cadena[i]);
        printf("\n");
       
       if (cadenab[i]!=cadena[i])
       {
        bandera = FALSE;
       }

    }
    return bandera ;
 }

 int main ()
{
    // Dependiendo de la dimencion o la cadena sera true, folse o sin \0
    // en este pude solucionar el problema de los valores medios con la logica del ejercicio 15 de la practica 1 y evaluando como si fuera capicua
    char palabra[]= "Neuquen";
    int resultado = es_palindromo_seguro(20, palabra);
    printf("resultado = %d",resultado);
    return 0;
}