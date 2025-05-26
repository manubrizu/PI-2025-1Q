#include <stdio.h>
#include <stdlib.h>
#include "ListADT.h"

typedef struct node{
    elemType head;
    struct node * tail;
} node;


typedef struct listCDT{
    struct node * first;
    unsigned int size;
    compare cmp;
} listCDT;


listADT newList(compare cmp){
    listADT aux = calloc(1, sizeof(listCDT));
    aux->cmp = cmp;
    return aux;
}

int isEmpty(const listADT l){
    return l->first == NULL;
}

int size(const listADT l){
    return l->size;
}

static void freeListRec(node * l){
    if(l == 0){
        return;
    }

    freeListRec(l->tail);
    free(l);
}

void freeList(listADT l){
    freeListRec(l->first);
}

int belongsRec(node * l, int elem, compare cmp){
    if(l == NULL){
        return 0;
    }
    int c = cmp(l->head, elem);
    if(c == 0){
        return 1;
    }
    if(c > 0){
        return 0;
    }
    return belongsRec(l->tail, elem, cmp);
}

int belongs(const listADT l, elemType elem){
    /*
    ITERATIVO
    node * aux = l->first;
    int c;
    while(aux != NULL && (c = l->cmp(aux->head, elem)) <= 0){
        if(c == 0){
            return 1;
        }    
        aux = aux->tail;
    }

    return 0;
    */

    /// RECURSIVO

    return belongsRec(l->first, elem, l->cmp);

}

int addElement(listADT l, elemType elem);

int delete(listADT l, elemType elem);




