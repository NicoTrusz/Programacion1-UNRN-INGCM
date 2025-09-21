/* 
 * Ejercicio 1.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>

 #define FILAS 3
 #define COLUMNAS 3

 void suma_matrices(int matriszA[FILAS][COLUMNAS], int matriszB[FILAS][COLUMNAS],int matriszC[FILAS][COLUMNAS])
 {
    for (int i=0; i< FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            matriszC[i][j]= matriszA[i][j]+matriszB[i][j];
        }
    }
 }

void imprimir_matrisz(int matriz[FILAS][COLUMNAS])
{
    for (int i=0; i< FILAS; i++)
    {
        for(int j=0; j<COLUMNAS;j++)
        {
            printf(" %4d ",matriz[i][j]);
        }
        printf("|\n|");
    }
}

int main ()
{
    int A[FILAS][COLUMNAS]= {{1,2,3},{4,5,6},{7,8,9}};
    int B[FILAS][COLUMNAS]= {{9,8,7},{6,5,4},{3,2,1}};
    int C[FILAS][COLUMNAS];

    suma_matrices(A,B,C);
    printf("Matrisz A\n|");
    imprimir_matrisz(A);
    printf("Matrisz B\n|");
    imprimir_matrisz(B);
    printf("Matrisz C\n|");
    imprimir_matrisz(C);
    return 0;
}