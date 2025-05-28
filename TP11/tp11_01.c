#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

List removeIf(List l, int (*compare) (int));
List removeIf(List l, int (*compare) (int));

int esPar(int x) {
    return x % 2 == 0;
}

int main() {
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int esperado[] = {1,3,5,7,9};
    List l = fromArray(v, 10);

    l = removeIf(l, esPar);

    if (checkElems(l, esperado, 5)) {
        printf("Test OK\n");
    } else {
        printf("Test ERROR\n");
    }

    freeList(l);
    return 0;
}


List removeIf(List l, int (*compare) (int)){
    if(isEmpty(l)){
        return NULL;
    }

    if(compare(l->head)){
        List aux = l->tail;
        free(l);
        return removeIf(aux, compare);
    }

    l->tail = removeIf(l->tail, compare);
    return l;
}