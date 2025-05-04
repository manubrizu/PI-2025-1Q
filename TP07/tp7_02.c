#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* convertirBase(const char* numStr, int base1, int base2);

int main(void) {
    int base1, base2;
    char numStr[100];

    printf("Ingrese las bases en formato <base1> base2: ");
    if (scanf(" <%d> %d", &base1, &base2) != 2 ||
        base1 < 2 || base1 > 10 || base2 < 2 || base2 > 10) {
        printf("Error: formato o bases inválidas (deben estar entre 2 y 10).\n");
        return 1;
    }

    printf("Ingrese el número en base %d: ", base1);
    scanf("%s", numStr);

    char *resultado = convertirBase(numStr, base1, base2);
    if (resultado) {
        printf("Resultado en base %d: %s\n", base2, resultado);
        free(resultado);
    } else {
        printf("Hubo un error en la conversión.\n");
    }

    return 0;
}

char* convertirBase(const char* numStr, int base1, int base2) {    
    int num = 0; // lo tengo q pasar a decimal
    for (int i = 0; numStr[i]; i++) {
        int digit = numStr[i] - '0';    // paso de char a int;
        if (digit < 0 || digit >= base1) {
            printf("Dígito inválido para base %d.\n", base1);
            return NULL;
        }
        num = num * base1 + digit;
    }

    unsigned char temp[33]; // un int son 4 bytes (32 bytes y el \0)
    int i = 0;

    if (num == 0) {
        temp[i++] = '0';
    } 
    else {
        while (num != 0) {
            temp[i++] = (num % base2) + '0';
            num /= base2;
        }
    }
    temp[i] = '\0';

    char *resultado = malloc(i + 1); // reservo espacio en el heap 

    // el resultado en la base2 queda dado vuelta, entonces lo doy vuelta

    for (int j = 0; j < i; j++) {
        resultado[j] = temp[i -1 - j];
    }

    resultado[i] = '\0';
    return resultado;
}