#include <stdio.h>
#include <stdlib.h>
#include "tp11_14.h"

typedef struct node{
    struct node * tail;
    elemType head;
} node;

typedef node * List;

typedef struct listCDT{
    List first;         // lista con orden de insercion
    List actual;
    List firstAsc;      // lista con orden ascendente
    List actualAsc;
    compare cmp;
} listCDT;


listADT newList(compare cmp){
    listADT aux = calloc(1, sizeof(listCDT));
    aux->cmp = cmp;
    return aux;
}

static List addElementRec(List l, elemType elem, compare cmp){
    if(l == NULL){
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = NULL;
        return aux;
    }

    if(cmp(elem, l->head) == 0){
        return l;
    }

    l->tail = addElementRec(l->tail, elem, cmp);
    return l;
}

static List addElementAscRec(List l, elemType elem, compare cmp){
    int c;
    if(l == NULL || (c = cmp(l->head, elem)) > 0){
        node * aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = l;
        return aux;
    }

    if(c == 0){
        return l;
    }

    l->tail = addElementAscRec(l->tail, elem, cmp);
    return l;
}

void add(listADT list, elemType elem){
    list->first = addElementRec(list->first, elem, list->cmp);
    list->firstAsc = addElementAscRec(list->firstAsc, elem, list->cmp);
}

static List removeRec(List l, elemType elem, compare cmp){
    if(l == NULL){
        return NULL;
    }
    if(cmp(elem, l->head) == 0){
        List aux = l->tail;
        free(l);
        return aux;
    }

    l->tail = removeRec(l->tail, elem, cmp);
    return l;
}

static List removeAscRec(List l, elemType elem, compare cmp){
    int c;
    if(l == NULL || (c = cmp(l->head, elem)) > 0){
        return NULL;
    }
    if(c == 0){
        List aux = l->tail;
        free(l);
        return aux;
    }

    l->tail = removeAscRec(l->tail, elem, cmp);
    return l;
}

void removeElem(listADT list, elemType elem){
    list->first = removeRec(list->first, elem, list->cmp);
    list->firstAsc = removeAscRec(list->firstAsc, elem, list->cmp);
}

void toBegin(listADT list){
    list->actual = list->first;
}

int hasNext(listADT list){
    return list->actual != NULL;
}

elemType next(listADT list){
    if(list->actual == NULL){
        exit(1);
    }
    elemType aux = list->actual->head;
    list->actual = list->actual->tail;
    return aux;
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list){
    list->actualAsc = list->firstAsc;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0
*/
int hasNextAsc(listADT list){
    return list->actualAsc != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente.
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list){
    if(list->actualAsc == NULL){
        exit(1);
    }
    elemType aux = list->actualAsc->head;
    list->actualAsc = list->actualAsc->tail;
    return aux;
}

static void freeListRec(List l){
    if(l != NULL){
        freeListRec(l->tail);
        free(l);
    }
}

void freeList(listADT list){
    freeListRec(list->first);
    freeListRec(list->firstAsc);
    free(list);
}