#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "./../random.h"
#include "./../getnum.h"

int f1(int num, int letra){
    int c, cont = 0, limite = 0;
    while((c = getchar()) != EOF && limite <= num){
        if ((c == letra || c == tolower(letra))){
            cont++;
        }
        limite++;
    }
    return cont;
}

int main (){
    randomize();
    int letra = randInt('A', 'Z');
    int num = randInt(1, 256);
    printf("%c\t%d\n", letra, num);

    printf("%d\n", f1(num, letra));
    return 0;
}