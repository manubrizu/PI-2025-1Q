#include <stdio.h>

int MCD(int n1, int n2){
    if(n1 == 0){
        return n2;
    }
    else if(n2 % n1 == 0){
        return n1;
    }
    return MCD(n2, n1 % n2);
}

int main(){
    printf("%d\n", MCD(13, 7));
}