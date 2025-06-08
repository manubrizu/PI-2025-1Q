#include <stdio.h>
#include <stdlib.h>
#include "piersADT.h"

typedef struct muelle{
    char amarrado;          // embarcacion amarrada
    int existsM;           // el muelle existe
}muelle;

typedef struct puerto{
    muelle * muelles;
    size_t dim;             // dim del vectorde muelles
    size_t cantMuelles;     // cantidad de muelles
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
    if(piers->dim < pierNumber){
        piers->puertos = realloc(piers->puertos, pierNumber * sizeof(puerto));
        for (size_t i = piers->dim; i < pierNumber; i++){
            piers->puertos[i].cantMuelles = 0;
            piers->puertos[i].muelles = NULL;
            piers->puertos[i].dim = 0;
            piers->puertos[i].existsP = 0;
        }
        piers->dim = pierNumber;
    }

    if(piers->puertos[pierNumber - 1].existsP){
        return 0;
    }

    piers->puertos[pierNumber - 1].existsP = 1;
    piers->cantPuertos++;
    return 1;
}

size_t addPierDock(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->dim < pierNumber){
        piers->puertos = realloc(piers->puertos, pierNumber * sizeof(puerto));
        for (size_t i = piers->dim; i < pierNumber; i++){
            piers->puertos[i].cantMuelles = 0;
            piers->puertos[i].muelles = NULL;
            piers->puertos[i].dim = 0;
            piers->puertos[i].existsP = 0;
        }
        piers->dim = pierNumber;
    }

    puerto * p = &piers->puertos[pierNumber - 1];

    if(p->dim < dockNumber){
        p->muelles = realloc(p->muelles, dockNumber * sizeof(muelle));
        for(size_t i = p->cantMuelles; i <= dockNumber; ++i){
            p->muelles[i].amarrado = 0;
            p->muelles[i].existsM = 0;
        }
        p->dim = dockNumber;
    }

    if(p->muelles[dockNumber - 1].existsM){
        return 0;
    }

    p->muelles[dockNumber - 1].existsM = 1;
    p->cantMuelles++;
    return 1;
}

size_t dockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->dim < pierNumber || piers->puertos[pierNumber - 1].dim < dockNumber || ! piers->puertos[pierNumber - 1].muelles[dockNumber - 1].existsM || piers->puertos[pierNumber - 1].muelles[dockNumber - 1].amarrado){
        return 0;
    }

    piers->puertos[pierNumber - 1].muelles[dockNumber - 1].amarrado = 1;
    return 1;
}

int shipInDock(const piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->dim < pierNumber || piers->puertos[pierNumber - 1].dim < dockNumber){
        return -1;
    }

    return piers->puertos[pierNumber - 1].muelles[dockNumber - 1].amarrado;
}
