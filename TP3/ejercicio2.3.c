/* 
 * Ejercicio 2.3
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define ORDEN_INVALIDO -1
 /* REFERENCIA PARA EJERCICIO ECHO EN CLASE CON EL PROFESOR DANIEL
Ordenar de mayor a menor

[4,6,87,9,0]

buscar_mayor (desde el 0) -> 87, pos 2
intercambiar pos 0 con pos 2

[87,6,4,9,0]

buscar_mayor (desde el 1) -> 9, pos 3
intercambiar pos 1 con pos 3

[87,9,4,6,0]

buscar_mayor(arr,n,pos_inicio)

    max_valor = arr[pos_inicio]
    pos_max = pos_inicio

    para los indices (i) de pos_inicio a (n-1)
        si arr[i]>max_valor
            max_valor = arr[i]
            pos_max = i 
    
    devolver pos_max


ordenamiento(arr,n)
    para los indices (i) de 0 a n-1
        posicion_mayor = buscar_mayor (desde la posición i)
        intercambiar (posición_mayor, i)

*/

int ordenar(int arreglo[],size_t largo,char orden)
{
    int bandera = 0;
    if (orden != '<' && orden != '>')
    {
        bandera = ORDEN_INVALIDO;
    }
    for (size_t i =0; i< largo -1; i++)
    {
        for(size_t j =0; j < largo -i -1; j++)
        {
            int condicion;
            if (orden =='<')
            {
                condicion = (arreglo[j] > arreglo [j+1] );
            }
            else
            {
                condicion = (arreglo[j] < arreglo [j+1] );
            }
            if (condicion)
            {
                int temp = arreglo[j];
                arreglo[j]= arreglo[j+1];
                arreglo[j+1]= temp;
            }
        }
    }
    return bandera ;
}

void imprimir_arreglo(int arreglo[], size_t largo)
{
    for (size_t i=0; i< largo; i++)
    {
        printf("%d",arreglo[i]);
    }
    printf("\n");
}

int main ()
{
    int datos[]= {5,2,9,1,7};
    size_t largo = sizeof(datos)/sizeof(datos[0]); // dimentcion del arreglo

    printf("Original: ");
    imprimir_arreglo(datos, largo);

    if (ordenar(datos,largo,'<') == 0 )
    {
        printf("Ordenado ascendente: ");
        imprimir_arreglo(datos,largo);
    }
    else
    {
        printf("ERROR: parametro de orden invalido\n");
    }
    if (ordenar(datos,largo,'>')==0)
    {
        printf("Ordenado decendete: ");
        imprimir_arreglo(datos,largo);
    }
    else
    {
        printf("ERROR: parametro de orden invalido\n");
    }
    return 0;
}