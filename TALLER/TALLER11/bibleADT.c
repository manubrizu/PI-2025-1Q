#include <stdio.h>
#include <stdlib.h>
#include "bibleADT.h"

#define LIBROS 76

typedef char * tverse;

typedef struct tbook{
    tverse * verses;
    size_t dim;
} tbook;

typedef struct bibleCDT{
    tbook bible[LIBROS];
} bibleCDT;


bibleADT newBible(){
    return calloc(1, sizeof(bibleCDT));
}

static char * copyStr(const char * s){
    if(s == NULL){
        return NULL;
    }

    char * copy = calloc(strlen(s) + 1, sizeof(char));
    return copy;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if(bookNbr < 1 || bookNbr > LIBROS || verseNbr < 1){
        return 0;
    }   

    tbook * book = &bible->bible[bookNbr - 1];
    if(verseNbr > book->dim){
        book->verses = realloc(book->verses, (verseNbr + 1) *sizeof (tverse));
        for (int i = book->dim; i < verseNbr; i++){
            book->verses[i] = NULL;
        }
        book->dim = verseNbr;
    }

    if(book->verses[verseNbr - 1] != NULL){
        return 0;
    }

    book->verses[verseNbr -1] = copyStr(verse);
    return 1;
}

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if(bookNbr < 1 || bookNbr > LIBROS || verseNbr < 1){
        return NULL;
    }

    tbook * book = &bible->bible[verseNbr - 1];
    if(verseNbr > book->dim){
        return NULL;
    }
    return copyStr(book->verses[verseNbr - 1]);
}

void freeBible(bibleADT b){
    for (int i = 0; i < LIBROS; i++){
        tbook * book = &b->bible[i];
        for (int j = 0; i < b->bible->dim; i++){
            free(book->verses[j]);
        }
        free(book);
    }
    free(b);
    
}




