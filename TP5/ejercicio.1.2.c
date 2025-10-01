#include<stdio.h>


int division_lenta(int dividendo, int divisor, int *cociente, int *resto)
{
    int bandera = 1;
    if (divisor == 0)
    {
        bandera = 0; // Division invalida
    }
    *cociente = dividendo / divisor;
    *resto = dividendo % divisor;
    return bandera; // Division valida
}

// cuerpo 
int main ()
{
    int a = 17;
    int b = 5;
    int q;
    int r;

    if (division_lenta(a, b, &q, &r))
    {
        printf("cociente: %d, resto: %d\n",q,r);
    }
    else
    {
        printf("Error division por cero\n");
    }

    if (!division_lenta(a, 0, &q, &r))
    {
        printf("division invalida");
    }
    return 0;
}