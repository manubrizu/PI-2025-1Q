#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../random.h"

#define MAX_INTENTOS 10
#define MAX_PALABRA 15




void jugar(const char* palabra, int longitud);
const char * generarPalabra(const char* palabras[], int total);
void imprimirAhorcado(const char* ahorcado, int longitud);
int chequeoPalabra(const char* palabra, char* ahorcado, char intento);
int gano(const char* ahorcado, int longitud);

int main(){
    randomize();
    const char* palabras[] = {"computadora", "teclado", "pantalla", "memoria", "procesador"};
    int totalPalabras = sizeof(palabras) / sizeof(palabras[0]);

    const char* palabra = generarPalabra(palabras, totalPalabras);
    int len = strlen(palabra);

    jugar(palabra, len);

}

void jugar(const char* palabra, int longitud){
    char ahorcado[MAX_PALABRA];
    int intentosRestantes = MAX_INTENTOS;

    for (int i = 0; i < MAX_PALABRA; i++){
        ahorcado[i] = '_';
    }
    
    ahorcado[longitud] = '\0';

    while (intentosRestantes > 0 && !gano(ahorcado, longitud)) {
        printf("AHORCADO: ");
        imprimirAhorcado(ahorcado, longitud);

        printf("Intentos restantes: %d\n", intentosRestantes);
        printf("Ingrese una letra: ");
        char intento = getchar();
        while (getchar() != '\n');

        if (!chequeoPalabra(palabra, ahorcado, intento)) {
            intentosRestantes--;
            printf("\nLetra incorrecta.\n");
        } else {
            printf("\n¡Bien! Letra correcta.\n");
            puts("----------------------");
            printf("\n");
        }
    }

    if (gano(ahorcado, longitud)) {
        printf("¡Ganaste! La palabra era: %s\n", palabra);
    } else {
        printf("¡Perdiste! La palabra era: %s\n", palabra);
    }
}

const char * generarPalabra(const char* palabras[], int total){
    int i = randInt(1, total);
    printf("%d\n", i);
    return palabras[i - 1];
}

void imprimirAhorcado(const char* ahorcado, int longitud){
    for (int i = 0; i < longitud; i++){
        printf("%c ", ahorcado[i]);
    }
    printf("\n");
}

int chequeoPalabra(const char* palabra, char* ahorcado, char intento){
    int acierto = 0;
    for (int i = 0; palabra[i] ; i++) {
        if (palabra[i] == intento && ahorcado[i] == '_') {
            ahorcado[i] = intento;
            acierto = 1;
        }
    }
    return acierto;
}

int gano(const char* ahorcado, int longitud){
    for (int i = 0; i < longitud; i++){
        if(ahorcado[i] == '_'){
            return 0;
        }
    }
    return 1;    
}