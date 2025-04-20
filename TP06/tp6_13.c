#include <stdio.h>

#define DIM 3

int productoInterno(int fila[], int col[], int dim);
void obtenerColumna(int mat[][DIM], int col[], int selectedCol, int dim);
void productoMatrices(int mat1[][DIM], int mat2[][DIM], int matRes[][DIM], int dim);
void imprimirMatriz(int mat[][DIM], int dim);


int main() {
    int A[][DIM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[][DIM] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[DIM][DIM];

    productoMatrices(A, B, C, DIM);

    printf("Matriz A:\n");
    imprimirMatriz(A, DIM);

    printf("\nMatriz B:\n");
    imprimirMatriz(B, DIM);

    printf("\nProducto A x B:\n");
    imprimirMatriz(C, DIM);

    return 0;
}

void productoMatrices(int mat1[][DIM], int mat2[][DIM], int matRes[][DIM], int dim) {
    int columna[DIM];
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            obtenerColumna(mat2, columna, j, dim);
            matRes[i][j] = productoInterno(mat1[i], columna, dim);
        }
    }
}

int productoInterno(int fila[], int col[], int dim) {
    int suma = 0;
    for (int i = 0; i < dim; i++)
        suma += fila[i] * col[i];
    return suma;
}

// Copia una columna de la matriz a un vector
void obtenerColumna(int mat[][DIM], int col[], int selectedCol, int dim) {
    for (int i = 0; i < dim; i++)
        col[i] = mat[i][selectedCol];
}

// Función para imprimir matrices
void imprimirMatriz(int mat[][DIM], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}
