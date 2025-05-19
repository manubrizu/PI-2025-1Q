#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(char * s);
int palindromoRec(char * s, int dim);

int main(){
    char * s = "neuquen";
    printf("%d\n", palindromo(s));
}

int palindromo(char * s){
    return palindromoRec(s, strlen(s));
}

int palindromoRec(char * s, int dim){
    if(dim <= 1) {
        return 1;
    }

    if(s[0] != s[dim -1]){        
        return 0;  
    }    
    
    return palindromoRec(s + 1, dim - 2);
}   