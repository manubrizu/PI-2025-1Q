#include <stdio.h>

#define SWAP(c1, c2) { int aux = c1; \
                        c1 = c2; \
                        c2 = aux;}
#define DIM 4

typedef enum colors {black = 0, white, blue, red, purple, orange} colors;

int checkBoard(char mat[][DIM]);

int main() {
    char board1[DIM][DIM] = {
        {black, white, black, white},
        {white, black, white, black},
        {black, white, black, white},
        {white, black, white, black}
    };

    char board2[DIM][DIM] = {
        {black, black, black, white},
        {white, black, white, black},
        {black, white, black, white},
        {white, black, white, black}
    };

    char board3[DIM][DIM] = {
        {black, white, black, white},
        {white, black, white, black},
        {black, white, black, white},
        {white, black, blue, black}
    };

    printf("Board 1: %d\n", checkBoard(board1)); // Debe imprimir 1 (válido)
    printf("Board 2: %d\n", checkBoard(board2)); // Debe imprimir 0 (adyacentes iguales)
    printf("Board 3: %d\n", checkBoard(board3)); // Debe imprimir 0 (más de dos colores)

    return 0;
}

int checkBoard(char mat[][DIM]) {

    int c1 = mat[0][0];
    int c2 = mat[0][1];

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (!((j % 2 == 0 && mat[i][j] == c1) || (j%2 == 1 && mat[i][j] == c2))) {
                return 0;
            }
        }
        SWAP(c1, c2);
    }

    return 1;
}