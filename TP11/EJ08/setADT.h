#include <stdio.h>
#include <stdlib.h>

typedef struct setCDT * setADT;
typedef const char * elemType;

typedef int (* compare) (elemType, elemType);

setADT newSet(compare cmp);

void freeSet(setADT set);

int isEmptySet(setADT set);

int setContains(const setADT set, elemType element);

int addElementSet(setADT set, elemType element);

int deleteElementSet(setADT set, elemType element);

int sizeSet(const setADT set);

setADT unionSet(setADT set1, setADT set2);

setADT intersectionSet(setADT set1, setADT set2);

setADT diffSet(setADT set1, setADT set2);