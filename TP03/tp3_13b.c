#include <stdio.h>
#include "./../getnum.h"

int main(){
    /*  int cont = 0, num = getint("Ingrese un numero: ");
    *   for(int i=num; i > 0; i--){
    *       if (cont != num){            
    *           printf("*");
    *           cont++;
    *           i++;
    *       }
    *       else{        
    *           cont = 0;
    *           printf("\n");
    *       }
    *   }
    */

    int num = getint("Ingrese un numero: ");
    for(int i=1; i <= num*num; i++){
        if(i%num == 0){
            printf("*");
            printf("\n");
        }
        else {
            printf("*");
        }
    }
    // SE USA LA OPERACION MATEMATICA DE MODULO

    return 0;
}