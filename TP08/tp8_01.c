#include <stdio.h>
#include <stdlib.h>

struct art {
        int code;
        double price;
};

struct art * newArt(int code, double price) {
    struct art * p = calloc(1, sizeof(struct art));
    p->code = code;
    p->price = price;
    return p;
}


int main(){

    /// a
    char c = 'a';
    char * p = malloc(sizeof(char));    
    *p = c;
    printf("Valor almacenado en p: %c\n", *p);
    free(p);

    /// b
    

    


    return 0;
}

