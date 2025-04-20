#include <stdio.h>
#define CUBO(x) ((x) * (x) * (x))
int cubo (int num);

int main(void) {
    int a=3, b, c, d, e, f; 
    b = CUBO( ++a ); 
    c = CUBO( a++ ); 
    d = 3;
    e = cubo ( ++d ); 
    d = 3;
    f = cubo ( d++ ); 

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    printf("%d\n", e);
    printf("%d\n", f);

    return 0;
}

int cubo ( int num ) 
{   
return num * num * num; 
}