#include <stdio.h>
#include <assert.h>
#include "collectionADT.h"

int compareInt(elemType a, elemType b) {
    return (a > b) - (a < b);
}

int main(void) {
    collectionADT c = newCollection(compareInt);
    // Agrega el elemento 10 a la colección.
    // No importa el índice que le pongamos, será el primero (posición cero)
    addElement(c, 10, 1); // 10
    // Agrega el elemento 20 al principio, desplazando una posición hacia atrás al 10
    addElement(c, 20, 0); // 20 - 10
    addElement(c, 30, 0); // 30 - 20 - 10
    addElement(c, 40, 1); // 30 - 40 - 20 - 10
    assert(sizeCollection(c)==4);
    addElement(c, 60, 10); // 30 - 40 - 20 - 10 - 60
    // Acepta repetidos
    addElement(c, 10, 10); // 30 - 40 - 20 - 10 - 60 - 10
    assert(positionFirst(c, 70)==-1); // No está en la colección
    assert(positionFirst(c, 30)==0);
    assert(positionFirst(c, 20)==2);
    assert(positionFirst(c, 10)==3);
    assert(sizeCollection(c)==6);
    toBegin(c);
    assert(hasNext(c)==1);
    assert(next(c)==30); assert(next(c)==40); assert(next(c)==20);
    assert(next(c)==10); assert(next(c)==60); assert(next(c)==10);
    assert(!hasNext(c));
    freeCollection(c);
    puts("OK!");
    return 0;
}
