#include<stdio.h>
#include<stddef.h>

void intercambiar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenamiento (int arr[], int n)
{
    for (int i =0; i<n-1; i++)
    {
        for(int j=0; j<n -i-1; j++)
        {
            if (arr[j]> arr[j+1])
            {
                intercambiar(&arr[j] , &arr[j+1] ) ;
            }
        }
    }
}

void imprimir (int arr[], int n)
{
    for (int i= 0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main ()
{
    int datos[] = {5,2,9,1,7};
    int n = sizeof(datos)/sizeof(datos[0]);

    printf("Arreglo original \n");
    imprimir(datos, n);

    ordenamiento(datos, n);

    printf("Arreglo ordenado \n");
    imprimir(datos,n);

    return 0;
}