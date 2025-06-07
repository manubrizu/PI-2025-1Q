#include <stdio.h>

#define CHAR_MAX 256

int depura(unsigned char vec[], int dim);

int main() {
    // Test case 1: Small vector with duplicates
    unsigned char vec1[] = {3, 1, 2, 2, 1, 3};
    int dim1 = sizeof(vec1)/sizeof(vec1[0]);
    int new_dim1 = depura(vec1, dim1);
    if (new_dim1 != 3) return 1;
    if (vec1[0] != 1 || vec1[1] != 2 || vec1[2] != 3) return 1;

    // Test case 2: Vector with all unique elements
    unsigned char vec2[] = {5, 3, 1, 4, 2};
    int dim2 = sizeof(vec2)/sizeof(vec2[0]);
    int new_dim2 = depura(vec2, dim2);
    if (new_dim2 != 5) return 1;
    if (vec2[0] != 1 || vec2[1] != 2 || vec2[2] != 3 || 
        vec2[3] != 4 || vec2[4] != 5) return 1;

    // Test case 3: Vector with all same elements
    unsigned char vec3[] = {7, 7, 7, 7, 7};
    int dim3 = sizeof(vec3)/sizeof(vec3[0]);
    int new_dim3 = depura(vec3, dim3);
    if (new_dim3 != 1) return 1;
    if (vec3[0] != 7) return 1;

    puts("OK!");
    return 0;
}

int depura(unsigned char vec[], int dim) {
    if (dim <= 0) return 0;
    
    int apariciones[CHAR_MAX] = {0};
    for (int i = 0; i < dim; i++) {
        if(!apariciones[vec[i]]) {
            apariciones[vec[i]] = 1; 
        }
    }
    
    int j = 0;
    for (int i = 0; i < CHAR_MAX; i++) {
        if (apariciones[i]) {
            vec[j++] = i;
        }
    }
    
    return j;
}
