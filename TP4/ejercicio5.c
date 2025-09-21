/* 
 * Ejercicio 5.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
// humilde opinion este ejercicio es horrible 
#include<stdio.h>
#define N 3


int calcular_determinante(int M[3][3])
{
    int a=M[0][0], b=M[0][1], c=M[0][2];
    int d=M[1][0], e=M[1][1], f=M[1][2];
    int g=M[2][0], h=M[2][1], i=M[2][2];
    int bandera = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
    return bandera;
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
    int A[3][3]= {{2,3,1},{0,1,4},{5,2,2}};
    printf("Matrisz A\n");
    imprimir_matriz(A);

    printf("\nDeterminante de A: %d", calcular_determinante(A));
    return 0; 
}