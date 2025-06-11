#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "roomsADT.h"

int main(void) {
    roomsADT conferenceCenter = newRooms(5);
    reserveRoom(conferenceCenter, 3, "Alice"); // Alice está en espera de la sala 3
    reserveRoom(conferenceCenter, 3, "Bob");
    reserveRoom(conferenceCenter, 3, "Bob");
    reserveRoom(conferenceCenter, 2, "Charlie");
    reserveRoom(conferenceCenter, 2, "David");
    // Se desea consultar los asistentes que están esperando en la sala 3
    toBeginByRoom(conferenceCenter, 3);
    // "Alice" es el primero que reservó la sala 3
    assert(hasNextByRoom(conferenceCenter, 3) == 1);
    assert(strcmp(nextByRoom(conferenceCenter, 3), "Alice") == 0);
    assert(hasNextByRoom(conferenceCenter, 3) == 1);
    assert(strcmp(nextByRoom(conferenceCenter, 3), "Bob") == 0);
    toBeginByRoom(conferenceCenter, 2);
    assert(hasNextByRoom(conferenceCenter, 2) == 1);
    assert(strcmp(nextByRoom(conferenceCenter, 2), "Charlie") == 0);
    // Se pueden usar en simultáneo las funciones de iteración para consultar
    // los asistentes que están esperando en distintas salas
    assert(hasNextByRoom(conferenceCenter, 3) == 1);
    assert(strcmp(nextByRoom(conferenceCenter, 3), "Bob") == 0);
    assert(hasNextByRoom(conferenceCenter, 2) == 1);
    assert(strcmp(nextByRoom(conferenceCenter, 2), "David") == 0);
    assert(hasNextByRoom(conferenceCenter, 3) == 0);
    assert(hasNextByRoom(conferenceCenter, 2) == 0);
    // Se realiza, para cada sala, la admisión del asistente que está esperando primero
    size_t admissionResultDim;
    char ** admissionResultVec;
    admissionResultVec = admitRooms(conferenceCenter, &admissionResultDim);
    assert(admissionResultDim == 2); // Se realizó la admisión en dos salas: 2 y 3
    // Resultado de la admisión en la sala 2
    assert(strcmp(admissionResultVec[0], "Charlie") == 0);
    // Resultado de la admisión en la sala 3
    assert(strcmp(admissionResultVec[1], "Alice") == 0);
    free(admissionResultVec);
    toBeginByRoom(conferenceCenter, 3);
    toBeginByRoom(conferenceCenter, 2);
    assert(strcmp(nextByRoom(conferenceCenter, 3), "Bob") == 0);
    assert(strcmp(nextByRoom(conferenceCenter, 2), "David") == 0);
    // Admitir hasta 2 personas por sala
    admissionResultVec = admitRoomsN(conferenceCenter, &admissionResultDim, 2);
    assert(admissionResultDim == 3); // Se hizo admisión de 3 personas
    // Resultado de la admisión en la sala 2
    assert(strcmp(admissionResultVec[0], "David") == 0);
    // Resultado de la admisión en la sala 3 (dos personas llamadas Bob)
    assert(strcmp(admissionResultVec[1], "Bob") == 0);
    assert(strcmp(admissionResultVec[2], "Bob") == 0);
    free(admissionResultVec);
    toBeginByRoom(conferenceCenter, 3);
    toBeginByRoom(conferenceCenter, 2);
    assert(hasNextByRoom(conferenceCenter, 3) == 0);
    assert(hasNextByRoom(conferenceCenter, 2) == 0);
    admissionResultVec = admitRooms(conferenceCenter, &admissionResultDim);
    assert(admissionResultDim == 0);
    assert(admissionResultVec == NULL);
    freeRooms(conferenceCenter);
    puts("OK!");
    return 0;
}
