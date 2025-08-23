/* 
 * Ejercicio 1
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */

 #include<stdio.h>
 /*
 se divide el numero por 10 por el tamaño que soporta el int en el caso de 
 necesitar mas cantidad de digitos cambiar el int que entra como parametro 
 en la funcion, el int que se utiliza para ingresar el numero en el cuerpo main 
 por unsigned long long si es un numero enorme y sino por long long que llega a 19 bits
 si se requiere mas de 30 digitos se tiene que utilizar cadenas[]
 */
 int contar_digitos(int numero)
 {
    int contador = 0;
    do 
    {
        numero /= 10; 
        contador ++;
    }
    while (numero > 0);
    {
        return contador;
    }
 }

 int main ()
 {
    // entrada
    int numero ;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d",&numero);
    // salida
    if (numero > 0)
    {
        int cantidad = 0;
        cantidad = contar_digitos(numero);
        printf("Cantidad de digitos: %d \n", cantidad);
    }
    else 
    {
        printf("El numero debe ser positivo. \n");
    }
    return 0;
 }