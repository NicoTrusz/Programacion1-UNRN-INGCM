/* 
 * Ejercicio 3
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */

 #include<stdio.h>

 void tabla_de_multiplicar(int numero)
 {
    int i;
    for (i=1; i<= 10; i++)
    {
        int multiplicacion = 0;
        multiplicacion = numero * i;
        printf("%d x %d = %d \n", numero,i,multiplicacion);
    }
 }

 int main ()
 {
    int numero;
    // entrada
    printf("Ingrese el numero de la tabla de multiplicar que quiere realizar: ");
    scanf("%d",&numero);
    // salida
    tabla_de_multiplicar(numero); 
    /*en este caso directamente llamo a la funcion que ya me imprime por terminal al usuario
    como en otros casos que defino una variable para luego imprimirla 
    recordatorio consultar al docente si esta permitido llamar desde el print a una funcion 
    */ 
 }