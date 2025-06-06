#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "museumTicketADT.h"

#define ISNOTVALID(x) ((x) > 366 || (x) <= 0)

#define DAYS 366

typedef struct node{
    struct node * next;
    char * nombre;    
} node;

typedef node * List;

typedef struct datos{
    List personas;
    List actual;
    size_t tickets;
} datos;

typedef struct museumTicketCDT{
    datos dias[DAYS];
    size_t tikcetsTot;
} museumTicketCDT;

museumTicketADT newMuseumTicket(void){
    return calloc(1, sizeof(museumTicketCDT));
}

static char * copyWord(const char * s){
    int len = strlen(s) + 1;
    return strcpy(malloc(len), s);
}

List addTicketRec(List l, char * visitor, int * flag){
    int c;
    if(l == NULL || (c = strcasecmp(l->nombre, visitor)) > 0){
        List aux = calloc(1, sizeof(node));
        aux->nombre = copyWord(visitor);
        *flag = 1;
        return aux;
    }
    if(c == 0){
        return l;
    }

    l->next = addTicketRec(l->next, visitor, flag);
    return l;

}

int addTicket(museumTicketADT m, size_t dayOfYear,  char * visitor){
    if(ISNOTVALID(dayOfYear) || m == NULL){
        return 0;
    } 
    
    
    int flag = 0;
    m->dias[dayOfYear - 1].personas = addTicketRec(m->dias[dayOfYear - 1].personas, visitor, &flag);
    if(flag){
        m->dias[dayOfYear - 1].tickets++;
        m->tikcetsTot++;        
        return m->dias[dayOfYear - 1].tickets;
    }
    return flag;
}

int dayTickets(const museumTicketADT m, size_t dayOfYear){
    if(ISNOTVALID(dayOfYear)){
        return -1;
    } 

    return m->dias[dayOfYear - 1].tickets;
}

int yearTickets(const museumTicketADT m){
    return m->tikcetsTot;
}

void toBeginByDay(museumTicketADT m, size_t dayOfYear){
    if(ISNOTVALID(dayOfYear)){
        return;
    }
    m->dias[dayOfYear - 1].actual = m->dias[dayOfYear - 1].personas;
}

size_t hasNextByDay(museumTicketADT m, size_t dayOfYear){
    if(ISNOTVALID(dayOfYear)){
        exit(1);
    } 

    return m->dias[dayOfYear - 1].actual != NULL;
}

char * nextByDay(museumTicketADT m, size_t dayOfYear){
    if(ISNOTVALID(dayOfYear)){
        return NULL;
    } 
    if(m->dias[dayOfYear - 1].actual == NULL){
        exit(1);        // por gracioso
    }

    char * aux = copyWord(m->dias[dayOfYear - 1].actual->nombre);
    m->dias[dayOfYear - 1].actual = m->dias[dayOfYear - 1].actual->next;
    return aux;
}

static void freeRec(List l){
    if(l != NULL){
        freeRec(l->next);
        free(l->nombre);
        free(l);
    }
}

void freeMuseumTicket(museumTicketADT m){
    for (int i = 0; i < DAYS; i++){
        freeRec(m->dias[i].personas);
    }
    free(m);    
}