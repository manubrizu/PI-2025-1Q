#include <stdio.h>
#include <stdlib.h>
#include "ListADT.h"

#define BLOCK 10

typedef struct node{
    elemType head;
    struct node * tail;
} node;


typedef struct listCDT{
    struct node * first;
    struct node * actual;
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
    free(l);
}

int belongsRec(node * l, elemType elem, compare cmp){
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

static node * addElementRec(node * l, elemType elem, compare cmp, int * flag){
    int c;

    if(l == NULL || (c = cmp(l->head, elem)) > 0){
        node * aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = l;
        *flag = 1;
        return aux;
    }

    if(c == 0){
        return l;
    }

    l->tail = addElementRec(l->tail, elem, cmp, flag);
    return l;
}

int addElement(listADT l, elemType elem){
    int flag = 0;
    l->first = addElementRec(l->first, elem, l->cmp, &flag);
    if(flag){
        l->size++;
    }
    return flag;
}

static node * deleteRec(node * l, elemType elem, compare cmp, int * flag){
    int c;
    if(l == NULL || (c = cmp(l->head, elem)) > 0){
        return l;
    }

    if(c == 0){
        node * aux = l->tail;
        free(l);
        *flag = 1;
        return aux;
    }
    
    l->tail = deleteRec(l->tail, elem, cmp, flag);
    return l;
}

int delete(listADT l, elemType elem){
    int flag = 0;
    l->first = deleteRec(l->first, elem, l->cmp, &flag);
    if(flag){
        l->size--;
    }
    return flag;
}

static elemType getRec(node * l, int i){
    if(l == NULL || i < 0){
        return NULL;
    }
    if(i == 0){
        return l->head;
    }
    return getRec(l->tail, i - 1);
}

elemType get(const listADT l, int i){
    if(i < 0 || i >= l->size) {
        return NULL;
    }
    return getRec(l->first, i);
}

elemType * toArray(const listADT l){
    elemType * aux = malloc(size(l) * sizeof(elemType));

    node * foo = l->first;
    
    for (int i = 0; i < size(l); i++){
        aux[i] = foo->head;
        foo = foo->tail; 
    }
    
    return aux;
}

void toBegin(listADT l){
    l->actual = l->first;
}

int hasNext(listADT l){
    return l->actual != NULL;
}

elemType next(listADT l){
    if(l->actual == NULL){
        exit(1);
    }
    
    elemType aux = l->actual->head;
    l->actual = l->actual->tail;
    return aux;
}

