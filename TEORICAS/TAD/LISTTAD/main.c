#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ListADT.h"

int main(){
    
    listADT l = newList(strcmp);

    assert(isEmpty(l));
    assert(addElement(l, "hola") == 1);
    assert(size(l) == 1);
    assert(addElement(l, "hola") == 0);
    assert(size(l) == 1);

    char s[] = "hola";
    
}