#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarGrupos(char * cadena, char caracter){
    if(*cadena == '\0'){
        return 0;
    }

    if(*cadena == caracter && *(cadena + 1) != caracter){
        return 1 + contarGrupos(cadena + 1, caracter);
    }
    
    return contarGrupos(cadena + 1, caracter);
}



