#include <stdio.h>
#include <assert.h>

#define CHAR_MAX 256

void firstN(unsigned char v[], int dimension, int n, int* dim, int* del);
void eliminarElemento(unsigned char v[], int posicion, int dimension);

int main(void) {
    // Test case 1: Mantener las primeras 2 apariciones de cada valor
    unsigned char v1[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim1 = 8, del1 = 0;
    firstN(v1, 8, 2, &dim1, &del1);
    assert(dim1 == 7);
    assert(del1 == 1);
    assert(v1[0] == 1 && v1[1] == 2 && v1[2] == 1 && v1[3] == 3 && 
           v1[4] == 4 && v1[5] == 5 && v1[6] == 2);

    // Test case 2: Mantener las primeras 3 apariciones de cada valor
    unsigned char v2[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim2 = 8, del2 = 0;
    firstN(v2, 8, 3, &dim2, &del2);
    assert(dim2 == 8);
    assert(del2 == 0);
    assert(v2[0] == 1 && v2[1] == 2 && v2[2] == 1 && v2[3] == 3 && 
           v2[4] == 1 && v2[5] == 4 && v2[6] == 5 && v2[7] == 2);

    // Test case 3: Mantener solo la primera aparición de cada valor
    unsigned char v3[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim3 = 8, del3 = 0;
    firstN(v3, 8, 1, &dim3, &del3);
    assert(dim3 == 5);
    assert(del3 == 3);
    assert(v3[0] == 1 && v3[1] == 2 && v3[2] == 3 && v3[3] == 4 && v3[4] == 5);

    // Test case 4: Vector vacío
    unsigned char v4[] = {0};
    int dim4 = 0, del4 = 0;
    firstN(v4, 0, 1, &dim4, &del4);
    assert(dim4 == 0);
    assert(del4 == 0);

    // Test case 5: Vector con un solo elemento
    unsigned char v5[] = {5};
    int dim5 = 1, del5 = 0;
    firstN(v5, 1, 1, &dim5, &del5);
    assert(dim5 == 1);
    assert(del5 == 0);
    assert(v5[0] == 5);

    puts("OK!");
    return 0;
}

void firstN(unsigned char v[], int dimension, int n, int* dim, int* del) {
    if (dimension == 0) {
        return;
    }

    int apariciones[CHAR_MAX] = {0};
    *del = 0;

    for (int i = 0; i < *dim;) {
        if (apariciones[v[i]] < n) {
            apariciones[v[i]]++;
            i++;
        } 
        else {
            eliminarElemento(v, i, *dim);
            (*dim)--;
            (*del)++;
        }
    }
}

void eliminarElemento(unsigned char v[], int posicion, int dimension) {
    for (int i = posicion; i < dimension - 1; i++) {
        v[i] = v[i + 1];
    }
}
