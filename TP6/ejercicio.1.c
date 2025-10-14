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
    fgets(miAlumno.nombre, sizeof(miAlumno.nombre), stdin); //---> forma mas optima
    //scanf("%20s",miAlumno.nombre); // %20 para solo poder ingresar 20 elementos en mi cadena
                                // en las cadenas no se requiere & para la asignacion 
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &miAlumno.edad);

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &miAlumno.promedio);

    // Mostrar los datos ingresados
    printf("\nDatos del alumno:\n");
    printf("Nombre: %s", miAlumno.nombre); // en el caso de usar fgets sacar el /n
    printf("Edad: %d\n", miAlumno.edad);
    printf("Promedio: %.2f\n", miAlumno.promedio);

    return 0;
}