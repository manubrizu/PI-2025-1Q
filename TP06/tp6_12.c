/*
Ejercicio 12 *
Escribir una función que cambie una matriz cuadrada por su traspuesta, recibiendo sólo los siguientes 2
parámetros:
● un número entero positivo que indique la dimensión de la matriz
● la matriz cuadrada
Dicha función debe hacer la conversión sobre la misma matriz recibida, sin usar vectores auxiliares
*/
#include <stdio.h>

#define DIM 3

void swap(int* a, int* b);
void transpuesta(unsigned int dim, int mat[][dim]);
void imprimirMatriz(int matriz[][DIM], int filas, int columnas);

int main(){
    int matriz[][DIM] = {
        {2, 4, 5},
        {6, 9, 2},
        {8, 3, 7}
    };
    
    printf("Matriz Original: \n");
    imprimirMatriz(matriz, DIM, DIM);

    transpuesta(DIM, matriz);

    printf("Matriz Ordenada en la columna 3: \n");
    imprimirMatriz(matriz, DIM, DIM);

    return 0;
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprimirMatriz(int matriz[][DIM], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void transpuesta(unsigned int dim, int mat[][dim]){
    for (int i = 0; i < dim; i++){        
        for (int j = i + 1; j < dim; j++){  // analizo solo la parte superior derecha de la matriz
                swap(&mat[i][j], &mat[j][i]);            
        }        
    }
    
}