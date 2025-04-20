#include <stdio.h>
int
main(void)
{
    int i, j, max;
    i = j = 2;
    max = (i>j ? i : j );
    printf("El maximo es: %d\n", max);
    
    return 0;
}
