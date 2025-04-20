#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int a = getint("Ingrese un numero: "); 
    int b = getint("Ingrese un numero: ");

    printf("Su promedio es: %.1f\n", (a+b)/2.0);
    printf("La suma es: %d\n", a+b);
    printf("El menor es: %d\n", (a<b) ? a : b);
    printf("El mayor es: %d\n", (a>b) ? a : b);
    printf("%s\n", (a==b) ? "Son iguales" : "No son iguales");


    return 0;
}