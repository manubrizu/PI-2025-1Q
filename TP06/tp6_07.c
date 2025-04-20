#include <stdio.h>

void unionVecs(const int vecA[], const int vecB[], int ord[]);
void prettyVec(const int vec[]);

int main(){
    int vec1[5] = {1, 2, 3, 4, -1}, vec2[4] = {2, 4, 5, -1}, ordenado[10];
    printf("Vector 1: ");
    prettyVec(vec1);

    printf("\nVector 2: ");
    prettyVec(vec2);


    unionVecs(vec1, vec2, ordenado);
    printf("\nLa union es: ");
    prettyVec(ordenado);
    
    printf("\n");

    return 0;
}

void prettyVec(const int vec[]){
    for (int i = 0; vec[i] != -1 ; i++){
        printf("%d ", vec[i]);
    }    
    printf("-1");
}

void unionVecs(const int vecA[], const int vecB[], int ord[]) {
    int i = 0, j = 0, k = 0;

    while (vecA[i] != -1 && vecB[j] != -1) {
        if (vecA[i] < vecB[j]) {
            ord[k++] = vecA[i++];
        } else if (vecA[i] > vecB[j]) {
            ord[k++] = vecB[j++];
        } else {
            ord[k++] = vecA[i];
            i++;
            j++;
        }
    }

    while (vecA[i] != -1) {
        ord[k++] = vecA[i++];
    }

    while (vecB[j] != -1) {
        ord[k++] = vecB[j++];
    }

    ord[k] = -1;
}