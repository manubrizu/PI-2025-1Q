#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countersADT.h"

typedef struct node{
    struct node * next;
    char * pasajero;
}node;

typedef struct queue{
    node * first;       // primero q sale   
    node * last;        // ultimo q entro
    node * actual;      // iterador
    size_t cantPas;     // cantidad de pasajeros por mostrador
} queue;

typedef struct countersCDT{
    queue * mostradores;        // vector de colas
    size_t cantMostradores;     // cantidad de mostradores (dim del vector)
}countersCDT;

static char * copyStr(const char * nombre){
    return strcpy(malloc(strlen(nombre) + 1), nombre);
}

countersADT newCounters(size_t maxCounters){
    if(maxCounters == 0){
        return NULL;
    }
    countersADT aux = calloc(1, sizeof(countersCDT));
    aux->cantMostradores = maxCounters;
    aux->mostradores = calloc(maxCounters, sizeof(queue));
    return aux;
}


void enterCounter(countersADT counters, size_t counterNumber, const char * passenger){
    if(counterNumber >= counters->cantMostradores){
        return;
    }

    node * aux = calloc(1, sizeof(node));
    aux->pasajero = copyStr(passenger);

    if(counters->mostradores[counterNumber].first == NULL){
        counters->mostradores[counterNumber].first = aux;
        counters->mostradores[counterNumber].last = aux;
    }
    else{
        counters->mostradores[counterNumber].last->next = aux;
        counters->mostradores[counterNumber].last = aux;
    }

    counters->mostradores[counterNumber].cantPas++;
}

void toBeginByCounter(countersADT counters, size_t counterNumber){
    if(counterNumber >= counters->cantMostradores){
        return;
    }

    counters->mostradores[counterNumber].actual = counters->mostradores[counterNumber].first;
}

static void dequeue(queue * q){
    if(isEmpty(q)){
        return;
    }
    node * aux = q->first;
    if(aux == q->last){
        q->first = q->last = NULL;
    }
    else{
        q->first = q->first->next;
    }
    free(aux);
}

struct checkInResult * checkInCounters(countersADT counters, size_t * checkInResultDim){
    struct checkInResult * aux = malloc(counters->cantMostradores * sizeof(struct checkInResult));
    size_t cont = 0;
    for (int i = 0; i < counters->cantMostradores; i++){
        if(counters->mostradores[i].cantPas != 0){
            aux[i].counterNumber = i;
            aux[i].checkedInPassenger = copyStr(counters->mostradores[i].first->pasajero);
            dequeue(&counters->mostradores[i].first);
            aux[i].waitingPassengers = --counters->mostradores[i].cantPas;
            cont++;
        }            
    }
    *checkInResultDim = cont;
    return aux;
}