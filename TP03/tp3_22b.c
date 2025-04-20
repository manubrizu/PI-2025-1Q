#include <stdio.h>
#include "./../getnum.h"

int main(){
    int c1;
    while ((c1 = getchar()) != EOF){
        if(c1 == '\t'){
            printf("\\t");
        }
        else if (c1 == '\b'){
            printf("\\b");
        }
        else if (c1 == '\\'){
            printf("\\\\");
        }
        else{
            putchar(c1);
        }
    }
    puts("");
    return 0;
}