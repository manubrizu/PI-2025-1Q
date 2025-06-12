#include <stdio.h>
#include <stdlib.h>
#include "attractionADT.h"

#define HOURS 24

typedef struct node{
    struct node * next;
    char * nombre;
} node;

typedef struct node * List;

typedef struct queue{
    List first;
    List last;
    size_t cantVisitors;    // cantidad de visitantes por Hora
} queue;

typedef struct attractionCDT{
    queue vec[HOURS];      
} attractionCDT;

attractionADT newAttraction(void){
    return calloc(1, sizeof(attractionCDT));
}

static char * copyStr(char * s){
    return strcpy(malloc(strlen(s) + 1), s);
}

void addVisitor(attractionADT att, size_t hour, const char * visitor){
    if(hour < HOURS){
        List aux = malloc(sizeof(node));
        aux->nombre = copyStr(visitor);
        queue * q = &att->vec[hour];

        if(q->first == NULL){
            q->first = q->last = aux;
        }
        else{
            q->last->next = aux;
            q->last = aux;
        }        
    }
}

char * rideVisitor(attractionADT att, size_t hour){
    if(hour >= HOURS || att->vec[hour].first == NULL){
        return NULL;
    }

    queue * q = &att->vec[hour];
    List aux = q->first;
    char * out = q->first->nombre;
    
    if(q->first == q->last){
        q->first = q->last = NULL;
    }
    else{
        q->first = q->first->next;
    }
    free(aux);
    return out;
}

static void pendingVisitorRec(List l, char ** aux, size_t * dim){
    if(l == NULL){
        return;
    }
    aux[*dim] = l->nombre;
    (*dim)++;
    pendingVisitorRec(l->next, aux, dim);
}

char ** pendingVisitors(const attractionADT att, size_t hour, size_t * dim){
    * dim =  0;
    if(hour >= HOURS || att->vec[hour].first == NULL){
        return NULL;
    }
    char ** aux = malloc(att->vec[hour].cantVisitors * sizeof(char *));

    pendingVisitorsRec(att->vec[hour].first, aux, dim);
    return aux;
}