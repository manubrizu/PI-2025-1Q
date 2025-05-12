#include <stdio.h>
#include <stdlib.h>
#include "./../random.h"

#define MAX 90
#define FILAS 3
#define COLUMNAS 5

typedef int TipoLinea[5];
typedef TipoLinea TipoCarton [3];

void generarCarton(TipoCarton carton);
int jugar(TipoCarton carton1, TipoCarton carton2);
int sacarBolilla(int bolillero[], int * cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);

int main() {
    randomize();

    TipoCarton carton1, carton2;
    generarCarton(carton1);  // Generar cartón para jugador 1
    generarCarton(carton2);  // Generar cartón para jugador 2

    printf("Cartón Jugador 1:\n");
    imprimirCarton(carton1);  // Imprimir cartón del jugador 1

    printf("\nCartón Jugador 2:\n");
    imprimirCarton(carton2);  // Imprimir cartón del jugador 2

    int ganador = jugar(carton1, carton2);  // Jugar el bingo

    if (ganador == 1) {
        printf("\n¡Jugador 1 ha ganado!\n");
    } else if (ganador == 2) {
        printf("\n¡Jugador 2 ha ganado!\n");
    } else {
        printf("\n¡Empate! No hubo un ganador.\n");
    }

    return 0;
}

void generarCarton(TipoCarton carton){
    int apar[MAX] = {0};
    int num;
    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            do{
                num = randInt(1, 90);
            } while (apar[num - 1]);
            apar[num - 1] = 1;
            carton[i][j] = num;
        }        
    }    
}

int jugar(TipoCarton carton1, TipoCarton carton2) {
    int bolillero[MAX] = {0};
    int cantBolillas = 90, num, gano = 0;

    while (cantBolillas > 0) {
        num = sacarBolilla(bolillero, &cantBolillas);
        printf("Bolilla extraída: %d\n", num);
        
        int lineas1 = controlarCarton(carton1, num);
        int lineas2 = controlarCarton(carton2, num);

        if (lineas1 > 0) {
            printf("Jugador 1 completó %d línea(s)\n", lineas1);
            if(lineas1 == 3){
                gano = 1; 
            }
        }
        if (lineas2 > 0) {
            printf("Jugador 2 completó %d línea(s)\n", lineas2);
            if(lineas2 == 3){
                gano = 2; 
            }
        }

        // Imprimir el estado de los cartones
        printf("\nEstado del cartón Jugador 1:\n");
        imprimirCarton(carton1);
        printf("\nEstado del cartón Jugador 2:\n");
        imprimirCarton(carton2);
        printf("\n-----------------------------\n");

        if (gano != 0) {
            return gano;
        }
    }
    return gano;
}

int sacarBolilla(int bolillero[], int * cantBolillas){
    int foo;
    do{
        foo = randInt(1, 90);
    } while (bolillero[foo - 1]);
    bolillero[foo - 1] = 1;
    (*cantBolillas)--;
    return foo;
}

int controlarCarton(TipoCarton carton, int bolilla) {
    int check = 0;
    if(buscarBolilla(carton, bolilla)){
        for (int i = 0; i < FILAS; i++){
            if(controlarLineas(carton[i])){
                check++;
            }
        }  
    }
    
    return check;
}

int buscarBolilla(TipoCarton carton, int bolilla){
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (carton[i][j] != 0 && carton[i][j] == bolilla) {
                carton[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int controlarLineas(TipoLinea linea){
    int cont = 0;
    for (int i = 0; i < COLUMNAS; i++){
        if (linea[i] == 0){
            cont++;
        }
    }
    return (cont == COLUMNAS);
}

void imprimirCarton(TipoCarton carton) {
    for (int i = 0; i < 3; i++) {
        printf("Línea %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            if (carton[i][j] != 0)
                printf("%2d ", carton[i][j]);
            else
                printf(" - ");  // Si está marcado, mostrar guion
        }
        printf("\n");
    }
}