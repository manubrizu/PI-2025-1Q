#include <stdio.h>
#include <string.h>

void invierte(char * org, char * dest);
void invierteRec(const char *org, char *dest, int len);

int main() {
    char origen1[] = "Practica";
    char destino1[20] = {0};
    invierte(origen1, destino1);
    printf("%s\n", destino1); // acitcarP

    char origen2[] = "";
    char destino2[10] = {0};
    invierte(origen2, destino2);
    printf("'%s'\n", destino2); // ''

    char origen3[] = "a";
    char destino3[5] = {0};
    invierte(origen3, destino3);
    printf("%s\n", destino3); // a

    char origen4[] = "12345";
    char destino4[10] = {0};
    invierte(origen4, destino4);
    printf("%s\n", destino4); // 54321

    char origen5[] = "abba";
    char destino5[10] = {0};
    invierte(origen5, destino5);
    printf("%s\n", destino5); // abba

    return 0;
}

void invierte(char * org, char * dest){
    int len = strlen(org);
    invierteRec(org, dest, len);
}

void invierteRec(const char *org, char *dest, int len) {
    if (len == 0) {
        dest[0] = '\0';
        return;
    }
    dest[0] = org[len - 1];
    invierteRec(org, dest + 1, len - 1);
}