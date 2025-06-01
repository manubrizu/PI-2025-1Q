#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"
#include "setADT.h"

typedef struct setCDT {
    listADT list;
    compare cmp;
} setCDT;

setADT newSet(compare cmp) {
    setADT aux = calloc(1, sizeof(struct setCDT));
    aux->cmp = cmp;
    aux->list = newList(cmp);
    return aux;
}

void freeSet(setADT set) {
    freeList(set->list);
    free(set);
}

int isEmptySet(setADT set) {
    return isEmpty(set->list);
}

int sizeSet(const setADT set) {
    return size(set->list);
}

int setContains(const setADT set, elemType element) {
    return belongs(set->list, element);
}

int addElementSet(setADT set, elemType element) {
    return addElement(set->list, element);
}

int deleteElementSet(setADT set, elemType element) {
    return deleteElement(set->list, element);
}

static listADT unionList(const listADT list1, const listADT list2, compare cmp) {
    listADT aux = newList(cmp);

    toBegin(list1);
    while(hasNext(list1)) {
        addElement(aux, next(list1));
    }

    toBegin(list2);
    while(hasNext(list2)) {
        addElement(aux, next(list2));
    }

    return aux;
}

setADT unionSet(setADT set1, setADT set2) {
    setADT resp = newSet(set1->cmp);
    freeList(resp->list);
    resp->list = unionList(set1->list, set2->list, set1->cmp);
    return resp;
}

static listADT intersectionList(const listADT list1, const listADT list2, compare cmp) {
    listADT aux = newList(cmp);

    toBegin(list1);
    toBegin(list2);

    // Si alguno de los conjuntos esta vacio, no hay interseccion
    int hasNext1 = hasNext(list1);
    int hasNext2 = hasNext(list2);

    if (!hasNext1 || !hasNext2) {
        return aux;
    }
    elemType elem1 = next(list1);
    elemType elem2 = next(list2);

    // Recorro ambas listas hasta que alguna no tenga proximo elemento
    while (hasNext1 && hasNext2) {
        int res = cmp(elem1, elem2);

        if (res == 0) {
            // Son iguales -> pertenece a la interseccion
            addElement(aux, elem1); // Podría ser elem2 tambien

            // Avanzo en ambas listas
            hasNext1 = hasNext(list1);
            hasNext2 = hasNext(list2);

            if (hasNext1) {
                elem1 = next(list1);
            }
            if (hasNext2) {
                elem2 = next(list2);
            }
        }
        else if (res < 0) {
            // elem1 < elem2 -> avanzar solo en list1
            hasNext1 = hasNext(list1);
            if (hasNext1) {
                elem1 = next(list1);
            }
        }
        else {
            // elem1 > elem2 -> avanzar solo en list2
            hasNext2 = hasNext(list2);
            if (hasNext2) {
                elem2 = next(list2);
            }
        }
    }

    return aux;
}


setADT intersectionSet(setADT set1, setADT set2) {
    setADT resp = newSet(set1->cmp);
    freeList(resp->list);
    resp->list = intersectionList(set1->list, set2->list, set1->cmp);
    return resp;
}

static listADT diffList(const listADT list1, const listADT list2, compare cmp) {
    listADT aux = newList(cmp);

    toBegin(list1);

    while (hasNext(list1)) {
        elemType elem = next(list1);
        // Si list2 no contiene el elemento, lo agrego
        if (!belongs(list2, elem)) {
            addElement(aux, elem);
        }
    }

    return aux;
}

setADT diffSet(setADT set1, setADT set2) {
    setADT resp = newSet(set1->cmp);
    freeList(resp->list);
    resp->list = diffList(set1->list, set2->list, set1->cmp);
    return resp;
}