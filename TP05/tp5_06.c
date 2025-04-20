#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "./../getnum.h"

int main(){
    int c = getchar();

    printf("1)Convertir de mayúscula a minúscula.\n2)Convertir de minúscula a mayúscula.\n3)Imprimir el carácter siguiente.\n4)Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')\n");
    int a = getint("Ingrese una opcion: ");

    switch (a)
    {
    case 1:
        c = tolower(c);
        break;
    
    case 2:
        c = toupper(c);
        break;
    
    case 3:
        printf("%c\n", c+1);
        break;
    
    case 4:
        if(isalpha(c)){
            if (c == 'Z' || c == 'z'){
                c -= 'Z' - 'A';
            }
            printf("%c\n", c);
        }
        break;
    
    default:
        return -1;
        break;
    }


    return 0;
}