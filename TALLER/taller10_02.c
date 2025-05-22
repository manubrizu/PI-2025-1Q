#include <stdio.h>
#include <stdlib.h>
#include "./utillist.h"

List concatenarList(List l1, List l2);

int main() {
    List l1 = NULL, l2 = NULL;

    // Lista 1: 1 -> 2 -> 3
    l1 = add(l1, 1);
    l1 = add(l1, 2);
    l1 = add(l1, 3);

    // Lista 2: 4 -> 5
    l2 = add(l2, 4);
    l2 = add(l2, 5);

    // Concatenar
    List l = concatenarList(l1, l2);

    printList(l); // Esperado: 3 2 1 5 4

    freeList(l);
    return 0;
}


List concatenarList(List l1, List l2){
    if (isEmpty(l2)) {
        return l1;
    }

    if(!isEmpty(l1)){        
        l1->tail = concatenarList(l1->tail, l2);
        return l1;
    }

    List aux = malloc(sizeof(node));
    aux->head = l2->head;
    aux->tail = concatenarList(NULL, l2->tail);
    return aux;
}