#include <stdio.h>
#include <stdlib.h>
#include "airpotADT.h"

#define CHECK(x) x > airportAdt->dim || ! airportAdt->cola[x - 1].exists || airportAdt->cola[x - 1].pendingPista == 0

typedef struct node{
    struct node * next;
    char * code;
} node;

typedef struct node * List;

typedef struct queue{
    List first;
    List last;
    size_t pendingPista;        // vuelos pendientes de salir de la pista;
    char exists;
} queue;

typedef struct airportCDT{
    queue * cola;               // vector dinamico de colas
    size_t pendingAirport;      // vuelos pendientes de salir del aeropuerto
    size_t pistas;
    size_t dim;
} airportCDT;


airportADT newAirport(){
    return calloc(1, sizeof(airportCDT));
}

int addRunway(airportADT airportAdt, size_t runwayId){
    if(runwayId == 0){
        return -1;
    }

    if(runwayId > airportAdt->dim){
        airportAdt->cola = realloc(airportAdt->cola, (runwayId) * sizeof(queue));
        queue * q = &airportAdt->cola;
        for(size_t i = airportAdt->dim; i < runwayId; ++i){
            q[i].last = NULL;
            q[i].first = NULL;
            q[i].pendingPista = 0;
            q[i].exists = 0;
        }       
        airportAdt->dim = runwayId;
    }

    if(airportAdt->cola[runwayId - 1].exists){
        return -1;
    }

    airportAdt->cola[runwayId - 1].exists = 1;
    return ++airportAdt->pistas;    
}

static void encolar(queue * q, char * code){
    node * aux = calloc(1, sizeof(node));
    aux->code = code;    
    if(isEmpty(q)){
        q->first= aux;
        q->last = aux;
    }
    else{
        q->last->next = aux;
        q->last = aux;
    }
}

char * dequeue(queue * q){
    if(q != NULL){    
        node * aux = q->first;
        char * out = q->first->code;
        if(aux == q->last){
            q->first = q->last = NULL;
        }
        else{
            q->first = q->first->next;
        }
        q->pendingPista--;
        free(aux);
        return out;
    }
    return NULL;
}

int addPlaneToRunway(airportADT airportAdt, size_t runwayId, const char * registration){


}

char * takeOff(airportADT airportAdt, size_t runwayId){
    if(CHECK(runwayId)){
        return NULL;
    } 
    
    return dequeue(&airportAdt->cola);
}

static void returnRec(List l, size_t * id, char ** aux){
    if(l == NULL){
        aux[*id] = ""; 
        return;
    }


    returnRec(l->next, id, aux + 1);

    if(l->next == NULL){
        *id = 0;
    }

    aux[*id] = l->code;
    (*id)++;
}

char ** pendingFlights(airportADT airportAdt, size_t runwayId){
    if(runwayId > airportAdt->dim || ! airportAdt->cola[runwayId - 1].exists){
        return NULL;
    }
    int i = airportAdt->pendingAirport;
    char ** aux = malloc((airportAdt->pendingAirport + 1) * sizeof(char *));
    
    returnRec(airportAdt->cola[runwayId - 1].first, &i, aux);
    
    aux[airportAdt->pendingAirport] = "";
    List foo = airportAdt->cola[runwayId - 1].first;

    for(size_t i = airportAdt->pendingAirport - 1; i >= 0; --i){
        aux[i] = foo->code;
        foo = foo->next;
    }
    
   return aux;
}
