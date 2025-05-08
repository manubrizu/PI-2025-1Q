#include <stdio.h>
#include <stdlib.h>
#include "./../getnum.h"

#define BLOCK 10

char * superDuperVector(int * dim);
void imprime(char * vec, int* dim);

int main(){
    char * superVectorPro;
    int dim = 0;
    superVectorPro = superDuperVector(&dim);
    imprime(superVectorPro, &dim);

    free(superVectorPro);
    return 0;
}


char * superDuperVector(int * dim){
    int c, i = 0;
    char * aux = NULL;
    while ((c = getchar()) != EOF){ 
        if (i % BLOCK == 0) {
            aux = realloc(aux, i + BLOCK);
        }
        aux[i++] = c;
    }

    aux = realloc(aux, i);

    *dim = i;
    return aux;
}

void imprime(char * vec, int * dim){
    for (int i = 0; i < *dim; i++){
        printf("%c", vec[i]);
    }    
}