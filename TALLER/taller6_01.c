#include <stdio.h>
#include <assert.h>


int incrementoFCMinMax(int angulos[], int dist[], int dim, int* fMin, int* cMin, int* fMax, int* cMax);

int main(){
    int angulos[] = {0, 45, 90, 135, 180, 225, 270, 315};
    int distancias[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int fMin, cMin, fMax, cMax;
    assert(incrementoFCMinMax(angulos, distancias, sizeof(angulos) / sizeof(angulos[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == 0 && cMin == 1 && fMax == 1 && cMax == 1);
 
 
    int angulos2[] = {0, 45, 90, 135, 180, 225, 270, 315};
    int distancias2[] = {8, 7, 6, 5, 4, 3, 2, 1};
    assert(incrementoFCMinMax(angulos2, distancias2, sizeof(angulos2) / sizeof(angulos2[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == 1 && cMin == 1 && fMax == 0 && cMax == 1);
 
 
    int angulos3[] = {45, 90, 135, 225, 180, 0};
    int distancias3[] = {12, 1, 4, 20, 7, 9};
    assert(incrementoFCMinMax(angulos3, distancias3, sizeof(angulos3) / sizeof(angulos3[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == -1 && cMin == 0 && fMax == 1 && cMax == -1);
 
 
    int angulos4[] = {90};
    int distancias4[] = {1};
    assert(incrementoFCMinMax(angulos4, distancias4, sizeof(angulos4) / sizeof(angulos4[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == -1 && cMin == 0 && fMax == -1 && cMax == 0);
 
 
    assert(incrementoFCMinMax(NULL, NULL, 0, &fMin, &cMin, &fMax, &cMax) == 0);
    assert(fMin == -1 && cMin == 0 && fMax == -1 && cMax == 0); // no debería modificar los valores
 
 
    puts("OK!");
    return 0;
}

int incrementoFCMinMax(int angulos[], int dist[], int dim, int* fMin, int* cMin, int* fMax, int* cMax){
    if (dim <= 0){
        return 0;
    }

    int max = 0, min = dist[0], indiceMax = 0, indiceMin = 0;
    int dir[][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};

    for (int i = 0; i < dim; i++){
        if(dist[i] > max){
            max = dist[i];
            indiceMax = i;
        }
        else if(dist[i] < min){
            min = dist[i];
            indiceMin = i;
        }
    }

    *fMin = dir[angulos[indiceMin] / 45][0];
    *fMax = dir[angulos[indiceMax] / 45][0];
    *cMin = dir[angulos[indiceMin] / 45][1];
    *cMax = dir[angulos[indiceMax] / 45][1];   

    return 1;    
}