#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus headentos, en el mismo orden
*/
List fromArray(const int v[], unsigned int dim ) {
  List ans = NULL;
  while (dim) {
     List aux = malloc(sizeof(node));
     aux->head = v[--dim];
     aux->tail = ans;
     ans = aux;
  }
  return ans;
}

/*
** Funcion auxiliar para verificar los headentos de una lista
** Retorna 1 si la lista y el vector contienen los mismos headentos en el mismo orden
*/
int checkElems(const List list, const int v[], int dim) {
  int i;
  List aux;
  for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
    if ( aux->head != v[i])
       return 0;
  }
  return aux == NULL && i==dim;
}

void freeList(List list) {
    if ( list == NULL)
       return;
    freeList(list->tail);
    free(list);
}

int isEmpty(const List l){
  return l == NULL;
}

List add(List l, int elem){
    if(isEmpty(l) || elem < l->head){
      node * aux = malloc(sizeof(node));
      aux->head = elem;
      aux->tail = l;
      return aux;
    }
    if(elem == l->head){
      return l;
    }

    l->tail = add(l->tail, elem);
    return l;
}

List delete (List l, int elem){
  if(isEmpty(l) || elem < l->head){
    return l;
  }
  if(l->head == elem){
    node * aux = l->tail;
    free(l->tail);
    return l;
  }
  l->tail = delete(l->tail, elem);
  return l;
}

int get(List l, int index){
  if(isEmpty(l)){
    exit(1);
  }
  if(index == 0){
    return l->head;
  }
  return get(l->tail, index - 1);
}