/* 
 * Ejercicio 4.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>

#define N 3

void Matriz_identidad(int I[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (i==j)
            {
                I[i][j]= 1;
            }
            else
            {
                I[i][j]= 0;
            }
        }
    }
}

void multipicar_matrisz (int A[N][N], int B[N][N], int R[N][N] )
{
    for (int i =0; i<N; i++)
    {
        for (int j=0; j<N;j++)
        {
            R[i][j]=0;
            for (int k=0; k<N; k++)
            {
                R[i][j] += A[i][k]*B[k][j];
                
            }
        }
        
    }
}

int son_iguales(int A[N][N],int B[N][N])
{
    int bandera = 0;
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N ; j++)
        if (A[i][j] == B[i][j])
        {
            bandera = 1;
        }
    }
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

int main() {
    int A[N][N] = {{2, 3, 1}, {0, 1, 4}, {5, 2, 2}};
    int I[N][N], R[N][N];

    Matriz_identidad(I);
    multipicar_matrisz(A, I, R);
    printf("Matrisz A\n");
    imprimir_matriz(A);
    printf("Matrisz I\n");
    imprimir_matriz(I);
    printf("Matrisz R\n");
    imprimir_matriz(R);

    if (son_iguales(A, R))
        printf(" A * I = A\n");
    else
        printf(" A * I ≠ A\n");

    return 0;
}
