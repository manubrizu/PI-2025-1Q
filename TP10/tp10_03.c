#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./utillist.h"

void order(List l);

int main(void) {
  int v[] = {1,1,2,1,0,-1,3,3,3,3,3,10,9,100,100,998};
  int dimV = sizeof(v)/sizeof(v[0]);
  List list = fromArray(v, dimV);
  
  order(list);
  int o[] = {1,2,3,10,100,998};
  assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);

  order(list);
  assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);
  freeList(list);
 
  List empty = NULL;
  order(empty);
  assert(empty ==NULL);

  list = fromArray(v,1);
  order(list);
  assert(list->head ==1 && list->tail == NULL);
  freeList(list);

  int w[] = {1,1,1,1,1,1,1,1,1,1};
  list = fromArray(w, sizeof(w)/sizeof(w[0]));
  order(list);
  assert(list->head ==1 && list->tail == NULL);
  freeList(list);

  printf ("OK!\n");
  return 0;
}

// void
void order(List l){
    if (l != NULL && l->tail != NULL){
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
}

// List
/*
10 -> 8 -> 9 -> 12 -> 15 -> 13		// el 10 no cambiaba (puede ser void)
      X    X                X
List remove(List l){
    if(l == NULL || l->tail == NULL){
	return l;
    }

    
    if(l->head >= l->tail->head){
	List aux = l->tail;
	l->tail = aux->tail;
	free(aux);	
	return remove(l);
    }
 
    l->tail = remove(l->tail);
    return l;
}
*/