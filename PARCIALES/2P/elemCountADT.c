#include <stdio.h>
#include <stdlib.h>
#include "elemCountADT.h"


typedef struct node{
    struct node * next;
    elemtype head;
    size_t count;
} node;

typedef struct node * List;

typedef struct elemCountCDT{
    List first;
    List actual;
    size_t elemsCount;
    compare cmp;
} elemCountCDT;

elemCountADT newElemCount(compare cmp){
    elemCountADT aux = calloc(1, sizeof(elemCountCDT));
    aux->cmp = cmp;
    return aux;
}

static List countElemRec(List l, elemtype elem, compare cmp, size_t * cont){
    if(l == NULL){	// el elemento no esta en la Lista lo agrego
    	List aux = malloc(sizeof(node));
        aux->count = *cont = 1;
        aux->head = elem;
        aux->next = NULL;
	    return aux;
    }

    if(cmp(l->head, elem) == 0){
        l->count++;
	    *cont = l->count;
	    return l;
    }
    
    l->next = countElemRec(l->next, elem, cmp, cont);
    return l;
}

size_t countElem(elemCountADT elemCountAdt, elemtype elem){
    size_t cont = 0;
    elemCountAdt->first = countElemRec(elemCountAdt->first, elem, elemCountAdt->cmp, &cont);
    if(cont == 1){
	    elemCountAdt->elemsCount++;
    }
    return cont;
}

size_t distinctElems(elemCountADT elemCountAdt){
    return elemCountAdt->elemsCount;
}

void toBegin(elemCountADT elemCountAdt){
    elemCountAdt->actual = elemCountAdt->first;
}

size_t hasNext(elemCountADT elemCountAdt){
    return elemCountAdt->actual != NULL;
}

elemtype next(elemCountADT elemCountAdt, size_t * count){
    if(elemCountAdt->actual == NULL){
	    exit(1); // por gracioso
    }

    elemtype aux = elemCountAdt->actual->head;
    *count = elemCountAdt->actual->count;
    elemCountAdt->actual = elemCountAdt->actual->next;
    return aux;
}

static void freeElemCountRec(List l){
    if(l != NULL){
        freeElemCountRec(l->next);
        free(l);
    }
}

void freeElemCount(elemCountADT elemCountAdt){
    freeElemCountRec(elemCountAdt->first);
    free(elemCountAdt);
}