#include <stdio.h>
#include <stdlib.h>
#include "complexADT.h"

typedef struct complexCDT{
    int real;
    int complex;
} complexCDT;

complexADT newComplex(int real, int complex) {
    complexADT z = malloc(sizeof(complexCDT));
    z->real = real;
    z->complex = complex;
    return z;
}

int real(complexADT z){
    return z->real;
}

int imaginario(complexADT z){
    return z->complex;
}       

complexADT suma(complexADT z, complexADT w){
    complexADT aux = malloc(sizeof(complexCDT));
    aux->real = z->real + w->real;
    aux->complex = z->complex + w->complex;
    return aux;
}
