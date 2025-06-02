#include <stdio.h>
#include <stdlib.h>
#include "bagADT.h"

typedef struct node{
    struct node * tail;
    elemType head;
    size_t count;
} node;

typedef struct bagCDT{
    struct node * first;
    size_t size;
    compare cmp;
} bagCDT;

typedef node * List;

void freeBag(bagADT bag){  
  node * actual = bag->first;
  node * next;

  while (actual != NULL){
    next = actual->tail;  
    free(actual);
    actual = next;
  }

  free(bag);
}

bagADT newBag(compare cmp){
    bagADT aux = calloc(1, sizeof(bagCDT));
    aux->cmp = cmp;
    return aux;
}

static List addRec(List list, elemType elem, size_t * cant, compare cmp){
    if (list == NULL){
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = NULL;
        aux->count = 1;
        return aux;
    }

    int c = cmp(list->head, elem);
    if(c == 0){
        (*cant) = list->count + 1;
        (list->count)++;
        return list;
    }
    if(c > 0){
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        aux->count = 1;
        return aux;
    }

    list->tail = addRec(list->tail, elem, cant, cmp);
    return list;

}

unsigned int add(bagADT bag, elemType elem){
    size_t cant = 1;
    bag->first = addRec(bag->first, elem, &cant, bag->cmp);
    if (cant == 1)
        (bag->size)++;
    return cant;
}

List deleteRec(List list, elemType elem, size_t * cant, compare cmp){
    if(list == NULL){
        return NULL;
    }
    int c = cmp(list->head, elem);

    if(c == 0){
        if(list->count){
            List aux = list->tail;
            free(list);
            return aux;
        }
        
        list->count--;
        return list;
    }

    if(c > 0){
        return list;
    }

    list->tail = deleteRec(list->tail, elem, cant, cmp);
    return list;
}

unsigned int delete(bagADT bag, elemType elem){
    int cant = count(bag, elem);
    bag->first = deleteRec(bag->first, elem, &cant, bag->cmp);
    if(cant == 0){
        (bag->size)--;
    }
    return cant;
}

static unsigned int countRec(List l, elemType elem, compare cmp){
    if(l == NULL){
        return 0;
    }
    
    int c = cmp(l->head, elem);
    if(c == 0){
        return l->count;
    }

    if(c > 0){
        return 0;
    }

    return countRec(l->tail, elem, cmp);
}

unsigned int count(const bagADT bag, elemType elem){
    return countRec(bag->first, elem, bag->cmp);
}

unsigned int size(const bagADT bag){
    return bag->size;
}

static void mostPopularRec(List list, unsigned int * max, elemType * object) {
    if (list == NULL)
        return;

    if (list->count > *max) {
        *max = list->count;
        *object = list->head;
    }

    mostPopularRec(list->tail, max, object);
}

elemType mostPopular(bagADT bag) {
    if (bag->size == 0) {
        exit(1);
    }

    unsigned int max = 0;
    elemType object = NULL;

    mostPopularRec(bag->first, &max, &object);
    return object;
}