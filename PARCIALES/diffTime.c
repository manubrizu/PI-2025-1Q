#include <stdio.h>

#define SECONDS_TO_HOURS 3600
#define SECONDS_TO_MINS 60

void diffTime(unsigned int vec[], int dim, int* horas, int* minutos, int* segundos);

int main() {
    unsigned int tiempos[] = {3600, 7200, 3661, 59, 86399}; // Ejemplo de tiempos en segundos
    int dim = sizeof(tiempos) / sizeof(tiempos[0]);
    int horas, minutos, segundos;

    diffTime(tiempos, dim, &horas, &minutos, &segundos);

    printf("Diferencia máxima:\n");
    printf("Horas: %d, Minutos: %d, Segundos: %d\n", horas, minutos, segundos);

    return 0;
}

void diffTime(unsigned int vec[], int dim, int* horas, int* minutos, int* segundos){
    if (dim <= 1) {
        *horas=0;
        *minutos=0;
        *segundos=0;
        return;
    }
    int max = 0, min = vec[0], diferencia;
    for (int i = 0; i < dim; i++){
        if(vec[i] > max){
            max = vec[i];
        }
        else if(vec[i] < min){
            min = vec[i];
        }
    }
    diferencia = max - min;

    *horas = diferencia / SECONDS_TO_HOURS;
    *minutos = (diferencia % SECONDS_TO_HOURS) / SECONDS_TO_MINS;
    *segundos = diferencia % SECONDS_TO_MINS;    
}