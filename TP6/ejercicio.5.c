/* 
 * Ejercicio 5.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>


 typedef struct 
 {
    char materia[50];
    int nota;
 } Examen;

 void cargar_Examen(Examen *e)
 {
    printf("Materia: ");
    scanf(" %[^\n]", e->materia);
    printf("Nota: ");
    scanf("%d", &e->nota);
 }
 
 float calcular_Promedio(Examen examenes[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += examenes[i].nota;
    }
    return (float)suma / tam;
}

void mostrarResultado(float promedio) {
    printf("\nPromedio: %.2f\n", promedio);
    if (promedio >= 6) {
        printf("Estado: Aprobado\n");
    } else {
        printf("Estado: Reprobado\n");
    }
}

int main() {
    Examen examenes[3];

    for (int i = 0; i < 3; i++) {
        printf("\nExamen %d:\n", i + 1);
        cargarExamen(&examenes[i]);
    }

    float promedio = calcularPromedio(examenes, 3);
    mostrarResultado(promedio);

    return 0;
}