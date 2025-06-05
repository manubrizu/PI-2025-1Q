#include <stdio.h>
#include <stdlib.h>
#include "moveToFront.h"

typedef struct node {
    struct node * next;
    elemType elem;
} node;

typedef struct node * List;

typedef struct moveToFrontCDT{
    List first;
    List actual;
    size_t count;
    compare cmp;
} moveToFrontCDT;


/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío
** La función compare retorna 0 si los elementos son iguales, negativo si e1 es
** "menor" que e2 y positivo si e1 es "mayor" que e2
*/
moveToFrontADT newMoveToFront(compare cmp){
    moveToFrontADT aux = calloc(1, sizeof(moveToFrontCDT));
    aux->cmp = cmp;
    return aux;
}

void freeRec(List l){
    if(l != NULL){
        freeRec(l->next);
        free(l);
    }
}

void freeMoveToFront(moveToFrontADT m){
    freeRec(m->first);
    free(m);   
}

/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/

static List addRec(List l, elemType elem, compare cmp, int * flag){
    if(l == NULL){
        List aux = calloc(1, sizeof(node));
        aux->elem = elem;
        *flag = 1;
        return aux;
    }

    if(cmp(l->elem, elem) == 0){
        return l;
    }

    l->next = addRec(l->next, elem, cmp, flag);
    return l;
}

unsigned int add(moveToFrontADT moveToFront, elemType elem){
    int flag = 0;
    moveToFront->first = addRec(moveToFront->first, elem, moveToFront->cmp, &flag);
    if(flag){
        moveToFront->count++;
    }
    return flag;
}

/* Retorna la cantidad de elementos que hay en la colección */
unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->count;
}

/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront){
    moveToFront->actual = moveToFront->first;
}

/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront){
    return moveToFront->actual != NULL;
}

elemType next(moveToFrontADT moveToFront){
    if(moveToFront->actual == NULL){
        exit(1); // por gracioso
    }

    elemType aux = moveToFront->actual->elem;
    moveToFront->actual = moveToFront->actual->next;
    return aux;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare.
** Si el elemento estaba lo ubica al principio.
*/

static List getRec(List list, elemType elem, compare cmp, List * nodo){
    if (list == NULL){
        return NULL;
    }

    if (cmp(list->elem, elem) == 0){
        *nodo = list;
        return list->next;  // chau nodo
    }
    
    list->next = getRec(list->next, elem, cmp, nodo);
    return list;
} 

elemType * get(moveToFrontADT moveToFront, elemType elem){
    if(moveToFront->first == NULL){
        return NULL;
    }

    if(moveToFront->cmp(moveToFront->first->elem, elem) == 0){      // es el primer elemento
        elemType * aux = malloc(sizeof(elemType));
        * aux = moveToFront->first->elem;
        return aux; 
    }

    List nodo = NULL;
    moveToFront->first = getRec(moveToFront->first, elem, moveToFront->cmp, &nodo);
    
    if (nodo != NULL){
        nodo->next = moveToFront->first;
        moveToFront->first = nodo; 

        elemType * element = malloc(sizeof(elemType));
        *element = moveToFront->first->elem;
        return element;
    }

    return NULL;
}
