#include <stdio.h>
#include <math.h>
#include <assert.h>

// ip       11000000 10101000 00000000 01100100
// maskRed  11111111 11111110 00000000 00000000 (0xFFFE0000)

unsigned long int getMask(unsigned char bitsNet);
void prettyPrint(unsigned long ip);
void separateNet(unsigned int ip, unsigned char bitsNet);

int main(){ 
    separateNet(0x10FF1112, 16);
    return 0;
}

unsigned long int getMask(unsigned char bitsNet){
    unsigned long mask = 1;
    for(unsigned char i = 1; i < 32 - bitsNet; ++i){
        mask = (mask << 1) | 1;           //    0000 0010 | 0000 0001 -> 0000 0011 ---> (15 veces) ->     00000000 00000001 11111111 11111111
    }
    return ~mask;   // -> 11111111 11111110 00000000 00000000
}

void prettyPrint(unsigned long ip){
    unsigned char b1, b2, b3, b4;
    unsigned long mask = 0xFFFFFFFF;
    
    b1 = (ip & mask) >> 24;
    mask >>= 8;
    b2 = (ip & mask) >> 16;
    mask >>= 8;
    b3 = (ip & mask) >> 8;
    mask >>= 8;
    b4 = (ip & mask);

    printf("%d.%d.%d.%d\n", b1, b2, b3, b4);
}

void separateNet(unsigned int ip, unsigned char bitsNet){
    assert(bitsNet >= 1 && bitsNet <= 32);

    unsigned int mask = getMask(bitsNet), red, host;

    red = ip & mask;        //  mask es la mascara de la red
    host = ip & ~mask;      // ~mask es la mascara del host

    printf("Red: ");
    prettyPrint(red);
    
    printf("Host: ");
    prettyPrint(host);
}