#include <stdio.h>

int fibo(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return  fibo(n-1) + fibo(n-2);    
}

int main(){
    printf("%d\n", fibo(7));
    return 0;
}