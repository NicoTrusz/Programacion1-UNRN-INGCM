#include<stdio.h>

char* busqueda(const char *cadena, const char *buscado)
{
    if (!*buscado)
    {
        return (char*)cadena; // subcadena vacia: se considera encontrada al inicio
    }

    for (; *cadena; cadena++)
    {
        const char *c = cadena;
        const char *b = buscado;

        while (*c && *b && *c == *b)
        {
            c++;
            b++;
        }
        if (!*b)
        {
            return (char*)cadena; // se encontro la subcadena completa
        }
    }

    return NULL; // no se encontro
}

int main ()
{
    const char *texto = "Hola mundo, bienvenido al mundo C";
    const char *sub = "mundo";

    char *resultado = busqueda(texto,sub);

    if (resultado != NULL)
    {
        printf("subcadena encontrada en: \"%s\"\n", resultado);
    }
    else
    {
        printf("subcadena no encontrada. \n");
    }
    return 0;
}