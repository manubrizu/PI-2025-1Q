#include <stdio.h>
#include "./../getnum.h"

int main(){
    int c1, suma = 0;
    while((c1 = getchar()) != EOF){
        if (c1 >= '0' && c1 <= '9'){
            suma += (c1 -= '0');
        }
    }
    printf("\nLa suma es %d\n", suma);

}