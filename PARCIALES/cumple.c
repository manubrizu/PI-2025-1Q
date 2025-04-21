/* PRIMER PARCIAL 23-09-2022*/

#include <stdio.h>

#define N 5

int cumple(int m[][N]);
int cumpleFila(int vec[], int fila);

int main(){
    return 0;
}

int cumple(int m[][N]){
    for (int i = 0; i < N; i++){
        if (!cumpleFila(m[i], i)){
            return 0;
        }        
    }
    return 1;
}

int cumpleFila(int vec[], int fila){
    int minimo = N * fila + 1, maximo = N * (fila + 1) - 1, aparicion[N] = {0};         // inicializo todos en 0
    for (int j = 0; j < N; j++){
        if(!(vec[j] >= minimo && vec[j] <= maximo)){        // chequeo para que este entre 1 y N*N
            return 0;
        }
        else{
            if (aparicion[vec[j] % N]){                     // chequeo q no haya repetidos
                return 0;
            }
            aparicion[vec[j] % N] = 1;
        }
    }
    return 1;
}