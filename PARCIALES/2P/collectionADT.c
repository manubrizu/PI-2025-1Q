#include <stdio.h>
#include <stdlib.h>
#include "collectionADT.h"

typedef struct node{
    struct node * tail;
    elemType elem;
} node;

typedef struct node * List;

typedef struct collectionCDT{
    List first;
    List actual;
    size_t cant;
    compare cmp;
} collectionCDT;

collectionADT newCollection(compare cmp){
    collectionADT aux = calloc(1, sizeof(collectionCDT));
    aux->cmp = cmp;
    return aux;
}

static List addElementRec(List l, elemType elem, size_t idx){
    if(l == NULL || idx == 0){
        List aux = malloc(sizeof(node));
        aux->elem = elem;
        aux->tail = l;
        return aux;
    }

    l->tail = addElementRec(l->tail, elem, idx - 1);
    return l;
}

void addElement(collectionADT collection, elemType elem, size_t idx){
    collection->first = addElementRec(collection->first, elem, idx);
    collection->cant++;
}

size_t sizeCollection(const collectionADT collection){
    return collection->cant;
}

static void positionFirstRec(List l, elemType elem, compare cmp, int * pos){
    if(l == NULL){
        *pos = -1;
        return;
    }

    if(cmp(elem, l->elem) == 0){
        return;
    }

    (*pos)++;
    positionFirstRec(l->tail, elem, cmp, pos);
}

int positionFirst(const collectionADT collection, elemType elem){
    int pos = 0;
    positionFirstRec(collection->first, elem, collection->cmp, &pos);
    return pos;
}

void toBegin(collectionADT collection){
    collection->actual = collection->first;
}

size_t hasNext(const collectionADT collection){
    return collection->actual != NULL;
}

elemType next(collectionADT collection){
    if(collection->actual == NULL){
        exit(1);    // por gracioso
    }

    elemType aux = collection->actual->elem;
    collection->actual = collection->actual->tail;
    return aux;
}

static void freeRec(List l){
    if(l != NULL){
        freeRec(l->tail);
        free(l);
    }
}

void freeCollection(collectionADT collection){
    freeRec(collection->first);
    free(collection);
}