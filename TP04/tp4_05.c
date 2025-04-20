#include <stdio.h>
#define MAXIMO2(a, b, r) (r = ((a) > (b)) ? (a) : (b))

int main(){
    int a = 5, b = 7, max;
    MAXIMO2(a, b, max);
    printf("%d\n", max);
    return 0;
}