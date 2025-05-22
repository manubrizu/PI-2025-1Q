#include <stdio.h>

void transforma(int * v, int n, int (*f) (int));
int cuadrado(int x);

int main(){
    int vec[5] = {0, 1, 2, 3, 4};

    transforma(vec, 5, cuadrado);

    for (int i = 0; i < 5; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
    return 0;
}

void transforma(int * v, int n, int (*f) (int)){
    if(n==0){
        return;
    }
    
    v[0] = f(v[0]);

    transforma(v + 1, n - 1, f);
}

int cuadrado(int x){
    return x*x;
}