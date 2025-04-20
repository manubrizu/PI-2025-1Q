#include <stdio.h>
#define SWAP(t, x, y)   {t aux; \
                    aux = x; \
                    x = y; \
                    y = aux; \
}



int main(){
    int x = 5, y=3;
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    SWAP(int, x, y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    return 0;

}