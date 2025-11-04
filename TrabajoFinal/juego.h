/*----------------------------------------------------------
  ===========================
       Archivo: juego.h
  ===========================
  Encabezado del módulo de tablero y lógica de juego.

  Define:
  - Constantes visuales (AGUA, BARCO, IMPACTO, FALLO)
  - Estructura Barco
  - Prototipos de funciones para:
    - Creación y liberación de tableros
    - Inicialización y visualización
    - Colocación de barcos
    - Disparos y verificación
    - Registro de jugadas
-----------------------------------------------------------*/

#ifndef JUEGO_H
#define JUEGO_H

#include <stdbool.h>
#include <stdio.h>

#define TAM 8
#define AGUA '~'
#define BARCO 'B'
#define IMPACTO 'X'
#define FALLO 'O'

typedef struct {
  char nombre[20];
  int tam;
} Barco;

typedef struct {
  bool cazando;    // true si está en modo cacería
  int ultimo_fila; // última coordenada de impacto
  int ultimo_col;
  int direccion_actual; // 0=arriba, 1=derecha, 2=abajo, 3=izquierda
  int intentos;         // intentos de dirección
} ModoCazeria;

/*
  Función: crear_tablero
  ----------------------
  Reserva memoria dinámica para un tablero cuadrado de tamaño tam x tam.

  Parámetros:
    - tam: tamaño del tablero

  Retorna:
    - char**: puntero doble a la matriz de caracteres
*/
char **crear_tablero(int tam);
/*
  Función: liberar_tablero
  ------------------------
  Libera la memoria previamente asignada a un tablero.

  Parámetros:
    - tablero: matriz de juego (char**)
    - tam: tamaño del tablero

  Retorna:
    - void
*/
void liberar_tablero(char **tablero, int tam);
/*
  Función: inicializar_tablero
  ----------------------------
  Rellena el tablero con el carácter '~' indicando agua/no disparado.

  Parámetros:
    - tablero: matriz de juego (char**)
    - tam: tamaño del tablero

  Retorna:
    - void
*/
void inicializar_tablero(char **tablero, int tam);
/*
  Función: imprimir_tablero
  -------------------------
  Muestra el tablero en consola con coordenadas. Puede ocultar los barcos si se
  desea.

  Parámetros:
    - tablero: matriz de juego (char**)
    - tam: tamaño del tablero
    - ocultar: si es true, oculta los barcos ('B')

  Retorna:
    - void
*/
void imprimir_tablero(char **tablero, int tam, bool ocultar);
/*
  Función: puede_colocar
  ----------------------
  Verifica si un barco puede colocarse en una posición sin salirse ni
  superponerse.

  Parámetros:
    - tablero: matriz de juego (char**)
    - fila, col: coordenadas iniciales
    - tam_barco: tamaño del barco
    - horizontal: orientación del barco
    - tam: tamaño del tablero

  Retorna:
    - true si se puede colocar, false si no
*/
bool puede_colocar(char **tablero, int fila, int col, int tam_barco,
                   bool horizontal, int tam);
/*
  Función: colocar_barco
  ----------------------
  Coloca un barco aleatoriamente en el tablero respetando las reglas de
  ubicación.

  Parámetros:
    - tablero: matriz de juego (char**)
    - tam_barco: tamaño del barco
    - tam: tamaño del tablero

  Retorna:
    - void
*/
void colocar_barco(char **tablero, int tam_barco, int tam);
/*
  Función: colocar_barcos
  -----------------------
  Coloca todos los barcos definidos en el tablero.

  Parámetros:
    - tablero: matriz de juego (char**)
    - tam: tamaño del tablero

  Retorna:
    - void
*/
void colocar_barcos(char **tablero, int tam);
/*
  Función: disparar
  -----------------
  Marca el resultado de un disparo en el tablero.

  Parámetros:
    - tablero: matriz de juego (char**)
    - fila, col: coordenadas del disparo

  Retorna:
    - true si fue impacto, false si fue agua
*/
bool disparar(char **tablero, int fila, int col);
/*
  Función: quedan_barcos
  ----------------------
  Verifica si quedan barcos activos en el tablero.

  Parámetros:
    - tablero: matriz de juego (char**)
    - tam: tamaño del tablero

  Retorna:
    - true si hay al menos un barco, false si todos fueron hundidos
*/
bool quedan_barcos(char **tablero, int tam);
/*
  Función: disparo_computadora
  ----------------------------
  Realiza un disparo aleatorio sobre el tablero del jugador, evitando repetir
  coordenadas.

  Parámetros:
    - tablero: matriz del jugador (char**)
    - disparos: matriz booleana de disparos realizados (bool**)
    - tam: tamaño del tablero
    - log: archivo de registro
    - score: puntero al contador de aciertos de la computadora

  Retorna:
    - true si fue impacto, false si fue agua
*/
bool disparo_computadora(char **tablero, bool **disparos, int tam, FILE *log,
                         int *score);
/*
  Función: disparo_computadora_inteligente
  ----------------------------------------
  Disparo mejorado: si acierta, entra en modo cacería y busca alrededor.

  Parámetros:
    - tablero: tablero del jugador
    - disparos: matriz de disparos realizados
    - tam: tamaño del tablero
    - log: archivo de registro
    - score: puntero al score de la CPU
    - estado: puntero al estado interno de la CPU

  Retorna:
    - true si fue impacto, false si fue agua
*/
bool disparo_computadora_inteligente(char **tablero, bool **disparos, int tam,
                                     FILE *log, int *score,
                                     ModoCazeria *estado);
/*
  Función: registrar_disparo
  --------------------------
  Escribe en el archivo el resultado de un disparo.

  Parámetros:
    - archivo: puntero al archivo
    - fila, col: coordenadas del disparo
    - acierto: true si fue impacto, false si fue agua

  Retorna:
    - void
*/
void registrar_disparo(FILE *archivo, int fila, int col, bool acierto);
/*
  Función: crear_matriz_bool
  --------------------------
  Crea una matriz booleana para registrar disparos realizados.

  Parámetros:
    - tam: tamaño del tablero

  Retorna:
    - bool**: matriz de valores false
*/
bool **crear_matriz_bool(int tam);
/*
  Función: liberar_matriz_bool
  ----------------------------
  Libera la memoria de la matriz booleana.

  Parámetros:
    - matriz: matriz booleana (bool**)
    - tam: tamaño del tablero

  Retorna:
    - void
*/
void liberar_matriz_bool(bool **matriz, int tam);

#endif