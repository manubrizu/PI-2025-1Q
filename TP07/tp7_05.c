#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void separar(const char **nombre, const char *curso, char ***cursoG, int *cantG, char ***cursoH, int *cantH);
void liberarMemoria(char **curso, int cantidad);

int main() {
    const char *nombre[] = {"Juan", "Maria", "Pedro", "Ana", "Luis", NULL};
    const char curso[] = {'G', 'H', 'G', 'H', 'G'};

    char **cursoG, **cursoH; 
    int cantG, cantH;

    separar(nombre, curso, &cursoG, &cantG, &cursoH, &cantH);

    // Imprimir los alumnos del curso G
    printf("curso G:\n");
    for (int i = 0; i < cantG; i++) {
        puts(cursoG[i]);
    }

    // Imprimir los alumnos del curso H
    printf("curso H:\n");
    for (int i = 0; i < cantH; i++) {
        puts(cursoH[i]);
    }

    // Liberar memoria dinámica
    liberarMemoria(cursoG, cantG);
    liberarMemoria(cursoH, cantH);

    return 0;
}


void separar(const char **nombre, const char *curso, char ***cursoG, int *cantG, char ***cursoH, int *cantH) {
    int g = 0, h = 0;

    *cantG = 0;
    *cantH = 0;
    for (int i = 0; nombre[i] != NULL; i++) {
        if (curso[i] == 'G') {
            (*cantG)++;
        } 
        else if (curso[i] == 'H') {
            (*cantH)++;
        }
    }

    *cursoG = malloc(*cantG * sizeof(char *));
    *cursoH = malloc(*cantH * sizeof(char *));
    int lenNombre;

    for (int i = 0; nombre[i] != NULL; i++) {
        if (curso[i] == 'G') {
            lenNombre = strlen(nombre[i]) + 1;
            (*cursoG)[g] = malloc(lenNombre * sizeof(char));
            strcpy((*cursoG)[g++], nombre[i]);
        } 
        else if (curso[i] == 'H') {
            lenNombre = strlen(nombre[i]) + 1;
            (*cursoH)[h] = malloc(lenNombre * sizeof(char));
            strcpy((*cursoH)[h++], nombre[i]);
        }
    }
}

void liberarMemoria(char **curso, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        free(curso[i]);
    }
    free(curso);
}