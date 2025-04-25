#include <stdio.h>

#define COLS 6

int onlyBin(unsigned char mat[][COLS], int fils);
int esFilaBinaria(unsigned char vec[]);
void copioFila(unsigned char mat[][COLS], int partida, int destino);

int main(){
    // Caso 1: Matriz mixta (caso normal)
    printf("=== CASO 1: Matriz con casos mixtos ===\n");
    unsigned char matriz[][COLS] = {
        {1, 0, 1, 1, 0, 0},  // Fila binaria
        {2, 3, 4, 5, 6, 7},  // No binaria
        {0, 0, 0, 1, 1, 1},  // Fila binaria
        {9, 1, 1, 0, 0, 1},  // No binaria
        {1, 1, 1, 1, 1, 1}   // Fila binaria
    };
    int filas = 5;

    printf("Matriz original:\n");
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    int filasValidas = onlyBin(matriz, filas);

    printf("\nMatriz despues de onlyBin (primeras %d filas son las binarias):\n", filasValidas);
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Cantidad de filas binarias encontradas: %d\n\n", filasValidas);

    // Caso 2: Matriz toda binaria
    printf("=== CASO 2: Matriz toda binaria ===\n");
    unsigned char matrizTodaBinaria[][COLS] = {
        {1, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0}
    };
    int filasBinarias = 4;

    printf("Matriz original:\n");
    for(int i = 0; i < filasBinarias; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%2d ", matrizTodaBinaria[i][j]);
        }
        printf("\n");
    }

    filasValidas = onlyBin(matrizTodaBinaria, filasBinarias);
    
    printf("\nMatriz despues de onlyBin (primeras %d filas son las binarias):\n", filasValidas);
    for(int i = 0; i < filasBinarias; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%2d ", matrizTodaBinaria[i][j]);
        }
        printf("\n");
    }
    printf("Cantidad de filas binarias encontradas: %d\n\n", filasValidas);

    // Caso 3: Matriz sin números binarios
    printf("=== CASO 3: Matriz sin números binarios ===\n");
    unsigned char matrizNoBinaria[][COLS] = {
        {2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13},
        {255, 254, 253, 252, 251, 250}  // Números grandes
    };
    int filasNoBinarias = 3;

    printf("Matriz original:\n");
    for(int i = 0; i < filasNoBinarias; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%3d ", matrizNoBinaria[i][j]);
        }
        printf("\n");
    }

    filasValidas = onlyBin(matrizNoBinaria, filasNoBinarias);
    
    printf("\nMatriz despues de onlyBin (primeras %d filas son las binarias):\n", filasValidas);
    for(int i = 0; i < filasNoBinarias; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%3d ", matrizNoBinaria[i][j]);
        }
        printf("\n");
    }
    printf("Cantidad de filas binarias encontradas: %d\n", filasValidas);

    return 0;
}

int onlyBin(unsigned char mat[][COLS], int fils){ 
    int resp = 0;
    for(int i=0; i<fils; i++){
        if(esFilaBinaria(mat[i])){
            copioFila(mat, i, resp++);
        }
    }
    return resp; 
}

int esFilaBinaria(unsigned char vec[]){
    for(int i=0; i<COLS; i++){
        if(vec[i] != 0 && vec[i] != 1){
            return 0;
        } 
    }
    return 1;
}

void copioFila(unsigned char mat[][COLS], int partida, int destino){
    for(int i=0; i<COLS; i++){
        mat[destino][i] = mat[partida][i];
    }
}