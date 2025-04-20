#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int c1 = getchar();
    
    printf("En Mayusculas es: %c\n", (c1 - 'a') + 'A');

    return 0;    
}