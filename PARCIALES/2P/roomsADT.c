#include <stdio.h>
#include <stdlib.h>
#include "roomsADT.h"

typedef struct node{
    struct node * next;
    char * nombre;
}node;

typedef struct node * List:

typedef struct roomList{
    List first;
    List actual;
    List last;
    size_t contAsistentes;
} roomList;

typedef struct roomsCDT{
    roomList * vec;
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
    if(roomNumber < rooms->maxRooms){
	
    }
}