/* 
 * Ejercicio 3.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *copiar_cadena(const char *src)
{   
    char *bandera = NULL;

    if (src != NULL) {
        char *copia_src = malloc(strlen(src) + 1);
        if (copia_src != NULL) {
            strcpy(copia_src, src);
            bandera = copia_src;
        } else {
            printf("Error: no se pudo asignar memoria\n");
        }
    }
    return bandera;
}

int main ()
{
    char entrada [100];

    printf("Ingrese una cadena: ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    char *copia = copiar_cadena(entrada);
    if (copia != NULL)
    {
        printf("Cadena copiada: %s\n", copia);
        free(copia);
    }
}