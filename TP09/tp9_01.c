#include <stdio.h>

int suma(int * vec, int dim){
    if (dim == 0){
        return 0;
    }

    return vec[0] + suma(vec + 1, dim - 1);    
}

int main(){
    int vec[] = {1, 2, 3, 4, 5};
    printf("%d\n", suma(vec, 5));
}