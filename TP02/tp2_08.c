#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    float velocidad = getfloat("Ingrese la velocidad en m/s: ");
    velocidad *= 3.6;
    printf("Su velocidad es de %.2f km/h.\n", velocidad);
    
    return 0;
}