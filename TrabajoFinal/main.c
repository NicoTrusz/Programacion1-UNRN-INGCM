#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include "juego.h"

int main ()
{
    srand(time(NULL));
    int tam = 8;
    
    char **jugador = crear_tablero(tam);
    char **computadora = crear_tablero(tam);
    bool **disparos_cpu = crear_matriz_bool(tam);

    FILE *log_jugador = fopen("jugador.txt","w");
    FILE *log_computadora = fopen("computadora.txt","w");

    inicializar_tablero(jugador, tam);
    inicializar_tablero(computadora, tam);
    colocar_barcos(jugador, tam);
    colocar_barcos(computadora, tam);

    int score_jugador = 0, score_cpu = 0;
    char mensaje_jugador[30]= "";
    char mensaje_cpu[30]= "";
    while(true)
    {
        system("cls");  // Limpia la terminal

        printf("\nTu tablero: \n");
        imprimir_tablero(jugador, tam, false);
        printf("\n tablero enemigo:\n");
        imprimir_tablero(computadora, tam, true);
        printf("\n Leyenda: B = Barco   X = Impacto  O = Agua  ~ = no disparado\n");

        if (strlen(mensaje_jugador) > 0) 
        {
            printf("\nResultado de tu disparo: %s\n", mensaje_jugador);
        }
        if (strlen(mensaje_cpu) > 0)
        {
            printf("Resultado del disparo de la computadora: %s\n", mensaje_cpu);
        }

        //  Limpieza de buffers antes de cargar nuevos mensajes
        //memset(mensaje_jugador, 0, sizeof(mensaje_jugador));
        //memset(mensaje_cpu, 0, sizeof(mensaje_cpu));


        int f,c;
        do
        {
            printf("Disparo (fila columna): ");
            scanf("%d %d", &f, &c);
            if (f < 0 || f >= tam || c < 0 || c >= tam)
            printf("Coordenadas fuera de rango.\n");
            else if (computadora[f][c] == 'X' || computadora[f][c] == 'O')
            printf("Ya disparaste ahi.\n");

        }while(f<0 || f>= tam || c < 0 || c>= tam || computadora[f][c]=='X' || computadora[f][c] == 'O');
        
        bool acierto = disparar(computadora,f,c);
        if (acierto)
        {
            score_jugador++;
            strcpy(mensaje_jugador, "Impacto");
        }
        else
        {
            strcpy(mensaje_jugador, "Agua.");
        }
        registrar_disparo(log_jugador,f,c,acierto);

        if (!quedan_barcos(computadora, tam))
        {
            printf("Ganaste\n");
            break;
        }
        
        printf("\nTurno de la computadora...\n");
        bool acierto_cpu = disparo_computadora(jugador, disparos_cpu, tam, log_computadora, &score_cpu);
        strcpy(mensaje_cpu, acierto_cpu ? "La computadora acerto." : "La computadora fallo.");


        if(!quedan_barcos(jugador,tam))
        {
            printf("Perdiste. Todos tus barcos fueron hundidos.\n");
            break;
        }
    }
    printf("\n Puntaje Final :\n Jugador %d \n Computadora: %d\n", score_jugador,score_cpu);
    if (score_jugador > score_cpu)
    {
        printf("Tuviste mejor punteria!\n");
    }
    else if (score_jugador < score_cpu)
    {
        printf("Te Gano la Computadora");
    }
    fclose(log_jugador);
    fclose(log_computadora);
    liberar_tablero(jugador, tam);
    liberar_tablero(computadora, tam);
    liberar_matriz_bool(disparos_cpu, tam);

    return 0;
}