#include <stdio.h>
#include "./../getnum.h"

int main(){
    long long int base = 1, numB = 0, num = getint("Ingrese un numero decimal hasta 65535: \n");
    while (num > 0) {
        numB += (num % 2) * base;
        base *= 10;
        num /= 2;        
    }
    printf("Tu numero en binario es: %016lld\n", numB);
    return 0;
}