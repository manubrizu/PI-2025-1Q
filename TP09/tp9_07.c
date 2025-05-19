#include <stdio.h>
#include <assert.h>

int busquedaBinaria(int * vec, int dim, int num);

int main() {
    int v1[] = {1, 2, 3, 4, 5};
    /// int v2[] = {};
    int v3[] = {7};
    int v4[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int v5[] = {2, 4, 6, 8, 10};

    // assert(busquedaBinaria(v2, 0, 1) == 0);
    assert(busquedaBinaria(v3, 1, 7) == 1);
    assert(busquedaBinaria(v3, 1, 2) == 0);
    assert(busquedaBinaria(v1, 5, 1) == 1);
    assert(busquedaBinaria(v1, 5, 5) == 1);
    assert(busquedaBinaria(v1, 5, 3) == 1);
    assert(busquedaBinaria(v1, 5, -10) == 0);
    assert(busquedaBinaria(v1, 5, 100) == 0);
    assert(busquedaBinaria(v1, 5, 6) == 0);
    assert(busquedaBinaria(v4, 8, 1) == 1);
    assert(busquedaBinaria(v4, 8, 15) == 1);
    assert(busquedaBinaria(v4, 8, 9) == 1);
    assert(busquedaBinaria(v4, 8, 8) == 0);
    assert(busquedaBinaria(v5, 5, 5) == 0);

    puts("OK!");
    return 0;
}


int busquedaBinaria(int * vec, int dim, int num){
    int foo = dim / 2;
    if(dim <= 0){
        return 0;
    }

    if(vec[foo] == num){
        return 1;
    }
    else if(vec[foo] < num){
        return busquedaBinaria(vec + foo + 1, dim - foo - 1, num);
    }
    else if(vec[foo] > num){        
        return busquedaBinaria(vec, foo, num);
    }

    return 0;
}