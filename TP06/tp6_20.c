/*
Ejercicio 20 ***
Escribir una función que compruebe si una solución dada a un Sudoku es correcta sabiendo que:
● Un tablero sudoku se compone de una matriz de 9 filas por 9 columnas. A su vez el tablero se subdivide en 9
subcuadrados de 9 casillas cada uno (3x3) NO SUPERPUESTOS (un número en una posición NO puede pertenecer
a dos subcuadrados).
● Se debe verificar que todas las casillas contienen un número comprendido entre el 1 y el 9. Si alguna casilla
contiene un número menor a 1 o mayor a 9, es incorrecta la matriz.
● Por fila, no hay valores repetidos
● Por columna, no hay valores repetidos
● Por subcuadrado, no hay valores repetidos
*/

#include <stdio.h>
#include <assert.h>
#include <math.h>

#define DIM 9

int sudokuSolver(char m[][DIM]);
int verifico(char vec[], int dim);
int verificoSubcuadrado(int dim, char m[][dim], int incioFila, int inicioCol);

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);

  printf("OK\n");

  return 0;
}

int sudokuSolver(char m[][DIM]){
    for (int i = 0; i < DIM; i++) {
        char vecFila[DIM], vecColumna[DIM];
        for (int j = 0; j < DIM; j++) {
            vecFila[j] = m[i][j];       
            vecColumna[j] = m[j][i];   
        }
        if (!verifico(vecFila, DIM) || !verifico(vecColumna, DIM)) {
            return 0; 
        }
    }
        
    for (int i = 0; i < DIM; i += 3){
        for (int j = 0; j < DIM; j += 3){
            if(!verificoSubcuadrado(DIM, m, i, j)){
                return 0;
            }
        }
    }  

    return 1;    
}

int verifico(char vec[], int dim){
    int suma = 0, presente[9];

    for (int i = 0; i < DIM; i++){
        presente[i] = 0;
    }
    

    for (int i = 0; i < dim; i++){
        suma += vec[i];
        if(vec[i] < 1 || vec[i] > 9)
            return 0;        
        presente[vec[i] - 1] = 1;
    }    

    for (int i = 0; i < 9; i++) {
        if (presente[i] == 0) {
            return 0;
        }
    }
    return (suma == 45) ? 1 : 0;
}

int verificoSubcuadrado(int dim, char m[][dim], int inicioFila, int inicioCol) {
    char vecCuadrado[9]; 
    int indice = 0;

    for (int i = inicioFila; i < inicioFila + 3; i++) {
        for (int j = inicioCol; j < inicioCol + 3; j++) {
            vecCuadrado[indice++] = m[i][j];
        }
    }

    return verifico(vecCuadrado, 9);
}