#include <stdio.h>
#include "./../getnum.h"

int main() 
{
    // printf("\"3\" + \"4\" = %s\n", "3" + "4");   ERROR
    printf("'3' + '4' = %d\n", '3' + '4');
    printf("3 + 4 = %d\n", 3 + 4);
    printf("'3' + 4 = %d\n", '3' + 4);
    printf("3 + '4' = %d\n", 3 + '4');
    // printf("\"3\" + '4' = %s\n", "3" + '4');     ERROR
    // printf("\"3\" + 4 = %s\n", "3" + 4);         ERROR

    return 0;
}
