#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./utillist.h"

List listIntersec (const List list1, const List list2);

int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  List l1 = fromArray(v, 6);
  List l2 = fromArray(w, 9);
  List l3 = listIntersec(l1, l2);
  assert(checkElems(l3, v, 6));
  assert(checkElems(l1, v, 6));
  assert(checkElems(l2, w, 9));
  freeList(l3);

  l3 = listIntersec(l2, l1);
  assert(checkElems(l3, v, 6));
  freeList(l3);

  l3 = listIntersec(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listIntersec(l2, NULL);
  assert(l3==NULL);
  l3 = listIntersec(NULL, l1);
  assert(l3==NULL);
  l3 = listIntersec(NULL, NULL);
  assert(l3==NULL);
  freeList(l1);
  freeList(l2);

  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listIntersec(l1, l2);
  assert(l3 == NULL);
  freeList(l3);
  freeList(l1);
  freeList(l2);

  printf ("OK!\n");
  return 0;
}

List listIntersec (const List l1, const List l2){
    if(isEmpty(l1) || isEmpty(l2)){
        return NULL;
    }

    if(l1->head < l2->head){
        return listIntersec(l1->tail, l2);
    }

    if(l1->head > l2->head){
        return listIntersec(l1, l2->tail);
    }

    List aux = malloc(sizeof(node));
    aux->head = l1->head;
    aux->tail = listIntersec(l1->tail, l2->tail);
    return aux;
}