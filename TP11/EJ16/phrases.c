#include <stdio.h>
#include <stdlib.h>
#include "phrases.h"

#define BLOCK 10

typedef char * phrase;

typedef struct phrasesCDT{
    phrase * vec;
    size_t dim;
} phrasesCDT;


phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    size_t dim = keyTo - keyFrom + 1;
    phrasesADT aux = calloc(1, dim * sizeof(phrasesCDT));
    aux->dim = dim;
    return aux;
}

void freePhrases(phrasesADT ph){
    free(ph->vec);
    free(ph);
}

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

int put(phrasesADT ph, size_t key, const char * phrase){

}