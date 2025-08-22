/* 
 * Ejercicio 1
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>
void HolaMundo()
{
    char saludo[20]="Hola Mundo C!.";
    printf("%s\n",saludo);
}
int main ()
{
    // para poder ejecutar debe entrar por CMD en el caso de windows y en el caso de Ubuntu por terminal
    // una vez en el CMD ingresar a la ruta donde se encuentra en archivo.c y encribir la siguiente linea de comando 
    // gcc (nombre del archivo).c "ejercicio1.c" -o (el "-o" es para colocarle un nombre en especifico) ejercicio1
    // una ves compilado colocar el nombre del .exe (ejercicio1) y felicidades compilo con exito su primer archivo.exe por terminal con gcc
    HolaMundo();
    return 0;
}