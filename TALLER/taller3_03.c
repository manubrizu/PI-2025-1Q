#include <stdio.h>
#include <math.h>

int numerosAmigos(int a, int b){
    int contA = 0, contB = 0;
    
    for(int i=1; i<a; ++i){
        contA += (a%i == 0)? i: 0;
    }

    for(int i=1; i<b; ++i){
        contB += (b%i == 0)? i: 0;
    }
    

    return (contA == b && contB == a);
}

int main(){
    printf("%d\n", numerosAmigos(220, 284));
    return 0;    
}

