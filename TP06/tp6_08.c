#include <stdio.h>

void unionVecs(const int vecA[], const int vecB[], int ord[]);
void prettyVec(const int vec[]);

int main(){
    int vec1[6] = {1, 2, 3, 4, 6, -1}, vec2[5] = {2, 4, 4, 5, -1}, ordenado[11];
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
    int i = 0, j = 0, k = 0, lastAdded;
    ord[0] = -1;
    
    while(vecA[i] != -1 || vecB[j] != -1){
        if(vecA[i] == -1 || vecB[j] == -1){
            lastAdded = (vecA[i] != -1) ? vecA[i] : vecB[j];
        }
        else{
            lastAdded = (vecA[i] < vecB[j]) ? vecA[i] : vecB[j];
        }
        if(k == 0 || lastAdded != ord[k - 1]){
            ord[k++] = lastAdded;
        }
        i += (vecA[i] == lastAdded);
        j += (vecB[j] == lastAdded);
    }
    ord[k] = -1;
}