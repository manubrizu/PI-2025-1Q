#include <stdio.h>

#define DIM 3
#define DIRS 8

int esTableroValido(signed char mat[][DIM]);

int chequeoBomba(signed char mat[][DIM], int fil, int col, int cantMinas);


int main(){
    // Caso 1: Tablero todo con minas (-1)
    signed char tableroTodoMinas[DIM][DIM] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}
    };

    // Caso 2: Tablero sin minas (0)
    signed char tableroSinMinas[DIM][DIM] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Caso 3: Tablero válido con algunas minas
    signed char tableroValido1[DIM][DIM] = {
        {1, -1, 1},
        {2, 2, 2},
        {1, -1, 1}
    };

    // Caso 4: Tablero inválido (números no coinciden con minas adyacentes)
    signed char tableroInvalido[DIM][DIM] = {
        {2, -1, 1},
        {1, 3, 1},
        {0, 0, 0}
    };

    // Prueba de cada caso
    printf("\nCaso 1 - Tablero todo con minas:\n");
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%2d ", tableroTodoMinas[i][j]);
        }
        printf("\n");
    }
    printf("Resultado: %s\n", esTableroValido(tableroTodoMinas) ? "VALIDO" : "NO VALIDO");

    printf("\nCaso 2 - Tablero sin minas:\n");
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%2d ", tableroSinMinas[i][j]);
        }
        printf("\n");
    }
    printf("Resultado: %s\n", esTableroValido(tableroSinMinas) ? "VALIDO" : "NO VALIDO");

    printf("\nCaso 3 - Tablero válido con algunas minas:\n");
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%2d ", tableroValido1[i][j]);
        }
        printf("\n");
    }
    printf("Resultado: %s\n", esTableroValido(tableroValido1) ? "VALIDO" : "NO VALIDO");

    printf("\nCaso 4 - Tablero inválido:\n");
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%2d ", tableroInvalido[i][j]);
        }
        printf("\n");
    }
    printf("Resultado: %s\n", esTableroValido(tableroInvalido) ? "VALIDO" : "NO VALIDO");

    return 0;
}

int esTableroValido(signed char mat[][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            if(mat[i][j] != -1){
                if(!chequeoBomba(mat, i, j, mat[i][j])){
                    return 0;
                }
            }
        }        
    }
    return 1;
}

int chequeoBomba(signed char mat[][DIM], int fil, int col, int cantMinas){
    int dir[][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
    int limI = 0, limS = DIM - 1, xAct, yAct, cant = 0;
    for (int i = 0; i < DIRS && cant < cantMinas; i++){
        xAct = col + dir[i][1];
        yAct = fil + dir[i][0];
        if(xAct >= limI && xAct <= limS && yAct >= limI && yAct <= limS){
            if(mat[yAct][xAct] == -1){
                cant++;
            }
        }
    }
    return (cant == cantMinas);
}