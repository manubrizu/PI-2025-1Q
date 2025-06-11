#include <stdio.h>
#include <stdlib.h>
#include "roomsADT.h"

typedef struct node{
    struct node * next;
    char * nombre;
}node;

typedef struct node * List;

typedef struct roomList{    // cola
    List first;
    List actual;
    List last;
    char ocupado;
    size_t contAsistentes;
} roomList;

typedef struct roomsCDT{
    roomList * vec;
    size_t roomsOcupados;
    size_t maxRooms;
} roomsCDT;

roomsADT newRooms(size_t maxRooms){
    if(maxRooms == 0){
    	return NULL; 		// ???
    }
    roomsADT aux = calloc(1, sizeof(roomsCDT));
    aux->vec = calloc(maxRooms, sizeof(roomList));
    aux->maxRooms = maxRooms;
    return aux;
}

void reserveRoom(roomsADT rooms, size_t roomNumber, const char * attendee){		// asumo que roomNumber arranca en 0
    if(roomNumber < rooms->maxRooms){   // si es mayor o igual no hace nada
        List aux = calloc(1, sizeof(node));
        aux->nombre = attendee;
        rooms->vec[roomNumber].contAsistentes++;
        if(!rooms->vec[roomNumber].ocupado){
            rooms->roomsOcupados++;
            rooms->vec[roomNumber].ocupado = 1;
        }
        roomList * q = &rooms->vec[roomNumber];
        if(q->first == NULL){
            q->first = aux;
            q->last = aux;
        }
        else{
            q->last->next = aux;
            q->last = aux;
        }
    }
}

void toBeginByRoom(roomsADT rooms, size_t roomNumber){
    if(roomNumber < rooms->maxRooms){ 
        rooms->vec[roomNumber].actual = rooms->vec[roomNumber].first;
    }
}

size_t hasNextByRoom(const roomsADT rooms, size_t roomNumber){
    if(roomNumber >= rooms->maxRooms){
        return 0;
    }
    return rooms->vec[roomNumber].actual != NULL;
}

const char * nextByRoom(roomsADT rooms, size_t roomNumber){
    if(roomNumber >= rooms->maxRooms){
        return NULL;
    }
    if(rooms->vec[roomNumber].actual == NULL){
        exit(1);    //por gracioso
    }

    char * aux = rooms->vec[roomNumber].actual->nombre;
    rooms->vec[roomNumber].actual = rooms->vec[roomNumber].actual->next;
    return aux; 
}

static char * dequeue(roomList * q){
    if(q != NULL){
        List aux = q->first;
        char * out = q->first->nombre;
        q->contAsistentes--;
        if(aux == q->last){
            q->first = q->last = NULL;
            q->ocupado = 0;
        }
        else{
            q->first = q->first->next;
        }
        free(aux);
        return out;
    }
    return NULL;
}

char ** admitRooms(roomsADT rooms, size_t * admissionResultDim){
    if(rooms->roomsOcupados == 0){
        *admissionResultDim = 0;
        return NULL;
    }
    char ** aux = malloc(rooms->roomsOcupados * sizeof(char *));
    size_t cont = 0;
    for(size_t i = 0; i < rooms->maxRooms; ++i){
        if(rooms->vec[i].ocupado){
            aux[cont++] = dequeue(&rooms->vec[i]);
            if(!rooms->vec[i].ocupado){
                rooms->roomsOcupados--;
            }
        }
    }
    *admissionResultDim = cont;
    return realloc(aux, cont * sizeof(char *));
}

char ** admitRoomsN(roomsADT rooms, size_t * admissionResultDim, size_t n){
    if(rooms->roomsOcupados == 0 || n == 0){
        *admissionResultDim = 0;
        return NULL;
    }
    char ** aux = malloc(rooms->roomsOcupados * n * sizeof(char *));    // creo un vector con posiciones de mas, dsp hago un realloc
    size_t cont = 0;
    for(size_t i = 0; i < rooms->maxRooms; ++i){
        roomList * q = &rooms->vec[i];
        if(q->ocupado){
            for(size_t j = 0; j < n && q->contAsistentes > 0; j++){
                aux[cont++] = dequeue(q);
            }            
        }
    }
    *admissionResultDim = cont;
    return realloc(aux, cont * sizeof(char *));
}

void freeRec(List l){
    if(l != NULL){
        freeRec(l->next);
        free(l);
    }
}

void freeRooms(roomsADT rooms){
    for(size_t i = 0; i < rooms->maxRooms; ++i){
        freeRec(rooms->vec[i].first);
    }
    free(rooms->vec);
    free(rooms);
}