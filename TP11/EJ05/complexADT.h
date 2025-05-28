#include <stdio.h>
#include <stdlib.h>

typedef struct complexCDT * complexADT;

complexADT newComplex(int real, int complex);

int real(complexADT z);

int imaginario(complexADT z);

complexADT suma(complexADT z, complexADT w);