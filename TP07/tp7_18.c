#include <stdio.h>
#include <stdlib.h>

int * copiaVector(int * vec, int dim);

int main(){
    int v[] = {3, 5, 6, 7, 8};
    int dim = 5;

    for (int i = 0; i < dim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    int * vInv = copiaVector(v, dim);

    for (int i = 0; i < dim; i++){
        printf("%d ", vInv[i]);
    }    
    printf("\n");

    free(vInv);
    
    return 0;
}

int * copiaVector(int * vec, int dim){
    int * resp;

    resp = malloc(dim * sizeof(vec[0]));

    for (int i = 0; i < dim; i++){
        resp[i] = vec[dim - 1 - i];
    }
        
    return resp;
}