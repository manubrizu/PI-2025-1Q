#include <stdio.h>

int productoEsc(int * v1, int * v2, int dim);

int main(){
    int v1[] = {2, 4, 2};
    int v2[] = {4, 2, 4};
    int dim = 3;

    printf("%d\n", productoEsc(v1, v2, dim));
}


int productoEsc(int * v1, int * v2, int dim){
    if(dim == 0){
        return 0;
    }

    return v1[0] * v2[0] + productoEsc(v1 + 1, v2 + 1, dim - 1);
}