#include <stdio.h>
#include <math.h>

int esPrimo(int num){
    if(num < 0)
        num = -num;
    double a = sqrt(num);
    for(int i = 2; i<=(int)a; ++i){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

void mostrarNPrimos(int cant){
    for(int i=2; cant!=0; ++i){
        if(esPrimo(i)){
            printf("%d\n", i);
            cant--;
        }
    }

}

int main(){
    mostrarNPrimos(8);
    return 0;    
}

