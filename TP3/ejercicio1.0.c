/* 
 * Ejercicio 1.0
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define DESTINO__INSUFICIENTE -2
#define EXITO 0

 int copia_cadena_segura(char destino[], int tam_dest, const char origen[], int tam_origen)
 {
    int i;
    int bandera = EXITO;
    // Verificar que origen tenga terminador 
    int tiene_terminador = 0;
    for ( i = 0; i < tam_origen; i++)
    {
        if (origen [i] == '\0')
        {
            tiene_terminador = 1;
            break;
        }
    }
    if (!tiene_terminador)
    {
        bandera = CADENA_SIN_TERMINADOR;
    }
    // COPIAR CON LIMITE   
    for (i=0;i<tam_dest -1 && origen[i]!= '\0'; i++)
    {
        destino[i]= origen [i];
    }
    if (origen[i]!= '\0')
    {
        bandera = DESTINO__INSUFICIENTE;
    }
    destino[i] = '\0';
    return bandera;
 }

 int largo_seguro(const char cadena[], int tam_max)
 {
    int bandera = CADENA_SIN_TERMINADOR ;
    for (int i = 0; i< tam_max; i++)
    {
        if (cadena[i]== '\0')
        {
            bandera = i;
            break;
        }
    }
    return bandera;
 }

int main()
{
    char origen1[10] = "Hola";
    char destino1[5];
    int resultado1= copia_cadena_segura(destino1,5,origen1,10);
    printf("Resultado 1: %d, copia: %s\n",resultado1, destino1); // CASO EXITO

    char origen2[10] = {'X','X','X','H','O','L','A','X','X','X'};
    char destino2[10];
    int resultado2= copia_cadena_segura(destino2, 10, origen2, 10 );
    printf("Resultado 2: %d, copia: %s\n",resultado2, destino2); // CADENA_SIN_TERMINADOR

    char origen3[10]= "Hola mundo";
    char destino3[5];
    int resultado3 = copia_cadena_segura(destino3, 5, origen3, 10); // CADENA DESTINO_INSUFICIENTE
    return 0;
}