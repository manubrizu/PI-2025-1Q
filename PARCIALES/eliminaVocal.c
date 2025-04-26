#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esVocal(char c);
void eliminaVoc(char str[]);


int main() {
    char str1[] = "hola mundo";
    char str2[] = "hola a todo el mundo";
    char str3[] = "xyz";
    char str4[] = "aholoaaa";
    char str5[] = "";
    char str6[] = "aa eo iu oa uo";
    char str7[] = "pa po pi po pu";
    char str8[] = "aeiou";
    char str9[] = "a,e,i,o,u";

    eliminaVoc(str1);
    eliminaVoc(str2);
    eliminaVoc(str3);
    eliminaVoc(str4);
    eliminaVoc(str5);
    eliminaVoc(str6);
    eliminaVoc(str7);
    eliminaVoc(str8);
    eliminaVoc(str9);

    printf("Resultado 1: \"%s\"\n", str1);
    printf("Resultado 2: \"%s\"\n", str2);
    printf("Resultado 3: \"%s\"\n", str3);
    printf("Resultado 4: \"%s\"\n", str4);
    printf("Resultado 5: \"%s\"\n", str5);
    printf("Resultado 6: \"%s\"\n", str6);
    printf("Resultado 7: \"%s\"\n", str7);
    printf("Resultado 8: \"%s\"\n", str8);
    printf("Resultado 9: \"%s\"\n", str9);

    return 0;
}

int esVocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void eliminaVoc(char str[]) {
    int len = strlen(str);
    int j = 0; 

    for (int i = 0; i < len; i++) {
        if (esVocal(str[i])) {
            // Verificar si es una vocal "suelta"
            int esSuleta = 1;

            // Verificar el carácter anterior
            if (i > 0 && !esVocal(str[i - 1]) && isalpha(str[i - 1])) {
                esSuleta = 0;
            }

            // Verificar el carácter siguiente
            if (i < len - 1 && !esVocal(str[i + 1]) && isalpha(str[i + 1])) {
                esSuleta = 0;
            }

            // Si es una vocal "suelta", no eliminarla
            if (esSuleta) {
                str[j++] = str[i];
            }
        } else {
            // No es vocal, copiar al nuevo string
            str[j++] = str[i];
        }
    }

    // Terminar el string
    str[j] = '\0';
}
