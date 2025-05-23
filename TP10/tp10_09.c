#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./utillist.h"

typedef struct nodeBrief * TListBrief;

typedef struct nodeBrief {
    int elem;
    size_t count;
    struct nodeBrief * tail;
} TNodeBrief;

TListBrief comprimeList(const List l);

// Auxiliar para que pase el test con sanitizer
void freeListBrief(TListBrief lb) {
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main(void) {

  int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
  List list = fromArray(v, sizeof(v)/sizeof(v[0]));
  TListBrief bf = comprimeList(list);

  TListBrief aux = bf;
  assert(aux->elem ==1 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==2 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==3 && aux->count == 5);

  aux = aux->tail;
  assert(aux->elem ==10 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==100 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==998 && aux->count == 1);

  aux = aux->tail;
  assert(aux == NULL);

  freeList(list);
  freeListBrief(bf);
  
  printf ("OK!\n");
  return 0;
}

TListBrief comprimeList(const List l){
    if (isEmpty(l)){
        return NULL;
    }    

    TListBrief aux = malloc(sizeof(TNodeBrief));
    aux->elem = l->head;

    if (l->tail == NULL ||  l->head != (l->tail)->head){
        aux->count = 1;
        aux->tail = comprimeList(l->tail);
    }
    else{
        TListBrief aux2 = comprimeList(l->tail);
        aux->count = 1 + aux2->count;
        aux->tail = aux2->tail;
        free(aux2);
    }

    return aux;

}  