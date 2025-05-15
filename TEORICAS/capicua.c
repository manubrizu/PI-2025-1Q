#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int capicua(char * s);
int capicuaRec(char * s, int dim);

int main(){
    char * s = "neuquen";
    printf("%d\n", capicua(s));
}

int capicua(char * s){
    return capicuaRec(s, strlen(s));
}

int capicuaRec(char * s, int dim){
    if(dim <= 1) {
        return 1;
    }

    if(s[0] != s[dim -1]){        
        return 0;  
    }    
    
    return capicuaRec(s + 1, dim - 2);
}   