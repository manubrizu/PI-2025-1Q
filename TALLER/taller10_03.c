#include <stdio.h>
#include <stdlib.h>
#include "./utillist.h"

List deleteAll(List L1, List l2);

int main() {
    List l1 = NULL, l2 = NULL;

    // Lista 1: 1 -> 2 -> 3 -> 4 -> 5
    l1 = add(l1, 1);
    l1 = add(l1, 2);
    l1 = add(l1, 3);
    l1 = add(l1, 4);
    l1 = add(l1, 5);

    // Lista 2: 2 -> 4 -> 6
    l2 = add(l2, 2);
    l2 = add(l2, 4);
    l2 = add(l2, 6);

    // Eliminar de l1 todos los elementos que aparecen en l2
    l1 = deleteAll(l1, l2);

    printList(l1); // Esperado: 1 3 5

    freeList(l1);
    freeList(l2);
    return 0;
}

List deleteAll(List l1, List l2){
    if(isEmpty(l2) || isEmpty(l1)){
        return l1;
    }
    
    if (l1->head < l2->head){
        l1->tail = deleteAll(l1->tail, l2);
        return l1;
    }

    if(l1->head > l2->head){
        return deleteAll(l1, l2->tail);
    }
    
    List aux = l1->tail;
    free(l1);
    return deleteAll(aux, l2->tail);
}