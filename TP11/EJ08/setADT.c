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

    if (isEmpty(l1) || cmp(l1->head, l2->head) > 0){
        aux->head = l2->head;
        aux->tail = unionRec(l1, l2->tail, cmp);
        return aux;
    }

    if (isEmpty(l2) || cmp(l1->head, l2->head) < 0){
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

static List listIntersec (const List l1, const List l2, compare cmp){
    if(isEmpty(l1) || isEmpty(l2)){
        return NULL;
    }

    if(l1->head < l2->head){
        return listIntersec(l1->tail, l2, cmp);
    }

    if(l1->head > l2->head){
        return listIntersec(l1, l2->tail, cmp);
    }

    List aux = newList(cmp);
    aux->head = l1->head;
    aux->tail = listIntersec(l1->tail, l2->tail, cmp);
    return aux;
}

setADT intersectionSet(setADT set1, setADT set2){
    setADT aux = newSet(set1->cmp);
    aux->l = listIntersec(set1->l, set2->l, set1->cmp);
    return aux;
}

static List listDiff(const List l1, const List l2, compare cmp){
    if (isEmpty(l1)) {
        return NULL;
    }
    
    if (isEmpty(l2) || l1->head < l2->head){
        List aux = newList(cmp);
        aux->head = l1->head;
        aux->tail = restaList(l1->tail, l2);    // sigo en l1
        return aux;
    }
    
    if(l1->head > l2->head){
        return restaList(l1, l2->tail);     // sigo en l2
    }

    // caso en que sean iguales 
    return restaList(l1->tail, l2->tail); 
}

setADT diffSet(setADT set1, setADT set2){
    setADT aux = newSet(set1->cmp);
    aux->l = listdiff(set1->l, set2->l);
    return aux;
}