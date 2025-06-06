#include <stdio.h>
#include <stdlib.h>
#include "phrases.h"

#define BLOCK 10

typedef char * phrase;

typedef struct phrasesCDT{
    phrase * vec;
    size_t count;
    size_t dim;
    size_t firstKey;
} phrasesCDT;


phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    if (keyFrom > keyTo){
        return NULL;
    }
    size_t dim = keyTo - keyFrom + 1;
    phrasesADT aux = calloc(1, sizeof(phrasesCDT));
    aux->vec = calloc(dim, sizeof(phrase));
    aux->dim = dim;
    aux->firstKey = keyFrom;
    return aux;
}

void freePhrases(phrasesADT ph){
    for(size_t i = 0; i < ph->dim; i++) {
        free(ph->vec[i]);
    }
    free(ph->vec);
    free(ph);
}

static char * copyStr(const char * s){
    int i = 0;
    char * aux = NULL;
    while (s[i] != '\0'){
        if(i % BLOCK == 0){
            aux = realloc(aux, i + BLOCK);
        }
        aux[i] = s[i];
        i++;             
    }
    aux = realloc(aux, i + 1);
    aux[i] = '\0';
    return aux;
}

int put(phrasesADT ph, size_t key, const char * phrase){
    size_t idx = key - ph->firstKey;
    if(idx >= ph->dim){
        return 0;
    }

    if(ph->vec[idx] == NULL){
        ph->count++;
    }
    else{
        free((ph->vec)[idx]);
    }
    ph->vec[idx] = copyStr(phrase);
    return 1;
}

char * get(const phrasesADT ph, size_t key){
    if(key < ph->firstKey || key >= ph->firstKey + ph->dim || ph->vec[key - ph->firstKey] == NULL){
    return NULL;
    }

    return copyStr(ph->vec[key - ph->firstKey]);
}

size_t size(const phrasesADT ph){
    return ph->count;
}

static char * concatToFrom(const phrasesADT ph, size_t from, size_t to){
    if(ph->count == 0){
        return NULL;
    }

    char * aux = NULL;
    size_t k = 0;

    for (size_t i = from; i < to; i++){
        if (ph->vec[i] != NULL){
            for(int j = 0; ph->vec[i][j] != '\0'; j++){
                if (k % BLOCK == 0) {
                    aux = realloc(aux, k + BLOCK);
                }
                aux[k++] = ph->vec[i][j];
            }
        }
    }

    aux = realloc(aux, k + 1);
    aux[k] = '\0';
    return aux;
}

char * concatAll(const phrasesADT ph){
    size_t from = 0;
    char * aux = concatToFrom(ph, from, ph->dim);
    return aux;
}

char * concat(const phrasesADT ph, size_t from, size_t to){
    size_t idxFrom = from - ph->firstKey;
    size_t idxTo = to - ph->firstKey;

    if(idxFrom > idxTo || idxTo >= ph->dim){
        return NULL;
    }

    char * aux = concatToFrom(ph, idxFrom, idxTo);
    return aux;
}
