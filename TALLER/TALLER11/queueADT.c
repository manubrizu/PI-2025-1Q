#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

typedef struct node {
    elemtype head;
    struct node * tail;
} node;

typedef struct queueCDT{
    node * first;
    node * last;
    node * current;
} queueCDT;


queueADT newQueue(){
    return calloc(1, sizeof(queueCDT));
}

int isEmpty(queueADT q){
    return q->first == NULL;
}

void queue(queueADT q, elemtype n){
    node * aux = calloc(1, sizeof(node));
    aux->head = n;    
    if(isEmpty(q)){
        q->first= aux;
        q->last = aux;
    }
    else{
        q->last->tail = aux;
        q->last = aux;
    }
}

void dequeue(queueADT q, elemtype * out){
    if(isEmpty(q)){
        return;
    }
    node * aux = q->first;
    *out = q->first->head;
    if(aux == q->last){
        q->first = q->last = NULL;
    }
    else{
        q->first = q->first->tail;
    }
    free(aux);
}

static void freeQueueRec(node * l){
    if(l ==  NULL){
        return;
    }
    freeQueueRec(l->tail);
    free(l);
}


void freeQueue(queueADT q){
    freeQueueRec(q->first);
    free(q);
}

void toBegin(queueADT q){
    q->current = q->first;
}

int hasNext(queueADT q){
    return q->current != NULL;
}

elemtype next(queueADT q){
    if(!hasNext(q)){
        exit(1);
    }
    elemtype aux = q->current->head;
    q->current = q->current->tail;
    return aux; 
}

