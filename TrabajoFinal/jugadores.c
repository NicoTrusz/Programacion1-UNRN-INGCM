/*-----------------------------------------------------------------
  ===========================
      Archivo: jugadores.c
  ===========================
  Implementación de funciones para gestión de jugadores.

  Funciones:
  - inicializar_jugadores: solicita nombres por consola
  - mostrar_ranking_final: ordena por score y muestra precisión

  Nota:
  - El ranking se ordena descendente por aciertos
  - Se calcula precisión como % de aciertos sobre disparos
------------------------------------------------------------------*/
#include "jugadores.h"
#include <stdio.h>
#include <string.h>

void inicializar_jugadores(Jugador jugadores[], int cantidad) {
  for (int i = 0; i < cantidad; i++) {
    printf("Ingrese nombre del Jugador %d: ", i + 1);
    scanf("%s", jugadores[i].nombre);
    jugadores[i].score = 0;
    jugadores[i].disparos = 0;
  }
}

void mostrar_ranking_final(Jugador jugadores[], int cantidad, int score_cpu) {
  // Ordenar por score descendente
  for (int i = 0; i < cantidad - 1; i++) {
    for (int j = i + 1; j < cantidad; j++) {
      if (jugadores[j].score > jugadores[i].score) {
        Jugador temp = jugadores[i];
        jugadores[i] = jugadores[j];
        jugadores[j] = temp;
      }
    }
  }

  printf("\n Ranking Final de Jugadores:\n");
  for (int i = 0; i < cantidad; i++) {
    float precision =
        jugadores[i].disparos > 0
            ? (float)jugadores[i].score / jugadores[i].disparos * 100
            : 0;
    printf("%d. %s - Aciertos: %d | Disparos: %d | Precision: %.2f%%\n", i + 1,
           jugadores[i].nombre, jugadores[i].score, jugadores[i].disparos,
           precision);
  }

  printf("Computadora: %d aciertos\n", score_cpu);
}
