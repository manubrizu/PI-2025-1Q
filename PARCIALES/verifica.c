#include <stdio.h>
#define N 6

int verifica(int mat[][N]);
int verificaSubcuadrado(int mat[][N], int fila, int columna, int* sum);

int main() {
    int matValida[N][N] = {
        {1, 2, 3, 6, 5, 4},
        {4, 5, 6, 3, 2, 1},
        {7, 8, 9, 9, 8, 7},
        {1, 2, 3, 6, 5, 4},
        {4, 5, 6, 3, 2, 1},
        {7, 8, 9, 9, 8, 7}
    };

    if (!verifica(matValida)) {
        puts("Fallo el test de matriz válida");
        return 1;
    }

    puts("Test OK!");
    return 0;
}

int verifica(int mat[][N]){
    int suma = 0;
    for (int i = 0; i < N; i += 3){
        for (int j = 0; j < N; j += 3){
            if(!verificaSubcuadrado(mat, i, j, &suma)){
                return 0;
            }
        }
    }
    return 1;
}

int verificaSubcuadrado(int mat[][N], int fila, int col, int* sum){
    int apariciones[3*N + 1] = {0};
    int suma = 0;

    for (int i = fila; i < fila + 3; i++){
        for (int j = col; j < col + 3; j++){
            if(mat[i][j] < 1 || mat[i][j] > 3*N){
                return 0;
            }
            if(apariciones[mat[i][j] - 1]){
                return 0;
            }
            apariciones[mat[i][j] - 1] = 1;
            suma += mat[i][j];
        }
    }

    if(*sum == 0) {
        *sum = suma;
        return 1;
    }

    return (*sum == suma);
}