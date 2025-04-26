#include <stdio.h>
#include <assert.h>
#define N 4

int contieneVector(int v1[], int v2[], int dim);
int contieneFilas(int m1[N][N], int m2[N][N]);
int contieneMatriz(int m1[N][N], int m2[N][N]);

int main(){
    // Tests
    int m1[N][N] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int m2[N][N] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    assert(contieneFilas(m1, m2) == 1);

    int m3[N][N] = {{1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {4,4,4,4}};
    int m4[N][N] = {{1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4}};
    assert(contieneFilas(m3, m4) == 1);

    int m5[N][N] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int m6[N][N] = {{4,3,2,1}, {8,7,6,5}, {12,11,10,9}, {16,15,14,13}};
    assert(contieneFilas(m5, m6) == 1);

    printf("OK!\n");
    return 0;
}

int contieneVector(int v1[], int v2[], int dim){
    int i = 0, j = 0;
    
    while (i < dim && j < dim) {
        if (v1[i] == v2[j]) {
            i++;  // Avanzamos en ambos vectores
            j++;
        }
        else if (v1[i] < v2[j]) {
            return 0;  // Si encontramos un elemento en v1 que no está en v2
        }
        else {
            j++;  // Solo avanzamos en v2
        }
    }
    
    return i == dim;  // Retornamos 1 si recorrimos todo v1, 0 si no
}

int contieneMatriz(int m1[N][N], int m2[N][N]) {
    for (int i = 0; i < N; i++) {
        int esta = 0;
        for (int j = 0; j < N && !esta; j++) {
            if (contieneVector(m1[i], m2[j], N)) {
                esta = 1;
            }
        }
        if (!esta) {
            return 0;
        }
    }
    return 1;    
}

int contieneFilas(int m1[N][N], int m2[N][N]){
    if(contieneMatriz(m1, m2)){
        return 1;
    }
    else if (contieneMatriz(m2, m1)){
        return 2;
    }
    else{
        return 0;
    }
}
