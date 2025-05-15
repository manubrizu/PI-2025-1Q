#include <stdio.h>
#include <stdlib.h>
#include "./../random.h"

#define MAX 15
#define BLOCK 10

typedef struct{
    int x;
    int y;
} tPunto2D;

typedef tPunto2D * tPosiciones;

void movimientos(tPosiciones * pos);

int main() {
    randomize();
    tPosiciones pos = NULL;
    movimientos(&pos);

    free(pos);
    return 0;
}


void movimientos(tPosiciones * pos){    
    int i = 0;
    pos = NULL;

    do{
        if(i % BLOCK == 0){            
            pos = realloc(pos, (i + BLOCK) * sizeof(tPunto2D *));
        }
        pos[i]->x = randInt(-MAX, MAX);
        pos[i]->y = randInt(-MAX, MAX);    
        i++;
    } while (!(pos[i]->x ==0 && pos[i]->y == 0));

    
    pos = realloc(pos, i * sizeof(tPunto2D *));
    
    
}