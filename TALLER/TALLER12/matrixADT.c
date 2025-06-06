#include <stdio.h>
#include <stdlib.h>
#include "matrixADT.h"

typedef struct row {
    elementType * cols;
    size_t countCol;
} row;


typedef struct matrixCDT{
    row * rows;
    size_t countRow;
} matrixCDT;

matrixADT newMatrix(){
    return calloc(1, sizeof(matrixCDT));
}

void freeMatrix(matrixADT m){
    for (int i = 0; i < m->countRow; i++){
        free(m->rows[i].cols); 
    }
    free(m->rows);
    free(m);    
}

int setElement(matrixADT m, size_t row, size_t col, elementType elem){
    // primero tengo que asegurarme que este ese lugar en la matriz
    if (row >= m->countRow){
        m->rows = realloc(m->rows, (row + 1) * sizeof(struct row));
        for (int i = m->countRow; i <= row; i++){
            m->rows[i].cols = NULL;
            m->rows[i].countCol = 0;
        }
        m->countRow = row + 1;
    }

    if (col >= m->rows[row].countCol){
        m->rows[row].cols = realloc(m->rows[row].cols, (col + 1) * sizeof(elementType));
        m->rows[row].countCol = col + 1;
    }

    m->rows[row].cols[col] = elem;    
    return 1;
}


int getElement(matrixADT m, size_t row, size_t col, elementType * out){
    if(row >= m->countRow || col >= m->rows[row].countCol){
        return 0;
    }
    
    *out = m->rows[row].cols[col];
    return 1;
}

size_t rows(matrixADT m){
    return m->countRow;
}