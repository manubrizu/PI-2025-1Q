#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int c1 = getint("Ingrese un numero: "); 
    int c2 = getint("Ingrese un numero: ");

    printf("%s\n", (c2 == 0) ? "ERROR" : ((c1 % c2 == 0) ? "Es múltiplo" : "NO es multiplo"));

    return 0;
} 