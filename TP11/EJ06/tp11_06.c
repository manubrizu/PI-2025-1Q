#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListADT.h"

int cmpStr(const char *a, const char *b) {
    return strcmp(a, b);
}

int main() {
    listADT l = newList(cmpStr);

    addElement(l, "banana");
    addElement(l, "manzana");
    addElement(l, "pera");
    addElement(l, "uva");

    printf("Elementos en la lista (ordenados):\n");
    for(int i = 0; i < size(l); i++) {
        printf("%s\n", devolver(l, i));
    }

    freeList(l);
    return 0;
}