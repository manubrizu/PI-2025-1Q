#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./utillist.h"

List restaList(List lista1, List lista2);

#define ELEMS 200

int main(void) {

  int pares[ELEMS], impares[ELEMS];

  for(int i=1; i <= ELEMS; i++) {
    pares[i-1] = i * 2 ;
    impares[i-1] = i * 2 - 1;
  }

  List lPar = fromArray(pares, ELEMS);
  List lImpar = fromArray(impares, ELEMS);

  List lPar2 = restaList(lPar, lImpar);
  assert(checkElems(lPar2, pares, ELEMS));
  // Verificamos ademas que no sean los mismos nodos
  assert(lPar2 != lPar);
  assert(lPar2->tail != lPar->tail);
  freeList(lPar2);
  freeList(lPar);
  freeList(lImpar);

  int all[ELEMS * 2];
  for(int i=1, j=0; i <= ELEMS; i++) {
    all[j++] = i * 2 - 1;
    all[j++] = i * 2 ;
  }
  List lAll = fromArray(all, ELEMS * 2);
  lPar = fromArray(pares, ELEMS);
  List lImpar2 = restaList(lAll, lPar);
  assert(checkElems(lImpar2, impares, ELEMS));
  freeList(lPar);

  lPar = restaList(lAll, lImpar2);
  assert(checkElems(lPar, pares, ELEMS));
  freeList(lPar);
  freeList(lAll);
  
  lPar = NULL;
  lImpar = fromArray(impares, ELEMS);
  List aux = restaList(lPar, lImpar);
  assert(aux == NULL);
  freeList(lImpar);

  aux = restaList(lImpar2, lImpar2);
  assert(aux == NULL);
  freeList(lImpar2);

  int v[] = { 3, 5};
  int v2[] = { 5, 7, 8};
  int res[] = { 3};
  List l1 = fromArray(v, 2);
  List l2 = fromArray(v2, 3);
  List l3 = restaList(l1, l2);
  assert(checkElems(l3, res, 1));
  freeList(l3);
  
  int v3[] = { 7, 8};
  l3 = restaList(l2, l1);
  assert(checkElems(l3, v3, 2));
  freeList(l3);

  freeList(l1);
  freeList(l2);
  
    
  printf ("OK!\n");
  return 0;
}

List restaList(List l1, List l2){
    if (isEmpty(l1)) {
        return l1; // NULL
    }
    
    if (isEmpty(l2) || l1->head < l2->head){
        List aux = malloc(sizeof(node));
        aux->head = l1->head;
        aux->tail = restaList(l1->tail, l2);    // sigo en l1
        return aux;
    }

    if(l1->head > l2->head){
        return restaList(l1, l2->tail);     // sigo en l2
    }

    // caso en que sean iguales 

    return restaList(l1->tail, l2->tail); 
}