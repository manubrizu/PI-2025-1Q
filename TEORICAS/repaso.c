#include <stdio.h>
#include <stdlib.h>
#include "./getnum.h"

double * crearVector(int * dim);

int main(){
    int dim;
    double* vec = crearVector(&dim);
    
    for (int i = 0; i < dim; i++){
        printf("%g ", vec[i]);
    }

    printf("\n");    
    free(vec);

    return 0;
}

double * crearVector(int * dim){
    *dim = getint("Ingrese la dimension (positiva PAJERO): \n");

    double * vec = malloc(*dim * sizeof(vec[0])); 

    for (int i = 0; i < *dim; i++){
        vec[i] = getdouble("Ingresa un numero real: \n");
    }
    
    return vec;
}



