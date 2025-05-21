#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./stackdADT.h"

int main(){
    stackADT s = newStack();
    push(s, 10);
    push(s, 20);
    assert(size(s) == 2);
    assert(pop(s) == 20);
    push(s, 30);
    push(s, 40);
    pop(s);
    assert(pop(s) == 30);
    freeStack(s);
}