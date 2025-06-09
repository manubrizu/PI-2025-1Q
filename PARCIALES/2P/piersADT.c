#include <stdio.h>
#include <stdlib.h>
#include "piersADT.h"


typedef struct puerto{
    char * muelles;
    size_t dim;             // dim del vectorde muelles
    size_t cantBarcos;     // cantidad de muelles
    char existsP;           // el puerto existe
}puerto;

typedef struct piersCDT{
    puerto * puertos;       
    size_t dim; 
    size_t cantPuertos;
} piersCDT;

piersADT newPiers(void){
    return calloc(1, sizeof(piersCDT));
}

size_t addPier(piersADT piers, size_t pierNumber){
    if(piers->dim <= pierNumber){
        piers->puertos = realloc(piers->puertos, (pierNumber + 1) * sizeof(puerto));
        for (size_t i = piers->dim; i <= pierNumber; i++){
            piers->puertos[i].cantBarcos = 0;
            piers->puertos[i].muelles = NULL;
            piers->puertos[i].dim = 0;
            piers->puertos[i].existsP = 0;
        }
        piers->dim = pierNumber + 1;
    }

    if(piers->puertos[pierNumber].existsP){
        return 0;
    }

    piers->puertos[pierNumber].existsP = 1;
    piers->cantPuertos++;
    return 1;
}

size_t addPierDock(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->dim <= pierNumber){
        piers->puertos = realloc(piers->puertos, (pierNumber + 1) * sizeof(puerto));
        for (size_t i = piers->dim; i <= pierNumber; i++){
            piers->puertos[i].cantBarcos = 0;
            piers->puertos[i].muelles = NULL;
            piers->puertos[i].dim = 0;
            piers->puertos[i].existsP = 0;
        }
        piers->dim = pierNumber + 1;
    }

    puerto * p = &piers->puertos[pierNumber];

    if(p->dim <= dockNumber){
        p->muelles = realloc(p->muelles, (dockNumber + 1) * sizeof(char *));
        for(size_t i = p->dim; i <= dockNumber; ++i){
            p->muelles[i] = 0;
        }
        p->dim = dockNumber + 1;
    }

    p->dim++;
    return 1;
}

size_t dockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->dim <= pierNumber || piers->puertos[pierNumber].dim <= dockNumber || piers->puertos[pierNumber].muelles[dockNumber]){
        return 0;
    }

    piers->puertos[pierNumber].muelles[dockNumber] = 1;
    return 1;
}

int shipInDock(const piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->dim <= pierNumber || piers->puertos[pierNumber].dim <= dockNumber){
        return -1;
    }

    return piers->puertos[pierNumber].muelles[dockNumber];
}
