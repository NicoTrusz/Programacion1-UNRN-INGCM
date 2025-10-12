/* 
 * Ejercicio 3.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>

 typedef struct 
 {
    float base;
    float altura;
 } Rectangulo;

 float calcular_area(Rectangulo r)
 {
    float area = r.base *r.altura;
    return area;
 }

 int main ()
{
    Rectangulo r1 = {5.0, 3.2};

    float area = calcular_area(r1);
    printf("rectangulo de base %.2f y altura %.2f\n", r1.base, r1.altura);
    printf("area: %.2f\n", area);

    return 0;
}