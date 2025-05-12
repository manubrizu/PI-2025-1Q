#include <stdio.h>
#include <stdlib.h>
#include "./../getnum.h"
#include "./../random.h"

#define MAX 90
#define FILAS 3
#define COLUMNAS 5

typedef int TipoLinea[5];
typedef TipoLinea TipoCarton [3];
typedef TipoCarton * Jugadores;

void generarCarton(TipoCarton carton);
int jugar(Jugadores jugadores, int cantidad);
int sacarBolilla(int bolillero[], int * cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);

int main() {
    randomize();
    int cantidad;
    do{
        cantidad = getint("Ingrese la cantidad de usuarios: ");
    } while (cantidad < 1);
    
    Jugadores jugadores = malloc(cantidad * sizeof(TipoCarton));

    for (int i = 0; i < cantidad; i++){
        generarCarton(jugadores[i]);
    }

    int ganador = jugar(jugadores, cantidad);

    printf("\n¡Jugador %d ha ganado!\n", ganador);

    free(jugadores);
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

int jugar(Jugadores jugadores, int cantidad){
    int bolillero[MAX] = {0};
    int cantBolillas = 90, num, gano = 0;

    while (cantBolillas > 0) {
        num = sacarBolilla(bolillero, &cantBolillas);
        printf("Bolilla extraída: %d\n", num);
        
        for (int i = 0; i < cantidad; i++) {
            int lineas = controlarCarton(jugadores[i], num);
            if (lineas > 0) {
                printf("Jugador %d completó %d línea(s)\n", i + 1, lineas);
                if (lineas == 3) {
                    gano = i + 1;
                }
            }
        }
        
        for (int i = 0; i < cantidad; i++){
            printf("\nEstado del cartón Jugador %d:\n", i + 1);
            imprimirCarton(jugadores[i]);
        }

        if(gano != 0){
            return gano;
        }
    }
    return 0;
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