#include <stdio.h>

int suma(int num){
    if ((num / 10) == 0){
        return num;
    }  

    return num % 10 + suma(num / 10);
}

int main(){
    printf("%d\n", suma(3498));
}