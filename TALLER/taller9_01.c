#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define NOTA 6

int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], int notas[]);
void freeTodo(char ** p, int tam);
static void mostrarNombres(char * arrNombres[], size_t n);

int
main(void) {
    char * arrNombres[] = {"anita","pepe","fabi","carlos","tere"};
    char * aprobados[5];
    int notas[] = {3,4,8,10,1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char*);
    mostrarNombres(arrNombres, tam);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
    printf("Aprobados:\n");
    mostrarNombres(aprobados, tamApro);
 
    // Test del ejemplo
    char * aprobados1[5];
    assert(obtenerAprobados(arrNombres, 0, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 1, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 2, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 3, aprobados1, notas) == 1);
    assert(strcmp(aprobados1[0], "fabi") == 0);
    char * aprobados2[5];
    assert(obtenerAprobados(arrNombres, 4, aprobados2, notas) == 2);
    assert(strcmp(aprobados2[0], "fabi") == 0);
    assert(strcmp(aprobados2[1], "carlos") == 0);
    char * aprobados3[5];
    assert(obtenerAprobados(arrNombres, 5, aprobados3, notas) == 2);
    assert(strcmp(aprobados3[0], "fabi") == 0);
    assert(strcmp(aprobados3[1], "carlos") == 0);
    
    freeTodo(aprobados, tamApro);
    freeTodo(aprobados1, tamApro);
    freeTodo(aprobados2, tamApro);
    freeTodo(aprobados3, tamApro);

    printf("\nOK!\n");
    return 0;
}


int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], int notas[]){
    int cont = 0, dim;
    for (int i = 0; i < tam; i++){
        if(notas[i] >= NOTA){
            dim = strlen(arrNombres[i]) + 1;
            aprobados[cont] = malloc(dim * sizeof(char));
            strcpy(aprobados[cont], arrNombres[i]);
            cont++;
        }
    }
    return cont;
}


void freeTodo(char ** p, int tam){
    for (int i = 0; i < tam; i++){
        free(p[i]);
    }
}


static void mostrarNombres(char * arrNombres[], size_t n){
    for (int i = 0; i < n; i++){
        printf("%s\n", arrNombres[i]);
    }    
}