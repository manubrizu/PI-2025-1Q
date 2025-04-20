#include <stdio.h>
#include "./../getnum.h"

int main(){
    int suma = 0, num = getint("Ingrese un numero: \n");        
    while (num != 0){
        suma += (num % 10);
        num /= 10;
    }
    printf("La suma es: %d\n", suma);
}