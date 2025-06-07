#include <stdio.h>

int escalar(unsigned int dim, int mat[dim][dim]);
int sumarFilas(unsigned int dim, int vec[dim]);

int main(){
    // Test case 1: Matriz escalar 3x3 (dos filas iguales)
    int mat1[3][3] = {
        {1, 1, 1},  // suma = 3
        {2, 2, 2},  // suma = 6
        {1, 1, 1}   // suma = 3
    };
    printf("Test 1 (debería ser 1): %d\n", escalar(3, mat1));

    // Test case 2: Matriz no escalar (sumas fuera de rango)
    int mat2[3][3] = {
        {0, 0, 0},  // suma = 0 < 3
        {2, 2, 2},  // suma = 6
        {3, 3, 3}   // suma = 9 > 6
    };
    printf("Test 2 (debería ser 0): %d\n", escalar(3, mat2));

    // Test case 3: Matriz no escalar (más de dos filas con misma suma)
    int mat3[3][3] = {
        {1, 1, 1},  // suma = 3
        {1, 1, 1},  // suma = 3
        {1, 1, 1}   // suma = 3
    };
    printf("Test 3 (debería ser 0): %d\n", escalar(3, mat3));

    // Test case 4: Matriz 1x1
    int mat4[1][1] = {{1}};
    printf("Test 4 (debería ser 1): %d\n", escalar(1, mat4));

    // Test case 5: Matriz 2x2 escalar
    int mat5[2][2] = {
        {1, 1},  // suma = 2
        {2, 2}   // suma = 4
    };
    printf("Test 5 (debería ser 1): %d\n", escalar(2, mat5));

    // Test case 6: Matriz 4x4 con todas las sumas diferentes
    int mat6[4][4] = {
        {1, 1, 1, 1},  // suma = 4
        {2, 2, 2, 2},  // suma = 8
        {3, 3, 3, 3},  // suma = 12
        {4, 4, 4, 4}   // suma = 16
    };
    printf("Test 6 (debería ser 0): %d\n", escalar(4, mat6));

    // Test case 7: Matriz 4x4 con dos pares de filas iguales
    int mat7[4][4] = {
        {1, 1, 1, 1},  // suma = 4
        {2, 2, 2, 2},  // suma = 8
        {1, 1, 1, 1},  // suma = 4
        {2, 2, 2, 2}   // suma = 8
    };
    printf("Test 7 (debería ser 0): %d\n", escalar(4, mat7));

    // Test case 8: Matriz 3x3 con sumas en el límite
    int mat8[3][3] = {
        {1, 1, 1},  // suma = 3 (mínimo)
        {2, 2, 2},  // suma = 6
        {2, 2, 2}   // suma = 6
    };
    printf("Test 8 (debería ser 1): %d\n", escalar(3, mat8));

    return 0;
}

int escalar(unsigned int dim, int mat[dim][dim]){
    if (dim == 1){
        return (mat[0][0] == 1);
    }

    int sumaFilas[dim];    
    for (int i = 0; i < dim; i++){
        sumaFilas[i] = sumarFilas(dim, mat[i]);
        if(sumaFilas[i] < dim || sumaFilas[i] > 2*dim){
            return 0;
        }
    }

    int coincide = 0;
    for (int i = 0; i < dim ; i++){        
        for (int j = i + 1; j < dim; j++){
            if(sumaFilas[i] == sumaFilas[j]){
                coincide ++;
                if(coincide > 1)
                    return 0;
            }
        }
    }   

    return 1;
}

int sumarFilas(unsigned int dim, int vec[dim]){
    int suma = 0;
    for (int i = 0; i < dim; i++){
        suma += vec[i];
    }
    return suma;
}
