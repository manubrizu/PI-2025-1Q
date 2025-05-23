#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25
#define BLOQUE 10
#define CANT 4

int getline(char s[], unsigned int maxLen);
char* getLine2();

int main(){
    /*
    char * palos[4];

    palos[0] = malloc(5);
    strcpy(palos[0], "Copa");

    palos[1] = malloc(6);
    strcpy(palos[1], "Basto");

    palos[2] = malloc(4);
    strcpy(palos[2], "Oro");

    palos[3] = malloc(7);
    strcpy(palos[3], "Espada");
    
    for (int i = 0; i < 4; i++){
        puts(palos[i]);
    }

    printf("\n");

    palos[0] = realloc(palos[0], 8);
    strcpy(palos[0], "Copitas");

    for (int i = 0; i < 4; i++){
        puts(palos[i]);
    }
    
    for (int i = 0; i < 4; i++){
        free(palos[i]);
    }    
    */

    char ** palos;                              // UN PUNTERO A UN PUNTERO DE CHARS
    palos = malloc(CANT * sizeof(char *));      // EL SIZEOF YA NO ES 1
    // char aux[MAX + 1];

    for (int i = 0; i <CANT; i++){
        /* con getline
        *   size_t len = getline(aux, MAX);
        *   palos[i] = malloc(len + 1);
        *   strcpy(palos[i], aux);
        */

        // con getLine2
        palos[i] = getLine2();        
    }

    for (int i = 0; i < CANT; i++){
        puts(palos[i]);
    }

    for (int i = 0; i < CANT; i++){
        free(palos[i]);
    }

    free(palos);
    
    return 0;
}



int getline(char s[], unsigned int maxLen){
    int i = 0, j= 0, c;
    while ((c = getchar()) != '\n' && c != EOF){
        if (i < maxLen){        // si ingresa mas del maximo, los ignora
            s[j++] = c;
        }
        i++;        
    }
    s[j] = '\0';
    return j;
}

char* getLine2(){
    int c, i = 0;
    char * s = NULL;
    while ((c = getchar()) != '\n' && c != EOF){
        if (i % BLOQUE == 0){
            s = realloc(s, i + BLOQUE);
        }
        s[i] = c;      
        i++; 
    }
    s = realloc(s, i+1);
    s[i] = '\0';
    return s;
    
}