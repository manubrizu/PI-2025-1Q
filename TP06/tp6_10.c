#include <stdio.h>
#include "./../random.h"

#define ROWS 20
#define COLS 80
#define CIRCUNDANTES 8

void generarMatriz(int vec[ROWS][COLS], int filas, int cols);

void generarCielo(int vec[ROWS][COLS], unsigned int rows, unsigned int cols);

int main(){
    int cielo[ROWS][COLS];
    generarMatriz(cielo, ROWS, COLS);
    generarCielo(cielo, ROWS, COLS);
    return 0;
}

void generarMatriz(int vec[ROWS][COLS], int filas, int cols){
    randomize();
    for(int i = 0; i < filas; ++i){
        for (int j = 0; j < cols; ++j){
            vec[i][j] = randInt(0, 20);
        }        
    }
}

void generarCielo(int vec[ROWS][COLS], unsigned int row, unsigned int col){
    const int dx[CIRCUNDANTES] = {-1, -1, -1,  0, 0, 1, 1, 1};
    const int dy[CIRCUNDANTES] = {-1,  0,  1, -1, 1, -1, 0, 1};
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            int intensidad = vec[i][j];

            for (int k = 0; k < CIRCUNDANTES; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                intensidad += vec[ni][nj];
            }

            if (intensidad / 9 > 10)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    
    
}