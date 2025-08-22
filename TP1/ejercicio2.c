/* 
 * Ejercicio 2
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
#include<stdio.h>
#include<stdlib.h>

float GradosCelsius(float temperatura) // funcion que pasa de C a F 
{
    float Celsisu = temperatura * 9.0 / 5.0 + 32;
    return Celsisu;
}

float GradosFahrenheit(float temperatura) // funcion que pasa de F a C
{
    float Fahrenheit = (temperatura -30) * 5.0 / 9.0 ;
    return Fahrenheit;
}
/*
 En el cuerpo main se define una varaiable para grados centigrados y otra para fahrenhei
 y se definen tambien 2 para llamar a la funcion de cada una (preguntar al profe si puedo definir y llamar en la misma linea)
 retornan los valores de las funciones y las imprimimos para que lo pueda ver el usuario en la terminal
 retornamos a 0 (retutn 0;) para liverar el espacio en memoria.
*/
int main ()
{
    float c = 9.0; // grados centigrados
    float f = 48; // grados Fahrenheit
    float centigrados = 0; // variable para guardar el valor de la funcion 
    float fahrenheit = 0; // variable para guardar el valor de la funcion 
    centigrados = GradosCelsius(c);
    fahrenheit = GradosFahrenheit(f);
    printf("%.2f C = %2.f F\n",c,centigrados); // imprimo en terminal para el usuario
    printf("%2f F = %.2f C\n",f,fahrenheit); // imprimo en la terminal para el usuario
    return 0;
}