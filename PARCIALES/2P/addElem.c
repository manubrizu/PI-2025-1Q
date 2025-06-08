#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct node {
    char head;
    int hits;
    struct node * tail;
} node;

typedef node * List;

List addElem(List l, char elem){
    if(l == NULL){      // el elemento no estaba
        List aux = calloc(1, sizeof(node));
        aux->head = elem;
        aux->hits = 0;
        aux->tail = NULL;
        return aux;
    }

    if(l->head == elem){       // el elemento en el que estoy parado es igual
        l->hits++;
        return l;
    }

    // sigo recorriendo
    l->tail = addElem(l->tail, elem);

    // ahora me fijo si el agregue en la cola tiene mas hit, sino lo cambio

    if(l->hits < l->tail->hits){
        List aux = l->tail;
        l->tail = aux->tail;
        aux->tail = l;
        return aux;
    }

    return l;
}

void freeRec(List l){
    if(l != NULL){
        freeRec(l->tail);
        free(l);
    }
}

int main(void) {
    List l = NULL;
    l = addElem(l, 'X');
    l = addElem(l, 'X');
    l = addElem(l, 'Z');
    // (X,1) -> (Z,0)
    assert(l->head == 'X'); 
    assert(l->tail->head == 'Z');
    l = addElem(l, 'A');
    // (X,1) -> (Z,0) -> (A,0) o bien (X,1) -> (A,0) -> (Z,0)
    assert(l->head == 'X');
    assert((l->tail->head == 'Z' && l->tail->tail->head == 'A')
    || (l->tail->head == 'A' && l->tail->tail->head == 'Z'));
    l = addElem(l, 'A');
    l = addElem(l, 'A');
    assert(l->head == 'A');
    assert(l->tail->head == 'X');
    assert(l->tail->tail->head == 'Z');
    assert(l->tail->tail->tail == NULL);
    // Se liberan todos los nodos de la lista

    freeRec(l);

    puts( "OK!");
    return 0;
}
