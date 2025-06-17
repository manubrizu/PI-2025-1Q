#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char head;
    struct node * tail;
};

typedef struct node * TList;

int countGroups(TList l, char caracter){
    if(l == NULL || l->tail == NULL){
        return 0;
    }

    if(l->head == caracter && l->head != l->tail->head){
        return 1 + countGroups(l->tail, caracter);
    }

    return countGroups(l->tail, caracter);
}


int contarGrupos(char * cadena, char caracter){
    if(*cadena == '\0'){
        return 0;
    }

    if(*cadena == caracter && *(cadena + 1) != caracter){
        return 1 + contarGrupos(cadena + 1, caracter);
    }
    
    return contarGrupos(cadena + 1, caracter);
}



