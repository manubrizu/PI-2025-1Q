#include <stdio.h>

typedef struct roomsCDT * roomsADT;

/* Crea un sistema de administración de salas a partir de la cantidad máxima
* #maxRooms de salas que tendrá el centro de conferencias.
* Se asume que la gran mayoría de las salas serán utilizadas por los asistentes.
* Si maxRooms es cero retorna NULL.
*/
roomsADT newRooms(size_t maxRooms);

/* Reserva al asistente #attendee en la espera de la sala #roomNumber
* para luego poder asistir a la conferencia.
* Un mismo asistente puede reservar múltiples veces la misma sala o varias
* salas distintas.
* Se asume que los nombres de los asistentes son cortos.
* No hace nada si #roomNumber es mayor o igual a la cantidad máxima de salas.
*/
void reserveRoom(roomsADT rooms, size_t roomNumber, const char * attendee);

/* Funciones de iteración para poder consultar para una sala los asistentes que están
* esperando, en ORDEN DE RESERVA (ver ejemplo en programa de prueba)
*/
void toBeginByRoom(roomsADT rooms, size_t roomNumber);
size_t hasNextByRoom(const roomsADT rooms, size_t roomNumber);
const char * nextByRoom(roomsADT rooms, size_t roomNumber);

/* Para cada sala, realiza la admisión del asistente que está esperando primero,
* si es que hay al menos un asistente esperando en esa sala.
* Retorna un arreglo con los nombres de los asistentes que hicieron la admisión
* y salieron de la espera
* respetando el ORDEN ASCENDENTE por número de sala
* Deja en un parámetro de entrada/salida la dimensión del vector de retorno
* Si no hay asistentes retorna NULL
*/
char ** admitRooms(roomsADT rooms, size_t * admissionResultDim);

/* Para cada sala, realiza la admisión de #n asistentes que están esperando primero,
* si es que hay al menos un asistente esperando en esa sala. Si en una sala hay menos
* de #n que están esperando, entran todos
* Retorna un arreglo con los nombres de los asistentes que hicieron la admisión
* y salieron de la espera
* respetando el ORDEN ASCENDENTE por número de sala
* Deja en un parámetro de entrada/salida la dimensión del vector de retorno
* Si no hay asistentes o n es cero retorna NULL
*/
char ** admitRoomsN(roomsADT rooms, size_t * admissionResultDim, size_t n);

/* Libera los recursos utilizados por el TAD
*/
void freeRooms(roomsADT rooms);
