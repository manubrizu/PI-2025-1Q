/*
Escribir un programa que lea un número entero y obtenga la suma de las cifras.
Ejemplo:
Se lee 4351209
Muestra: 24

Modificar el programa anterior para que lea un número decimal y sume los
dígitos de la parte decimal. Utilizar la función getfloat de la librería getnum
provista por la cátedra.
Analizamos:
● ¿Qué sucede si se ingresan los siguientes valores:
○ 1.25
○ 2.11

*/

#include <stdio.h>
#include "./../getnum.h"

int main(){
    float num = getfloat("Ingrese un numero: \n");        
    int suma = 0; 
    if (num < 0) {
        num *= -1;
    }
    
    // PARTE ENTERA
    int numEntero = (int) num;

    while (numEntero != 0){
        suma += (numEntero % 10);
        numEntero /= 10;
    }
    
    num -= (int) num;

    printf("%f\n", num);

    // PARTE DECIMAL
    while (num != 0){
        num*=10;
        suma += ((int)num % 10);
        num -= (int)num; // ME SACO LA PARTE ENTERA
    }


    printf("La suma es: %d\n", suma);


}