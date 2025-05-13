#include <stdio.h>
#include <stdlib.h>

char * copiarPrefijo(char * s, int n);

int main(){
    char * s = "Hola";
    int n = 2;

    char * prefijo = copiarPrefijo(s, n);
    puts(prefijo);

    free(prefijo);
    return 0;
}

char * copiarPrefijo(char * s, int n){
    char * resp = malloc(n + 1);
    int i;
    for (i = 0; i < n && s[i] != 0; i++){
        resp[i] = s[i];
    }

    resp[i] = '\0'; 

    return resp;    
}