/* 
 * Ejercicio 2.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>
 #include<string.h>

 typedef struct 
 {
    int codigo;
    char descripcion[50];
    float precio;
 } Producto;
 
 int main()
 {
    Producto p1 = {1001, "Teclado inalambrico", 59999,99};
    Producto p2 = {1010, "Teclado mecanico", 8000,50};

    printf("producto 1: %s - $%.2f\n", p1.descripcion, p1.precio);
    printf("producto 1: %s - $%.2f\n", p2.descripcion, p2.precio);

    if (p1.precio > p2.precio)
    {
      printf("El producto más caro es: %s\n", p1.descripcion);
    } else if (p2.precio > p1.precio) {
        printf("El producto más caro es: %s\n", p2.descripcion);
    } else {
        printf("Ambos productos tienen el mismo precio.\n");
    }

    return 0;
 }