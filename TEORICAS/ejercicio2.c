#include <stdio.h>
#include <stdlib.h>

#define MIN(x1, x2) (((x1) < (x2)) ? (x1) : (x2))
#define BLOCK 15

int * interseccion(int v1[], int v2[], int dim1, int dim2, int* dimResp);

int main(){
    int v1[5] = {3, 4, 5, 6, 7};
    int v2[6] = {3, 5, 6, 7, 8, 9};
    int * vec;
    int dimResp;

    vec = interseccion(v1, v2, 5, 6, &dimResp);

    for (int i = 0; i < dimResp; i++){
        printf("%d ", vec[i]);
    }
    
    printf("\n");

    free(vec);

    return 0;
}


int * interseccion(int v1[], int v2[], int dim1, int dim2, int* dimResp){
    int * vecAux = NULL;
    int cant = 0, i=0, j=0;

    while(i < dim1 && j < dim2){
        if(v1[i] < v2[j]){
            i++;
        }
        else if(v2[j] < v1[i]){
            j++;
        }
        else{
            if(cant % BLOCK == 0){
                vecAux = realloc(vecAux, (cant + BLOCK) * sizeof(vecAux[0]));
            }
            
            vecAux[cant++] = v1[i];
            i++;
            j++;
        }
    }

    *dimResp = cant;
    vecAux = realloc(vecAux, (cant) * sizeof(vecAux[0]));
    return vecAux;
}
