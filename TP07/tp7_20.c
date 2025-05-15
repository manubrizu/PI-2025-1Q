#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 10

typedef char *TAlumnos[];

char **aprobados(TAlumnos alumnos, const int notas[]);
void liberarMemoria(char **aprobados);

int main() {
    TAlumnos alumnos = {"Ana", "Juan Pablo", "Mariana", "Fernando", "Carolina", NULL};
    int notas[] = {8, 3, 10, 7, 5};

    char **alumAprob = aprobados(alumnos, notas);

    printf("Alumnos aprobados:\n");
    for (int i = 0; alumAprob[i] != NULL; i++) {
        printf("%s\n", alumAprob[i]);
    }

    liberarMemoria(alumAprob);

    return 0;
}

void liberarMemoria(char **aprobados) {
    for (int i = 0; aprobados[i] != NULL; i++) {
        free(aprobados[i]);
    }
    free(aprobados);
}

char **aprobados(TAlumnos alumnos, const int notas[]) {
    int count = 0, j = 0;
    char **aprobados = NULL;

    for (int i = 0; alumnos[i] != NULL && alumnos[i][0] != '\0'; i++) {
        if (notas[i] >= 4) {
            if (count % BLOCK == 0){
                aprobados = realloc(aprobados, (count + BLOCK + 1) * sizeof(char *));
            }
            count++;
            
            aprobados[j] = malloc((strlen(alumnos[i]) + 1) * sizeof(char));
            strcpy(aprobados[j], alumnos[i]);
            j++;
        }
    }

    aprobados = realloc(aprobados, (count + 1) * sizeof(char *));
    aprobados[j] = NULL;

    return aprobados;
}