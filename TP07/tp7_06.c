#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../getnum.h"
#include "./../random.h"

#define X 5
#define DIGITOS 10

int* generarAleatorio();
int elegirNivel();
int * leerNumero();
int coincideNumero(int n1[], int n2[]);
int cantidadBien(int n1[], int n2[]);
int cantidadRegular(int n1[], int n2[]);

int main(){
    randomize();
    int intentosMax = elegirNivel(), intentos = 0, gano = 0;
    int* incognita = generarAleatorio();
    for (int i = 0; i < X; i++){
        printf("%d", incognita[i]);
    }

    printf("\n");
    
    int* num;

    while (intentos++ < intentosMax && !gano){
        num = leerNumero();
        if(coincideNumero(num, incognita)){
            printf("CORRECTO.\n");
            gano = 1;
        }
        free(num);
    } 

    if(!gano){
        printf("PERDISTE.\n");
    }

    free(incognita);
    return 0;
}

int* generarAleatorio(){
    int* incognita = malloc(X * sizeof(int));
    int apariciones[DIGITOS] = {0};
    for (int i = 0; i < X;){
        int random = randInt(0, 9);
        if(!apariciones[random]){
            incognita[i] = random;
            apariciones[random] = 1;
            i++;
        }
    }    
    return incognita;
}


int elegirNivel(){
    int nivel;
    do{
        nivel = getint("NIVEL: ");
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

int coincideNumero(int n1[], int n2[]){
    int cant_bien = cantidadBien(n1, n2);
    if(cant_bien == X){
        printf("%d bien\n", cant_bien);
        return 1;
    }    
    int cant_reg = cantidadRegular(n1, n2);
    printf("%d bien, %d regular\n", cant_bien, cant_reg);
    return 0;
}

int cantidadBien(int n1[], int n2[]){
    int cant = 0;
    for (int i = 0; i < X; i++){
        if(n1[i] == n2[i]){
            cant++;
        }
    }
    return cant;
}

int cantidadRegular(int n1[], int n2[]) {
    int cant = 0;
    for (int i = 0; i < X; i++) {
        if (n1[i] != n2[i]) {
            for (int j = 0; j < X; j++) {
                if (i != j && n1[i] == n2[j] && n1[j] != n2[j]) {
                    cant++;
                }
            }
        }
    }
    return cant;
}