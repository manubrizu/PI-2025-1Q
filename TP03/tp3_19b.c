#include <stdio.h>
#include "./../getnum.h"

int main(){
    float numF = getfloat("Ingrese un numero entero: \n");
    if (numF < 0){
        numF = -numF;
    }
    int cont = 0, num = (int) numF;

    while (num > 0){
        cont += (num % 10 !=0 && num % 5 == 0);
        num /= 10;
    }

    // ME SACO LA PARTE ENTERA
    numF -= (int)numF;    

    printf("%f\n", numF);

    while (numF > 0){
        numF *= 10;
        cont += ((int)numF % 5 == 0);
        numF -= (int)numF;
    }
    printf("Hay %d cincos.\n", cont);
    return 0;    
}