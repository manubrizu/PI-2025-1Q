#include <stdio.h>
#include <stdlib.h>
#include ".././random.h"

void desordenar(int vec[], int dim, int vecD[]){
    randomize();
    int usados[dim]; 
    for (int i = 0; i < dim; i++) {
        usados[i] = 0; 
    }

    for (int i = 0; i < dim; i++) {
        int j;
        do {
            j = randInt(0, dim - 1);
        } while (usados[j]);

        vecD[i] = vec[j];
        usados[j] = 1;
    }
}


int main(){
int original[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int dimO = sizeof(original) / sizeof(original[0]);
int desordenado[dimO];


printf("Original:   ");
for (int m = 0; m < dimO; m++) 
    printf("%d ", original[m]);

desordenar(original, dimO, desordenado);

printf("\nDesordenado: ");
for (int n = 0; n < dimO; n++) 
    printf("%d ", desordenado[n]);

return 0;
}