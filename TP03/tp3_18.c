#include <stdio.h>
#include "./../getnum.h"

int main(){
    int fact = 1, num = getint("Ingrese un numero: \n");
    if (num < 0) {
        puts("ERROR. Ingrese un numero entero positivo.");
    } 
    else {
        for (int i = num; i >= 0; i--){
            if (i==0){
                fact *= 1;
            }
            else {
                fact *= i;
            }
        }
        printf("El factorial es: %d\n", fact);
    }
    return 0;
}