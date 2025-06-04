#include <stdio.h>
#include <stdlib.h>
#include "rankingADT.h"

typedef struct rankingCDT{
    elemType * vec;
    size_t count;
    compare cmp;
} rankingCDT;

static void swap(elemType * a, elemType * b){
    elemType aux = *a;
    *a = *b;
    *b = aux;
}

rankingADT newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT aux = calloc(1, sizeof(rankingCDT));
    aux->cmp = cmp;
    
    if(dim > 0){
        aux->vec = malloc(dim * sizeof(elemType));
        for (int i = 0; i < dim; i++){
            aux->vec[i] = elems[i];
        }
        aux->count = dim;
    }   
    return aux;
}


int contains(rankingADT ranking, elemType elem){
    for (int i = 0; i < ranking->count; i++){
        if(!ranking->cmp(ranking->vec[i], elem)){
            if(i!=0){
                swap(&ranking->vec[i], &ranking->vec[i-1]);
            }
            return 1;
        }
    }
    return 0;
}

void addRanking(rankingADT ranking, elemType elem){
    if(!contains(ranking, elem)){
        ranking->vec = realloc(ranking->vec, (ranking->count + 1) * sizeof(elemType));
        ranking->vec[ranking->count] = elem;
        ranking->count++;
    }
}

size_t size(const rankingADT ranking){
    return ranking->count;
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem){
    if(ranking->vec != NULL && n > 0 && n <= ranking->count){
        *elem = ranking->vec[n - 1];
        if(n > 1){            
            swap(&ranking->vec[n - 1], &ranking->vec[n - 2]);
        }
        return 1;
    }
    return 0;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top){
    if(ranking->vec == NULL){
        *top = 0;
        return NULL;
    }
    size_t n = (*top < ranking->count) ? *top : ranking->count;
    elemType * aux = malloc(n * sizeof(elemType));
    for (int i = 0; i < n; i++){
        aux[i] = ranking->vec[i];
    }
    * top = n;
    return aux;
}

/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n){
    if(n > 0 && n <= ranking->count){
        swap(&ranking->vec[n - 1], &ranking->vec[n]);
    }
}

void freeRanking(rankingADT r){
    free(r->vec);
    free(r);
}

int position(const rankingADT r, elemType elem){
    for (int i = 0; i < r->count; i++){
        if(!r->cmp(r->vec[i], elem)){
            return i + 1;
        }
    }
    return 0;
}