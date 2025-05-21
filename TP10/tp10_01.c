#include <stdio.h>
#include "./utillist.h"

int sumAll(List l);
int odds(List l);

int main() {
    List l = NULL;

    l = add(l, 3);
    l = add(l, 2);
    l = add(l, 1); // Lista: 1 -> 2 -> 3

    printf("Suma: %d\n", sumAll(l)); // Debe imprimir 6

    freeList(l);
    return 0;
}

int sumAll(List l){
    if(isEmpty(l)){
        return 0;
    }

    return l->head + sumAll(l->tail);
}

int odds(List l){
    if(isEmpty(l)){
        return 1;
    }

    if(l->head % 2 == 0){
        return 0;
    }

    return odds(l->tail);
}