#include <stdio.h>

unsigned long factorial(int num){
    if(num == 0){
        return 1;
    }
    return num * factorial(num - 1);    
}

int main(){
    printf("%lu\n", factorial(30));
    return 0;
}