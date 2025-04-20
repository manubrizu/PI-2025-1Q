#include <stdio.h>
#include "./../getnum.h"

int main(){
    int c1, minMin = 'z', minMax = 'Z'; 
    while ((c1 = getchar()) != EOF){
        if ('a' <= c1 && c1 <= 'z'){
            if (c1 < minMin){
                minMin = c1;
            }
        }
        else if ('A' <= c1 && c1 <= 'Z'){
            if (c1 < minMax){
                minMax = c1;
            }
        }       
    }
    if ((minMin + 'A' - 'a') <= minMax){
        printf("\n%c\n", minMin);
    }
    else{
        printf("\n%c\n", minMax);
    }

    return 0;    
}