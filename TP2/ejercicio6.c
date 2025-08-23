/* 
 * Ejercicio 6
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */

 int suma_primos(int numero)
 {
    int suma = 0;
    int contador = 0;
    int condicion_de_primo = 2;

    while (condicion_de_primo < numero)
    {
        int es_primo = 1;
        int i;
        for (i=2; i*i <= condicion_de_primo; i++)
        {
            if (condicion_de_primo % i == 0)
            {
                es_primo =0;
                break;
            }
        }
        if (es_primo)
        {
            suma += condicion_de_primo;
            contador++;
        }
        condicion_de_primo++;
    }
    return suma;
 }

 int main ()
 {
    int numero ;
    int resultado ;
    // entrada
    printf ("Ingrese un numero: ");
    scanf("%d",&numero);
    resultado = suma_primos(numero);
    // salida
    printf("la suma de los primeros %d primos es: %d \n",numero,resultado);
    return 0;
 }