#include <stdio.h>
#include "./../getnum.h"
#include <math.h>

int main(){
    float a = getfloat("Ingrese el coeficiente a: \n");
    float b = getfloat("Ingrese el coeficiente b: \n");
    float c = getfloat("Ingrese el coeficiente c: \n");
    float discri = (b*b)-4*a*c;

    if (a==0){
        printf("ERROR\n");
    }
    else if (discri < 0){
        puts("Raices Imaginarias.\n");
    }
    else{
        float raiz1 = ((-b)+sqrt(discri))/2*a;
        float raiz2 = ((-b)-sqrt(discri))/2*a;
        
        printf("Las raices son: %f y %f.\n", raiz1, raiz2);
    }

    return 0; 

}