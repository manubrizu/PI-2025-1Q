#include <stdio.h>
#include <stdlib.h>
#include "./stackdADT.h"

typedef struct stackCDT{
    struct node * first;
    int size;
} stackCDT;

typedef struct node{ 
    int head;
    struct node * tail;
} node;

typedef node * List;

stackADT newStack(){
    return calloc(1, sizeof(stackCDT));
}

int isEmpy(const stackADT stack){
    return stack->first == NULL;
}

void push(stackADT stack, int elem){
    List aux = malloc(sizeof(node));
    
}