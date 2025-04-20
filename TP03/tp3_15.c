#include <stdio.h>
#include "./../getnum.h"
#include <math.h>

int main(){
    int expo = 1, numB = 0, num = getint("Ingrese su numero en binario: \n"), aux = num;

    // CHEQUEAR QUE ES BINARIO
    while (aux > 0) {
        if ((aux % 10) > 1){
            puts("ERROR. No es binario.");
            return 1;
        }
        aux /= 10;
    }
    while (num > 0) {
        numB += (num % 10) * expo;
        num /= 10;
        expo *=2;
    }  
    printf("%d\n", numB);
    return 0;
}   