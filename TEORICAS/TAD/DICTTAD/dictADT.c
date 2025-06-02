#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictADT.h"

#define LETRAS 'z' - 'a' + 1
#define BLOCK 10

typedef struct node{
    struct node * next;
    char * word;
    char * deff;
    size_t lenW;
    size_t lenD;
} node;

typedef struct node * List;

typedef struct words {
    struct node * first;
    size_t deffCount;
} words;


typedef struct dictCDT{
    words letters[LETRAS];
    size_t wordsCount;
} dictCDT;

dictADT newDict(void){
    return calloc(1, sizeof(dictCDT));
}

// SOLO PARA STRINGS CORTOS, RECORRE DOS VECES
static char * copyWord(const char * s, int * len){
    * len = strlen(s) + 1;
    return strcpy(malloc(* len), s);
}

// DEVUELVE UNA COPIA DE UN STRING. EVITAMOS RECORRERLO DOS VECES
// POR LO QUE IREMOS COPIANDO DE A BLOQUES
static char * copyDeff(const char * s, int * len){
    int i = 0;
    char * aux = NULL;
    while (s[i] != '\0'){
        if(i % BLOCK == 0){
            aux = realloc(aux, i + BLOCK);
        }
        aux[i] = s[i++];
    }

    aux[i++] = '\0';
    *len = i;
    aux = realloc(aux, *len);
    return aux;
}

static List addWordRec(List l, const char * word, const char * deff, int * flag){
    int c = strcmp(l->word, word);
    if(l == NULL || c < 0){
        List aux = malloc(sizeof(node));
        int lenW, lenD;
        aux->word =  copyWord(word, &lenW);
        aux->lenW = lenW;
        aux->deff = copyDeff(deff, &lenD);
        flag = 1;
        aux->next = l;
        return aux;
    }   
    
    if(c < 0){
        l->next = addWordRec(l->next, word, deff, flag);
    }
    
    return l;
}

void addDefinition(dictADT dict, const char * word, const char * deff){
    int idx = word - 'a';
    int flag = 0; // para ver si la agrego o no
    dict->letters[idx].first = addWordRec(dict->letters[idx].first, word, deff, &flag);
    if(flag){
        dict->wordsCount++;
        dict->letters[idx].deffCount++;
    }
}


char * getDeffRec(List l , const char * word){
    int c;
    if(l == NULL || (c = strcmp(l->word, word)) < 0){
        return NULL;
    }

    if(c == 0){
        char * aux = malloc(l->lenD);
        strcpy(aux, l->deff);
        return aux;
    }

    return getDeffRec(l->next, word);    
}

char * getDeff(const dictADT dict, const char * word){
    int idx = word - 'a';
    return getDeffRec(dict->letters[idx].first, word);
}

