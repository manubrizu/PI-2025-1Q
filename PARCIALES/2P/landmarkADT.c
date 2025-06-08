#include <stdio.h>
#include <stdlib.h>
#include "landmarkADT.h"

typedef struct node{
    landmarkType nombre;
    char exists;
} ptoDeInteres;

typedef struct landmarkCDT{
    ptoDeInteres * vec;
    size_t cantSites;
    size_t dim;
    compare cmp;
} landmarkCDT;

landmarkADT newLandmark(compare cmp){
    landmarkADT aux = calloc(1, sizeof(landmarkCDT));
    aux->cmp = cmp;
    return aux;
}

void addLandmark(landmarkADT landmark, size_t meters, landmarkType site){
    int idx = meters / 100;
    if(idx >= landmark->dim){
        landmark->vec = realloc(landmark->vec, (idx + 1) * sizeof(ptoDeInteres));
        for(size_t i = landmark->dim; i <= idx; ++i){
            landmark->vec[i].nombre = NULL;
            landmark->vec[i].exists = 0;
        }
        landmark->dim = idx + 1;
    }

    if(!landmark->vec[idx].exists){
        landmark->cantSites++;
        landmark->vec[idx].exists = 1;
    }

    landmark->vec[idx].nombre = site;
}

int hasLandmark(const landmarkADT landmark, size_t meters){
    int idx = meters / 100;
    if(idx >= landmark->dim){
        return 0;
    }
    return (int) landmark->vec[idx].exists;
}

landmarkType * landmarks(const landmarkADT landmark){
    if(landmark->cantSites == 0){
        return NULL;
    }

    landmarkType * aux = malloc(landmark->cantSites * sizeof(landmarkType));
    size_t j = 0;

    for(size_t i = 0; i < landmark->dim ; ++i){
        if(landmark->vec[i].exists){
            aux[j++] = landmark->vec[i].nombre;
        }
    }

    return aux;
}

