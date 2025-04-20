#include <stdio.h>
#include "./../getnum.h"

int main(){
    float ingresoFinal = getfloat("Ingrese el monto de Venta: \n");
    if (ingresoFinal >= 4000.0){
        ingresoFinal += ingresoFinal * 0.09;
    }
    else if (ingresoFinal >= 2000.0){
        ingresoFinal += ingresoFinal * 0.07;
    }
    else if (ingresoFinal >= 1000.0){
        ingresoFinal += ingresoFinal * 0.05;
    }    
    printf("Su total es: %.2f", ingresoFinal + 300.0);
}