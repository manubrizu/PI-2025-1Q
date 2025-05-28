#include <stdio.h>
#include <stdlib.h>
#include "complexADT.h"

int main() {
    complexADT z1 = newComplex(2, 3); // 2 + 3i
    complexADT z2 = newComplex(4, -1); // 4 - i

    printf("z1: %d + %di\n", real(z1), imaginario(z1));
    printf("z2: %d + %di\n", real(z2), imaginario(z2));

    complexADT sum = suma(z1, z2);
    printf("z1 + z2: %d + %di\n", real(sum), imaginario(sum));

    // Liberar memoria
    free(z1);
    free(z2);
    free(sum);

    return 0;
}