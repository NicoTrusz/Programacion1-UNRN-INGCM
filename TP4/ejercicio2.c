/* 
 * Ejercicio 2.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

void multiplicarMatrices(int A[FILAS][COLUMNAS], int B[FILAS][COLUMNAS], int C[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            C[i][j] = 0; // Inicializar acumulador
            for (int k = 0; k < COLUMNAS; k++) {
                C[i][j] = A[i][k] * B[k][j] + C[i][j];
            }
        }
    }
}

void imprimirMatriz(int M[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[FILAS][COLUMNAS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[FILAS][COLUMNAS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[FILAS][COLUMNAS];

    multiplicarMatrices(A, B, C);

    printf("Matriz A:\n");
    imprimirMatriz(A);
    printf("Matriz B:\n");
    imprimirMatriz(B);
    printf("Matriz C (A x B):\n");
    imprimirMatriz(C);

    return 0;
}
