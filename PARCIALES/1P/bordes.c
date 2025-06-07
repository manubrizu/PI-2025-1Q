// PRIMER PARCIAL 2023 2Q EJERCICIO 2

#include <stdio.h>
#include <assert.h>

#define M 6

int sumaBorde(int m[][M], int borde);
void bordes(int m[][M], int vec[M/2]);

int main() {
    // Test 1: Matriz con todos 1s
    int m1[M][M] = {
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1}
    };
    int vec1[M/2];
    bordes(m1, vec1);
    assert(vec1[0] == 20);  
    assert(vec1[1] == 12);  
    assert(vec1[2] == 4);   

    // Test 2: Matriz con valores incrementales
    int m2[M][M] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30},
        {31,32,33,34,35,36}
    };
    int vec2[M/2];
    bordes(m2, vec2);
    assert(vec2[0] == 370);  
    assert(vec2[1] == 222);  
    assert(vec2[2] == 74);   

    // Test 3: Matriz con ceros en los bordes
    int m3[M][M] = {
        {0,0,0,0,0,0},
        {0,1,1,1,1,0},
        {0,1,1,1,1,0},
        {0,1,1,1,1,0},
        {0,1,1,1,1,0},
        {0,0,0,0,0,0}
    };
    int vec3[M/2];
    bordes(m3, vec3);
    assert(vec3[0] == 0);  
    assert(vec3[1] == 12);  
    assert(vec3[2] == 4);   

    // Test 4: Matriz con patrón de ajedrez
    int m4[M][M] = {
        {1,0,1,0,1,0},
        {0,1,0,1,0,1},
        {1,0,1,0,1,0},
        {0,1,0,1,0,1},
        {1,0,1,0,1,0},
        {0,1,0,1,0,1}
    };
    int vec4[M/2];
    bordes(m4, vec4);
    assert(vec4[0] == 10);  
    assert(vec4[1] == 6);  
    assert(vec4[2] == 2);   

    puts("OK!");
    return 0;
}

int sumaBorde(int m[][M], int borde) {
    int suma = 0;
    int limite = M - borde - 1;
    int i = borde + 1;    
    
    while (i < limite) {
        //HORIZONTALES
        suma += m[borde][i];         
        suma += m[limite][i];      
    
        // VERTICALES
        suma += m[i][borde];         
        suma += m[i++][limite];        
    }
    
    // ESQUINAS
    suma += m[borde][borde];                    
    suma += m[borde][limite];                   
    suma += m[limite][borde];                   
    suma += m[limite][limite];                  
    
    return suma;
}

void bordes(int m[][M], int vec[M/2]){
    for (int i = 0; i < M/2; i++){      // voy a repetir la cantidad de bordes (M/2)
        vec[i] = sumaBorde(m, i);
    }    
}