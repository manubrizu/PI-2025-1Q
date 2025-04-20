#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    int segs = getint("Ingrese una cantidad de segundos: ");

    printf("Eso equilave a %d hora/s, %d minuto/s y %d segundo/s.\n", segs/3600, (segs%3600)/60, segs%60);

    return 0;    
}