#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./../getnum.h"

int DCM(int n1, int n2);
void simplificarFraccion();
void sumarFracciones();

int main(){
    int opcion, flag = 1;
    do
    {
        opcion = getint("Ingrese una opcion: ");
        switch (opcion){
            case 1:
                simplificarFraccion();
                break;
            case 2:
                sumarFracciones();
                break;
            case 3:
                flag = 0;
                break;            
            default:
                printf("ERROR.\n");
                break;
        }
    } while (flag);
    return 0;
}

int DCM(int n1, int n2){
    n1 = abs(n1) , n2 = abs(n2);    
    while (n2 > 0){
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }    
    return n1;         
}

void simplificarFraccion() {
    int n = getint("Ingrese el numerador: ");
    int d = getint("Ingrese el denominador: ");
    if (d == 0) {
        printf("ERROR: El denominador no puede ser 0.\n");
        return;
    }
    int mcd = DCM(n, d);
    n /= mcd;
    d /= mcd;
    printf("La fracción simplificada es: %d / %d\n", n, d);
}

void sumarFracciones() {
    int n1 = getint("Ingrese el primer nominador: ");
    int d1 = getint("Ingrese el primer denominador: "); 
    int n2 = getint("Ingrese el segundo nominador: ");
    int d2 = getint("Ingrese el segundo denominador: "); 
    if (d1 == 0 || d2 == 0) {
        printf("ERROR. Los denominadores no pueden ser 0.\n");
        return;
    }

    int d = d1 * d2;
    int n = n1 * d2 + n2 * d1;
    int mcd = DCM(n, d);
    n /= mcd;
    d /= mcd;

    printf("La suma de las fracciones es: %d / %d\n", n, d);
}
