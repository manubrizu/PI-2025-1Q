#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generarMatriz(int dim, int mat[][dim]);
int getMask(unsigned char bits);

int main(){    
    srand(time(NULL));
    int mat[5][5];
    generarMatriz(5, mat);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}


void generarMatriz(int dim, int mat[][dim]){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            mat[i][j] = rand() % 10 + 1;
        }
    }
    
}

// 1010 0011 0111 0110
// 0000 0000 0000 1111  (0x000F)
// 0000 0000 1111 0000
---
// 0000 0000 0111 0110 

//

