#include <stdio.h>
#include <assert.h>

#define COLS 6

int esCapicua(char vec[]);
void elimnarFila(char v[], int filaActual, int filas);
void elimina(char m[][COLS], int filas);

int main() {
    // Test 1: Matriz sin filas capicúa
    char m1[][COLS] = {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {'g', 'h', 'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p', 'q', 'r'}
    };
    elimina(m1, 3);
    assert(m1[0][0] == 'a' && m1[0][1] == 'b'); // La matriz no debería cambiar
    assert(m1[1][0] == 'g' && m1[1][1] == 'h');
    assert(m1[2][0] == 'm' && m1[2][1] == 'n');

    // Test 2: Matriz con una fila capicúa al principio
    char m2[][COLS] = {
        {'a', 'b', 'c', 'c', 'b', 'a'}, // capicúa
        {'g', 'h', 'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p', 'q', 'r'}
    };
    elimina(m2, 3);
    assert(m2[0][0] == 'g' && m2[0][1] == 'h'); // La primera fila debería ser eliminada
    assert(m2[1][0] == 'm' && m2[1][1] == 'n');
    assert(m2[2][0] == ' ' && m2[2][1] == ' '); // La última fila debería estar vacía

    // Test 3: Matriz con una fila capicúa en el medio
    char m3[][COLS] = {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {'a', 'b', 'c', 'c', 'b', 'a'}, // capicúa
        {'m', 'n', 'o', 'p', 'q', 'r'}
    };
    elimina(m3, 3);
    assert(m3[0][0] == 'a' && m3[0][1] == 'b');
    assert(m3[1][0] == 'm' && m3[1][1] == 'n');
    assert(m3[2][0] == ' ' && m3[2][1] == ' ');

    // Test 4: Matriz con todas las filas capicúa
    char m4[][COLS] = {
        {'a', 'b', 'c', 'c', 'b', 'a'}, // capicúa
        {'d', 'e', 'f', 'f', 'e', 'd'}, // capicúa
        {'g', 'h', 'i', 'i', 'h', 'g'}  // capicúa
    };
    elimina(m4, 3);
    assert(m4[0][0] == ' ' && m4[0][1] == ' '); // Todas las filas deberían estar vacías
    assert(m4[1][0] == ' ' && m4[1][1] == ' ');
    assert(m4[2][0] == ' ' && m4[2][1] == ' ');

    // Test 5: Matriz con una sola fila capicúa
    char m5[][COLS] = {
        {'a', 'b', 'c', 'c', 'b', 'a'} // capicúa
    };
    elimina(m5, 1);
    assert(m5[0][0] == ' ' && m5[0][1] == ' '); // La única fila debería estar vacía

    puts("OK!");
    return 0;
}

int esCapicua(char vec[]){    
    for (int i = 0, j = COLS - 1; i < j; i++ , j--){
        if(vec[i] != vec[j]){
            return 0;
        }
    }
    return 1;
}

void eliminarFila(char m[][COLS], int filaActual, int filas){
    for (int i = filaActual; i < filas - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            m[i][j] = m[i + 1][j];
        }
    }

    for (int j = 0; j < COLS; j++) {
        m[filas - 1][j] = ' ';
    }
}

void elimina(char m[][COLS], int filas){
    int filasEliminadas = 0;
    for (int i = 0; i < filas - filasEliminadas;){
        if(esCapicua(m[i])){
            eliminarFila(m, i, filas);
            filasEliminadas++;
        }        
        else{
            i++;
        }
    }    
}