#include <stdio.h>
#include "./../getnum.h"

int main(){
    int cont = 0, num = getint("Ingrese un numero entero: \n");
    while (num > 0){
        if (num % 10 !=0 && num % 5 == 0 ){
            cont++;
        }
        num /= 10;
    }
    printf("Hay %d cincos.\n", cont);
    return 0;    
}