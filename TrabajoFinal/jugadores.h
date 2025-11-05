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
#define MAX_JUGADORES 1

typedef struct {
  char nombre[30];
  int score;
  int disparos;
} Jugador;

/*
  Función: inicializar_jugadores
  ------------------------------
  Solicita el nombre de cada jugador y los inicializa con score y disparos en
  cero.

  Parámetros:
    - jugadores: arreglo de estructuras Jugador
    - cantidad: número de jugadores

  Retorna:
    - void
*/
void inicializar_jugadores(Jugador jugadores[], int cantidad);
/*
  Función: mostrar_ranking_final
  ------------------------------
  Ordena los jugadores por score descendente y muestra sus estadísticas.

  Parámetros:
    - jugadores: arreglo de estructuras Jugador
    - cantidad: número de jugadores
    - score_cpu: aciertos totales de la computadora

  Retorna:
    - void
*/
void mostrar_ranking_final(Jugador jugadores[], int cantidad, int score_cpu);

#endif