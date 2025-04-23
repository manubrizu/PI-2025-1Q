#include <stdio.h>

int verificaMat(unsigned int dim, int mat[dim][dim]);

int main(){
    // Test case 1: Valid 1x1 matrix
    int mat1[1][1] = {{1}};
    if (!verificaMat(1, mat1)) return 1;

    // Test case 2: Valid 2x2 matrix
    int mat2[2][2] = {
        {1, 3},
        {4, 2}
    };
    if (!verificaMat(2, mat2)) return 1;

    // Test case 3: Valid 3x3 matrix
    int mat3[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    if (!verificaMat(3, mat3)) return 1;

    // Test case 4: Invalid 2x2 matrix (repeated number)
    int mat4[2][2] = {
        {1, 1},
        {3, 4}
    };
    if (verificaMat(2, mat4)) return 1;

    // Test case 5: Invalid 2x2 matrix (number out of range)
    int mat5[2][2] = {
        {1, 2},
        {3, 5}
    };
    if (verificaMat(2, mat5)) return 1;

    // Test case 6: Invalid 3x3 matrix (missing number)
    int mat6[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 1}
    };
    if (verificaMat(3, mat6)) return 1;

    puts("OK!");
    return 0;
}

int verificaMat(unsigned int dim, int mat[dim][dim]){
    char vecAp[dim*dim]; // no hay que poner = {0}

    for (int i = 0; i < dim * dim; i++){
        vecAp[i] = 0;
    }

    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            if(mat[i][j] < 1 || mat[i][j] > dim * dim){
                return 0;
            }
            else if(vecAp[mat[i][j] - 1]){
                return 0;
            }
            vecAp[mat[i][j] - 1] = 1;
        }
        
    }
    return 1;
}