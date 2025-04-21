#include <stdio.h>
#include <assert.h>

#define CHAR_MAX 256

void firstN(unsigned char v[], int dimension, int elemento, int* dim, int* del);
void eliminarElemento(unsigned char v[], int posicion, int cantidad);

void test_firstN() {
    // Test case 1: No changes when elemento is greater than all elements
    unsigned char v1[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim1 = 8, del1 = 0;
    firstN(v1, 8, 3, &dim1, &del1);
    assert(dim1 == 8);
    assert(del1 == 0);
    assert(v1[0] == 1 && v1[1] == 2 && v1[2] == 1 && v1[3] == 3 && 
           v1[4] == 1 && v1[5] == 4 && v1[6] == 5 && v1[7] == 2);

    // Test case 2: No changes when elemento is greater than all elements
    unsigned char v2[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim2 = 8, del2 = 0;
    firstN(v2, 8, 8, &dim2, &del2);
    assert(dim2 == 8);
    assert(del2 == 0);
    assert(v2[0] == 1 && v2[1] == 2 && v2[2] == 1 && v2[3] == 3 && 
           v2[4] == 1 && v2[5] == 4 && v2[6] == 5 && v2[7] == 2);

    // Test case 3: No changes when elemento is greater than all elements
    unsigned char v3[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim3 = 8, del3 = 0;
    firstN(v3, 8, 4, &dim3, &del3);
    assert(dim3 == 8);
    assert(del3 == 0);
    assert(v3[0] == 1 && v3[1] == 2 && v3[2] == 1 && v3[3] == 3 && 
           v3[4] == 1 && v3[5] == 4 && v3[6] == 5 && v3[7] == 2);

    // Test case 4: Remove elements greater than 1
    unsigned char v4[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim4 = 8, del4 = 0;
    firstN(v4, 8, 1, &dim4, &del4);
    assert(dim4 == 5);
    assert(del4 == 3);
    assert(v4[0] == 1 && v4[1] == 2 && v4[2] == 3 && v4[3] == 4 && v4[4] == 5);

    // Test case 5: Remove all elements when elemento is 0
    unsigned char v5[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim5 = 8, del5 = 0;
    firstN(v5, 8, 0, &dim5, &del5);
    assert(dim5 == 0);
    assert(del5 == 8);

    // Test case 6: Remove one element greater than 2
    unsigned char v6[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim6 = 8, del6 = 0;
    firstN(v6, 8, 2, &dim6, &del6);
    assert(dim6 == 7);
    assert(del6 == 1);
    assert(v6[0] == 1 && v6[1] == 2 && v6[2] == 1 && v6[3] == 3 && 
           v6[4] == 4 && v6[5] == 5 && v6[6] == 2);

    // Test case 7: Empty array
    unsigned char v7[] = {};
    int dim7 = 0, del7 = 0;
    firstN(v7, 0, 1, &dim7, &del7);
    assert(dim7 == 0);
    assert(del7 == 0);

    // Test case 8: Single element array
    unsigned char v8[] = {5};
    int dim8 = 1, del8 = 0;
    firstN(v8, 1, 4, &dim8, &del8);
    assert(dim8 == 1);
    assert(del8 == 0);
    assert(v8[0] == 5);

    printf("All tests passed successfully!\n");
}

int main() {
    test_firstN();
    return 0;
} 