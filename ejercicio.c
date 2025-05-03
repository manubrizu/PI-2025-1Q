#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

int getline(char s[], unsigned int maxLen);

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

    char * palos[4];
    char aux[MAX + 1];



    return 0;
}



int getline(char s[], unsigned int maxLen){
    int i = 0, c;

    while ((c = getchar()) != '\n' && c != EOF){
        if (i < maxLen){        // si ingresa mas del maximo, los ignora
            s[j++] = c;
        }
        i++;        
    }

    s[j] = 0;
    return j;
}