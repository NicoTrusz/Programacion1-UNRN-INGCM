#ifndef JUEGO_H
#define JUEGO_H

#include<stdbool.h>
#include<stdio.h>

#define TAM 8
#define AGUA '~'
#define BARCO 'B'
#define IMPACTO 'X'
#define FALLO 'O'

typedef struct 
{
    char nombre[20];
    int tam;
}Barco;

extern Barco barcos[];
extern int num_barcos;

char **crear_tablero(int tam);
void liberar_tablero(char **tablero, int tam);
void inicializar_tablero(char **tablero, int tam);
void imprimir_tablero(char **tablero, int tam, bool ocultar);
bool puede_colocar(char **tablero, int fila, int col, int tam_barco, bool horizontal, int tam);
void colocar_barco(char **tablero, int tam_barco, int tam);
void colocar_barcos(char **tablero, int tam);
bool disparar(char **tablero, int fila, int col);
bool quedan_barcos(char **tablero, int tam);
void disparo_computadora(char **tablero, bool **disparos, int tam, FILE *log, int *score);
void registrar_disparo(FILE *archivo, int fila, int col, bool acierto);
bool **crear_matriz_bool(int tam);
void liberar_matriz_bool(bool **matriz, int tam);

#endif