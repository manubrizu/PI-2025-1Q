#include <stdio.h>
#include <stdlib.h>


typedef struct queueCDT * queueADT;

typedef int * elemtype;


queueADT newQueue();

void queue(queueADT q, elemtype n);

void dequeue(queueADT q, elemtype * out);

void freeQueue(queueADT q);

int isEmpty(queueADT q);

void toBegin(queueADT q);

int hasNext(queueADT q);

elemtype next(queueADT q);

