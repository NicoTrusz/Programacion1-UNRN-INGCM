#include<stdio.h>
#include<stdlib.h>
int main() {

    int papel = 3 ;
    int tijera = 2 ;
    int piedra = 1 ;

    int jugador1 = 0;
    int jugador2 = 0;
    printf("Ingrese la juada del jugador 1 (1 para piedra, 2 para tijera, 3 para papel): ");
    scanf("%d", &jugador1);
    printf("Ingrese la juada del jugador 2 (1 para piedra, 2 para tijera, 3 para papel): ");
    scanf("%d", &jugador2);

    if (jugador1 == jugador2 ){
        printf("Empate");
    } else if ((jugador1 == papel && jugador2 == piedra) || (jugador1 == tijera && jugador2 == papel) || (jugador1 == piedra && jugador2 == tijera)) {
        printf("Gana jugador 1");
    } else {
        printf("Gana jugador 2");
    }
    return 0;
}