#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../getnum.h"
#include "./../random.h"

#define X 5
#define DIGITOS 10

int* generarAleatorio(){
    int* incognita = malloc(X * sizeof(int));
    for (int i = 0; i < X; i++){
        incognita[i] = randInt(0, 9);
    }    
    return incognita;
}

int elegirNivel(){
    int nivel;
    do{
        nivel = getint("Ingrese un nivel: ");
    } while (nivel < 1 || nivel > 10);
    
    return nivel;
}

int * leerNumero(){
    char num[100];
    int apar[DIGITOS] = {0};
    int vale = 0;

    while (!vale){
        printf("Ingrese un numero de %d digitos: ", X);
        scanf("%s", num);

        int len = strlen(num);
        if (len == X){
            vale = 1;
            for (int i = 0; i < len && vale; i++){
                int digito = num[i] - '0';
                if (!apar[digito]){
                    apar[digito] = 1;
                }
                else{
                    vale = 0;
                    for (int i = 0; i < DIGITOS; i++){
                        apar[i] = 0;
                    }                    
                }                
            }
        } 
    }

    int* resp = malloc(X * sizeof(int));
    for (int i = 0; i < X; i++){
        resp[i] = num[i] - '0';
    }
    

    return resp;    
}

int main(){
    randomize();

    int* vec = generarAleatorio();

    free(vec);

    int* num = leerNumero();

    for (int i = 0; i < X; i++){
        printf("%d", num[i]);
    }

    printf("\n");
    
    

    free(num);

    return 0;
}