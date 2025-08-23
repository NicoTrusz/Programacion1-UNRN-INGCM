/* 
 * Ejercicio 5
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicolastrusz
 */
// reutilizado del ejercicio 4 solo se modifico las condiciones del if para comparar y que sea menor 
  int numero_mayor(int num1, int num2, int num3)
 {
    int mayor = num1;
    if (num2 < mayor)
    {
        mayor = num2;
    }
    if (num3 < mayor)
    {
        mayor = num3;
    }
    return mayor ;
 }

  int main ()
 {
    int numero1;
    int numero2;
    int numero3;
    int funcion =0;
    // entrada
    printf("Ingrese numero 1: ");
    scanf("%d",&numero1);
    printf("Ingrese numero 2: ");
    scanf("%d",&numero2);
    printf("Ingrese numero 3: ");
    scanf("%d",&numero3);
    funcion = numero_mayor(numero1,numero2,numero3);
    // salida
    printf("el numero menor es: %d\n",funcion);
    return 0;
 }