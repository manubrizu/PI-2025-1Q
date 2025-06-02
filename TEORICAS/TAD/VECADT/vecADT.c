#include <stdio.h>
#include <stdlib.h>
#include "vecADT.h"

typedef struct node{
    elemType elem;
    char exist;    // 1 si esta ocupada, 0 si no
} node;


typedef struct vectorCDT{
    node * vec;
    size_t count;   // cantidad de elementos insertados
    size_t dim;     // cantidad de posiciones reservadas     
} vectorCDT;

vectorADT newVector(){
    return calloc(1, sizeof(vectorCDT));
}

int elementCount(const vectorADT v){
    return v->count;
}

void addElement(vectorADT v, elemType elem, size_t index){
    if(index >= v->dim){
        v->vec = realloc(v->vec, (index + 1) * sizeof(node));
        for (size_t i = v->dim; i < index + 1; i++){
            v->vec[i].exist = 0;
        }
        v->dim = index + 1;        
    }
    
    v->vec[index].elem = elem;

    if(!v->vec[index].exist){
        v->count++;
        v->vec[index].exist = 1;
    }   
}

static int isOccupied(vectorADT v, size_t index){
    return index < v->dim && v->vec[index].exist;
}

int getElement(const vectorADT v, size_t index, elemType * elem){
    if(! isOccupied(v, index)){
        return 0;
    }    

    *elem = v->vec[index].elem;
    return 1;
}

int deleteElement(vectorADT v, size_t index){
    if(! isOccupied(v, index)){
        return 0;
    }

    v->vec[index].exist = 0;
    v->count--;
    return 1;
}

void freeVector(vectorADT v){
    free(v->vec);
    free(v);
}


