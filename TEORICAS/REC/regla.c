#include <stdio.h>

// si h = 8  -->  1 2 1 4 1 2 1 8 1 4 1 2 1 

void regla(int h);

int main(){
    regla(8);
    printf("\n");
}

void regla(int h){
    if (h == 1) {
        printf("1 ");
        return;
    } 
    regla(h / 2);
    printf("%d ", h);
    regla(h / 2);
}