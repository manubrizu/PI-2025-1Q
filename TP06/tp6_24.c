#include <stdio.h>
#include <string.h>

void eliminaEspacios (char string[]){
    unsigned int i,j;
    
    for (i = 0, j = 0; string[i] ; i++){
        if (i == 0 || !(string[i] == ' ' && string[i-1] == ' ')){
            string[j++] = string[i];
        }
    }

    string[j] = 0;
}

int main(){

    char string[] = "Hola    mundo";

    puts(string);

    eliminaEspacios(string);

    puts(string);

    return 0;
}