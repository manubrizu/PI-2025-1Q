#include <stdio.h>

#define COLS 5
#define FILS 6

typedef enum colors {VERDE = 'V', AMARILLO = 'A', GRIS = 'G'} colors;

int wordle(char palabra[COLS], char mat[FILS][COLS], int intentos, char colors[FILS][COLS]);

int checkFil(char palabra[COLS], char intento[COLS], char colors[COLS]);

int main(){
    // Test case: palabra secreta "ROSAS"
    char palabra_secreta[COLS] = {'R', 'O', 'S', 'A', 'S'};
    
    // Matriz de intentos
    char intentos[FILS][COLS] = {
        {'F', 'A', 'R', 'O', 'L'},  // FAROL
        {'S', 'A', 'C', 'O', 'S'},  // SACOS
        {'R', 'A', 'T', 'O', 'S'},  // RATOS
        {'R', 'O', 'S', 'A', 'S'},  // ROSAS
        {'C', 'O', 'S', 'A', 'S'},  // COSAS
        {'T', 'E', 'C', 'L', 'A'}   // TECLA
    };
    
    // Matriz para almacenar los colores
    char colores[FILS][COLS];
    
    // Llamar a la función wordle
    int resultado = wordle(palabra_secreta, intentos, 6, colores);
    
    // Imprimir resultados
    printf("Resultado: %d\n", resultado);
    
    // Imprimir la matriz de colores
    printf("\nMatriz de colores:\n");
    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", colores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}



int wordle(char palabra[COLS], char mat[FILS][COLS], int intentos, char colors[FILS][COLS]){
    for (int i = 0; i < intentos; i++){
        if(checkFil(palabra, mat[i], colors[i])){
            return i + 1;
        }        
    }
    return -1;
}


int checkFil(char palabra[COLS], char intento[COLS], char colors[COLS]){
    int contVerde = 0;
    int letrasUsadas[COLS] = {0};
    
    for (int i = 0; i < COLS; i++) {
        // Primero verificar si es verde
        if (palabra[i] == intento[i]) {
            colors[i] = VERDE;
            contVerde++;
            letrasUsadas[i] = 1;
        } else {
            colors[i] = GRIS; 
            for (int j = 0; j < COLS; j++) {
                if (!letrasUsadas[j] && palabra[j] == intento[i]) {
                    colors[i] = AMARILLO;
                    letrasUsadas[j] = 1;
                    j = COLS;
                }
            }
        }
    }    
    return (contVerde == COLS);
}