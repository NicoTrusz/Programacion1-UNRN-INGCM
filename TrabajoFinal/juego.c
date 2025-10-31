#include "juego.h"
#include<stdlib.h>
#include<time.h>

Barco barcos[] = {{"Portaaviones", 4},{"Submarino",3},{"Destructor",2}};
int num_barcos = sizeof(barcos) / sizeof(barcos[0]);

char **crear_tablero(int tam)
{
    char **tablero = malloc(tam * sizeof(char *));
    for (int i = 0; i< tam ; i++)
    {
        tablero[i] = malloc(tam * sizeof(char));
    }
    return tablero;
}

void liberar_tablero(char **tablero, int tam)
{
    for(int i =0; i<tam; i++)
    {
        free(tablero[i]);
    }
    free(tablero);
}

void inicializar_tablero(char **tablero, int tam)
{
    for (int i =0; i<tam; i++)
    {
        for(int j=0; j< tam; j++)
        tablero[i][j] = '~';
    }
}

void imprimir_tablero(char **tablero, int tam, bool ocultar)
{   
    printf("   ");
    for (int col = 0; col < tam; col++)
    {
     printf("%2d ", col);   
    }
    printf("\n");

    for (int fila = 0; fila < tam; fila++) {
        printf("%2d ", fila);
        for (int col = 0; col < tam; col++) {
            char c = tablero[fila][col];
            if (ocultar && c == 'B') c = AGUA;  // Oculta barcos enemigos
            printf(" %c ", c);
        }
        printf("\n");
    }
}

bool puede_colocar(char **tablero, int fila, int col, int tam_barco, bool horizontal, int tam)
{
    bool valido = true;
    for (int i = 0; i< tam_barco; i++)
    {
        int r = fila;
        int c = col;
        if (horizontal) // si el barco esta en pocicion horizontal me desplazo en la columna sino en la fila
        {
            c += i;
        }
        else
        {
            r += i;
        }
        if (r >= tam || c >= tam || tablero[r][c] != AGUA)
        {
            valido = false;
            break;
        }
    }
    return valido;
}

void colocar_barco(char **tablero, int tam_barco, int tam)
{
    while (true)
    {
        bool horizontal = rand() %2;
        int fila = rand() % (tam - (horizontal ? 1 : tam_barco));
        int col = rand() % (tam -(horizontal ? tam_barco : 1));
        if (puede_colocar(tablero, fila, col, tam_barco, horizontal, tam))
        {
            for (int i= 0; i < tam_barco; i++)
            {
                int r = fila + (horizontal ? 0 : i);
                int c = col + (horizontal ? i : 0);
                tablero[r][c]=BARCO;
            }
            break;
        }
    }
}

void colocar_barcos(char **tablero, int tam)
{
    for (int i=0; i < num_barcos; i++)
    {
        colocar_barco(tablero,barcos[i].tam,tam);
    }
}

bool disparar(char **tablero, int fila, int col)
{   bool valido = false;
    if (tablero[fila][col] == BARCO)
    {
        tablero[fila][col] = IMPACTO;
        valido = true;
    }else if (tablero[fila][col] == AGUA)
    {
        tablero[fila][col]= FALLO;
    }
    return valido;
}

bool quedan_barcos(char **tablero, int tam)
{
    bool valido = false;
    for (int i =0; i<tam ; i++)
    {
        for(int j =0; j<tam; j++)
        {
            if (tablero[i][j] == BARCO)
            {
                valido = true;
            }
        }
    }
    return valido;
}

bool disparo_computadora(char **tablero, bool **disparos, int tam, FILE *log, int *score)
{
    int f, c;
    do
    {
        f = rand()%tam;
        c = rand()%tam;
    }while (disparos[f][c]);
    disparos[f][c]= true;

    bool acierto = disparar(tablero,f,c);
    if (acierto)
    {
        (*score)++;
    }
    registrar_disparo(log, f,c,acierto);
   return acierto;
}

void registrar_disparo(FILE *archivo, int fila, int col, bool acierto)
{
    fprintf(archivo, "Disparo en (%d,%d): %s\n",fila,col, acierto ? "Impacto" : "Agua");
}

bool **crear_matriz_bool(int tam)
{
    bool **matriz = malloc(tam * sizeof(bool *));
    for(int i = 0; i< tam; i++)
    {
        matriz[i] = malloc(tam * sizeof(bool));
        for(int j =0; j<tam; j++)
        {
            matriz[i][j]= false;
        }
    }
    return matriz;
}

void liberar_matriz_bool(bool **matriz, int tam)
{
    for (int i =0; i<tam ; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}