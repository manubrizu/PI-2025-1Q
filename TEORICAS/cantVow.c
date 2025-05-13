#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isVowel(char c){
    return strchr("aeiou", tolower(c)) != NULL;
}

int cantVow(char * str){
    if(! *str){
        return 0;
    }
    return isVowel(*str) + cantVow(str + 1);
}


int main(){
    char * str = "Hola";
    printf("%d\n", cantVow(str));
}