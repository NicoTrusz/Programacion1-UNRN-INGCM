/*
 estructura para agregar mas de un solo jugador
 aun se esta por implementar
*/
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