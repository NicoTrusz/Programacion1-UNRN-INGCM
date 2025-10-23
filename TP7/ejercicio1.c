/* 
 * Ejercicio 1.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

/*
codigos de exit 
0 ---> fin exitoso todo funciona correctamente
1 ---> fin error generico fallo en entrada de memoria
>1 --> fin eroor especifico a definir por codigo personalizado
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipos
int solicitarCantidad();
int* reservarMemoria(int cantidad);
void ingresarNumeros(int *numeros, int cantidad);
void mostrarInverso(const int *numeros, int cantidad);
void liberarMemoria(int *numeros);

int main ()
{
    int bandera = 0;
    int cantidad = solicitarCantidad();
    int *numeros = reservarMemoria(cantidad);

    if (numeros == NULL)
    {
        bandera = 1; // Error de asignacion a numeros
    }
    else
    {
        ingresarNumeros(numeros, cantidad);
        mostrarInverso(numeros, cantidad);
        liberarMemoria(numeros);
    }
    return bandera;
}

// Solicita al usuario la cantidad de enteros
int solicitarCantidad()
{
    int n;
    printf("Ingresar la cantidad de enteros a almacenar: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Entrada invalida.\n");
        exit(1); // error generico
    }
    return n;
}

// Reserva memoria dinamica y verifica errores
int* reservarMemoria(int cantidad)
{
    int *ptr = (int *)malloc(cantidad * sizeof(int));
    if (ptr == NULL)
    {
        printf("Error al asignar memoria.\n");
    }
    return ptr;
}

// ingresa los numeros
void ingresarNumeros(int *numeros, int cantidad)
{
    for (int i = 0; i< cantidad; i++)
    {
        printf("Ingrese el numero %d: ", i+1);
        
        if (scanf("%d",&numeros[i] )!= 1) // lo que hace es leer el numero ingresado y compara si es un numero o un tipo char
        {
            printf("Entrada invalida.\n");
            free(numeros); // libero MD reservada por malloc 
            exit(1); // error generico
        }
    }
}

// Imprime los numeros en orden inverso
void mostrarInverso(const int *numeros, int cantidad)
{
    printf("\nNumeros en orden inverso\n");
    for(int i = cantidad -1; i>= 0; i-- )
    {
        printf("%d", numeros[i]);
    }
    printf("\n");
}

// libero memoria reservada
void liberarMemoria(int *numeros)
{
    free(numeros); // libero MD reservada por malloc
}