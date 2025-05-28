#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ListADT.h"

int main(void) {
    listADT l = newList(strcmp);
    assert(isEmpty(l));
    assert(addElement(l, "Hola")==1);
    assert(size(l)==1);
    assert(addElement(l, "Hola")==0);
    assert(size(l)==1);
    char s[] = "Hola";
    assert(addElement(l, s)==0);
    assert(size(l)==1);
    assert(addElement(l, "Adios")==1);
    assert(addElement(l, "adios")==1);
    assert(addElement(l, "Botella")==1);
    assert(size(l)==4);

    assert(belongs(l, "Adios"));
    assert(!belongs(l, "Beautiful"));

    assert(delete(l, "futbol")==0);
    assert(delete(l, "adios")==1);
    assert(delete(l, "adios")==0);
    assert(size(l)==3);
    assert(delete(l, "Adios")==1);
    assert(delete(l, "Botella")==1);

    assert(addElement(l, "Noche magica")==1);
    assert(addElement(l, "Mis noches de enero")==1);
    assert(addElement(l, "Musica")==1);
    assert(addElement(l, "La melodia de Dios")==1);
    assert(addElement(l, "Loca")==1);
    assert(addElement(l, "Tus horas magicas")==1);
    assert(addElement(l, "Arruinarse")==1);
    assert(addElement(l, "Un poco perdido")==1);
    assert(addElement(l, "Hola mi vida")==1);
    assert(addElement(l, "Chica bionica")==1);

    // A desarrollar el dia miercoles 28/5

    // Funcion get, para obtener un elementos en base a su posicion
    int dim = size(l);
    for(int i=0; i < dim; i++) {
        puts(get(l, i));
    }
    puts("--------");

    // Obtener un vector con todos los elementos de la lista, ordenados
    const char ** elems = toArray(l);
    for(int i=0; i < dim; i++) {
        puts(elems[i]);
    }
    free(elems);
    puts("--------");

    freeList(l);
    puts("OK");
    return 0;
}