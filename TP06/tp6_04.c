#include <stdio.h>

int eliminarRepe(const int vec[], int dim, int resp[]);
int estaRepetido(const int vec[], int pos, int dim);
void prettyVec(const int vec[], int dim);


int main(){
    int vec1[5] = {1, 3, 33, 33, 1}, dim1 = sizeof(vec1)/sizeof(vec1[0]), vec2[dim1];

    int dim2 = eliminarRepe(vec1, dim1, vec2);
    printf("El tamaño del vector es de: %d\n", dim2);
    printf("El vector era: ");
    prettyVec(vec1, dim1);

    printf("\nEl vector quedo: ");
    prettyVec(vec2, dim2);

    printf("\n");
    return 0;
}

int eliminarRepe(const int vec[], int dim, int resp[]){
    int cont = 0;
    for (int i = 0; i < dim; i++){
        if(! (estaRepetido(vec, i, dim))){
            resp[cont++] = vec[i];
            
        }        
    }
    return cont;
}

int estaRepetido(const int vec[], int pos, int dim){
    for (int i = pos + 1; i < dim; i++){
        if(vec[pos] == vec[i]){
            return 1;
        }
    }
    return 0;
}

void prettyVec(const int vec[], int dim){
    for (int i = 0; i < dim; i++){
        printf("%d ", vec[i]);
    }    
}