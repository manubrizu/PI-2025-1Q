#include <assert.h>
#include <stdio.h>


int verificaSuma(unsigned int rows1, unsigned int cols1, unsigned int m1[][cols1], unsigned int rows2, unsigned int cols2, unsigned int m2[][cols2]);
int verifica(unsigned int rows1, unsigned int cols1, unsigned int m1[][cols1], unsigned int rows2, unsigned int cols2, unsigned int m2[][cols2]);
int incluyeSuma(unsigned int suma, unsigned int rows, unsigned int cols, unsigned int m[][cols]);
unsigned int sumar (const unsigned int v[], unsigned int dim);

int main(void) {
    unsigned int m1[][4] = {{1, 1, 3, 3}, // la fila suma 8
                            {2, 3, 5, 5}, // la fila suma 15
                            {3, 3, 4, 2}}; // suma 12

    unsigned int m2[][3] = {{2, 4, 6}, // la fila suma 12
                            {3, 6, 3}, // la fila suma 12
                            {6, 5, 4}}; // suma 15

    assert(verificaSuma(3, 4, m1, 3, 3, m2)==2);
    assert(verificaSuma(3, 3, m2, 3, 4, m1)==1);

    // las sumas de las filas de m1 está incluidas en m3, pero no a la inversa
    unsigned int m3[][1] = { {15}, {8}, {11}, {12}, {15}};
    assert(verificaSuma(3, 4, m1, 5, 1, m3)==1);
    assert(verificaSuma(4, 1, m3, 3, 4, m1)==2);

    puts("OK!");
    return 0;
}

unsigned int sumar (const unsigned int v[], unsigned int dim) {
    unsigned int sum=0;
    for(int i=0; i<dim; i++) {
        sum += v[i];
    }
    return sum;
}


int incluyeSuma(unsigned int suma, unsigned int rows, unsigned int cols, unsigned int m[][cols]) {
    for (int i=0; i< rows; i++) {
        unsigned sumAux = 0;
        for(int j=0; j<cols && sumAux <= suma; j++) {
            sumAux += m[i][j];
        }
        if (sumAux == suma) {
            return 1;
        }
    }
    return 0;
}

int verifica(unsigned int rows1, unsigned int cols1, unsigned int m1[][cols1], unsigned int rows2, unsigned int cols2, unsigned int m2[][cols2]) {
    for(int i=0; i < rows1; i++) {
        unsigned int sum = sumar(m1[i], cols1);
        if (!incluyeSuma(sum, rows2, cols2, m2)) {
            return 0;
        }
    }
    return 1;
}

int verificaSuma(unsigned int rows1, unsigned int cols1, unsigned int m1[][cols1], unsigned int rows2, unsigned int cols2, unsigned int m2[][cols2]) {
    if (verifica(rows1, cols1, m1, rows2, cols2, m2)) {
        return 1;
    }
    if (verifica(rows2, cols2, m2, rows1, cols1, m1)) {
        return 2;
    }
    return 0;
}