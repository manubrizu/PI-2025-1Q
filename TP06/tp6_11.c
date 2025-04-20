#include <stdio.h>
#include <stdbool.h>

#define FILAS 4
#define COLS 5

void swap(int* a, int* b);
void bubbleSort(int arr[], int n);
void ordenarColumna(unsigned int cols, unsigned int rows, int mat[][cols], unsigned int selectedCol);
void imprimirMatriz(int matriz[][COLS], int filas, int columnas);

int main(){
    int matriz[FILAS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {3, 5, 8, 2, 1},
        {8, 1, 3, 6, 7}
    };
    
    printf("Matriz Original: \n");
    imprimirMatriz(matriz, FILAS, COLS);

    ordenarColumna(COLS, FILAS, matriz, 3);

    printf("Matriz Ordenada en la columna 3: \n");
    imprimirMatriz(matriz, FILAS, COLS);

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped = true;

    for (i = 0; i < n - 1 && swapped; i++) { 
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
    }
}

void imprimirMatriz(int matriz[][COLS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ordenarColumna(unsigned int cols, unsigned int rows, int mat[][cols], unsigned int selectedCol){
    int aux[rows];
    for (int i = 0; i < rows; i++){
        aux[i] = mat[i][selectedCol-1];
    }
    bubbleSort(aux, rows);
    for (int i = 0; i < rows; i++)
    {
        mat[i][selectedCol-1] = aux[i];
    }   
}
