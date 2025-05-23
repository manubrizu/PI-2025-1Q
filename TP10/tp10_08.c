#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./utillist.h"

List listUnion (const List l1, const List l2);


int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  List l1 = fromArray(v, 6);
  List l2 = fromArray(w, 9);
  List l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);
  
  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);


  printf ("OK!\n");
  return 0;
}

List listUnion (const List l1, const List l2){
    if(isEmpty(l1) && isEmpty(l2)){
        return NULL;
    }
    
    List aux = malloc(sizeof(node)); // en cada iteracion voy a agregar algo.
      
    if(!isEmpty(l2) && (isEmpty(l1) || l1->head > l2->head)){ // tengo que chequear que l2 no este vacia, ya que podria estar acciendo a NULL
        aux->head = l2->head;
        aux->tail = listUnion(l1, l2->tail);
    }
    else if(isEmpty(l2) || l1->head < l2->head){ // aca ya me asegure que l1 no es vacia en el if de arriba, no hace falta la otra condicion
        aux->head = l1->head;
        aux->tail = listUnion(l1->tail, l2);
    }
    else{  // el unico caso que queda es en el que los elementos son iguales
        aux->head = l1->head;
        aux->tail = listUnion(l1->tail, l2->tail);
    }    
    return aux;
}