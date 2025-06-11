#include <stdio.h>
#include <stdlib.h>
#include "./stackdADT.h"

typedef struct node{ 
    int head;
    struct node * tail;
} node;

typedef node * List;

typedef struct stackCDT{
    struct node * first;
    int size;
} stackCDT;

stackADT newStack(){
    return calloc(1, sizeof(stackCDT));
}

int isEmpy(const stackADT stack){
    return stack->first == NULL;
}

void push(stackADT stack, int elem){
    List aux = malloc(sizeof(node));
    aux->tail = stack->first;
    aux->head = elem;
    stack->first = aux;
    stack->size++;
}

int pop(stackADT stack){
    if(isEmpy(stack)){
        exit(1);
    }
    List aux = stack->first;
    stack->first = aux->tail;
    int foo = aux->head;
    free(aux);
    stack->size--;
    return foo;
}

void freeStack(stackADT stack){
    freeNodes(stack->first);
    free(stack);
}

void freeNodes(List list) {
    if (list == NULL)
       return;
    freeList(list->tail);
    free(list);
}