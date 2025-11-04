/*-------------------------------------------------------------------
  ===========================
        Archivo: main.c
  ===========================
  Punto de entrada del juego Batalla Naval.

  Funcionalidades:
  - Inicializa jugadores (hasta MAX_JUGADORES)
  - Crea tableros individuales para cada jugador y para la computadora
  - Ejecuta turnos de disparo jugador vs computadora
  - Registra jugadas en archivos
  - Muestra ranking final ordenado por puntería

  Requiere:
  - juego.h / juego.c → lógica de tableros y disparos
  - jugadores.h / jugadores.c → gestión de jugadores y estadísticas
---------------------------------------------------------------------*/

#include "juego.h"
#include "jugadores.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int tam = 8;
  int cantidad_jugadores = MAX_JUGADORES;

  Jugador jugadores[MAX_JUGADORES];
  inicializar_jugadores(jugadores, cantidad_jugadores);

  char **tablero_cpu = crear_tablero(tam);
  // bool **disparos_cpu = crear_matriz_bool(tam);
  inicializar_tablero(tablero_cpu, tam);
  colocar_barcos(tablero_cpu, tam);

  // FILE *log_computadora = fopen("computadora.txt", "w");
  // int score_cpu = 0;

  for (int turno = 0; turno < cantidad_jugadores; turno++) {
    // printf("\033[2J\033[H"); no funciono
    system("cls");

    // Tablero del jugador
    char **tablero_jugador = crear_tablero(tam);
    inicializar_tablero(tablero_jugador, tam);
    colocar_barcos(tablero_jugador, tam);

    // Tablero de la computadora (independiente por jugador)
    char **tablero_cpu = crear_tablero(tam);
    inicializar_tablero(tablero_cpu, tam);
    colocar_barcos(tablero_cpu, tam);

    // Matriz de disparos de la computadora
    bool **disparos_cpu = crear_matriz_bool(tam);

    // Archivos de registro
    FILE *log_jugador = fopen(jugadores[turno].nombre,
                              "wb"); // archivo binario por participante
    FILE *log_computadora =
        fopen("computadora.txt", "w"); // archivo txt para CP

    char *mensaje_jugador = "";
    char *mensaje_cpu = "";
    int score_cpu = 0;

    while (true) {
      system("cls");
      // printf("\033[2J\033[H"); al final no funciono :(
      printf("=====================================\n");
      printf("        TURNO DE %s\n", jugadores[turno].nombre);
      printf("=====================================\n\n");
      printf(" Tablero de %s:\n", jugadores[turno].nombre);
      imprimir_tablero(tablero_jugador, tam, false);
      printf("\n Tablero enemigo:\n");
      /* no hacer trampa y dejar en true jajajaja =D
       EL valor True o False hacen que en la funcion imprimir_tablero
       la condicion Ocultar haga su trabajo en ocultar o no los Barcos 'B'
      */
      imprimir_tablero(tablero_cpu, tam, true);
      printf(
          "\nLeyenda: B = Barco   X = Impacto  O = Agua  ~ = no disparado\n");

      if (strlen(mensaje_jugador) > 0) {
        printf("\nResultado de tu disparo: %s\n", mensaje_jugador);
      }
      if (strlen(mensaje_cpu) > 0) {
        printf("Resultado del disparo de la computadora: %s\n", mensaje_cpu);
      }
      int f, c;
      do {
        /* printf("Disparo (fila columna): ");
         if (scanf("%d %d", &f, &c) != 2) {
           printf("\nEntrada invalida\n");
           exit(1);
         }*/
        while (true) {
          printf("Entrada (fila columna): ");
          if (scanf("%d %d", &f, &c) == 2) {
            break;
          }
          char c = 0;
          do {
            c = getchar(); // getchar lee un caracter de entrada
          } while (c != '\n');
          printf("Entrada invalida. ");
        }
        if (f < 0 || f >= tam || c < 0 || c >= tam) {
          printf("Coordenadas fuera de rango.\n");
        } else if (tablero_cpu[f][c] == 'X' || tablero_cpu[f][c] == 'O') {
          printf("Ya disparaste ahi.\n");
        }
      } while (f < 0 || f >= tam || c < 0 || c >= tam ||
               tablero_cpu[f][c] == 'X' || tablero_cpu[f][c] == 'O');

      bool acierto = disparar(tablero_cpu, f, c);
      jugadores[turno].disparos++;
      if (acierto) {
        jugadores[turno].score++;
        mensaje_jugador = "Impacto";
      } else {
        mensaje_jugador = "Agua.";
      }
      registrar_disparo(log_jugador, f, c, acierto);

      if (!quedan_barcos(tablero_cpu, tam)) {
        printf("%s gano! Hundio todos los barcos enemigos.\n",
               jugadores[turno].nombre);
        break;
      }

      printf("\nTurno de la computadora...\n");
      bool acierto_cpu = disparo_computadora(tablero_jugador, disparos_cpu, tam,
                                             log_computadora, &score_cpu);
      mensaje_cpu =
          acierto_cpu ? "La COMPUTADORA IMPACTO" : "LA COMPUTADORA AGUA";

      if (!quedan_barcos(tablero_jugador, tam)) {
        printf("La computadora hundio todos tus barcos. Fin del turno.\n");
        break;
      }
    }

    fclose(log_jugador);
    fclose(log_computadora);
    liberar_tablero(tablero_jugador, tam);
    liberar_tablero(tablero_cpu, tam);
    liberar_matriz_bool(disparos_cpu, tam);
  }

  // Mostrar ranking final
  mostrar_ranking_final(jugadores, cantidad_jugadores,
                        0); // score_cpu no es acumulativo

  return 0;
}

/*
----------------------NOTAS PARA REPARAR---------------------------------
----------------------------SOLUCIONADO----------------------------------
        * Problemas con la imprecion del tablero
       ** Se soluciono pero se tuvo que modificar toda la funcion de
          Imprimir_tablero
-------------------------------------------------------------------------
--------------------------SOLUCIONADO------------------------------------
        * En las cordenadas si se colocan letras o caracteres
          se rompe y entra en bucle de llamada de cordenadas

       ** Arreglo momentaneo si se agrega al gun valor que no
          sea numerico finaliza el programa
       ** Solucionado con getchart
-------------------------------------------------------------------------
---------------------------SOLUCIONADO-----------------------------------
        * Problema con la secuencia de jugador al pasar de un jugador
          a otro no se limpia tablero ni se limpia las jugadas lo
          cual rompe la secuencia de jugadores arreglar de manera urgente

      ** Problema solucionado jugadores
         se implemento archivos binarios para el profe y txt
--------------------------------------------------------------------------
------------------------ERROR NO MORTAL-----------------------------------
       * EL score_cpu al no ser acumulativo solo se compara contra el
         ultimo jugador en el caso que contra el jugador 1 gane la CP
         y contra el ultimo jugador pierda no se hace score entre jugadas
         por lo cual solo queda el ultimo valor de jugada
--------------------------------------------------------------------------
------------------------FALLA SCANF EN JUGADORES.C------------------------
       * Al agregar un nombre + un espacio toma como si estuviera
       colocando doble nombre de jugadores ya que el Scanf con %s
       lee hasta recibir un espacio
    ** Solucionado con getchart
--------------------------------------------------------------------------
*/