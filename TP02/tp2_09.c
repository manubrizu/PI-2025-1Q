#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int num = getint("Ingrese un numero entero positivo: ");
    num >>= 1;
    printf("Su numero divido 2 es: %d\n", num);
    return 0;
}