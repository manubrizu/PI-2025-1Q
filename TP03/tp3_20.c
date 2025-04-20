#include <stdio.h>
#include "./../getnum.h"
#define EPS 0.0000001

int main(){
    double e = 1, prev = 0;
    int fact = 1;
    printf("%-10s %-10s\n", "N", "e");

    for (int i = 1; e - prev > EPS; i++){
        printf("%-10d %-10.7f\n", i, e);
        fact *= i;
        prev = e;
        e += 1.0/fact;
    }
    return 0;
}