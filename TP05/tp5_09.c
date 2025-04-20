#include <stdio.h>
#include <math.h>
#include "./../getnum.h"
#define EPS 0.0001

double f1(double x){
    return x*x - 4;
}

int main(){
    double extremInf = getdouble("Ingrese el extremo inferior: \n"), extremSup = getdouble("Ingrese el extremo superior: \n");
    int flagRaiz = 0;
    

    for(double i = extremInf; i <= extremSup; i += 0.001){
        double a = f1(i);
        double b = f1(i + 0.001);

        if (a == 0){
            printf("Hay una raiz en: %f\n", i);
        }
        else if (a * b < 0){
            printf("Hay una raiz entre: [%.3f, %.3f]\n", i, i+0.001);
            flagRaiz = 1;
        }

    }

    if(!flagRaiz)
        puts("NO hay una raiz.");

    return 0;
}
