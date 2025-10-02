#include<stdio.h>
#include<stddef.h>

size_t largo_seguro (const char *str, size_t capacidad)
{
    size_t bandera;
    const char *fin = str;
    while (*fin != '\0' && (size_t)(fin-str)<capacidad)
    {
        fin ++;
        bandera = (size_t)(fin-str);
    }
    return bandera;
}

int main ()
{
    char text[]="Hola mundo";
    size_t capacidad = 20;
    size_t largo = largo_seguro(text, capacidad);
    printf("largo seguro: %zu\n", largo);

    char sin_fin[]={'A', 'B', 'C', 'D', 'E'};
    largo = largo_seguro(sin_fin, 5);
    printf("Largo truncado: %zu\n", largo);

    return 0;
}