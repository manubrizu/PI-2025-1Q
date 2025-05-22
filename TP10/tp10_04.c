#include <stdio.h>
#include "./utillist.h"

List addAll(List l1, List l2);

int main() {
    List l1 = NULL, l2 = NULL;

    // Lista 1: 1 -> 2 -> 4
    l1 = add(l1, 1);
    l1 = add(l1, 2);
    l1 = add(l1, 4);

    // Lista 2: 1 -> 3 -> 5 -> 6
    l2 = add(l2, 1);
    l2 = add(l2, 3);
    l2 = add(l2, 5);
    l2 = add(l2, 6);

    // Unir listas
    l1 = addAll(l1, l2);

    printList(l1);
    
    freeList(l1);
    freeList(l2);
    return 0;
}

List addAll(List l1, List l2){
    if (isEmpty(l2)){
        return l1;
    }
    if (isEmpty(l1) || l2->head < l1->head){
        return add(addAll(l1, l2->tail), l2->head);
    }        
    if (l2->head == l1->head){
        return addAll(l1, l2->tail);
    }
    
    if (l2->head > l1->head){
        l1->tail = addAll(l1->tail, l2);
    }

    return l1;
}