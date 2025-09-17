/* 
 * Ejercicio 1.4
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include <stddef.h>

#define CADENA_SIN_TERMINADOR -1
#define ERROR_CAPACIDAD_INSUFICIENTE -2

/**
 * Inserta una cadena dentro de otra en una posición dada, de forma segura.
 * 
 * @param destino Cadena donde se insertará. Debe tener capacidad suficiente.
 * @param capacidad Tamaño físico máximo del arreglo destino.
 * @param insertar Cadena a insertar.
 * @param posicion Posición en la que se insertará la cadena.
 * @param bandera Largo final de la cadena destino o código de error negativo.
 */
int insertar_seguro(char destino[], size_t capacidad, const char insertar[], size_t posicion) 
{
    size_t largo_destino = 0;
    size_t largo_insertar = 0;
    int bandera = 0;

    // Calcular largo de destino
    while (largo_destino < capacidad && destino[largo_destino] != '\0') {
        largo_destino++;
    }
    if (largo_destino == capacidad)
    {
      bandera =  CADENA_SIN_TERMINADOR;  
    } 

    // Calcular largo de insertar
    while (largo_insertar < capacidad && insertar[largo_insertar] != '\0') {
        largo_insertar++;
    }
    if (largo_insertar == capacidad)
    {
        bandera = CADENA_SIN_TERMINADOR;
    } 

    // Verificar posición válida
    if (posicion > largo_destino)
    {
      bandera = ERROR_CAPACIDAD_INSUFICIENTE;  
    } 

    // Verificar capacidad suficiente
    if (largo_destino + largo_insertar >= capacidad)
    {
        bandera = ERROR_CAPACIDAD_INSUFICIENTE;
    }

    // Desplazar caracteres en destino para hacer espacio
    for (size_t i = largo_destino; i >= posicion; i--) {
        destino[i + largo_insertar] = destino[i];
        if (i == 0) break; // evitar underflow
    }

    // Insertar la cadena
    for (size_t i = 0; i < largo_insertar; i++) {
        destino[posicion + i] = insertar[i];
    }
    bandera = largo_destino + largo_insertar; 

    return bandera;
}

#include <stdio.h>

int main() {
    char destino[20] = "Mundo";
    const char insertar[] = "HOLA";
    int resultado = insertar_seguro(destino, 20, insertar, 2);

    if (resultado >= 0) {
        printf("Resultado: %s\n", destino); // MunHOLAdo
        printf("Largo: %d\n", resultado);
    } else {
        printf("Error: %d\n", resultado);
    }

    return 0;
}
