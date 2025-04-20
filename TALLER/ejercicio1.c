#include <stdio.h>

int main()
{
    unsigned char var, var1, var2, var3, var4;
    var = 0xD8;
    var1 = (var & 0xC0) >> 6; // Quiero solamente los primeros 2 (1100 0000 = 0xC0)
    var2 = (var & 0x30) >> 4; // Quiero solamente (0011 0000 = 0x30)
    var3 = (var & 0x0C) >> 2; // Quiero solamente (0000 1100 = 0x0C)
    var4 = (var & 0x03); // Quiero solamente (0000 0011 = 0x03)

    printf("%d\n", var1);
    printf("%d\n", var2);
    printf("%d\n", var3);
    printf("%d\n", var4);

}