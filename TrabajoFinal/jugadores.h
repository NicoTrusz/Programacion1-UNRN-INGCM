/*--------------------------------------------------------
  ===========================
    Archivo: jugadores.h
  ===========================
  Encabezado del módulo de gestión de jugadores.

  Define:
  - Estructura Jugador: nombre, score, disparos
  - Constante MAX_JUGADORES
  - Prototipos:
    - inicializar_jugadores: carga nombres
    - mostrar_ranking_final: ordena y muestra resultados
----------------------------------------------------------*/
#ifndef JUGADORES_H
#define JUGADORES_H

#define MAX_JUGADORES 3

typedef struct {
  char nombre[30];
  int score;
  int disparos;
} Jugador;

void inicializar_jugadores(Jugador jugadores[], int cantidad);
void mostrar_ranking_final(Jugador jugadores[], int cantidad, int score_cpu);

#endif