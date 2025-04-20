#include <stdio.h>

int eliminarRepeOrd(const int vec[], int dim, int resp[]);
void prettyVec(const int vec[], int dim);


int main(){
    int vec1[5] = {1, 3, 3, 33, 33}, dim1 = sizeof(vec1)/sizeof(vec1[0]), vec2[dim1];

    int dim2 = eliminarRepeOrd(vec1, dim1, vec2);
    printf("El tamaño del vector es de: %d\n", dim2);
    printf("El vector era: ");
    prettyVec(vec1, dim1);

    printf("\nEl vector quedo: ");
    prettyVec(vec2, dim2);

    printf("\n");
    return 0;
}

int eliminarRepeOrd(const int vec[], int dim, int resp[]){
    int dimResp = 0, i = 0;
    if(dim < 1)
        return dimResp;

    while (i < dim - 1)    {
        if(vec[i] != vec[i + 1]){
            resp[dimResp++] = vec[i];
        }
        i++;
    }
    resp[dimResp++] = vec[i];  
    return dimResp;
}

void prettyVec(const int vec[], int dim){
    for (int i = 0; i < dim; i++){
        printf("%d ", vec[i]);
    }    
}