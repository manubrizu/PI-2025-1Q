#include <stdio.h>
#include "./utillist.h"

List depuraLista(List l, int (*f) (int));

int main(){

}

List depuraLista(List l, int (*f) (int)){
    if(isEmpty(l)){
        return l;
    }

    if(f(l->head)){
        List aux = l->tail;
        free(l);
        return depuraLista(aux, f);
    }

    l->tail = depuraLista(l->tail, f);
    return l;
}