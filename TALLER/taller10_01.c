#include <stdio.h>
#include <stdlib.h>

void recMinMax(int * v, int dim, int * min, int * max);

int main(){

}

void recMinMax(int * v, int dim, int * min, int * max){
    if(dim == 0){
        *min = 0;
        *max = 0;
    }
    if(dim == 1 && *v>0){
        *min = *v;
        *max = *v;
        return;
    }

    if(*v<0){
        *min = -1;
        *max = -1;
        return;
    }

    recMinMax(v + 1, dim - 1, min, max);

    if(*min != -1 && *v < *min){
        *min = *v;
    }
    if(*max != -1 && *v > *max){
        *min = *v;
    }
}