#include<stdio.h>

void intercambiar (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invertir(int *inicio, int *fin) {
    while (inicio < fin) {
        intercambia(inicio, fin);
        inicio++;
        fin--;
    }
}


void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int datos[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo original:\n");
    imprimir(datos, n);

    invertir(&datos[0], &datos[n - 1]);

    printf("Arreglo invertido:\n");
    imprimir(datos, n);

    return 0;
}