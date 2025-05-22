#include <stdio.h>
#include "./utillist.h"

void order(List l);

int main(){

}

void order(List l){
    if (isEmpty(l))
        return;

    if(l->head >= (l->tail)->head){
        List aux = l->tail;
        l->tail = aux->tail;
        free(aux);
        order(l);
    }
    else{
        order(l->tail);  
    }  
}