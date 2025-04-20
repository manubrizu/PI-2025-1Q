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

int main(){
    printf("%d\n", esPrimo(1));
    return 0;    
}

