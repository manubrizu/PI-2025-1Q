#include <stdio.h>

void factorial(int num, int * resp);

int main(){
    int fact;
    factorial(5, &fact);

    printf("%d\n", fact);
}

void factorial(int num, int * resp){
    if(num==0){
        * resp = 1;
        return;
    }
    
    factorial(num - 1, resp);
    
    *resp *= num;
}