/* 
 * Ejercicio 4.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 #include<stdio.h>

 #define TAM 5

 typedef struct 
 {
    char nombre[50];
    char telefono[20];
    int edad;
 } Persona;


 void cargar_Persona(Persona *p)
 {
    printf("Nombre: ");
    scanf("%[^\n]",p->nombre); // utilizo la sentencia [^\n] para hacer el corte al ingresar la cadena
    printf("Telefono: ");
    scanf("%[^\n]",p->telefono);// utilizo la sentencia [^\n] para hacer el corte al ingresar la cadena
    printf("Edad: ");
    scanf("%d",&p->edad);
 }

 void mostrar_Mayores(Persona agenda[], int tam)
 {
    printf("\nContactos mayores de 18 años:\n");
    for (int i = 0; i < tam; i++)
    {
        if (agenda[i].edad > 18)
        {
            printf("Nombre %s | Telefono: %s | Edad: %d\n", agenda[i].nombre,agenda[i].telefono,agenda[i].edad);
        }
    }
 }

 int main()
 {
    Persona agenda[TAM];

    for (int i =0; i<TAM; i++)
    {
        printf("\nContacto %d:\n",i+1);
        cargar_Persona(&agenda[i]);
    }
    mostrar_Mayores(agenda, TAM);

    return 0;
 }