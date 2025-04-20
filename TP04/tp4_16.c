#include <stdio.h>
#define DIVISOR(n1, n2) ((n2) != 0 && ((n1) % (n2)) == 0)

int main(){
    int a, b = -15, c = -4;
    a = DIVISOR(b, c);
    printf("%d\n", a);
    a = DIVISOR(b, c-1);
    printf("%d\n", a);

    return 0;
}