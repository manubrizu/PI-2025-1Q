/*
Ejercicio 16 ***
Escribir una función que reciba una matriz de números enteros y cuya cantidad de filas está dada por la
constante simbólica FILS y la cantidad de columnas por la constante simbólica COLS.
Se asegura que ambas constantes son mayores o iguales a 2 (no hace falta validarlo)
La función debe retornar 1 si la matriz es "ascendente", -1 si es "descendente" y 0 si no es ascendente ni
descendente. Se dice que una matriz es ascendente si recorriendola en forma ordenada por filas cada
elemento es mayor o igual al anterior, En forma análoga se define una matriz descendente.
El recorrido comienza por el elemento [0][0], continúa con el [0][1] y luego de terminar la primera fila hace lo
mismo con la segunda fila, tercer fila, etc.
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define FILS 3
#define COLS 4

int ascendenteODescendente(int (m[])[COLS]);

int main(void){
    int m1[][COLS] = {
		{-6,-5,2,6},
		{7,9,9,14},
		{21,32,45,46}
	}; // m1 es ascendente

  assert(ascendenteODescendente(m1)==1);
	int m2[][COLS] = {
		{19,13,12,8},
		{7,7,5,-1},
		{-6,-10,-14, -16}
	}; // m2 es descendente
assert(ascendenteODescendente(m2)==-1);


	int m3[][COLS] = {
		{-6,-5,-6,6},
		{7,9,10,14},
		{21,32,45,46}
	}; // m3 no es ascendente ni descendente
  assert(ascendenteODescendente(m3)==0);
	
	int m4[][COLS] = {
		{19,13,18,8},
		{7,5,2,-1},
		{-6,-10,-14}
	}; // m4 no es ascendente ni descendente
assert(ascendenteODescendente(m4)==0);

int m5[][COLS] = {
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	}; // m5 es ascendente y descendente. La funciÃ³n podrÃ­a devolver 1 Ã³ -1
  int respM5 =  ascendenteODescendente(m5);
  assert(respM5==1 || respM5 == -1);
  
  int m6[][COLS] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,10}
	}; 
  int respM6 =  ascendenteODescendente(m6);
  assert(respM6 == 0);
  
  int m7[][COLS] = {
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	}; 
  int respM7 =  ascendenteODescendente(m7);
  assert(respM7 == 0);

  
	int m8[][COLS] = {
		{19,19,12,8},
		{7,7,5,-1},
		{-6,-10,-14, -16}
	}; // m2 es descendente
    assert(ascendenteODescendente(m8)==-1);

   int m9[][COLS] = {
		{-6,-6,-6,6},
		{7,9,9,14},
		{21,32,45,46}
	}; 
	   assert(ascendenteODescendente(m9)==1);
	   
    puts("OK");
    return 0;
}

int ascendenteODescendente(int (m[])[COLS]){
    bool esAscendente = false, esDescendente = false, esNinguno = false;
    int ultimo = m[0][0];
    for (int i = 0; i < FILS && !esNinguno; i++) {
        for (int j = 0; j < COLS && !esNinguno; j++) {
            if (!(i == 0 && j == 0)){
                int actual = m[i][j];
                if(actual > ultimo){
                    if(esDescendente)
                        esNinguno = true;
                    esAscendente = true;
                }
                else if(actual < ultimo){
                    if(esAscendente)
                        esNinguno = true;
                    esDescendente = true;
                }
                ultimo = actual;
            }            
        }
    }
    return (esNinguno) ? 0 : (esAscendente) ? 1 : -1;    
}