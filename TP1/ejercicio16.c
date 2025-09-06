/* 
 * Ejercicio 16
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int invertir_numero( int numero)
{
    int copia = numero; // tengo que probar si directamente en digito coloco la variable numero y me ahorro la variable copia 
    int invertido ;
    while (copia > 0)
    {
        int digito = copia % 10; // extraigo el ultimo digito
        invertido = invertido *10 +digito; // lo agrego al invertido
        copia = copia /10; // saco el ultimo digito 
    }
    return invertido;
}
bool es_capicua(int a ,int b)
{
    bool comparado = false;
    if (a == b) // comparo si a y b son iguales true, sino ya es falso
    {
        comparado = true;
    }
    return comparado; // retorno falso o verdadero
}
void imprimir(bool condicion) // imprimo el resultado 
{
    if (condicion == true)
    {
        printf("es capicua");
    }
    else
    {
        printf("no es capicua");
    }
}
int main ()
{
    int numero;
    printf("ingrese el numero: ");
    scanf("%d",&numero);
    imprimir ( es_capicua(numero,invertir_numero(numero))); // muy rebuscada pero puede funcionar 
    return 0;
}