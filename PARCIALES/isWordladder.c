#include <stdio.h>
#include <ctype.h>
#include <assert.h>


int indexOfCambio(char pal1[], char pal2[], unsigned int longPalabras);
int isWordLadder(unsigned int cantPalabras, unsigned int longPalabras, char m[][longPalabras]);

int main(void) {
    char wordMatrix[][4] = {
    {'T', 'e', 'S', 't'},
    {'b', 'e', 'S', 'T'},
    {'B', 'E', 's', 'o'},
    {'B', 'E', 'S', 'A'}};
    
    // Considerando todas las filas no es escalera
    // pues los últimos dos cambios son en la última letra
    assert(!isWordLadder(4, 4, wordMatrix));
    // Considerando una sola fila es escalera
    assert(isWordLadder(1, 4, wordMatrix) == 1);
    // Considerando las tres primeras filas es escalera
    assert(isWordLadder(3, 4, wordMatrix) == 1);
    char wordMatrix2[][3] = {
    {'T', 'e', 'S'},
    {'t', 'b', 'e'},
    {'S', 'b', 'E'},
    {'B', 'b', 'e'}};
    // TeS -> Tbe cambian dos letras
    assert(!isWordLadder(4, 3, wordMatrix2));
    char wordMatrix3[][3] = {
    {'a', 'm', 'o'},
    {'a', 'r', 'o'},
    {'o', 's', 'a'}};
    
    // aro -> osa cambian tres letras
    assert(!isWordLadder(3, 3, wordMatrix3));
    puts("OK!");
    return 0;
}

int indexOfCambio(char pal1[], char pal2[], unsigned int longPalabras){
	int cantCambios = 0, index = 0;
	for(int i = 0; i < longPalabras; i++){
		if(tolower(pal1[i]) != tolower(pal2[i])){
			cantCambios++;
            if(cantCambios > 1){
                return -1;
            }
            index = i;
		}
	}
    if(cantCambios == 0){
        return -1;
    }
    else{
        return index;
    }
	
}

int isWordLadder(unsigned int cantPalabras, unsigned int longPalabras, char m[][longPalabras]){
	int index = 0, lastIndex = -1;

	for(int i = 0; i < cantPalabras - 1; i++){
		index = indexOfCambio(m[i], m[i+1], longPalabras);
		if(index == -1){
            return 0;
        }
        else if(lastIndex != index){
			lastIndex = index;
		}
		else{
			return 0;
		}	
	}

	return 1;
}