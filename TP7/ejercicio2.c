/* 
 * Ejercicio 2.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

#include<stdio.h>
#include<stdlib.h>

 int variable_Global = 10;
 void mostrarDirecciones()
 {
    int variable_Local = 20;

    static int variable_Estatica = 30;
    int *variable_Dinamica = (int *)malloc(sizeof(int));
    if (variable_Dinamica == NULL)
    {
        printf("Error al asignar memoria dinamica.\n");
        free(variable_Dinamica);
        exit(1);
    }
    *variable_Dinamica = 40;
    printf("Direccion de variable global     : %p (segmento de datos)\n", (void *)&variable_Global);
    printf("Direccion de variable local      : %p (segmento stack)\n", (void *)&variable_Local);
    printf("Direccion de variable estatica   : %p (segmento de datos)\n", (void *)&variable_Estatica);
    printf("Direccion de variable dinamica   : %p (segmento heap)\n", (void *)variable_Dinamica);

    free(variable_Dinamica);
 }

 int main()
 {
    mostrarDirecciones();
    return 0;
 }