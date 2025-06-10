#include <stdio.h>
#include <stdlib.h>
#include "bikeSharingADT.h"

typedef struct station{
    char * docks;           // 1 ocupado || 0 libre
    char exists;
    size_t countDocks;      // funciona como un dim
    size_t countBikes;      // cant de docks ocupados
} station;

typedef struct bikeSharingCDT{
    station * stations;
    size_t countStations;   // funciona como un dim
    size_t maxStations;
} bikeSharingCDT;

bikeSharingADT newBikeSharing(size_t maxStationsCount){
    bikeSharingADT aux = calloc(1, sizeof(bikeSharingCDT));
    aux->maxStations = maxStationsCount;
    aux->stations = calloc(1, maxStationsCount * sizeof(station));
    return aux;
}

int addStation(bikeSharingADT bike, size_t stationId, size_t docksCount){
    if(stationId == 0 || stationId > bike->maxStations || bike->stations[stationId - 1].exists){
        return -1;
    }

    station * s = &bike->stations[stationId - 1];
    s->docks = malloc(docksCount);
    for(int i = s->countDocks; i < docksCount; ++i){
        s->docks[i] = 1;
    }
    s->countBikes = docksCount;
    s->countDocks = docksCount;
    
    s->exists = 1;
    return ++bike->countStations;         
}

int rentBike(bikeSharingADT bike, size_t stationId, size_t dockId){
    if(stationId == 0 || bike->countStations > stationId || ! bike->stations[stationId - 1].exists || dockId >= bike->stations[stationId - 1].countDocks || ! bike->stations[stationId - 1].docks[dockId]){
        return -1;
    }

    bike->stations[stationId - 1].docks[dockId] = 0;
    bike->stations[stationId - 1].countBikes--;
    return 0;
}

int bikesAvailable(bikeSharingADT bike, size_t stationId){
    if(stationId == 0 || bike->countStations > stationId || ! bike->stations[stationId - 1].exists){
        return -1;
    }

    return bike->stations[stationId - 1].countBikes;
}

int docksAvailable(bikeSharingADT bike, size_t stationId){
    if(stationId == 0 || bike->countStations > stationId || ! bike->stations[stationId - 1].exists){
        return -1;
    }

    return  bike->stations[stationId - 1].countDocks - bike->stations[stationId - 1].countBikes;
}

int returnBike(bikeSharingADT bike, size_t stationId, size_t dockId){
    if(stationId == 0 || bike->countStations > stationId || ! bike->stations[stationId - 1].exists || dockId >= bike->stations[stationId - 1].countDocks || bike->stations[stationId - 1].docks[dockId]){
        return -1;
    }

    bike->stations[stationId - 1].docks[dockId] = 1;
    bike->stations[stationId - 1].countBikes++;
    return 0;
}


void freeBikeSharing(bikeSharingADT bike){
    for(size_t i = 0; i < bike->maxStations; ++i){
        free(bike->stations[i].docks);
    }
    free(bike->stations);
    free(bike);
}

