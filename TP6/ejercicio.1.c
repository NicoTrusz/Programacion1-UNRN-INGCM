/* 
 * Ejercicio 1.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>


 struct alumno 
 {
    char nombre [50];
    int edad;
    float promedio;
 };

int main ()
{
    struct alumno miAlumno;

    // solicitar datos de usuario
    printf("Ingrese el nombre del Alumno: ");
    fgets(miAlumno.nombre, sizeof(miAlumno.nombre), stdin);

    printf("Ingrese la edad del alumno: ");
    scanf("%d", &miAlumno.edad);

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &miAlumno.promedio);

    // Mostrar los datos ingresados
    printf("\nDatos del alumno:\n");
    printf("Nombre: %s", miAlumno.nombre);
    printf("Edad: %d\n", miAlumno.edad);
    printf("Promedio: %.2f\n", miAlumno.promedio);

    return 0;
}