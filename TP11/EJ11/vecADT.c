#include <stdio.h>
#include <stdlib.h>
#include "vecADT.h"

typedef struct node{
    elemType elem;
    char exist;    // 1 si esta ocupada, 0 si no
} node;


typedef struct vectorCDT{
    node * vec;
    compare cmp;
    size_t count;   // cantidad de elementos insertados
    size_t dim;     // cantidad de posiciones reservadas     
} vectorCDT;

vectorADT newVector(compare cmp){
    vectorADT aux = calloc(1, sizeof(vectorCDT));
    aux->cmp = cmp;
    return aux;
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

void freeVector(vectorADT v){
    free(v->vec);
    free(v);
}

int getIdx(vectorADT v, elemType elem, compare cmp){
    for (int i = 0; i < v->dim; i++){
        if(! cmp(v->vec->elem, elem)){
            return i;
        }
    }
    return -1;    
}

void deleteElement(vectorADT v, size_t index){
    if(!isOccupied(v, index)){
        return;
    }

    v->vec[index].exist = 0;
    v->count--;
}


int put(vectorADT v, elemType * elems, size_t dim, size_t index){
    size_t cont = 0;
    size_t dimTot = index + dim;
    if(dimTot > v->dim){
        v->vec = realloc(v->vec, dimTot * sizeof(node));
        for(size_t i = v->dim; i < dimTot; i++)
            v->vec[i].exist = 0;
        v->dim = dimTot;
    }
    
    size_t pos = index;
    for(size_t i = 0; i < dim; i++, pos++) {
        if(!isOccupied(v, pos)) {
            v->vec[pos].elem = elems[i];
            v->vec[pos].exist = 1;
            v->count++;
            cont++;
        }
    }

    return cont;   
}

int elementCount(vectorADT v){
    return v->count;
}