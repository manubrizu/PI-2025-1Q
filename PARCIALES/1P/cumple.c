/* PRIMER PARCIAL 23-09-2022*/

#include <stdio.h>

#define N 5

int cumple(int m[][N]);
int cumpleFila(int vec[], int fila);

int main(){
    // Test case 1: Valid matrix
    int m1[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    if (!cumple(m1)) {
        printf("Error en test 1\n");
        return 1;
    }

    // Test case 2: Matrix with repeated numbers in same row
    int m2[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 24}
    };
    if (cumple(m2)) {
        printf("Error en test 2\n");
        return 1;
    }

    // Test case 3: Matrix with numbers out of range
    int m3[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 26}
    };
    if (cumple(m3)) {
        printf("Error en test 3\n");
        return 1;
    }

    // Test case 4: Matrix with numbers from wrong row
    int m4[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 1}
    };
    if (cumple(m4)) {
        printf("Error en test 4\n");
        return 1;
    }

    // Test case 5: Matrix with all same numbers in a row
    int m5[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 11, 11, 11, 11},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    if (cumple(m5)) {
        printf("Error en test 5\n");
        return 1;
    }

    // Test case 6: Matrix with numbers in wrong order but valid
    int m6[N][N] = {
        {5, 4, 3, 2, 1},
        {10, 9, 8, 7, 6},
        {15, 14, 13, 12, 11},
        {20, 19, 18, 17, 16},
        {25, 24, 23, 22, 21}
    };
    if (!cumple(m6)) {
        printf("Error en test 6\n");
        return 1;
    }

    printf("OK!\n");
    return 0;
}

int cumple(int m[][N]){
    for (int i = 0; i < N; i++){
        if (!cumpleFila(m[i], i)){
            return 0;
        }        
    }
    return 1;
}

int cumpleFila(int vec[], int fila){
    int minimo = (N * fila) + 1, maximo = N * (fila + 1), aparicion[N] = {0};         // inicializo todos en 0
    for (int j = 0; j < N; j++){
        if(!(vec[j] >= minimo && vec[j] <= maximo)){        // chequeo para que este entre 1 y N*N
            return 0;
        }
        else if (aparicion[vec[j] - minimo]){                     // chequeo q no haya repetidos
            return 0;
        }
        aparicion[vec[j] - minimo] = 1;
    }
    return 1;
}