#include <stdio.h>
#include "./../getnum.h"


int main() 
{
    int c1 = getchar();

    printf("%s\n", (c1 != EOF) ? "1" : "0");

    printf("%d\n", EOF);

    return 0;
}