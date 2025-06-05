#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "squirrelTAD.h"

#define DIST 15 // la distancia que tiene el cuadrado

typedef struct row {
    size_t colCount;
    size_t * ardillas;  // seria cols
} row;

typedef struct squirrelCensusCDT{
    size_t blockSize;
    size_t rowCount;
    row * rows;    
} squirrelCensusCDT;


squirrelCensusADT newSquirrelCensus(size_t blockSizeMeters){
    if(blockSizeMeters == 0){
        return NULL;    // ABORTO
    }
    squirrelCensusADT aux = calloc(1, sizeof(squirrelCensusCDT));
    aux->blockSize = blockSizeMeters;
    return aux;
}

size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    size_t x = yDistance / squirrelAdt->blockSize;
    size_t y = xDistance / squirrelAdt->blockSize;

    if(x >= squirrelAdt->rowCount){     // NO TENGO LUGAR, NECESITO CREAR
        squirrelAdt->rows = realloc(squirrelAdt->rows, (x + 1) * sizeof(row));
        // Ahora a inicializar
        for (int i = squirrelAdt->rowCount; i <= x; i++){
            squirrelAdt->rows[i].colCount = 0;
            squirrelAdt->rows[i].ardillas = NULL;
        }

        // si usara MEMSET
        // memset(squirrelAdt->rows + squirrelAdt->rowCount, (x - squirrelAdt->rowCount + 1) * sizeof(row), 0);   
        
        squirrelAdt->rowCount = x + 1;
    }

    // Ahora chequeo si existe la columa

    if(y >= squirrelAdt->rows[x].colCount){
        squirrelAdt->rows[x].ardillas = realloc(squirrelAdt->rows[x].ardillas, (y + 1) * sizeof(size_t));
        // Ahora a inicializar
        for (int i = squirrelAdt->rows[x].colCount; i <= y; i++){
            squirrelAdt->rows[x].ardillas[i] = 0;
        }

        squirrelAdt->rows[x].colCount = y + 1;
    }

    // Ya me asegure que este el lugar al que voy a acceder

    squirrelAdt->rows[x].ardillas[y]++;
    return squirrelAdt->rows[x].ardillas[y];
}

size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDist, size_t xDist){
    size_t y = yDist / squirrelAdt->blockSize;
    size_t x = xDist / squirrelAdt->blockSize;

    if(y >= squirrelAdt->rowCount || x >= squirrelAdt->rows[y].colCount){
        return 0;
    }

    return squirrelAdt->rows[y].ardillas[x];
}

void freeSquirrelCensus(squirrelCensusADT squirrelAdt){
    for (int i = 0; i < squirrelAdt->rowCount; i++){
        free(squirrelAdt->rows[i].ardillas);
    }
    free(squirrelAdt->rows);
    free(squirrelAdt);    
}