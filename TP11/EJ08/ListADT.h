#include <stdio.h>
#include <stdlib.h>

typedef struct listCDT * listADT;
typedef const char * elemType;

// Retorna negativo, 0 o positivo
typedef int (* compare) (elemType, elemType);

listADT newList(compare cmp);

void freeList(listADT l);

int addElement(listADT l, elemType elem);

int delete(listADT l, elemType elem);

int isEmpty(const listADT l);

int belongs(const listADT l, elemType elem);

int size(const listADT l); // NO HACE FALTA LO HACE MENOS INEFICIENTE SE PUEDE AGREGAR DIRECTAMENTE EN EL ISTCDT

elemType get(listADT l, int i);

elemType * toArray(listADT l);

void toBegin(listADT l);

int hasNext(listADT l);

elemType next(listADT l);
