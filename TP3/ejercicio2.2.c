/* 
 * Ejercicio 2.2
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
 
 #include<stdio.h>
 #include<stddef.h>

 void imprimir_inverso(size_t cantidad, int arreglo[])
 {
    for (int i = (int)cantidad -1; i>=0; i--)
    {
        printf("%d", arreglo[i]);
    }
    printf("\n");
 }

 void imprimir_paridad(size_t cantidad, int arreglo[], int tipo)
 {
    for(size_t i = 0; i < cantidad; i++)
    {
        if (tipo == 0 && arreglo[i] % 2 == 0)
        {
            printf("%d",arreglo[i]);
        }
        else if (tipo == 1 && arreglo[i] % 2 != 0)
        {
            printf("%d", arreglo[i]);
        }
    }
    printf("\n");
 }

 void imprimir_elementos(size_t cantidad, int arreglo[], size_t indice)
 {
    if (indice < cantidad)
    {
        printf("%d", arreglo[indice]);
    }
    else
    {
        printf("Error: indice fuera de rango");
    }
    printf("\n");
 }

 void recorrer_por_indices(size_t cantidadA, int arregloA[], size_t cantidadB, int arregloB[])
 {
    for (size_t i= 0; i < cantidadB; i++)
    {
        int indice = arregloB[i];
        if (indice >= 0 && indice < (int)cantidadA)
        {
            printf("%d", arregloA[indice]);
        }
        else
        {
            printf("Error: indice fuera de rango");
        }
    }
    printf("\n");
 }

 int main()
 {
    int arreglo[] = {1, 2, 3, 4, 5, 6};
    int indices[] = {4, 0, 2};
    int indices_invalidos[] = {4, 0, 2};

    printf("1. Inverso:\n");
    imprimir_inverso(6, arreglo);

    printf("\n2. Pares:\n");
    imprimir_paridad(6, arreglo, 0);

    printf("\n3. Elemento en posicion 3:\n");
    imprimir_elementos(6, arreglo, 3);

    printf("\n4. Recorrido por indices validos:\n");
    recorrer_por_indices(6, arreglo, 3, indices);

    printf("\n4. Recorrido por indices con error:\n");
    recorrer_por_indices(6, arreglo, 3, indices_invalidos);

    return 0;
 }