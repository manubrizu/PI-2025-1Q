#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int c1 = getchar(); 
    int c2 = getchar(); 

    printf("Mayor ASCII: %c\n", (c1 > c2) ? c1 : c2);

    return 0;
}