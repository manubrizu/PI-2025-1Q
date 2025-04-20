#include <stdio.h>
#include "./../getnum.h"

int main(){
    int c1, prev = '\0';
    while ((c1 = getchar()) != EOF){
        if (!(prev == ' ' && c1 == ' ')){
            putchar(c1);
        } 
        prev = c1;        
    }
    puts("");
    return 0;
    
}