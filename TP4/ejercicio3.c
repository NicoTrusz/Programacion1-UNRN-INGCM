/* 
 * Ejercicio 3.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>

 #define M_CUADRADA 3

 void matrisz_traspuesta(int original[M_CUADRADA][M_CUADRADA], int traspuesta[M_CUADRADA][M_CUADRADA])
 {
    for (int i =0; i< M_CUADRADA; i++)
    {
        for(int j=0; j<M_CUADRADA; j++)
        {
            traspuesta[i][j]=original[j][i];
        }
    }
 }

 void imprimir_matrisz(int matrisz[M_CUADRADA][M_CUADRADA])
 {
    for (int i =0; i< M_CUADRADA; i++)
    {
        for(int j=0; j<M_CUADRADA; j++)
        {
            printf("%d",matrisz[i][j]);
        }
        printf("\n");
    }
 }

 int main ()
 {
    int A[M_CUADRADA][M_CUADRADA]={{1,2,3},{4,5,6},{7,8,9}};
    int T[M_CUADRADA][M_CUADRADA];

    printf("Matriz Original: \n");
    imprimir_matrisz(A);

    matrisz_traspuesta(A,T);

    printf("\nMatrisz Transpuesta:\n");
    imprimir_matrisz(T);

    return 0;
 }