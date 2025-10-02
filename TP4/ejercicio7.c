/* 
 * Ejercicio 7.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
# define N 3

void rotar_90 (int A[N][N],int R[N][N])
{
    for(int i =0; i<N;i++)
        for(int j=0; j<N; j++)
        {
             R[i][j] = A[N-1-j][i];
        }
}

 void imprimir_matriz(int M[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[N][N]={{1,2,3},{4,5,6},{7,8,9}};
    int R[N][N];
    printf("Matriz A\n");
    imprimir_matriz(A);
    rotar_90(A,R);
    printf("\nMatriz rotada 90 \n");
    imprimir_matriz(R);

    return 0;
}