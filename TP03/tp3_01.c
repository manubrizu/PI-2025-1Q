#include <stdio.h>
#include "./../getnum.h"

int main(){
    int c1 = getchar();    
    if (('a' <= c1) &&(c1 <= 'z')){
        printf("%c es una letra minuscula.\n", c1);
    }
    else if (('A' <= c1) && (c1 <= 'Z')){
        printf("%c es una letra mayuscula.\n", c1);
    }
    else
        puts("NO es una letra");
    return 0;
}