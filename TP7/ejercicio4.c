/* 
 * Ejercicio 4.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include <stdio.h>

// Función que imprime el valor apuntado según el tipo
void imprimir_valor(void *ptr, char tipo) {
    switch (tipo) {
        case 'i':
            printf("Entero: %d\n", *(int *)ptr);
            break;
        case 'f':
            printf("Flotante: %.2f\n", *(float *)ptr);
            break;
        case 'c':
            printf("Carácter: %c\n", *(char *)ptr);
            break;
        default:
            printf("Tipo desconocido\n");
    }
}

int main() {
    int entero = 42;
    float flotante = 3.14f;
    char caracter = 'A';

    // Pruebas con punteros genéricos
    imprimir_valor(&entero, 'i');
    imprimir_valor(&flotante, 'f');
    imprimir_valor(&caracter, 'c');

    return 0;
}
