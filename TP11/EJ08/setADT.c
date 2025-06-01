#include <stdio.h>
#include <stdlib.h>
#include "setADT.h"
#include "ListADT.h"
#include "./utillist.h"

typedef struct setCDT{
    listADT l;
    compare cmp;
} setCDT;

setADT newSet(compare cmp){
    setADT aux = calloc(1, sizeof(setCDT));
    aux->l = newList(cmp);
    aux->cmp = cmp;
    return aux;
}

void freeSet(setADT set){
    freeList(set->l);
    free(set);
}

int isEmptySet(setADT set){
    return isEmpty(set->l);
}

int setContains(const setADT set, elemType element){
    return belongs(set->l, element);
}

int addElementSet(setADT set, elemType element){
    return addElement(set->l, element);
}

int deleteElementSet(setADT set, elemType element){
    return delete(set->l, element);
}

int sizeSet(const setADT set){
    return size(set->l);
}

static List listUnion (const List l1, const List l2, compare cmp){
    if(isEmpty(l1) && isEmpty(l2)){
        return NULL;
    }

    List aux = newList(cmp);

    if (l1 == NULL || cmp(l1->head, l2->head) > 0){
    aux->head = l2->head;
    aux->tail = unionRec(l1, l2->tail, cmp);
    return aux;

    }
    if (l2 == NULL || cmp(l1->head, l2->head) < 0){
        aux->head = l1->head;
        aux->tail = unionRec(l1->tail, l2, cmp);
        return aux;
    }

    aux->head = l1->head; 
    aux->tail = unionRec(l1->tail, l2->tail, cmp);
    return aux;

}

setADT unionSet(setADT set1, setADT set2){
    setADT aux = newSet(set1->cmp);
    aux->l = listUnion(set1->l, set2->l, set1->cmp);
    return aux;
}

static List listIntersec (const List l1, const List l2){
    if(isEmpty(l1) || isEmpty(l2)){
        return NULL;
    }

    if(l1->head < l2->head){
        return listIntersec(l1->tail, l2);
    }

    if(l1->head > l2->head){
        return listIntersec(l1, l2->tail);
    }

    List aux = malloc(sizeof(node));
    aux->head = l1->head;
    aux->tail = listIntersec(l1->tail, l2->tail);
    return aux;
}

setADT intersectionSet(setADT set1, setADT set2){
    setADT aux = newSet(set1->cmp);
    aux->l = listIntersec(set1->l, set2->l);
    return aux;
}

static List listdiff(const List l1, const List l2){
    if (isEmpty(l1) && isEmpty(l2)) {
        return NULL;
    }
    if (isEmpty(l1)) {
        // Copiar el resto de l2
        List aux = malloc(sizeof(node));
        aux->head = l2->head;
        aux->tail = listSymDiff(NULL, l2->tail);
        return aux;
    }
    if (isEmpty(l2)) {
        // Copiar el resto de l1
        List aux = malloc(sizeof(node));
        aux->head = l1->head;
        aux->tail = listSymDiff(l1->tail, NULL);
        return aux;
    }
    if (l1->head < l2->head) {
        List aux = malloc(sizeof(node));
        aux->head = l1->head;
        aux->tail = listSymDiff(l1->tail, l2);
        return aux;
    }
    if (l1->head > l2->head) {
        List aux = malloc(sizeof(node));
        aux->head = l2->head;
        aux->tail = listSymDiff(l1, l2->tail);
        return aux;
    }

    return listSymDiff(l1->tail, l2->tail);
}

setADT diffSet(setADT set1, setADT set2){
    setADT aux = newSet(set1->cmp);
    aux->l = listdiff(set1->l, set2->l);
    return aux;
}