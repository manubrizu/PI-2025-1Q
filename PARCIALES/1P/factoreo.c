#include <stdio.h>
#include <assert.h>

long factoreo(int vec[]);
void eliminaElemento(int vec[], int elemento);

int main(void) {
    int factores[] = {2, 2, 2, 3, 3, 4, 5, 5, 6, 6, 6, 6, 7, -1};
    long resultado = factoreo(factores);
    assert(resultado == 65318400);
    assert(factores[0] == 2);
    assert(factores[1] == 3);
    assert(factores[2] == 4);
    assert(factores[3] == 5);
    assert(factores[4] == 6);
    assert(factores[5] == 7);
    assert(factores[6] == -1);
    int factores2[] = {2, -1};
    resultado = factoreo(factores2);
    assert(resultado == 2);
    assert(factores2[0] == 2);
    assert(factores2[1] == -1);
    int factores3[] = {11, 11, 13, -1};
    resultado = factoreo(factores3);
    assert(resultado == 1573); // 11 * 11 * 13
    assert(factores3[0] == 11);
    assert(factores3[1] == 13);
    assert(factores3[2] == -1);
    int factores4[] = {-1};
    resultado = factoreo(factores4);
    assert(resultado == 0);
    assert(factores4[0] == -1);
    int factores5[] = {1, -1};
    resultado = factoreo(factores5);
    assert(resultado == 1);
    assert(factores5[0] == 1);
    assert(factores5[1] == -1);
    puts("OK!");
    return 0;
}


long factoreo(int vec[]){
    if(vec[0] == -1)        // VECTOR VACIO
        return 0;

    long resp = 1;
    int i = 0;
    while (vec[i] != -1){
        resp *= (long) vec[i];
        i++;
    }

    // Ahora elimino repetidos
    i = 1;
    while (vec[i] != -1){
        if(vec[i - 1] == vec[i]){
            eliminaElemento(vec, i);
        }
        else{
            i++;
        }
    }    
    return resp;
}

void eliminaElemento(int vec[], int posicion){
    int i = posicion;
    while (vec[i] != -1){
        vec[i] = vec[i + 1];
        i++;
    }   
}