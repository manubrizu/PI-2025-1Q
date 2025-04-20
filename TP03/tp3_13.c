#include <stdio.h>
#include "./../getnum.h"

int main(){
    int num = getint("Ingrese un numero: ");
    for(int i=num; i > 0; i--){
        for (int j = num; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
}