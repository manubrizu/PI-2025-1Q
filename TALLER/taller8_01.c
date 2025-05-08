#include <stdio.h>
#include <stdlib.h>
#include "./../getnum.h"

#define BLOCK 10

int * cargarNumeros(int * dim);
int chequeo(int * vec, int dim, int num);

int main() {
    int dim;
    int * arr = cargarNumeros(&dim);

    for (int i = 0; i < dim; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

int * cargarNumeros(int * dim) {
    int * foo = NULL;
    int i = 0;
    int aux;
    int repetido= 0;

    while (!repetido) {
        aux = getint("Ingrese un numero: ");        /// SIEMPRE ES MEJOR PEDIR AL USUARIO ANTES DE RESERVAR MEMORIA

        if (chequeo(foo, i, aux)) {
            repetido= 1;
        } else {
            if (i % BLOCK == 0) {
                foo = realloc(foo, (i + BLOCK) * sizeof(foo[0]));
            }
            foo[i++] = aux;
        }
    }

    *dim = i;
    foo = realloc(foo, i * sizeof(foo[0]));
    return foo;
}

int chequeo(int * vec, int dim, int num) {
    for (int i = 0; i < dim; i++) {
        if (vec[i] == num) {
            return 1;
        }
    }
    return 0;
}
