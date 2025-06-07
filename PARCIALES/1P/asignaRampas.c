#include <stdio.h>

int asignaRampas(int vec[], int dim, int codigo, int cant);

int main(){
    int v[] = {0, 44, 44, 0, 0, 0, 1};
    printf("Vector inicial: ");
    for(int i = 0; i < 7; i++) printf("%d ", v[i]);
    printf("\n");
    
    int n = asignaRampas(v, 7, 56, 2);
    printf("Asignadas %d rampas a 56: ", n);
    for(int i = 0; i < 7; i++) printf("%d ", v[i]);
    printf("\n");
    
    n = asignaRampas(v, 7, 1, 3);
    printf("Asignadas %d rampas a 1: ", n);
    for(int i = 0; i < 7; i++) printf("%d ", v[i]);
    printf("\n");
    
    n = asignaRampas(v, 7, 88, 3);
    printf("Asignadas %d rampas a 88: ", n);
    for(int i = 0; i < 7; i++) printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}

int asignaRampas(int vec[], int dim, int codigo, int cant){
    int j = 0;
    for (int i = 0; i < dim; i++){
        if(vec[i] != 0){
            vec[j++] = vec[i];
        }
    }
    int rampas = 0;
    for (int i = j; i < dim; i++){
        if(rampas < cant){
            vec[i] = codigo;
            rampas++;
        }
        else{
            vec[i] = 0;
        }
    }   

    return rampas;
}