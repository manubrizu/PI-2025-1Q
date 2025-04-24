#include <stdio.h>

#define N 6

int verifica(int mat[][N]);
int verificaSubcuadrado(int mat[][N], int fila, int columna, int* sum);

int main() {
    // Test case 1: Valid matrix with correct sums
    int mat1[N][N] = {
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 9, 16, 17, 18},
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 9, 16, 17, 18}
    };
    if (!verifica(mat1)) return 1;

    // Test case 2: Invalid matrix with repeated numbers in sub-square
    int mat2[N][N] = {
        {1, 1, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 9, 16, 17, 18},
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 9, 16, 17, 18}
    };
    if (verifica(mat2)) return 1;

    // Test case 3: Invalid matrix with different sums in sub-squares
    int mat3[N][N] = {
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 9, 16, 17, 18},
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 1, 16, 17, 18}  // Changed 9 to 1 to make sum different
    };
    if (verifica(mat3)) return 1;

    // Test case 4: Invalid matrix with number out of range
    int mat4[N][N] = {
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 9, 16, 17, 18},
        {1, 2, 3, 10, 11, 12},
        {4, 5, 6, 13, 14, 15},
        {7, 8, 19, 16, 17, 18}  // 19 is out of range (1-18)
    };
    if (verifica(mat4)) return 1;

    puts("OK!");
    return 0;
}

int verifica(int mat[][N]){
    int suma = 0;
    for (int i = 0; i < N; i +=3){
        for (int j = 0; j < N; j +=3){
            if(!verificaSubcuadrado(mat, i, j, &suma)){
                return 0;
            }
        }        
    }
    return 1;    
}

int verificaSubcuadrado(int mat[][N], int fila, int col, int* sum){
    int apariciones[3*N + 1] = {0};  // +1 to avoid index 0 issues
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