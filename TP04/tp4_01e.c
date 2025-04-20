#include <stdio.h>

#define DIVISION(x, y, z) {int i; \
                        for(z=0, i=x-y; i >= 0; z++, i-=y); \
}

int main(){
    int a, b, c, m, n, p, x, y, z;

    a = 20; b=5; c=3;
    DIVISION(a, b, c);

    
}