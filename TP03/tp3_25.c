#include <stdio.h>
#include "./../getnum.h"

int main(){
    long long int base = 1, numB = 0, num = getint("Ingrese un numero decimal hasta 65535: \n");
    int cont = 0;
    while (num > 0) {
        numB += (num % 2) * base;
        base *= 10;
        num /= 2;        
    }

    while (numB > 0){
        cont += (numB % 10);
        numB /= 10;
    }

    printf("%d\n", cont);
    return 0;
}