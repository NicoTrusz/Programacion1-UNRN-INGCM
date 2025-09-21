/* 
 * Ejercicio 6.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

#include<stdio.h>

#define N 3

void producto_de_matriz_vector(int A[N][N], int V[N],int R[N])
{
    for (int i =0; i<N; i++)
    {
        R[i]=0;
        for(int j=0;j<N;j++)
        {
            R[i] += A[i][j] * V[j];

        }
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

void imprimir_vector(int M[N])
{
    for(int i=0; i<N; i++)
    {
       printf("%4d", M[i]);    
    }
}

int main ()
{
    int A[N][N]={{1,2,3},{4,5,6},{7,8,9}};
    int V[N]={1,2,3};
    int R[N];
    printf("Matrisz A\n");
    imprimir_matriz(A);
    printf("\nVector V\n");
    imprimir_vector(V);
    producto_de_matriz_vector(A,V,R);
    printf("\nResultado R\n");
    imprimir_vector(R);
    return 0;
}