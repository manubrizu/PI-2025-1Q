#include <stdio.h>

int potencia(int num, int exp){
    if(exp == 0){
        return 1;
    }
    return  num * potencia(num, exp - 1);    
}

int main(){
    printf("%d\n", potencia(2, 5));
    return 0;
}