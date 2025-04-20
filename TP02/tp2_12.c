#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int c1 = getchar(); 

    printf("%s\n", (('A' <= c1 && c1 <= 'Z') || ('a' <= c1 && c1 <= 'z')) ? "Es una letra" : "No es una letra" );

    return 0;
}