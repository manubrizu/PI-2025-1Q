#include <stdio.h>
#include "./../getnum.h"

int main(){
    int c1 = getchar();
    int c2 = getchar();
    if (c1 < c2){
        printf("%c es menor que %c.\n", c1, c2);
    }
    else if (c1 > c2){
        printf("%c es mayor que %c.\n", c1, c2);
    }
    else {
        printf("%c y %c son iguales.\n", c1, c2);
    }
    return 0;
}